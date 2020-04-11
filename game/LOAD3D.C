
#include "LOAD3D.H"


// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_InitCd()
 // line 226, offset 0x800371cc
	/* begin block 1 */
		// Start line: 269
	/* end block 1 */
	// End Line: 270

	/* begin block 2 */
		// Start line: 391
	/* end block 2 */
	// End Line: 392

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 250, offset 0x800371fc
	/* begin block 1 */
		// Start line: 317
	/* end block 1 */
	// End Line: 318

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 262, offset 0x80037248
	/* begin block 1 */
		// Start line: 263
		// Start offset: 0x80037248

		/* begin block 1.1 */
			// Start line: 270
			// Start offset: 0x80037284
			// Variables:
		// 		struct _ReadQueueEntry *currentQueueFile; // $s0
		// 		long actualReadSize; // $a1

			/* begin block 1.1.1 */
				// Start line: 287
				// Start offset: 0x800372EC
				// Variables:
			// 		int status; // $s1
			/* end block 1.1.1 */
			// End offset: 0x80037358
			// End Line: 319
		/* end block 1.1 */
		// End offset: 0x80037358
		// End Line: 320
	/* end block 1 */
	// End offset: 0x80037358
	// End Line: 325

	/* begin block 2 */
		// Start line: 343
	/* end block 2 */
	// End Line: 344

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 328, offset 0x8003736c
	/* begin block 1 */
		// Start line: 329
		// Start offset: 0x8003736C
		// Variables:
	// 		static int crap; // offset 0x0

		/* begin block 1.1 */
			// Start line: 339
			// Start offset: 0x80037398
			// Variables:
		// 		long crap[3]; // stack offset -40
		// 		int bytes; // $s0

			/* begin block 1.1.1 */
				// Start line: 361
				// Start offset: 0x8003740C
				// Variables:
			// 		struct CdlLOC loc; // stack offset -24
			/* end block 1.1.1 */
			// End offset: 0x8003740C
			// End Line: 364
		/* end block 1.1 */
		// End offset: 0x8003740C
		// End Line: 364
	/* end block 1 */
	// End offset: 0x80037484
	// End Line: 386

	/* begin block 2 */
		// Start line: 480
	/* end block 2 */
	// End Line: 481

/* File: C:\kain2\game\LOAD3D.C */

void LOAD_CdReadReady(uchar intr,uchar *result)

