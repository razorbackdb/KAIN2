#include "THISDUST.H"
#include "LOAD3D.H"

// char @0x800CE4D0, len = 0x00000001
HashExtensions = 0x64;
// _LoadStatus @0x800D0D84, len = 0x00000098
loadStatus =
    {
        // _ReadQueueEntry @0x800D0D84, len = 0x0000002C
        .currentQueueFile =
            {
                // long @0x800D0D84, len = 0x00000004
                .readStartPos = null,
                // long @0x800D0D88, len = 0x00000004
                .readSize = null,
                // long @0x800D0D8C, len = 0x00000004
                .readCurSize = null,
                // void * @0x800D0D90, len = 0x00000004
                .readStartDest = null,
                // void * @0x800D0D94, len = 0x00000004
                .readCurDest = null,
                // long @0x800D0D98, len = 0x00000004
                .readStatus = null,
                // long @0x800D0D9C, len = 0x00000004
                .checksum = null,
                // long @0x800D0DA0, len = 0x00000004
                .checksumType = null,
                // void * @0x800D0DA4, len = 0x00000004
                .retFunc = null,
                // void * @0x800D0DA8, len = 0x00000004
                .retData = null,
                // void * @0x800D0DAC, len = 0x00000004
                .retData2 = null},
        // long @0x800D0DB0, len = 0x00000004
        .state = null,
        // long @0x800D0DB4, len = 0x00000004
        .bytesTransferred = null,
        // long @0x800D0DB8, len = 0x00000004
        .lastCheckPos = null,
        // long @0x800D0DBC, len = 0x00000004
        .cdWaitTime = null,
        // uchar * @0x800D0DC0, len = 0x00000004
        .compSrcAddr = null,
        // uchar * @0x800D0DC4, len = 0x00000004
        .compDstAddr = null,
        // long @0x800D0DC8, len = 0x00000004
        .compControlbits = null,
        // long @0x800D0DCC, len = 0x00000004
        .compControl = null,
        // long @0x800D0DD0, len = 0x00000004
        .compEndBytes = null,
        // long @0x800D0DD4, len = 0x00000004
        .decompressLen = null,
        // long @0x800D0DD8, len = 0x00000004
        .checksum = null,
        // long * @0x800D0DDC, len = 0x00000004
        .checkAddr = null,
        // _BigFile @0x800D0DE0, len = 0x00000024
        .bigFile =
            {
                // long @0x800D0DE0, len = 0x00000004
                .bigfileBaseOffset = null,
                // _BigFileDir * @0x800D0DE4, len = 0x00000004
                .rootDir = null,
                // _BigFileDir * @0x800D0DE8, len = 0x00000004
                .currentDir = null,
                // _BigFileDir * @0x800D0DEC, len = 0x00000004
                .cachedDir = null,
                // long @0x800D0DF0, len = 0x00000004
                .currentDirID = null,
                // long @0x800D0DF4, len = 0x00000004
                .cachedDirID = null,
                // long @0x800D0DF8, len = 0x00000004
                .searchDirID = null,
                // long @0x800D0DFC, len = 0x00000004
                .numSubDirs = null,
                // _BigFileDirEntry * @0x800D0E00, len = 0x00000004
                .subDirList = null},
        // void * @0x800D0E04, len = 0x00000004
        .buffer1 = null,
        // void * @0x800D0E08, len = 0x00000004
        .buffer2 = null,
        // int @0x800D0E0C, len = 0x00000004
        .changeDir = null,
        // long @0x800D0E10, len = 0x00000004
        .endLoadTime = null,
        // long @0x800D0E14, len = 0x00000004
        .currentDirLoading = null,
        // long @0x800D0E18, len = 0x00000004
        .currentSector = null};
// decompiled code
// original method signature:
// void /*$ra*/ LOAD_InitCd()
// line 231, offset 0x80036d44
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
// line 255, offset 0x80036d74
/* begin block 1 */
// Start line: 327
/* end block 1 */
// End Line: 328

/* begin block 2 */
// Start line: 328
/* end block 2 */
// End Line: 329

void LOAD_CdSeekCallback(uchar intr, uchar *result)

