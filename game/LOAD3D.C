#include "THISDUST.H"
#include "LOAD3D.H"


// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_InitCd()
 // line 226, offset 0x80037c64
	/* begin block 1 */
		// Start line: 269
	/* end block 1 */
	// End Line: 270

	/* begin block 2 */
		// Start line: 391
	/* end block 2 */
	// End Line: 392

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
 // line 250, offset 0x80037c94
	/* begin block 1 */
		// Start line: 317
	/* end block 1 */
	// End Line: 318

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
 // line 262, offset 0x80037ce0
	/* begin block 1 */
		// Start line: 263
		// Start offset: 0x80037CE0

		/* begin block 1.1 */
			// Start line: 270
			// Start offset: 0x80037D1C
			// Variables:
		// 		struct _ReadQueueEntry *currentQueueFile; // $s0
		// 		long actualReadSize; // $a1

			/* begin block 1.1.1 */
				// Start line: 287
				// Start offset: 0x80037D84
				// Variables:
			// 		int status; // $s1
			/* end block 1.1.1 */
			// End offset: 0x80037DF0
			// End Line: 319
		/* end block 1.1 */
		// End offset: 0x80037DF0
		// End Line: 320
	/* end block 1 */
	// End offset: 0x80037DF0
	// End Line: 325

	/* begin block 2 */
		// Start line: 343
	/* end block 2 */
	// End Line: 344

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
 // line 328, offset 0x80037e04
	/* begin block 1 */
		// Start line: 329
		// Start offset: 0x80037E04
		// Variables:
	// 		static int crap; // offset 0x0

		/* begin block 1.1 */
			// Start line: 339
			// Start offset: 0x80037E30
			// Variables:
		// 		long crap[3]; // stack offset -40
		// 		int bytes; // $s0

			/* begin block 1.1.1 */
				// Start line: 361
				// Start offset: 0x80037EA4
				// Variables:
			// 		struct CdlLOC loc; // stack offset -24
			/* end block 1.1.1 */
			// End offset: 0x80037EA4
			// End Line: 364
		/* end block 1.1 */
		// End offset: 0x80037EA4
		// End Line: 364
	/* end block 1 */
	// End offset: 0x80037F1C
	// End Line: 386

	/* begin block 2 */
		// Start line: 480
	/* end block 2 */
	// End Line: 481

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
 // line 391, offset 0x80037f60
	/* begin block 1 */
		// Start line: 623
	/* end block 1 */
	// End Line: 624

	/* begin block 2 */
		// Start line: 626
	/* end block 2 */
	// End Line: 627

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
 // line 406, offset 0x80037fa4
	/* begin block 1 */
		// Start line: 407
		// Start offset: 0x80037FA4
		// Variables:
	// 		long bytesLoaded; // $a0
	// 		long readSoFar; // $v0
	// 		long state; // $s0
	/* end block 1 */
	// End offset: 0x80038040
	// End Line: 443

	/* begin block 2 */
		// Start line: 656
	/* end block 2 */
	// End Line: 657

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
      }
    }
    else {
      GXFilePrint("CD ERROR: checksum error\n");
      loadStatus.currentQueueFile.readStatus = 7;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_DoCDBufferedReading()
 // line 450, offset 0x80038050
	/* begin block 1 */
		// Start line: 752
	/* end block 1 */
	// End Line: 753

	/* begin block 2 */
		// Start line: 754
	/* end block 2 */
	// End Line: 755

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
 // line 461, offset 0x8003806c
	/* begin block 1 */
		// Start line: 462
		// Start offset: 0x8003806C

		/* begin block 1.1 */
			// Start line: 462
			// Start offset: 0x8003806C
			// Variables:
		// 		struct CdlLOC loc; // stack offset -16
		/* end block 1.1 */
		// End offset: 0x800380A8
		// End Line: 477
	/* end block 1 */
	// End offset: 0x800380A8
	// End Line: 478

	/* begin block 2 */
		// Start line: 774
	/* end block 2 */
	// End Line: 775

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
 // line 536, offset 0x800380e8
	/* begin block 1 */
		// Start line: 537
		// Start offset: 0x800380E8

		/* begin block 1.1 */
			// Start line: 537
			// Start offset: 0x800380E8
			// Variables:
		// 		struct CdlLOC loc; // stack offset -16
		/* end block 1.1 */
		// End offset: 0x8003811C
		// End Line: 553
	/* end block 1 */
	// End offset: 0x8003811C
	// End Line: 554

	/* begin block 2 */
		// Start line: 966
	/* end block 2 */
	// End Line: 967

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
 // line 561, offset 0x8003815c
	/* begin block 1 */
		// Start line: 562
		// Start offset: 0x8003815C

		/* begin block 1.1 */
			// Start line: 602
			// Start offset: 0x80038254
			// Variables:
		// 		long cdWaitTimeDiff; // $s0

			/* begin block 1.1.1 */
				// Start line: 608
				// Start offset: 0x80038294
				// Variables:
			// 		struct CdlLOC loc; // stack offset -16
			/* end block 1.1.1 */
			// End offset: 0x80038294
			// End Line: 609
		/* end block 1.1 */
		// End offset: 0x80038320
		// End Line: 633
	/* end block 1 */
	// End offset: 0x80038320
	// End Line: 635

	/* begin block 2 */
		// Start line: 1052
	/* end block 2 */
	// End Line: 1053

	/* begin block 3 */
		// Start line: 1058
	/* end block 3 */
	// End Line: 1059

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
    GXFilePrint("CD ERROR: checksum error\n");
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
        TIMER_GetTimeMS();
        GXFilePrint("CD ERROR: timeout after %d mS, %8d %8d try again\n");
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
 // line 639, offset 0x80038330
	/* begin block 1 */
		// Start line: 640
		// Start offset: 0x80038330
		// Variables:
	// 		struct CdlFILE fp; // stack offset -40
	// 		int i; // $s0
	// 		char *readBuffer; // $s0
	/* end block 1 */
	// End offset: 0x80038414
	// End Line: 684

	/* begin block 2 */
		// Start line: 1215
	/* end block 2 */
	// End Line: 1216

char * LOAD_ReadFileFromCD(char *filename,int memType)

{
  undefined4 *puVar1;
  char *fmt;
  int iVar2;
  undefined4 uStack40;
  ulong local_24;
  
  iVar2 = 0;
  do {
    puVar1 = CdSearchFile(&uStack40,filename);
    if (puVar1 != (undefined4 *)0x0) break;
    CdReset(0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  if (iVar2 == 10) {
    fmt = "CD ERROR: localization file not found\n";
  }
  else {
    fmt = MEMPACK_Malloc(local_24,(uchar)memType);
    if (fmt != (char *)0x0) {
      iVar2 = CdPosToInt((byte *)&uStack40);
      loadStatus.currentQueueFile.readCurSize = 0;
      loadStatus.currentQueueFile.readStatus = 1;
      loadStatus.currentQueueFile.checksumType = 0;
      loadStatus.currentQueueFile.checksum = 0;
      loadStatus.currentQueueFile.readStartPos =
           (iVar2 - loadStatus.bigFile.bigfileBaseOffset) * 0x800;
      loadStatus.currentQueueFile.readSize = local_24;
      loadStatus.currentQueueFile.readStartDest = fmt;
      do {
        LOAD_ProcessReadQueue();
        iVar2 = LOAD_IsFileLoading();
      } while (iVar2 != 0);
      CdControlF(9,(byte *)0x0);
      return fmt;
    }
    fmt = "CD ERROR: could not allocate read buffer\n";
  }
  GXFilePrint(fmt);
  return (char *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_CdReadFromBigFile(long fileOffset /*$a0*/, unsigned long *loadAddr /*$a1*/, long bytes /*$a2*/, long chksumLevel /*$a3*/, long checksum /*stack 16*/)
 // line 686, offset 0x8003842c
	/* begin block 1 */
		// Start line: 1328
	/* end block 1 */
	// End Line: 1329

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
// struct _BigFileDir * /*$ra*/ LOAD_ReadDirectory(struct _BigFileDirEntry *dirEntry /*$s2*/)
 // line 699, offset 0x80038458
	/* begin block 1 */
		// Start line: 700
		// Start offset: 0x80038458
		// Variables:
	// 		struct _BigFileDir *dir; // $s1
	// 		long sizeOfDir; // $s0
	/* end block 1 */
	// End offset: 0x8003848C
	// End Line: 708

	/* begin block 2 */
		// Start line: 1358
	/* end block 2 */
	// End Line: 1359

	/* begin block 3 */
		// Start line: 1362
	/* end block 3 */
	// End Line: 1363

_BigFileDir * LOAD_ReadDirectory(_BigFileDirEntry *dirEntry)

{
  _BigFileDir *loadAddr;
  ulong allocSize;
  
  if (gameTrackerX.debugFlags < 0) {
    GXFilePrint("Reading directory %d with %d files\n");
  }
  allocSize = (int)dirEntry->numFiles * 0x10 + 4;
  loadAddr = (_BigFileDir *)MEMPACK_Malloc(allocSize,',');
  LOAD_CdReadFromBigFile(dirEntry->subDirOffset,(ulong *)loadAddr,allocSize,0,0);
  return loadAddr;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_InitCdLoader(char *bigFileName /*$s0*/, char *voiceFileName /*$a1*/)
 // line 715, offset 0x800384dc
	/* begin block 1 */
		// Start line: 716
		// Start offset: 0x800384DC
		// Variables:
	// 		struct CdlFILE fp; // stack offset -40
	// 		long i; // $s1

		/* begin block 1.1 */
			// Start line: 783
			// Start offset: 0x800385B0
			// Variables:
		// 		char *ptr; // $s0
		/* end block 1.1 */
		// End offset: 0x80038628
		// End Line: 798
	/* end block 1 */
	// End offset: 0x80038664
	// End Line: 810

	/* begin block 2 */
		// Start line: 1396
	/* end block 2 */
	// End Line: 1397

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
  if (iVar2 == 10) {
    GXFilePrint("CD ERROR: bigfile not found\n");
  }
  else {
    LOAD_InitCdStreamMode();
    loadStatus.bigFile.bigfileBaseOffset = CdPosToInt((byte *)auStack40);
    loadStatus.cdWaitTime = 0;
    loadStatus.currentQueueFile.readStatus = 0;
    loadStatus.bigFile.currentDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.currentDirID = 0;
    loadStatus.bigFile.cachedDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.cachedDirID = 0;
    loadStatus.bigFile.searchDirID = 0;
    GXFilePrint("Found bigfile at %d\n");
    LOAD_CdReadFromBigFile(0,(ulong *)&loadStatus.bigFile.numSubDirs,4,0,0);
    do {
      LOAD_ProcessReadQueue();
      iVar2 = LOAD_IsFileLoading();
    } while (iVar2 != 0);
    CdControlF(9,(byte *)0x0);
    GXFilePrint("Num of directories %d\n");
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
    GXFilePrint("Num of files in root %d\n");
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ LOAD_SetupFileInfo(struct _NonBlockLoadEntry *loadEntry /*$s0*/)
 // line 812, offset 0x80038678
	/* begin block 1 */
		// Start line: 813
		// Start offset: 0x80038678
		// Variables:
	// 		struct _BigFileEntry *fileInfo; // $v1
	/* end block 1 */
	// End offset: 0x800386EC
	// End Line: 836

	/* begin block 2 */
		// Start line: 1613
	/* end block 2 */
	// End Line: 1614

int LOAD_SetupFileInfo(_NonBlockLoadEntry *loadEntry)

{
  _BigFileEntry *p_Var1;
  int iVar2;
  
  p_Var1 = LOAD_GetBigFileEntryByHash(loadEntry->fileHash);
  if (p_Var1 == (_BigFileEntry *)0x0) {
    iVar2 = 0;
    if (loadEntry->dirHash == 0) {
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
 // line 839, offset 0x800386fc
	/* begin block 1 */
		// Start line: 1668
	/* end block 1 */
	// End Line: 1669

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
 // line 859, offset 0x80038780
	/* begin block 1 */
		// Start line: 860
		// Start offset: 0x80038780
		// Variables:
	// 		struct _ReadQueueEntry *currentQueueReq; // $v1
	/* end block 1 */
	// End offset: 0x80038814
	// End Line: 885

	/* begin block 2 */
		// Start line: 1708
	/* end block 2 */
	// End Line: 1709

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
 // line 898, offset 0x80038824
	/* begin block 1 */
		// Start line: 899
		// Start offset: 0x80038824
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
	// End offset: 0x80038938
	// End Line: 942

	/* begin block 2 */
		// Start line: 1794
	/* end block 2 */
	// End Line: 1795

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
 // line 945, offset 0x8003897c
	/* begin block 1 */
		// Start line: 947
		// Start offset: 0x8003897C
		// Variables:
	// 		int val; // $v1
	// 		int last; // $t0
	// 		int hash; // $a2
	// 		int num; // $a3
	// 		int flag; // $t1
	// 		char *c; // $a0
	/* end block 1 */
	// End offset: 0x80038A10
	// End Line: 981

	/* begin block 2 */
		// Start line: 1901
	/* end block 2 */
	// End Line: 1902

	/* begin block 3 */
		// Start line: 1902
	/* end block 3 */
	// End Line: 1903

	/* begin block 4 */
		// Start line: 1903
	/* end block 4 */
	// End Line: 1904

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
 // line 986, offset 0x80038a20
	/* begin block 1 */
		// Start line: 988
		// Start offset: 0x80038A20
		// Variables:
	// 		int i; // $a1
	// 		struct _BigFileEntry *entry; // $v1
	/* end block 1 */
	// End offset: 0x80038AA0
	// End Line: 1007

	/* begin block 2 */
		// Start line: 2006
	/* end block 2 */
	// End Line: 2007

	/* begin block 3 */
		// Start line: 2007
	/* end block 3 */
	// End Line: 2008

	/* begin block 4 */
		// Start line: 2010
	/* end block 4 */
	// End Line: 2011

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
 // line 1009, offset 0x80038aa8
	/* begin block 1 */
		// Start line: 1010
		// Start offset: 0x80038AA8
	/* end block 1 */
	// End offset: 0x80038AA8
	// End Line: 1010

	/* begin block 2 */
		// Start line: 2057
	/* end block 2 */
	// End Line: 2058

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
 // line 1065, offset 0x80038ad0
	/* begin block 1 */
		// Start line: 1066
		// Start offset: 0x80038AD0
		// Variables:
	// 		struct _BigFileEntry *entry; // $v0
	/* end block 1 */
	// End offset: 0x80038AF4
	// End Line: 1071

	/* begin block 2 */
		// Start line: 2127
	/* end block 2 */
	// End Line: 2128

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
 // line 1076, offset 0x80038b04
	/* begin block 1 */
		// Start line: 1077
		// Start offset: 0x80038B04
		// Variables:
	// 		struct RECT rect; // stack offset -24
	// 		long *clutAddr; // $s0
	/* end block 1 */
	// End offset: 0x80038B90
	// End Line: 1106

	/* begin block 2 */
		// Start line: 2141
	/* end block 2 */
	// End Line: 2142

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
 // line 1108, offset 0x80038ba4
	/* begin block 1 */
		// Start line: 1109
		// Start offset: 0x80038BA4
		// Variables:
	// 		struct RECT rect; // stack offset -16
	/* end block 1 */
	// End offset: 0x80038BA4
	// End Line: 1109

	/* begin block 2 */
		// Start line: 2213
	/* end block 2 */
	// End Line: 2214

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
 // line 1146, offset 0x80038bec
	/* begin block 1 */
		// Start line: 1147
		// Start offset: 0x80038BEC
		// Variables:
	// 		long *lastMoveDest; // $v1
	// 		long tableSize; // $s3
	// 		struct RedirectList redirectListX; // stack offset -32
	// 		struct RedirectList *redirectList; // $a0
	/* end block 1 */
	// End offset: 0x80038C84
	// End Line: 1167

	/* begin block 2 */
		// Start line: 2271
	/* end block 2 */
	// End Line: 2272

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
 // line 1239, offset 0x80038ca4
	/* begin block 1 */
		// Start line: 2475
	/* end block 1 */
	// End Line: 2476

	/* begin block 2 */
		// Start line: 2399
	/* end block 2 */
	// End Line: 2400

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
 // line 1253, offset 0x80038cec
	/* begin block 1 */
		// Start line: 2427
	/* end block 1 */
	// End Line: 2428

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
 // line 1263, offset 0x80038d28
	/* begin block 1 */
		// Start line: 1264
		// Start offset: 0x80038D28
		// Variables:
	// 		unsigned char cdMode; // stack offset -16
	/* end block 1 */
	// End offset: 0x80038D28
	// End Line: 1264

	/* begin block 2 */
		// Start line: 2451
	/* end block 2 */
	// End Line: 2452

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
// int /*$ra*/ LOAD_ChangeDirectoryByID(int id /*$s1*/)
 // line 1273, offset 0x80038d70
	/* begin block 1 */
		// Start line: 1274
		// Start offset: 0x80038D70

		/* begin block 1.1 */
			// Start line: 1278
			// Start offset: 0x80038D88
			// Variables:
		// 		int i; // $v1

			/* begin block 1.1.1 */
				// Start line: 1285
				// Start offset: 0x80038DA8
				// Variables:
			// 		struct _BigFileDir *dir; // $a0
			/* end block 1.1.1 */
			// End offset: 0x80038DC8
			// End Line: 1291
		/* end block 1.1 */
		// End offset: 0x80038E54
		// End Line: 1309
	/* end block 1 */
	// End offset: 0x80038E58
	// End Line: 1312

	/* begin block 2 */
		// Start line: 2474
	/* end block 2 */
	// End Line: 2475

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
 // line 1319, offset 0x80038e6c
	/* begin block 1 */
		// Start line: 2634
	/* end block 1 */
	// End Line: 2635

	/* begin block 2 */
		// Start line: 2579
	/* end block 2 */
	// End Line: 2580

void LOAD_SetSearchDirectory(long id)

{
  loadStatus.bigFile.searchDirID = id;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ LOAD_GetSearchDirectory()
 // line 1324, offset 0x80038e78
	/* begin block 1 */
		// Start line: 2588
	/* end block 1 */
	// End Line: 2589

	/* begin block 2 */
		// Start line: 2589
	/* end block 2 */
	// End Line: 2590

/* WARNING: Unknown calling convention yet parameter storage is locked */

long LOAD_GetSearchDirectory(void)

{
  return loadStatus.bigFile.searchDirID;
}



// decompiled code
// original method signature: 
// int /*$ra*/ LOAD_ChangeDirectoryFlag()
 // line 1329, offset 0x80038e84
	/* begin block 1 */
		// Start line: 2598
	/* end block 1 */
	// End Line: 2599

	/* begin block 2 */
		// Start line: 2599
	/* end block 2 */
	// End Line: 2600

/* WARNING: Unknown calling convention yet parameter storage is locked */

int LOAD_ChangeDirectoryFlag(void)

{
  return loadStatus.changeDir;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_UpdateBigFilePointers(struct _BigFileDir *oldDir /*$a0*/, struct _BigFileDir *newDir /*$a1*/)
 // line 1334, offset 0x80038e90
	/* begin block 1 */
		// Start line: 2608
	/* end block 1 */
	// End Line: 2609

	/* begin block 2 */
		// Start line: 2609
	/* end block 2 */
	// End Line: 2610

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
 // line 1349, offset 0x80038ec0
	/* begin block 1 */
		// Start line: 2638
	/* end block 1 */
	// End Line: 2639

	/* begin block 2 */
		// Start line: 2644
	/* end block 2 */
	// End Line: 2645

/* WARNING: Unknown calling convention yet parameter storage is locked */

int LOAD_IsFileLoading(void)

{
  return (uint)(loadStatus.currentQueueFile.readStatus != 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ LOAD_StopLoad()
 // line 1391, offset 0x80038ecc
	/* begin block 1 */
		// Start line: 2775
	/* end block 1 */
	// End Line: 2776

	/* begin block 2 */
		// Start line: 2690
	/* end block 2 */
	// End Line: 2691

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