{
  uint uVar1;
  int iVar2;
  CdlLOC aCStack40 [4];
  CdlLOC aCStack24 [2];
  
  if (loadStatus.state == 2) {
    if (intr == '\x01') {
      uVar1 = loadStatus.currentQueueFile.readSize - loadStatus.currentQueueFile.readCurSize;
      if (0x7ff < (int)uVar1) {
        uVar1 = 0x800;
      }
      loadStatus.state = 4;
      loadStatus.bytesTransferred = uVar1;
      CdGetSector(aCStack40,3);
      iVar2 = CdPosToInt(aCStack40);
      if (loadStatus.currentSector == iVar2) {
        loadStatus.currentSector = loadStatus.currentSector + 1;
        CdGetSector(loadStatus.currentQueueFile.readCurDest,uVar1 >> 2);
        LOAD_CdDataReady();
      }
      else {
        loadStatus.state = (uint)intr;
        CdIntToPos(loadStatus.currentSector,aCStack24);
        CdControl('\x06',(u_char *)aCStack24,(u_char *)0x0);
      }
    }
    else {
      if (intr == '\x05') {
        loadStatus.state = 6;
        loadStatus.currentQueueFile.readStatus = 4;
      }
      else {
        printf(s_something__x_800cf69c,(uint)intr);
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
 // line 391, offset 0x800374c8
	/* begin block 1 */
		// Start line: 623
	/* end block 1 */
	// End Line: 624

	/* begin block 2 */
		// Start line: 626
	/* end block 2 */
	// End Line: 627

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 406, offset 0x8003750c
	/* begin block 1 */
		// Start line: 407
		// Start offset: 0x8003750C
		// Variables:
	// 		long bytesLoaded; // $a0
	// 		long readSoFar; // $v0
	// 		long state; // $s0
	/* end block 1 */
	// End offset: 0x800375A8
	// End Line: 446

	/* begin block 2 */
		// Start line: 656
	/* end block 2 */
	// End Line: 657

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 453, offset 0x800375b8
	/* begin block 1 */
		// Start line: 759
	/* end block 1 */
	// End Line: 760

	/* begin block 2 */
		// Start line: 761
	/* end block 2 */
	// End Line: 762

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 464, offset 0x800375d4
	/* begin block 1 */
		// Start line: 465
		// Start offset: 0x800375D4

		/* begin block 1.1 */
			// Start line: 465
			// Start offset: 0x800375D4
			// Variables:
		// 		struct CdlLOC loc; // stack offset -16
		/* end block 1.1 */
		// End offset: 0x80037610
		// End Line: 480
	/* end block 1 */
	// End offset: 0x80037610
	// End Line: 481

	/* begin block 2 */
		// Start line: 781
	/* end block 2 */
	// End Line: 782

/* File: C:\kain2\game\LOAD3D.C */

void LOAD_SetupFileToDoCDReading(void)

{
  long lVar1;
  CdlLOC aCStack16 [2];
  
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
  CdIntToPos(loadStatus.currentSector,aCStack16);
  CdControl('\x06',(u_char *)aCStack16,(u_char *)0x0);
  loadStatus.cdWaitTime = TIMER_GetTimeMS();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_SetupFileToDoBufferedCDReading()
 // line 539, offset 0x80037650
	/* begin block 1 */
		// Start line: 540
		// Start offset: 0x80037650

		/* begin block 1.1 */
			// Start line: 540
			// Start offset: 0x80037650
			// Variables:
		// 		struct CdlLOC loc; // stack offset -16
		/* end block 1.1 */
		// End offset: 0x80037684
		// End Line: 556
	/* end block 1 */
	// End offset: 0x80037684
	// End Line: 557

	/* begin block 2 */
		// Start line: 973
	/* end block 2 */
	// End Line: 974

/* File: C:\kain2\game\LOAD3D.C */

void LOAD_SetupFileToDoBufferedCDReading(void)

{
  long lVar1;
  CdlLOC aCStack16 [2];
  
  loadStatus.currentQueueFile.readStatus = 6;
  loadStatus.checksum = 0;
  loadStatus.state = 1;
  loadStatus.checkAddr = (long *)loadStatus.currentQueueFile.readStartDest;
  lVar1 = loadStatus.currentQueueFile.readStartPos;
  if (loadStatus.currentQueueFile.readStartPos < 0) {
    lVar1 = loadStatus.currentQueueFile.readStartPos + 0x7ff;
  }
  loadStatus.currentSector = loadStatus.bigFile.bigfileBaseOffset + (lVar1 >> 0xb);
  CdIntToPos(loadStatus.currentSector,aCStack16);
  CdControl('\x06',(u_char *)aCStack16,(u_char *)0x0);
  loadStatus.cdWaitTime = TIMER_GetTimeMS();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_ProcessReadQueue()
 // line 564, offset 0x800376c4
	/* begin block 1 */
		// Start line: 565
		// Start offset: 0x800376C4

		/* begin block 1.1 */
			// Start line: 605
			// Start offset: 0x800377AC
			// Variables:
		// 		long cdWaitTimeDiff; // $v0

			/* begin block 1.1.1 */
				// Start line: 611
				// Start offset: 0x800377EC
				// Variables:
			// 		struct CdlLOC loc; // stack offset -16
			/* end block 1.1.1 */
			// End offset: 0x800377EC
			// End Line: 612
		/* end block 1.1 */
		// End offset: 0x80037858
		// End Line: 636
	/* end block 1 */
	// End offset: 0x80037858
	// End Line: 638

	/* begin block 2 */
		// Start line: 1059
	/* end block 2 */
	// End Line: 1060

	/* begin block 3 */
		// Start line: 1065
	/* end block 3 */
	// End Line: 1066

/* File: C:\kain2\game\LOAD3D.C */

void LOAD_ProcessReadQueue(void)

{
  ulong uVar1;
  int iVar2;
  CdlLOC aCStack16 [2];
  
  if (DAT_800d218c < 0) {
    FONT_Print(s_CD_St__d_LS__d_sk__d_tm__d_rd__d_800cf6ac);
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
        CdIntToPos(loadStatus.currentSector,aCStack16);
        CdControl('\x06',(u_char *)aCStack16,(u_char *)0x0);
        loadStatus.cdWaitTime = TIMER_GetTimeMS();
      }
      else {
        iVar2 = VOICEXA_IsPlaying();
        if (iVar2 == 0) {
          CdControlF('\t',(u_char *)0x0);
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
 // line 642, offset 0x80037868
	/* begin block 1 */
		// Start line: 643
		// Start offset: 0x80037868
		// Variables:
	// 		struct CdlFILE fp; // stack offset -40
	// 		int i; // $s0
	// 		char *readBuffer; // $s0
	/* end block 1 */
	// End offset: 0x80037930
	// End Line: 687

	/* begin block 2 */
		// Start line: 1222
	/* end block 2 */
	// End Line: 1223

/* File: C:\kain2\game\LOAD3D.C */

char * LOAD_ReadFileFromCD(char *filename,int memType)

{
  CdlFILE *pCVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  CdlFILE CStack40;
  
  iVar4 = 0;
  do {
    pCVar1 = CdSearchFile(&CStack40,filename);
    if (pCVar1 != (CdlFILE *)0x0) break;
    CdReset(0);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  pcVar3 = (char *)0x0;
  if (iVar4 != 10) {
    pcVar2 = MEMPACK_Malloc(CStack40.size,(uchar)memType);
    pcVar3 = (char *)0x0;
    if (pcVar2 != (char *)0x0) {
      iVar4 = CdPosToInt((CdlLOC *)&CStack40);
      loadStatus.currentQueueFile.readCurSize = 0;
      loadStatus.currentQueueFile.readStatus = 1;
      loadStatus.currentQueueFile.checksumType = 0;
      loadStatus.currentQueueFile.checksum = 0;
      loadStatus.currentQueueFile.readStartPos =
           (iVar4 - loadStatus.bigFile.bigfileBaseOffset) * 0x800;
      loadStatus.currentQueueFile.readSize = CStack40.size;
      loadStatus.currentQueueFile.readStartDest = pcVar2;
      do {
        LOAD_ProcessReadQueue();
        iVar4 = LOAD_IsFileLoading();
      } while (iVar4 != 0);
      CdControlF('\t',(u_char *)0x0);
      pcVar3 = pcVar2;
    }
  }
  return pcVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_CdReadFromBigFile(long fileOffset /*$a0*/, unsigned long *loadAddr /*$a1*/, long bytes /*$a2*/, long chksumLevel /*$a3*/, long checksum /*stack 16*/)
 // line 689, offset 0x80037948
	/* begin block 1 */
		// Start line: 1335
	/* end block 1 */
	// End Line: 1336

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 702, offset 0x80037974
	/* begin block 1 */
		// Start line: 703
		// Start offset: 0x80037974
		// Variables:
	// 		struct _BigFileDir *dir; // $s2
	// 		long sizeOfDir; // $s1
	/* end block 1 */
	// End offset: 0x80037974
	// End Line: 703

	/* begin block 2 */
		// Start line: 1365
	/* end block 2 */
	// End Line: 1366

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 718, offset 0x800379dc
	/* begin block 1 */
		// Start line: 719
		// Start offset: 0x800379DC
		// Variables:
	// 		struct CdlFILE fp; // stack offset -40
	// 		long i; // $s1

		/* begin block 1.1 */
			// Start line: 786
			// Start offset: 0x80037A90
			// Variables:
		// 		char *ptr; // $s0
		/* end block 1.1 */
		// End offset: 0x80037AF8
		// End Line: 801
	/* end block 1 */
	// End offset: 0x80037B20
	// End Line: 813

	/* begin block 2 */
		// Start line: 1399
	/* end block 2 */
	// End Line: 1400

/* File: C:\kain2\game\LOAD3D.C */

void LOAD_InitCdLoader(char *bigFileName,char *voiceFileName)

{
  CdlFILE *pCVar1;
  ulong *loadAddr;
  int iVar2;
  ulong allocSize;
  CdlFILE CStack40;
  
  iVar2 = 0;
  loadStatus.state = 0;
  do {
    pCVar1 = CdSearchFile(&CStack40,bigFileName);
    if (pCVar1 != (CdlFILE *)0x0) break;
    CdReset(0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  if (iVar2 != 10) {
    LOAD_InitCdStreamMode();
    loadStatus.bigFile.bigfileBaseOffset = CdPosToInt((CdlLOC *)&CStack40);
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
    CdControlF('\t',(u_char *)0x0);
    allocSize = loadStatus.bigFile.numSubDirs * 8 + 4;
    loadAddr = (ulong *)MEMPACK_Malloc(allocSize,'\b');
    CdSync(0,(u_char *)0x0);
    LOAD_CdReadFromBigFile(0,loadAddr,allocSize,0,0);
    loadStatus.bigFile.subDirList = (_BigFileDirEntry *)(loadAddr + 1);
    do {
      LOAD_ProcessReadQueue();
      iVar2 = LOAD_IsFileLoading();
    } while (iVar2 != 0);
    loadStatus.bigFile.rootDir =
         (_BigFileDir *)LOAD_ReadDirectory((_BigFileDirEntry *)loadStatus.bigFile.subDirList);
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
 // line 815, offset 0x80037b34
	/* begin block 1 */
		// Start line: 816
		// Start offset: 0x80037B34
		// Variables:
	// 		struct _BigFileEntry *fileInfo; // $v1
	/* end block 1 */
	// End offset: 0x80037BAC
	// End Line: 839

	/* begin block 2 */
		// Start line: 1643
	/* end block 2 */
	// End Line: 1644

/* File: C:\kain2\game\LOAD3D.C */

int LOAD_SetupFileInfo(_NonBlockLoadEntry *loadEntry)

{
  _BigFileEntry *p_Var1;
  int iVar2;
  
  p_Var1 = LOAD_GetBigFileEntryByHash(loadEntry->fileHash);
  if (p_Var1 == (_BigFileEntry *)0x0) {
    iVar2 = 0;
    if (loadEntry->dirHash == loadStatus.bigFile.currentDirID) {
      DEBUG_FatalError(s_CD_ERROR__File__s_does_not_exist_800cf6d4);
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
 // line 842, offset 0x80037bbc
	/* begin block 1 */
		// Start line: 1698
	/* end block 1 */
	// End Line: 1699

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 862, offset 0x80037c40
	/* begin block 1 */
		// Start line: 863
		// Start offset: 0x80037C40
		// Variables:
	// 		struct _ReadQueueEntry *currentQueueReq; // $v1
	/* end block 1 */
	// End offset: 0x80037CD4
	// End Line: 888

	/* begin block 2 */
		// Start line: 1738
	/* end block 2 */
	// End Line: 1739

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 901, offset 0x80037ce4
	/* begin block 1 */
		// Start line: 902
		// Start offset: 0x80037CE4
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
	// End offset: 0x80037DF8
	// End Line: 945

	/* begin block 2 */
		// Start line: 1824
	/* end block 2 */
	// End Line: 1825

/* File: C:\kain2\game\LOAD3D.C */

long LOAD_HashName(char *string)

{
  int iVar1;
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
  iVar1 = strlen();
  iVar5 = iVar1 + -1;
  pcVar2 = strchr(string,'.');
  uVar9 = 0;
  if (pcVar2 != (char *)0x0) {
    uVar4 = 0;
    s2 = HashExtensions;
    do {
      iVar3 = strcmpi(pcVar2 + 1,s2);
      uVar9 = uVar4;
      if (iVar3 == 0) break;
      uVar4 = uVar4 + 1;
      s2 = s2 + 4;
      uVar9 = 0;
    } while ((int)uVar4 < 7);
    if ((int)uVar4 < 7) {
      iVar5 = iVar1 + -5;
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
 // line 948, offset 0x80037e3c
	/* begin block 1 */
		// Start line: 950
		// Start offset: 0x80037E3C
		// Variables:
	// 		int val; // $v1
	// 		int last; // $t0
	// 		int hash; // $a2
	// 		int num; // $a3
	// 		int flag; // $t1
	// 		char *c; // $a0
	/* end block 1 */
	// End offset: 0x80037ED0
	// End Line: 984

	/* begin block 2 */
		// Start line: 1931
	/* end block 2 */
	// End Line: 1932

	/* begin block 3 */
		// Start line: 1932
	/* end block 3 */
	// End Line: 1933

	/* begin block 4 */
		// Start line: 1933
	/* end block 4 */
	// End Line: 1934

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 989, offset 0x80037ee0
	/* begin block 1 */
		// Start line: 991
		// Start offset: 0x80037EE0
		// Variables:
	// 		int i; // $a1
	// 		struct _BigFileEntry *entry; // $v1
	/* end block 1 */
	// End offset: 0x80037F60
	// End Line: 1010

	/* begin block 2 */
		// Start line: 2036
	/* end block 2 */
	// End Line: 2037

	/* begin block 3 */
		// Start line: 2037
	/* end block 3 */
	// End Line: 2038

	/* begin block 4 */
		// Start line: 2040
	/* end block 4 */
	// End Line: 2041

/* File: C:\kain2\game\LOAD3D.C */

_BigFileEntry * LOAD_GetBigFileEntryByHash(long hash)

{
  _BigFileEntry *p_Var1;
  int iVar2;
  
  if ((loadStatus.bigFile.currentDir != (_BigFileDir *)0x0) && (loadStatus.currentDirLoading == 0))
  {
    iVar2 = (loadStatus.bigFile.currentDir)->numFiles;
    p_Var1 = (loadStatus.bigFile.currentDir)->fileList;
    while (iVar2 != 0) {
      iVar2 = iVar2 + -1;
      if (p_Var1->fileHash == hash) {
        return (_BigFileEntry *)p_Var1;
      }
      p_Var1 = p_Var1 + 1;
    }
  }
  iVar2 = (loadStatus.bigFile.rootDir)->numFiles;
  p_Var1 = (loadStatus.bigFile.rootDir)->fileList;
  while( true ) {
    if (iVar2 == 0) {
      return (_BigFileEntry *)0x0;
    }
    iVar2 = iVar2 + -1;
    if (p_Var1->fileHash == hash) break;
    p_Var1 = p_Var1 + 1;
  }
  return (_BigFileEntry *)p_Var1;
}



// decompiled code
// original method signature: 
// struct _BigFileEntry * /*$ra*/ LOAD_GetBigFileEntry(char *fileName /*$a0*/)
 // line 1012, offset 0x80037f68
	/* begin block 1 */
		// Start line: 1013
		// Start offset: 0x80037F68
	/* end block 1 */
	// End offset: 0x80037F68
	// End Line: 1013

	/* begin block 2 */
		// Start line: 2087
	/* end block 2 */
	// End Line: 2088

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 1068, offset 0x80037f90
	/* begin block 1 */
		// Start line: 1069
		// Start offset: 0x80037F90
		// Variables:
	// 		struct _BigFileEntry *entry; // $v0
	/* end block 1 */
	// End offset: 0x80037FB4
	// End Line: 1074

	/* begin block 2 */
		// Start line: 2133
	/* end block 2 */
	// End Line: 2134

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 1079, offset 0x80037fc4
	/* begin block 1 */
		// Start line: 1080
		// Start offset: 0x80037FC4
		// Variables:
	// 		struct RECT rect; // stack offset -24
	// 		long *clutAddr; // $s0
	/* end block 1 */
	// End offset: 0x80038050
	// End Line: 1109

	/* begin block 2 */
		// Start line: 2171
	/* end block 2 */
	// End Line: 2172

/* File: C:\kain2\game\LOAD3D.C */

void LOAD_LoadTIM(long *addr,long x_pos,long y_pos,long clut_x,long clut_y)

{
  long *plVar1;
  u_long *p;
  RECT local_18;
  
  plVar1 = addr + 2;
  p = (u_long *)0x0;
  if (addr[1] == 8) {
    p = (u_long *)(addr + 5);
    plVar1 = addr + 0xd;
  }
  local_18.x = (short)x_pos;
  local_18.y = (short)y_pos;
  local_18.w = *(short *)(plVar1 + 2);
  local_18.h = *(short *)((int)plVar1 + 10);
  LoadImage(&local_18,(u_long *)(plVar1 + 3));
  if (p != (u_long *)0x0) {
    local_18.x = (short)clut_x;
    local_18.y = (short)clut_y;
    local_18.w = 0x10;
    local_18.h = 1;
    DrawSync(0);
    LoadImage(&local_18,p);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_LoadTIM2(long *addr /*$a1*/, long x_pos /*$a1*/, long y_pos /*$a2*/, long width /*$a3*/, long height /*stack 16*/)
 // line 1111, offset 0x80038064
	/* begin block 1 */
		// Start line: 1112
		// Start offset: 0x80038064
		// Variables:
	// 		struct RECT rect; // stack offset -16
	/* end block 1 */
	// End offset: 0x80038064
	// End Line: 1112

	/* begin block 2 */
		// Start line: 2243
	/* end block 2 */
	// End Line: 2244

/* File: C:\kain2\game\LOAD3D.C */

void LOAD_LoadTIM2(long *addr,long x_pos,long y_pos,long width,long height)

{
  RECT local_10;
  
  local_10.x = (short)x_pos;
  local_10.y = (short)y_pos;
  local_10.w = *(short *)(addr + 4);
  local_10.h = *(short *)((int)addr + 0x12);
  LoadImage(&local_10,(u_long *)(addr + 5));
  DrawSync(0);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ LOAD_RelocBinaryData(long *data /*$s0*/, long fileSize /*$s1*/)
 // line 1149, offset 0x800380ac
	/* begin block 1 */
		// Start line: 1150
		// Start offset: 0x800380AC
		// Variables:
	// 		long *lastMoveDest; // $v1
	// 		long tableSize; // $s3
	// 		struct RedirectList redirectListX; // stack offset -32
	// 		struct RedirectList *redirectList; // $a0
	/* end block 1 */
	// End offset: 0x80038144
	// End Line: 1170

	/* begin block 2 */
		// Start line: 2277
	/* end block 2 */
	// End Line: 2278

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 1242, offset 0x80038164
	/* begin block 1 */
		// Start line: 2481
	/* end block 1 */
	// End Line: 2482

	/* begin block 2 */
		// Start line: 2429
	/* end block 2 */
	// End Line: 2430

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 1256, offset 0x800381ac
	/* begin block 1 */
		// Start line: 2457
	/* end block 1 */
	// End Line: 2458

/* File: C:\kain2\game\LOAD3D.C */

void * LOAD_InitBuffers(void)

{
  loadStatus.buffer1 = MEMPACK_Malloc(0x800,'#');
  loadStatus.buffer2 = MEMPACK_Malloc(0x800,'#');
  return loadStatus.buffer1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_InitCdStreamMode()
 // line 1266, offset 0x800381e8
	/* begin block 1 */
		// Start line: 1267
		// Start offset: 0x800381E8
		// Variables:
	// 		unsigned char cdMode; // stack offset -16
	/* end block 1 */
	// End offset: 0x800381E8
	// End Line: 1267

	/* begin block 2 */
		// Start line: 2481
	/* end block 2 */
	// End Line: 2482

/* File: C:\kain2\game\LOAD3D.C */

void LOAD_InitCdStreamMode(void)

{
  u_char local_10 [8];
  
  local_10[0] = -0x60;
  CdReadyCallback(LOAD_CdReadReady);
  CdSyncCallback(LOAD_CdSeekCallback);
  CdControl('\x0e',local_10,(u_char *)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_DumpCurrentDir()
 // line 1276, offset 0x80038230
	/* begin block 1 */
		// Start line: 2504
	/* end block 1 */
	// End Line: 2505

	/* begin block 2 */
		// Start line: 2505
	/* end block 2 */
	// End Line: 2506

/* File: C:\kain2\game\LOAD3D.C */

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
 // line 1292, offset 0x80038280
	/* begin block 1 */
		// Start line: 1293
		// Start offset: 0x80038280

		/* begin block 1.1 */
			// Start line: 1297
			// Start offset: 0x80038298
			// Variables:
		// 		int i; // $v1

			/* begin block 1.1.1 */
				// Start line: 1304
				// Start offset: 0x800382B8
				// Variables:
			// 		struct _BigFileDir *dir; // $a0
			/* end block 1.1.1 */
			// End offset: 0x800382D8
			// End Line: 1310
		/* end block 1.1 */
		// End offset: 0x80038370
		// End Line: 1329
	/* end block 1 */
	// End offset: 0x80038374
	// End Line: 1332

	/* begin block 2 */
		// Start line: 2537
	/* end block 2 */
	// End Line: 2538

/* File: C:\kain2\game\LOAD3D.C */

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
          loadStatus.bigFile.currentDir =
               (_BigFileDir *)
               LOAD_ReadDirectory((_BigFileDirEntry *)(loadStatus.bigFile.subDirList + iVar3));
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
 // line 1339, offset 0x80038388
	/* begin block 1 */
		// Start line: 2674
	/* end block 1 */
	// End Line: 2675

	/* begin block 2 */
		// Start line: 2646
	/* end block 2 */
	// End Line: 2647

/* File: C:\kain2\game\LOAD3D.C */

void LOAD_SetSearchDirectory(long id)

{
  loadStatus.bigFile.searchDirID = id;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ LOAD_GetSearchDirectory()
 // line 1344, offset 0x80038394
	/* begin block 1 */
		// Start line: 2655
	/* end block 1 */
	// End Line: 2656

	/* begin block 2 */
		// Start line: 2656
	/* end block 2 */
	// End Line: 2657

/* File: C:\kain2\game\LOAD3D.C */

long LOAD_GetSearchDirectory(void)

{
  return loadStatus.bigFile.searchDirID;
}



// decompiled code
// original method signature: 
// int /*$ra*/ LOAD_ChangeDirectoryFlag()
 // line 1349, offset 0x800383a0
	/* begin block 1 */
		// Start line: 2665
	/* end block 1 */
	// End Line: 2666

	/* begin block 2 */
		// Start line: 2666
	/* end block 2 */
	// End Line: 2667

/* File: C:\kain2\game\LOAD3D.C */

int LOAD_ChangeDirectoryFlag(void)

{
  return loadStatus.changeDir;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_UpdateBigFilePointers(struct _BigFileDir *oldDir /*$a0*/, struct _BigFileDir *newDir /*$a1*/)
 // line 1354, offset 0x800383ac
	/* begin block 1 */
		// Start line: 2675
	/* end block 1 */
	// End Line: 2676

	/* begin block 2 */
		// Start line: 2676
	/* end block 2 */
	// End Line: 2677

/* File: C:\kain2\game\LOAD3D.C */

void LOAD_UpdateBigFilePointers(_BigFileDir *oldDir,_BigFileDir *newDir)

{
  if (loadStatus.bigFile.currentDir == (_BigFileDir *)oldDir) {
    loadStatus.bigFile.currentDir = (_BigFileDir *)newDir;
  }
  if (loadStatus.bigFile.cachedDir == (_BigFileDir *)oldDir) {
    loadStatus.bigFile.cachedDir = (_BigFileDir *)newDir;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ LOAD_IsFileLoading()
 // line 1369, offset 0x800383dc
	/* begin block 1 */
		// Start line: 2705
	/* end block 1 */
	// End Line: 2706

	/* begin block 2 */
		// Start line: 2711
	/* end block 2 */
	// End Line: 2712

/* File: C:\kain2\game\LOAD3D.C */

int LOAD_IsFileLoading(void)

{
  return (uint)(loadStatus.currentQueueFile.readStatus != 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_StopLoad()
 // line 1411, offset 0x800383e8
	/* begin block 1 */
		// Start line: 2815
	/* end block 1 */
	// End Line: 2816

	/* begin block 2 */
		// Start line: 2757
	/* end block 2 */
	// End Line: 2758

/* File: C:\kain2\game\LOAD3D.C */

void LOAD_StopLoad(void)

{
  if (loadStatus.currentDirLoading != 0) {
    loadStatus.currentDirLoading = 0;
  }
  loadStatus.currentQueueFile.readStatus = 0;
  loadStatus.state = 5;
  return;
}