{
  if (loadStatus.state == 1)
  {
    loadStatus.state = 2;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_CdDataReady()
// line 267, offset 0x80036d90
/* begin block 1 */
// Start line: 268
// Start offset: 0x80036D90

/* begin block 1.1 */
// Start line: 275
// Start offset: 0x80036DCC
// Variables:
// 		struct _ReadQueueEntry *currentQueueFile; // $s0
// 		long actualReadSize; // $a1

/* begin block 1.1.1 */
// Start line: 292
// Start offset: 0x80036E30
// Variables:
// 		int status; // $s1
/* end block 1.1.1 */
// End offset: 0x80036E9C
// End Line: 324
/* end block 1.1 */
// End offset: 0x80036E9C
// End Line: 325
/* end block 1 */
// End offset: 0x80036E9C
// End Line: 330

/* begin block 2 */
// Start line: 351
/* end block 2 */
// End Line: 352

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_CdDataReady(void)

{
  int iVar1;

  if (loadStatus.state == 3)
  {
    loadStatus.state = 4;
  }
  else
  {
    if (loadStatus.state == 4)
    {
      loadStatus.currentQueueFile.readCurSize =
          loadStatus.currentQueueFile.readCurSize + loadStatus.bytesTransferred;
      if (loadStatus.currentQueueFile.readStatus == 3)
      {
        loadStatus.currentQueueFile.readCurDest =
            (void *)((int)loadStatus.currentQueueFile.readCurDest + loadStatus.bytesTransferred);
        if (loadStatus.currentQueueFile.readCurSize == loadStatus.currentQueueFile.readSize)
        {
          loadStatus.state = 5;
        }
        else
        {
          loadStatus.state = 2;
        }
      }
      else
      {
        if (loadStatus.currentQueueFile.readStatus == 6)
        {
          iVar1 = 2;
          if (loadStatus.currentQueueFile.readCurSize == loadStatus.currentQueueFile.readSize)
          {
            iVar1 = 5;
          }
          if (loadStatus.currentQueueFile.retFunc != (void *)0x0)
          {
            (*(code *)loadStatus.currentQueueFile.retFunc)(loadStatus.currentQueueFile.readCurDest, loadStatus.bytesTransferred,
                                                           (uint)(iVar1 == 5), loadStatus.currentQueueFile.retData,
                                                           loadStatus.currentQueueFile.retData2);
          }
          if (loadStatus.currentQueueFile.readCurDest == loadStatus.buffer1)
          {
            loadStatus.currentQueueFile.readCurDest = loadStatus.buffer2;
            loadStatus.state = iVar1;
          }
          else
          {
            loadStatus.currentQueueFile.readCurDest = loadStatus.buffer1;
            loadStatus.state = iVar1;
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
// line 333, offset 0x80036eb0
/* begin block 1 */
// Start line: 334
// Start offset: 0x80036EB0

/* begin block 1.1 */
// Start line: 344
// Start offset: 0x80036EDC
// Variables:
// 		long crap[3]; // stack offset -40
// 		int bytes; // $s0

/* begin block 1.1.1 */
// Start line: 367
// Start offset: 0x80036F50
// Variables:
// 		struct CdlLOC loc; // stack offset -24
/* end block 1.1.1 */
// End offset: 0x80036F50
// End Line: 370
/* end block 1.1 */
// End offset: 0x80036F50
// End Line: 370
/* end block 1 */
// End offset: 0x80036F88
// End Line: 396

/* begin block 2 */
// Start line: 488
/* end block 2 */
// End Line: 489

void LOAD_CdReadReady(uchar intr, uchar *result)

{
  uint uVar1;
  int iVar2;
  byte abStack40[16];
  char acStack24[8];

  if (loadStatus.state == 2)
  {
    if (intr == '\x01')
    {
      uVar1 = loadStatus.currentQueueFile.readSize - loadStatus.currentQueueFile.readCurSize;
      if (0x7ff < (int)uVar1)
      {
        uVar1 = 0x800;
      }
      loadStatus.state = 4;
      loadStatus.bytesTransferred = uVar1;
      CdGetSector(abStack40, 3);
      iVar2 = CdPosToInt(abStack40);
      if (loadStatus.currentSector == iVar2)
      {
        loadStatus.currentSector = loadStatus.currentSector + 1;
        CdGetSector(loadStatus.currentQueueFile.readCurDest, uVar1 >> 2);
        LOAD_CdDataReady();
      }
      else
      {
        loadStatus.state = (uint)intr;
        CdIntToPos(loadStatus.currentSector, acStack24);
        CdControl(6, acStack24, (undefined *)0x0);
      }
    }
    else
    {
      if (intr == '\x05')
      {
        loadStatus.state = 6;
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_UpdateCheckSum(long bytes /*$a1*/)
// line 398, offset 0x80036f9c
/* begin block 1 */
// Start line: 632
/* end block 1 */
// End Line: 633

/* begin block 2 */
// Start line: 635
/* end block 2 */
// End Line: 636

void LOAD_UpdateCheckSum(long bytes)

{
  bool bVar1;
  int iVar2;
  int iVar3;

  if ((loadStatus.currentQueueFile.checksumType == 1) && (iVar3 = bytes + -4, bytes != 0))
  {
    do
    {
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
// line 413, offset 0x80036fe0
/* begin block 1 */
// Start line: 414
// Start offset: 0x80036FE0
// Variables:
// 		long bytesLoaded; // $a0
// 		long readSoFar; // $v0
// 		long state; // $s0
// 		long lastCheck; // $v1
/* end block 1 */
// End offset: 0x8003707C
// End Line: 509

/* begin block 2 */
// Start line: 665
/* end block 2 */
// End Line: 666

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_DoCDReading(void)

{
  long lVar1;
  int bytes;

  lVar1 = loadStatus.state;
  bytes = loadStatus.currentQueueFile.readCurSize - loadStatus.lastCheckPos;
  loadStatus.lastCheckPos = loadStatus.currentQueueFile.readCurSize;
  if ((bytes != 0) && (loadStatus.currentQueueFile.checksumType != 0))
  {
    LOAD_UpdateCheckSum(bytes);
  }
  if (lVar1 == 5)
  {
    if ((loadStatus.currentQueueFile.checksumType == 0) ||
        (loadStatus.checksum == loadStatus.currentQueueFile.checksum))
    {
      loadStatus.currentQueueFile.readStatus = 0;
      if (loadStatus.currentDirLoading != 0)
      {
        loadStatus.currentDirLoading = 0;
        MEMPACK_SetMemoryDoneStreamed((char *)loadStatus.bigFile.currentDir);
      }
    }
    else
    {
      loadStatus.currentQueueFile.readStatus = 7;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_DoCDBufferedReading()
// line 516, offset 0x8003708c
/* begin block 1 */
// Start line: 879
/* end block 1 */
// End Line: 880

/* begin block 2 */
// Start line: 881
/* end block 2 */
// End Line: 882

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_DoCDBufferedReading(void)

{
  if (loadStatus.state == 5)
  {
    loadStatus.currentQueueFile.readStatus = 0;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_SetupFileToDoCDReading()
// line 527, offset 0x800370a8
/* begin block 1 */
// Start line: 528
// Start offset: 0x800370A8

/* begin block 1.1 */
// Start line: 528
// Start offset: 0x800370A8
// Variables:
// 		struct CdlLOC loc; // stack offset -16
/* end block 1.1 */
// End offset: 0x800370E4
// End Line: 543
/* end block 1 */
// End offset: 0x800370E4
// End Line: 544

/* begin block 2 */
// Start line: 901
/* end block 2 */
// End Line: 902

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_SetupFileToDoCDReading(void)

{
  long lVar1;
  char acStack16[8];

  loadStatus.currentQueueFile.readStatus = 3;
  loadStatus.checksum = 0;
  loadStatus.lastCheckPos = 0;
  loadStatus.state = 1;
  loadStatus.currentQueueFile.readCurDest = loadStatus.currentQueueFile.readStartDest;
  loadStatus.checkAddr = (long *)loadStatus.currentQueueFile.readStartDest;
  lVar1 = loadStatus.currentQueueFile.readStartPos;
  if (loadStatus.currentQueueFile.readStartPos < 0)
  {
    lVar1 = loadStatus.currentQueueFile.readStartPos + 0x7ff;
  }
  loadStatus.currentSector = loadStatus.bigFile.bigfileBaseOffset + (lVar1 >> 0xb);
  CdIntToPos(loadStatus.currentSector, acStack16);
  CdControl(6, acStack16, (undefined *)0x0);
  loadStatus.cdWaitTime = TIMER_GetTimeMS();
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_SetupFileToDoBufferedCDReading()
// line 602, offset 0x80037124
/* begin block 1 */
// Start line: 603
// Start offset: 0x80037124

/* begin block 1.1 */
// Start line: 603
// Start offset: 0x80037124
// Variables:
// 		struct CdlLOC loc; // stack offset -16
/* end block 1.1 */
// End offset: 0x80037158
// End Line: 619
/* end block 1 */
// End offset: 0x80037158
// End Line: 620

/* begin block 2 */
// Start line: 1093
/* end block 2 */
// End Line: 1094

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_SetupFileToDoBufferedCDReading(void)

{
  long lVar1;
  char acStack16[8];

  loadStatus.currentQueueFile.readStatus = 6;
  loadStatus.checksum = 0;
  loadStatus.state = 1;
  loadStatus.checkAddr = (long *)loadStatus.currentQueueFile.readStartDest;
  lVar1 = loadStatus.currentQueueFile.readStartPos;
  if (loadStatus.currentQueueFile.readStartPos < 0)
  {
    lVar1 = loadStatus.currentQueueFile.readStartPos + 0x7ff;
  }
  loadStatus.currentSector = loadStatus.bigFile.bigfileBaseOffset + (lVar1 >> 0xb);
  CdIntToPos(loadStatus.currentSector, acStack16);
  CdControl(6, acStack16, (undefined *)0x0);
  loadStatus.cdWaitTime = TIMER_GetTimeMS();
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_ProcessReadQueue()
// line 627, offset 0x80037198
/* begin block 1 */
// Start line: 628
// Start offset: 0x80037198

/* begin block 1.1 */
// Start line: 668
// Start offset: 0x80037248
// Variables:
// 		long cdWaitTimeDiff; // $v0

/* begin block 1.1.1 */
// Start line: 674
// Start offset: 0x80037298
// Variables:
// 		struct CdlLOC loc; // stack offset -16
/* end block 1.1.1 */
// End offset: 0x80037298
// End Line: 675
/* end block 1.1 */
// End offset: 0x80037304
// End Line: 699
/* end block 1 */
// End offset: 0x80037304
// End Line: 701

/* begin block 2 */
// Start line: 1179
/* end block 2 */
// End Line: 1180

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_ProcessReadQueue(void)

{
  ulong uVar1;
  int iVar2;
  char acStack16[8];

  if (loadStatus.currentQueueFile.readStatus == 3)
  {
    LOAD_DoCDReading();
  }
  else
  {
    if (loadStatus.currentQueueFile.readStatus < 4)
    {
      if (loadStatus.currentQueueFile.readStatus == 1)
      {
        LOAD_SetupFileToDoCDReading();
      }
    }
    else
    {
      if (loadStatus.currentQueueFile.readStatus == 5)
      {
        LOAD_SetupFileToDoBufferedCDReading();
      }
      else
      {
        if (loadStatus.currentQueueFile.readStatus == 6)
        {
          LOAD_DoCDBufferedReading();
        }
      }
    }
  }
  if (loadStatus.currentQueueFile.readStatus == 7)
  {
    loadStatus.currentQueueFile.readStatus = 1;
  }
  else
  {
    if ((loadStatus.cdWaitTime != 0) &&
        ((uVar1 = TIMER_GetTimeMS(), 0x41a0 < (int)(uVar1 - loadStatus.cdWaitTime) ||
                                         (loadStatus.state == 6))))
    {
      if ((loadStatus.currentQueueFile.readStatus == 3) ||
          (loadStatus.currentQueueFile.readStatus == 6))
      {
        loadStatus.state = 0;
        CdReset(0);
        LOAD_InitCdStreamMode();
        loadStatus.state = 1;
        CdIntToPos(loadStatus.currentSector, acStack16);
        CdControl(6, acStack16, (undefined *)0x0);
        loadStatus.cdWaitTime = TIMER_GetTimeMS();
      }
      else
      {
        iVar2 = VOICEXA_IsPlaying();
        if (iVar2 == 0)
        {
          CdControlF(9, (undefined *)0x0);
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
// line 705, offset 0x80037314
/* begin block 1 */
// Start line: 706
// Start offset: 0x80037314
// Variables:
// 		struct CdlFILE fp; // stack offset -40
// 		int i; // $s0
// 		char *readBuffer; // $s0
/* end block 1 */
// End offset: 0x800373DC
// End Line: 750

/* begin block 2 */
// Start line: 1336
/* end block 2 */
// End Line: 1337

char *LOAD_ReadFileFromCD(char *filename, int memType)

{
  undefined4 *puVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uStack40;
  ulong local_24;

  iVar4 = 0;
  do
  {
    puVar1 = CdSearchFile(&uStack40, filename);
    if (puVar1 != (undefined4 *)0x0)
      break;
    CdReset(0);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  pcVar3 = (char *)0x0;
  if (iVar4 != 10)
  {
    pcVar2 = MEMPACK_Malloc(local_24, (uchar)memType);
    pcVar3 = (char *)0x0;
    if (pcVar2 != (char *)0x0)
    {
      iVar4 = CdPosToInt((byte *)&uStack40);
      loadStatus.currentQueueFile.readCurSize = 0;
      loadStatus.currentQueueFile.readStatus = 1;
      loadStatus.currentQueueFile.checksumType = 0;
      loadStatus.currentQueueFile.checksum = 0;
      loadStatus.currentQueueFile.readStartPos =
          (iVar4 - loadStatus.bigFile.bigfileBaseOffset) * 0x800;
      loadStatus.currentQueueFile.readSize = local_24;
      loadStatus.currentQueueFile.readStartDest = pcVar2;
      do
      {
        LOAD_ProcessReadQueue();
        iVar4 = LOAD_IsFileLoading();
      } while (iVar4 != 0);
      CdControlF(9, (undefined *)0x0);
      pcVar3 = pcVar2;
    }
  }
  return pcVar3;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_CdReadFromBigFile(long fileOffset /*$a0*/, unsigned long *loadAddr /*$a1*/, long bytes /*$a2*/, long chksumLevel /*$a3*/, long checksum /*stack 16*/)
// line 752, offset 0x800373f4
/* begin block 1 */
// Start line: 1449
/* end block 1 */
// End Line: 1450

void LOAD_CdReadFromBigFile(long fileOffset, ulong *loadAddr, long bytes, long chksumLevel, long checksum)

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
// line 765, offset 0x80037420
/* begin block 1 */
// Start line: 766
// Start offset: 0x80037420
// Variables:
// 		struct _BigFileDir *dir; // $s2
// 		long sizeOfDir; // $s1
/* end block 1 */
// End offset: 0x80037420
// End Line: 766

/* begin block 2 */
// Start line: 1479
/* end block 2 */
// End Line: 1480

_BigFileDir *LOAD_ReadDirectory(_BigFileDirEntry *dirEntry)

{
  _BigFileDir *loadAddr;
  ulong allocSize;

  allocSize = (int)dirEntry->numFiles * 0x10 + 4;
  loadAddr = (_BigFileDir *)MEMPACK_Malloc(allocSize, ',');
  LOAD_CdReadFromBigFile(dirEntry->subDirOffset, (ulong *)loadAddr, allocSize, 0, 0);
  return loadAddr;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_InitCdLoader(char *bigFileName /*$s0*/, char *voiceFileName /*$a1*/)
// line 828, offset 0x80037488
/* begin block 1 */
// Start line: 829
// Start offset: 0x80037488
// Variables:
// 		struct CdlFILE fp; // stack offset -40
// 		long i; // $s1

/* begin block 1.1 */
// Start line: 896
// Start offset: 0x80037538
// Variables:
// 		char *ptr; // $s0
/* end block 1.1 */
// End offset: 0x800375A0
// End Line: 920
/* end block 1 */
// End offset: 0x800375C8
// End Line: 932

/* begin block 2 */
// Start line: 1607
/* end block 2 */
// End Line: 1608

void LOAD_InitCdLoader(char *bigFileName, char *voiceFileName)

{
  undefined4 *puVar1;
  ulong *loadAddr;
  int iVar2;
  ulong allocSize;
  undefined4 auStack40[6];

  iVar2 = 0;
  loadStatus.state = 0;
  do
  {
    puVar1 = CdSearchFile(auStack40, bigFileName);
    if (puVar1 != (undefined4 *)0x0)
      break;
    CdReset(0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  if (iVar2 != 10)
  {
    LOAD_InitCdStreamMode();
    loadStatus.bigFile.bigfileBaseOffset = CdPosToInt((byte *)auStack40);
    loadStatus.cdWaitTime = 0;
    loadStatus.currentQueueFile.readStatus = 0;
    loadStatus.bigFile.currentDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.currentDirID = 0;
    loadStatus.bigFile.cachedDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.cachedDirID = 0;
    loadStatus.bigFile.searchDirID = 0;
    LOAD_CdReadFromBigFile(0, (ulong *)&loadStatus.bigFile.numSubDirs, 4, 0, 0);
    do
    {
      LOAD_ProcessReadQueue();
      iVar2 = LOAD_IsFileLoading();
    } while (iVar2 != 0);
    CdControlF(9, (undefined *)0x0);
    allocSize = loadStatus.bigFile.numSubDirs * 8 + 4;
    loadAddr = (ulong *)MEMPACK_Malloc(allocSize, '\b');
    CdSync(0, (undefined *)0x0);
    LOAD_CdReadFromBigFile(0, loadAddr, allocSize, 0, 0);
    loadStatus.bigFile.subDirList = (_BigFileDirEntry *)(loadAddr + 1);
    do
    {
      LOAD_ProcessReadQueue();
      iVar2 = LOAD_IsFileLoading();
    } while (iVar2 != 0);
    loadStatus.bigFile.rootDir = LOAD_ReadDirectory(loadStatus.bigFile.subDirList);
    do
    {
      LOAD_ProcessReadQueue();
      iVar2 = LOAD_IsFileLoading();
    } while (iVar2 != 0);
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ LOAD_SetupFileInfo(struct _NonBlockLoadEntry *loadEntry /*$s0*/)
// line 934, offset 0x800375dc
/* begin block 1 */
// Start line: 935
// Start offset: 0x800375DC
// Variables:
// 		struct _BigFileEntry *fileInfo; // $v1
/* end block 1 */
// End offset: 0x80037654
// End Line: 958

/* begin block 2 */
// Start line: 1869
/* end block 2 */
// End Line: 1870

int LOAD_SetupFileInfo(_NonBlockLoadEntry *loadEntry)

{
  _BigFileEntry *p_Var1;
  int iVar2;

  p_Var1 = LOAD_GetBigFileEntryByHash(loadEntry->fileHash);
  if (p_Var1 == (_BigFileEntry *)0x0)
  {
    iVar2 = 0;
    if (loadEntry->dirHash == loadStatus.bigFile.currentDirID)
    {
      DEBUG_FatalError(s_CD_ERROR__File__x_does_not_exist_800ce4ac);
      iVar2 = 0;
    }
  }
  else
  {
    loadEntry->filePos = p_Var1->filePos;
    loadEntry->loadSize = p_Var1->fileLen;
    iVar2 = 1;
    loadEntry->checksum = p_Var1->checkSumFull;
  }
  return iVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_CD_ReadPartOfFile(struct _NonBlockLoadEntry *loadEntry /*$s0*/)
// line 963, offset 0x80037664
/* begin block 1 */
// Start line: 964
// Start offset: 0x80037664
// Variables:
// 		struct _ReadQueueEntry *currentQueueReq; // $v1
/* end block 1 */
// End offset: 0x800376F4
// End Line: 989

/* begin block 2 */
// Start line: 1928
/* end block 2 */
// End Line: 1929

void LOAD_CD_ReadPartOfFile(_NonBlockLoadEntry *loadEntry)

{
  int iVar1;

  iVar1 = LOAD_SetupFileInfo(loadEntry);
  if (iVar1 != 0)
  {
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
// line 1002, offset 0x80037704
/* begin block 1 */
// Start line: 1003
// Start offset: 0x80037704
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
// End offset: 0x80037814
// End Line: 1046

/* begin block 2 */
// Start line: 2014
/* end block 2 */
// End Line: 2015

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
  pcVar2 = strchr(string, 0x2e);
  uVar9 = 0;
  if (pcVar2 != (char *)0x0)
  {
    uVar4 = 0;
    s2 = &HashExtensions;
    do
    {
      iVar3 = strcmpi(pcVar2 + 1, s2);
      uVar9 = uVar4;
      if (iVar3 == 0)
        break;
      uVar4 = uVar4 + 1;
      s2 = s2 + 4;
      uVar9 = 0;
    } while ((int)uVar4 < 7);
    if ((int)uVar4 < 7)
    {
      iVar5 = sVar1 - 5;
    }
  }
  uVar4 = 0;
  while (-1 < iVar5)
  {
    uVar4 = (uint)(byte)string[iVar5];
    if (string[iVar5] != 0x5c)
    {
      if (uVar4 - 0x61 < 0x1a)
      {
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
// line 1049, offset 0x80037858
/* begin block 1 */
// Start line: 1051
// Start offset: 0x80037858
// Variables:
// 		int val; // $v1
// 		int last; // $t0
// 		int hash; // $a2
// 		int num; // $a3
// 		int flag; // $t1
// 		char *c; // $a0
/* end block 1 */
// End offset: 0x800378EC
// End Line: 1085

/* begin block 2 */
// Start line: 2121
/* end block 2 */
// End Line: 2122

/* begin block 3 */
// Start line: 2122
/* end block 3 */
// End Line: 2123

/* begin block 4 */
// Start line: 2123
/* end block 4 */
// End Line: 2124

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
  while (bVar1 != 0)
  {
    uVar5 = (uint)(byte)*name;
    if (uVar5 - 0x30 < 10)
    {
      iVar8 = iVar8 * 10 + -0x30 + uVar5;
      uVar6 = uVar3;
    }
    else
    {
      uVar6 = uVar5 - 0x61;
      if (uVar5 - 0x41 < 0x1a)
      {
        uVar6 = uVar5 - 0x41;
      }
      if (bVar2)
      {
        iVar4 = (uVar6 - uVar3) * 0x20;
      }
      else
      {
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
// line 1090, offset 0x800378fc
/* begin block 1 */
// Start line: 1092
// Start offset: 0x800378FC
// Variables:
// 		int i; // $a1
// 		struct _BigFileEntry *entry; // $v1
/* end block 1 */
// End offset: 0x8003797C
// End Line: 1111

/* begin block 2 */
// Start line: 2226
/* end block 2 */
// End Line: 2227

/* begin block 3 */
// Start line: 2227
/* end block 3 */
// End Line: 2228

/* begin block 4 */
// Start line: 2230
/* end block 4 */
// End Line: 2231

_BigFileEntry *LOAD_GetBigFileEntryByHash(long hash)

{
  _BigFileEntry *p_Var1;
  int iVar2;

  if ((loadStatus.bigFile.currentDir != (_BigFileDir *)0x0) && (loadStatus.currentDirLoading == 0))
  {
    iVar2 = (loadStatus.bigFile.currentDir)->numFiles;
    p_Var1 = (_BigFileEntry *)(loadStatus.bigFile.currentDir + 1);
    while (iVar2 != 0)
    {
      iVar2 = iVar2 + -1;
      if (p_Var1->fileHash == hash)
      {
        return p_Var1;
      }
      p_Var1 = p_Var1 + 1;
    }
  }
  iVar2 = (loadStatus.bigFile.rootDir)->numFiles;
  p_Var1 = (_BigFileEntry *)(loadStatus.bigFile.rootDir + 1);
  while (true)
  {
    if (iVar2 == 0)
    {
      return (_BigFileEntry *)0x0;
    }
    iVar2 = iVar2 + -1;
    if (p_Var1->fileHash == hash)
      break;
    p_Var1 = p_Var1 + 1;
  }
  return p_Var1;
}

// decompiled code
// original method signature:
// struct _BigFileEntry * /*$ra*/ LOAD_GetBigFileEntry(char *fileName /*$a0*/)
// line 1113, offset 0x80037984
/* begin block 1 */
// Start line: 1114
// Start offset: 0x80037984
/* end block 1 */
// End offset: 0x80037984
// End Line: 1114

/* begin block 2 */
// Start line: 2277
/* end block 2 */
// End Line: 2278

_BigFileEntry *LOAD_GetBigFileEntry(char *fileName)

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
// line 1169, offset 0x800379ac
/* begin block 1 */
// Start line: 1170
// Start offset: 0x800379AC
// Variables:
// 		struct _BigFileEntry *entry; // $v0
/* end block 1 */
// End offset: 0x800379D0
// End Line: 1175

/* begin block 2 */
// Start line: 2338
/* end block 2 */
// End Line: 2339

long LOAD_DoesFileExist(char *fileName)

{
  _BigFileEntry *p_Var1;
  uint uVar2;

  p_Var1 = LOAD_GetBigFileEntry(fileName);
  uVar2 = 0;
  if (p_Var1 != (_BigFileEntry *)0x0)
  {
    uVar2 = (uint)(p_Var1->fileLen != 0);
  }
  return uVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_NonBlockingReadFile(struct _NonBlockLoadEntry *loadEntry /*$s0*/)
// line 1181, offset 0x800379e0
/* begin block 1 */
// Start line: 2363
/* end block 1 */
// End Line: 2364

void LOAD_NonBlockingReadFile(_NonBlockLoadEntry *loadEntry)

{
  int iVar1;
  long *plVar2;

  iVar1 = LOAD_SetupFileInfo(loadEntry);
  if (iVar1 == 0)
  {
    loadStatus.changeDir = 1;
    return;
  }
  if (loadEntry->loadAddr == (long *)0x0)
  {
    if (loadEntry->mallocFailOk == 0)
    {
      plVar2 = (long *)MEMPACK_Malloc(loadEntry->loadSize, *(uchar *)&loadEntry->memType);
      loadEntry->loadAddr = plVar2;
    }
    else
    {
      plVar2 = (long *)MEMPACK_MallocFailOk(loadEntry->loadSize, *(uchar *)&loadEntry->memType);
      loadEntry->loadAddr = plVar2;
    }
    if (loadEntry->loadAddr == (long *)0x0)
    {
      loadStatus.changeDir = 0;
      return;
    }
  }
  LOAD_CdReadFromBigFile(loadEntry->filePos, (ulong *)loadEntry->loadAddr, loadEntry->loadSize,
                         loadEntry->checksumType, loadEntry->checksum);
  loadStatus.changeDir = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_LoadTIM(long *addr /*$a1*/, long x_pos /*$t0*/, long y_pos /*$a2*/, long clut_x /*$s1*/, long clut_y /*stack 16*/)
// line 1226, offset 0x80037a9c
/* begin block 1 */
// Start line: 1227
// Start offset: 0x80037A9C
// Variables:
// 		struct RECT rect; // stack offset -24
// 		long *clutAddr; // $s0
/* end block 1 */
// End offset: 0x80037B28
// End Line: 1256

/* begin block 2 */
// Start line: 2453
/* end block 2 */
// End Line: 2454

void LOAD_LoadTIM(long *addr, long x_pos, long y_pos, long clut_x, long clut_y)

{
  long *plVar1;
  long *plVar2;
  short local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;

  plVar1 = addr + 2;
  plVar2 = (long *)0x0;
  if (addr[1] == 8)
  {
    plVar2 = addr + 5;
    plVar1 = addr + 0xd;
  }
  local_18 = (short)x_pos;
  local_16 = (undefined2)y_pos;
  local_14 = *(undefined2 *)(plVar1 + 2);
  local_12 = *(undefined2 *)((int)plVar1 + 10);
  LoadImage(&local_18, plVar1 + 3);
  if (plVar2 != (long *)0x0)
  {
    local_18 = (short)clut_x;
    local_16 = (undefined2)clut_y;
    local_14 = 0x10;
    local_12 = 1;
    DrawSync(0);
    LoadImage(&local_18, plVar2);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_LoadTIM2(long *addr /*$a1*/, long x_pos /*$a1*/, long y_pos /*$a2*/, long width /*$a3*/, long height /*stack 16*/)
// line 1258, offset 0x80037b3c
/* begin block 1 */
// Start line: 1259
// Start offset: 0x80037B3C
// Variables:
// 		struct RECT rect; // stack offset -16
/* end block 1 */
// End offset: 0x80037B3C
// End Line: 1259

/* begin block 2 */
// Start line: 2525
/* end block 2 */
// End Line: 2526

void LOAD_LoadTIM2(long *addr, long x_pos, long y_pos, long width, long height)

{
  short local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;

  local_10 = (short)x_pos;
  local_e = (undefined2)y_pos;
  local_c = *(undefined2 *)(addr + 4);
  local_a = *(undefined2 *)((int)addr + 0x12);
  LoadImage(&local_10, addr + 5);
  DrawSync(0);
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ LOAD_RelocBinaryData(long *data /*$s0*/, long fileSize /*$s1*/)
// line 1296, offset 0x80037b84
/* begin block 1 */
// Start line: 1297
// Start offset: 0x80037B84
// Variables:
// 		long *lastMoveDest; // $v1
// 		long tableSize; // $s3
// 		struct RedirectList redirectListX; // stack offset -32
// 		struct RedirectList *redirectList; // $a0
/* end block 1 */
// End offset: 0x80037C1C
// End Line: 1317

/* begin block 2 */
// Start line: 2592
/* end block 2 */
// End Line: 2593

long LOAD_RelocBinaryData(long *data, long fileSize)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  RedirectList local_20;

  local_20.data = data + 1;
  local_20.numPointers = *data;
  iVar1 = local_20.numPointers + 0x200;
  if (iVar1 < 0)
  {
    iVar1 = local_20.numPointers + 0x3ff;
  }
  iVar1 = iVar1 >> 9;
  RESOLVE_Pointers(&local_20, data + iVar1 * 0x200, data);
  plVar3 = data + (fileSize + 3 >> 2) + iVar1 * -0x200;
  if (data < plVar3)
  {
    plVar2 = data + iVar1 * 0x200;
    do
    {
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
// line 1389, offset 0x80037c3c
/* begin block 1 */
// Start line: 2778
/* end block 1 */
// End Line: 2779

/* begin block 2 */
// Start line: 2711
/* end block 2 */
// End Line: 2712

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_CleanUpBuffers(void)

{
  if (loadStatus.buffer1 != (void *)0x0)
  {
    MEMPACK_Free((char *)loadStatus.buffer1);
    loadStatus.buffer1 = (void *)0x0;
  }
  if (loadStatus.buffer2 != (void *)0x0)
  {
    MEMPACK_Free((char *)loadStatus.buffer2);
    loadStatus.buffer2 = (void *)0x0;
  }
  return;
}

// decompiled code
// original method signature:
// void * /*$ra*/ LOAD_InitBuffers()
// line 1403, offset 0x80037c84
/* begin block 1 */
// Start line: 2739
/* end block 1 */
// End Line: 2740

/* WARNING: Unknown calling convention yet parameter storage is locked */

void *LOAD_InitBuffers(void)

{
  loadStatus.buffer1 = MEMPACK_MallocFailOk(0x800, '#');
  if ((char *)loadStatus.buffer1 != (char *)0x0)
  {
    loadStatus.buffer2 = MEMPACK_MallocFailOk(0x800, '#');
    if ((char *)loadStatus.buffer2 == (char *)0x0)
    {
      LOAD_CleanUpBuffers();
    }
  }
  return loadStatus.buffer1;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_InitCdStreamMode()
// line 1418, offset 0x80037cd4
/* begin block 1 */
// Start line: 1419
// Start offset: 0x80037CD4
// Variables:
// 		unsigned char cdMode; // stack offset -16
/* end block 1 */
// End offset: 0x80037CD4
// End Line: 1419

/* begin block 2 */
// Start line: 2772
/* end block 2 */
// End Line: 2773

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_InitCdStreamMode(void)

{
  undefined local_10[8];

  local_10[0] = 0xa0;
  CdReadyCallback(LOAD_CdReadReady);
  CdSyncCallback(LOAD_CdSeekCallback);
  CdControl(0xe, local_10, (undefined *)0x0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_DumpCurrentDir()
// line 1428, offset 0x80037d1c
/* begin block 1 */
// Start line: 2795
/* end block 1 */
// End Line: 2796

/* begin block 2 */
// Start line: 2796
/* end block 2 */
// End Line: 2797

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_DumpCurrentDir(void)

{
  if (loadStatus.bigFile.currentDir != (_BigFileDir *)0x0)
  {
    MEMPACK_Free((char *)loadStatus.bigFile.currentDir);
    loadStatus.bigFile.currentDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.currentDirID = 0;
  }
  if (loadStatus.bigFile.cachedDir != (_BigFileDir *)0x0)
  {
    MEMPACK_Free((char *)loadStatus.bigFile.cachedDir);
    loadStatus.bigFile.cachedDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.cachedDirID = 0;
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ LOAD_ChangeDirectoryByID(int id /*$s1*/)
// line 1444, offset 0x80037d6c
/* begin block 1 */
// Start line: 1445
// Start offset: 0x80037D6C

/* begin block 1.1 */
// Start line: 1449
// Start offset: 0x80037D84
// Variables:
// 		int i; // $v1

/* begin block 1.1.1 */
// Start line: 1456
// Start offset: 0x80037DA4
// Variables:
// 		struct _BigFileDir *dir; // $a0
/* end block 1.1.1 */
// End offset: 0x80037DC4
// End Line: 1462
/* end block 1.1 */
// End offset: 0x80037E5C
// End Line: 1481
/* end block 1 */
// End offset: 0x80037E60
// End Line: 1484

/* begin block 2 */
// Start line: 2828
/* end block 2 */
// End Line: 2829

int LOAD_ChangeDirectoryByID(int id)

{
  _BigFileDir *p_Var1;
  long lVar2;
  int iVar3;
  int iVar4;

  lVar2 = loadStatus.bigFile.currentDirID;
  p_Var1 = loadStatus.bigFile.currentDir;
  if (id != 0)
  {
    if (loadStatus.bigFile.currentDirID == id)
    {
      return 1;
    }
    if (loadStatus.bigFile.cachedDirID == id)
    {
      loadStatus.bigFile.currentDir = loadStatus.bigFile.cachedDir;
      loadStatus.bigFile.cachedDir = p_Var1;
      loadStatus.bigFile.currentDirID = id;
      loadStatus.bigFile.cachedDirID = lVar2;
      return 1;
    }
    iVar3 = 0;
    if (0 < loadStatus.bigFile.numSubDirs)
    {
      do
      {
        iVar4 = iVar3 + 1;
        if (id == (int)loadStatus.bigFile.subDirList[iVar3].streamUnitID)
        {
          if (loadStatus.bigFile.cachedDir != (_BigFileDir *)0x0)
          {
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
// line 1491, offset 0x80037e74
/* begin block 1 */
// Start line: 2982
/* end block 1 */
// End Line: 2983

/* begin block 2 */
// Start line: 2937
/* end block 2 */
// End Line: 2938

void LOAD_SetSearchDirectory(long id)

{
  loadStatus.bigFile.searchDirID = id;
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ LOAD_GetSearchDirectory()
// line 1496, offset 0x80037e80
/* begin block 1 */
// Start line: 2946
/* end block 1 */
// End Line: 2947

/* begin block 2 */
// Start line: 2947
/* end block 2 */
// End Line: 2948

/* WARNING: Unknown calling convention yet parameter storage is locked */

long LOAD_GetSearchDirectory(void)

{
  return loadStatus.bigFile.searchDirID;
}

// decompiled code
// original method signature:
// int /*$ra*/ LOAD_ChangeDirectoryFlag()
// line 1501, offset 0x80037e8c
/* begin block 1 */
// Start line: 2956
/* end block 1 */
// End Line: 2957

/* begin block 2 */
// Start line: 2957
/* end block 2 */
// End Line: 2958

/* WARNING: Unknown calling convention yet parameter storage is locked */

int LOAD_ChangeDirectoryFlag(void)

{
  return loadStatus.changeDir;
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_UpdateBigFilePointers(struct _BigFileDir *oldDir /*$a0*/, struct _BigFileDir *newDir /*$a1*/)
// line 1506, offset 0x80037e98
/* begin block 1 */
// Start line: 2966
/* end block 1 */
// End Line: 2967

/* begin block 2 */
// Start line: 2967
/* end block 2 */
// End Line: 2968

void LOAD_UpdateBigFilePointers(_BigFileDir *oldDir, _BigFileDir *newDir)

{
  if (loadStatus.bigFile.currentDir == oldDir)
  {
    loadStatus.bigFile.currentDir = newDir;
  }
  if (loadStatus.bigFile.cachedDir == oldDir)
  {
    loadStatus.bigFile.cachedDir = newDir;
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ LOAD_IsFileLoading()
// line 1521, offset 0x80037ec8
/* begin block 1 */
// Start line: 2996
/* end block 1 */
// End Line: 2997

/* begin block 2 */
// Start line: 3002
/* end block 2 */
// End Line: 3003

/* WARNING: Unknown calling convention yet parameter storage is locked */

int LOAD_IsFileLoading(void)

{
  return (uint)(loadStatus.currentQueueFile.readStatus != 0);
}

// decompiled code
// original method signature:
// void /*$ra*/ LOAD_StopLoad()
// line 1563, offset 0x80037ed4
/* begin block 1 */
// Start line: 3126
/* end block 1 */
// End Line: 3127

/* begin block 2 */
// Start line: 3048
/* end block 2 */
// End Line: 3049

/* WARNING: Unknown calling convention yet parameter storage is locked */

void LOAD_StopLoad(void)

{
  if (loadStatus.currentDirLoading != 0)
  {
    loadStatus.currentDirLoading = 0;
  }
  loadStatus.currentQueueFile.readStatus = 0;
  loadStatus.state = 5;
  return;
}
