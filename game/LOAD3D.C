#include "THISDUST.H"
#include "LOAD3D.H"

void LOAD_InitCdStreamMode(void)

{
  CdInit();
  G2Anim_SetCallback();
  CdSetDebug(0);
  return;
}

void LOAD_CdSeekCallback(u_char intr, u_char *result)

{
  u_int uVar1;

  if (loadStatus.state == 1)
  {
    loadStatus.state = 2;
    uVar1 = GetRCnt(0xf2000000);
    crap1 = uVar1 & 0xffff | gameTimer << 0x10;
  }
  return;
}

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
                                                           (u_int)(iVar1 == 5), loadStatus.currentQueueFile.retData,
                                                           loadStatus.currentQueueFile.retData2);
          }
          loadStatus.state = iVar1;
          if (loadStatus.currentQueueFile.readCurDest == loadStatus.buffer1)
          {
            loadStatus.currentQueueFile.readCurDest = loadStatus.buffer2;
          }
          else
          {
            loadStatus.currentQueueFile.readCurDest = loadStatus.buffer1;
          }
        }
      }
    }
  }
  return;
}

void LOAD_CdReadReady(u_char intr, u_char *result)

{
  u_int uVar1;
  int iVar2;
  byte abStack40[16];
  byte abStack24[8];

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
      CdGetSector2((dword)abStack40, 3);
      iVar2 = CdPosToInt(abStack40);
      if (loadStatus.currentSector == iVar2)
      {
        loadStatus.currentSector = loadStatus.currentSector + 1;
        CdGetSector2((dword)loadStatus.currentQueueFile.readCurDest, uVar1 >> 2);
        LOAD_CdDataReady();
      }
      else
      {
        loadStatus.state = (u_int)intr;
        CdIntToPos(loadStatus.currentSector, (char *)abStack24);
        CdControlF(6, abStack24, (undefined *)0x0);
      }
    }
    else
    {
      if (intr == '\x05')
      {
        loadStatus.state = 6;
        loadStatus.currentQueueFile.readStatus = 4;
      }
      else
      {
        printf("something %x\n");
      }
    }
  }
  if (crap1 != 0)
  {
    loadStatus.seekTime = TIMER_TimeDiff(crap1);
    crap1 = 0;
  }
  loadStatus.sectorTime = TIMER_TimeDiff(crap_35);
  uVar1 = GetRCnt(0xf2000000);
  crap_35 = uVar1 & 0xffff | gameTimer << 0x10;
  return;
}

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

void LOAD_DoCDReading(void)

{
  if (loadStatus.state == 5)
  {
    loadStatus.currentQueueFile.readStatus = 0;
  }
  return;
}

void LOAD_SetupFileToDoBufferedCDReading(void)

{
  long lVar1;
  byte abStack16[8];

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
  CdIntToPos(loadStatus.currentSector, (char *)abStack16);
  CdControlF(6, abStack16, (undefined *)0x0);
  loadStatus.cdWaitTime = TIMER_GetTimeMS();
  return;
}

void LOAD_DoCDBufferedReading(void)

{
  long lVar1;
  byte abStack16[8];

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
  CdIntToPos(loadStatus.currentSector, (char *)abStack16);
  CdControlF(6, abStack16, (undefined *)0x0);
  loadStatus.cdWaitTime = TIMER_GetTimeMS();
  return;
}

void LOAD_ProcessReadQueue(void)

{
  u_long uVar1;
  int iVar2;
  byte abStack16[8];

  if (gameTrackerX.debugFlags < 0)
  {
    FONT_Print("CD St %d LS %d sk %d tm %d rd %d cs %d\n");
  }
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
        LOAD_SetupFileToDoBufferedCDReading();
      }
    }
    else
    {
      if (loadStatus.currentQueueFile.readStatus == 5)
      {
        LOAD_DoCDBufferedReading();
      }
      else
      {
        if (loadStatus.currentQueueFile.readStatus == 6)
        {
          LOAD_DoCDReading();
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
        (uVar1 = TIMER_GetTimeMS(), 0x20d0 < (int)(uVar1 - loadStatus.cdWaitTime)))
    {
      if ((loadStatus.currentQueueFile.readStatus == 3) ||
          (loadStatus.currentQueueFile.readStatus == 6))
      {
        loadStatus.state = 0;
        CdReset(0);
        LOAD_InitCdStreamMode();
        loadStatus.state = 1;
        CdIntToPos(loadStatus.currentSector, (char *)abStack16);
        CdControlF(6, abStack16, (undefined *)0x0);
        loadStatus.cdWaitTime = TIMER_GetTimeMS();
      }
      else
      {
        iVar2 = VOICEXA_IsPlaying();
        if (iVar2 == 0)
        {
          CdControl(9, (byte *)0x0);
        }
        loadStatus.cdWaitTime = 0;
      }
    }
  }
  return;
}

char *LOAD_ReadFile(char *filename, int memType)

{
  u_char *puVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  u_char uStack40;
  u_long local_24;

  iVar4 = 0;
  do
  {
    puVar1 = CdSearchFile(&uStack40, filename);
    if (puVar1 != (u_char *)0x0)
      break;
    CdReset(0);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  pcVar3 = (char *)0x0;
  if (iVar4 != 10)
  {
    pcVar2 = MEMPACK_Malloc(local_24, (u_char)memType);
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
        iVar4 = LOAD_NonBlockingFileLoad();
      } while (iVar4 != 0);
      CdControl(9, (byte *)0x0);
      pcVar3 = pcVar2;
    }
  }
  return pcVar3;
}

void LOAD_CdReadFromBigFile(long fileOffset, u_long *loadAddr, long bytes, long chksumLevel, long checksum)

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

_BigFileDir *LOAD_ChangeDirectoryFlag(_BigFileDirEntry *dirEntry)

{
  _BigFileDir *loadAddr;
  u_long allocSize;

  allocSize = (int)dirEntry->numFiles * 0x10 + 4;
  loadAddr = (_BigFileDir *)MEMPACK_Malloc(allocSize, ',');
  LOAD_CdReadFromBigFile(dirEntry->subDirOffset, (u_long *)loadAddr, allocSize, 0, 0);
  return loadAddr;
}

void LOAD_InitCdLoader(char *bigFileName, char *voiceFileName)

{
  u_char *puVar1;
  u_long *loadAddr;
  int iVar2;
  u_long allocSize;
  u_char auStack40[6];

  iVar2 = 0;
  loadStatus.state = 0;
  do
  {
    puVar1 = CdSearchFile(auStack40, bigFileName);
    if (puVar1 != (u_char *)0x0)
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
    LOAD_CdReadFromBigFile(0, (u_long *)&loadStatus.bigFile.numSubDirs, 4, 0, 0);
    do
    {
      LOAD_ProcessReadQueue();
      iVar2 = LOAD_NonBlockingFileLoad();
    } while (iVar2 != 0);
    CdControl(9, (byte *)0x0);
    allocSize = loadStatus.bigFile.numSubDirs * 8 + 4;
    loadAddr = (u_long *)MEMPACK_Malloc(allocSize, '\b');
    CdSync(0, (undefined *)0x0);
    LOAD_CdReadFromBigFile(0, loadAddr, allocSize, 0, 0);
    loadStatus.bigFile.subDirList = (_BigFileDirEntry *)(loadAddr + 1);
    do
    {
      LOAD_ProcessReadQueue();
      iVar2 = LOAD_NonBlockingFileLoad();
    } while (iVar2 != 0);
    loadStatus.bigFile.rootDir = LOAD_ChangeDirectoryFlag(loadStatus.bigFile.subDirList);
    do
    {
      LOAD_ProcessReadQueue();
      iVar2 = LOAD_NonBlockingFileLoad();
    } while (iVar2 != 0);
  }
  return;
}

int LOAD_SetupFileToDoCDReading(_NonBlockLoadEntry *loadEntry)

{
  _BigFileEntry *p_Var1;
  int iVar2;

  p_Var1 = LOAD_GetBigFileEntry(loadEntry->fileHash);
  if (p_Var1 == (_BigFileEntry *)0x0)
  {
    iVar2 = 0;
    if (loadEntry->dirHash == loadStatus.bigFile.currentDirID)
    {
      DEBUG_FatalError("CD ERROR: File %s does not exist\n");
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

void LOAD_NonBlockingReadFile(_NonBlockLoadEntry *loadEntry)

{
  int iVar1;
  long *plVar2;

  iVar1 = LOAD_SetupFileToDoCDReading(loadEntry);
  if (iVar1 == 0)
  {
    loadStatus.changeDir = 1;
  }
  else
  {
    if (loadEntry->loadAddr == (long *)0x0)
    {
      plVar2 = (long *)MEMPACK_Malloc(loadEntry->loadSize, *(u_char *)&loadEntry->memType);
      loadEntry->loadAddr = plVar2;
    }
    LOAD_CdReadFromBigFile(loadEntry->filePos, (u_long *)loadEntry->loadAddr, loadEntry->loadSize,
                           loadEntry->checksumType, loadEntry->checksum);
    loadStatus.changeDir = 0;
  }
  return;
}

void LOAD_CD_ReadPartOfFile(_NonBlockLoadEntry *loadEntry)

{
  int iVar1;

  iVar1 = LOAD_SetupFileToDoCDReading(loadEntry);
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

long LOAD_HashName(char *string)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  u_int uVar4;
  char *s2;
  int iVar5;
  int iVar6;
  int iVar7;
  u_int uVar8;
  u_int uVar9;
  u_int uVar10;

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
    s2 = "drm";
    do
    {
      iVar3 = strcpy(pcVar2 + 1, s2);
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
    uVar4 = (u_int)(byte)string[iVar5];
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

long LOAD_HashUnit(char *name)

{
  byte bVar1;
  bool bVar2;
  u_int uVar3;
  int iVar4;
  u_int uVar5;
  u_int uVar6;
  int iVar7;
  int iVar8;

  iVar7 = 0;
  iVar8 = 0;
  bVar1 = *name;
  bVar2 = false;
  uVar3 = 0;
  while (bVar1 != 0)
  {
    uVar5 = (u_int)(byte)*name;
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

_BigFileEntry *LOAD_GetBigFileEntry(long hash)

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

_BigFileEntry *LOAD_GetBigFileEntryByHash(char *fileName)

{
  long hash;
  _BigFileEntry *p_Var1;

  hash = LOAD_HashName(fileName);
  p_Var1 = LOAD_GetBigFileEntry(hash);
  return p_Var1;
}

long LOAD_DoesFileExist(char *fileName)

{
  _BigFileEntry *p_Var1;
  u_int uVar2;

  p_Var1 = LOAD_GetBigFileEntryByHash(fileName);
  uVar2 = 0;
  if (p_Var1 != (_BigFileEntry *)0x0)
  {
    uVar2 = (u_int)(p_Var1->fileLen != 0);
  }
  return uVar2;
}

void LOAD_LoadToAddress(long *addr, long x_pos, long y_pos, long clut_x, long clut_y)

{
  long *plVar1;
  long *plVar2;
  undefined2 local_18;
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
  local_18 = (undefined2)x_pos;
  local_16 = (undefined2)y_pos;
  local_14 = *(undefined2 *)(plVar1 + 2);
  local_12 = *(undefined2 *)((int)plVar1 + 10);
  LoadImage((u_char *)&local_18, plVar1 + 3);
  if (plVar2 != (long *)0x0)
  {
    local_18 = (undefined2)clut_x;
    local_16 = (undefined2)clut_y;
    local_14 = 0x10;
    local_12 = 1;
    DrawSync(0);
    LoadImage((u_char *)&local_18, plVar2);
  }
  return;
}

void LOAD_LoadTIM2(long *addr, long x_pos, long y_pos, long width, long height)

{
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;

  local_10 = (undefined2)x_pos;
  local_e = (undefined2)y_pos;
  local_c = *(undefined2 *)(addr + 4);
  local_a = *(undefined2 *)((int)addr + 0x12);
  LoadImage((u_char *)&local_10, addr + 5);
  DrawSync(0);
  return;
}

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

void LOAD_CleanUpBuffers(void)

{
  if (loadStatus.buffer1 != (void *)0x0)
  {
    MEMPACK_Init((char *)loadStatus.buffer1);
    loadStatus.buffer1 = (void *)0x0;
  }
  if (loadStatus.buffer2 != (void *)0x0)
  {
    MEMPACK_Init((char *)loadStatus.buffer2);
    loadStatus.buffer2 = (void *)0x0;
  }
  return;
}

void *LOAD_InitBuffers(void)

{
  loadStatus.buffer1 = MEMPACK_Malloc(0x800, '#');
  loadStatus.buffer2 = MEMPACK_Malloc(0x800, '#');
  return loadStatus.buffer1;
}

void LOAD_InitCdStreamMode(void)

{
  byte local_10[8];

  local_10[0] = 0xa0;
  CdReadyCallback(LOAD_CdReadReady);
  CdSyncCallback(LOAD_CdSeekCallback);
  CdControlF(0xe, local_10, (undefined *)0x0);
  return;
}

void LOAD_DumpCurrentDir(void)

{
  if (loadStatus.bigFile.currentDir != (_BigFileDir *)0x0)
  {
    MEMPACK_Init((char *)loadStatus.bigFile.currentDir);
    loadStatus.bigFile.currentDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.currentDirID = 0;
  }
  if (loadStatus.bigFile.cachedDir != (_BigFileDir *)0x0)
  {
    MEMPACK_Init((char *)loadStatus.bigFile.cachedDir);
    loadStatus.bigFile.cachedDir = (_BigFileDir *)0x0;
    loadStatus.bigFile.cachedDirID = 0;
  }
  return;
}

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
            MEMPACK_Init((char *)loadStatus.bigFile.cachedDir);
          }
          loadStatus.currentDirLoading = 1;
          loadStatus.bigFile.cachedDirID = loadStatus.bigFile.currentDirID;
          loadStatus.bigFile.cachedDir = loadStatus.bigFile.currentDir;
          loadStatus.bigFile.currentDir =
              LOAD_ChangeDirectoryFlag(loadStatus.bigFile.subDirList + iVar3);
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

void LOAD_SetSearchDirectory(long id)

{
  loadStatus.bigFile.searchDirID = id;
  return;
}

long LOAD_GetSearchDirectory(void)

{
  return loadStatus.bigFile.searchDirID;
}

int LOAD_ChangeDirectory(void)

{
  return loadStatus.changeDir;
}

void EVENT_UpdatePuzzlePointers(_BigFileDir *oldDir, _BigFileDir *newDir)

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

int LOAD_NonBlockingFileLoad(void)

{
  return (u_int)(loadStatus.currentQueueFile.readStatus != 0);
}

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
