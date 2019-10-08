#include "THISDUST.H"
#include "VOICEXA.H"

void VOICEXA_Play(void)

{
  u_char *puVar1;
  int iVar2;
  XAVoiceTracker *pXVar3;
  int iVar4;
  u_char auStack80[6];
  char acStack56[32];

  pXVar3 = &voiceTracker;
  if ((gameTrackerX.debugFlags & 0x80000U) != 0)
  {
    iVar4 = 0;
    voiceTracker.voiceStatus = '\0';
    voiceTracker.cdStatus = '\0';
    voiceTracker.reqIn = '\0';
    voiceTracker.reqOut = '\0';
    voiceTracker.reqsQueued = '\0';
    voiceTracker.cdCmdIn = '\0';
    voiceTracker.cdCmdOut = '\0';
    voiceTracker.cdCmdsQueued = '\0';
    voiceTracker.voiceCmdIn = '\0';
    voiceTracker.voiceCmdOut = '\0';
    voiceTracker.voiceCmdsQueued = '\0';
    do
    {
      sprintf(acStack56, "\\VOICE\\VOICE%02d.XA;1");
      puVar1 = CdSearchFile(auStack80, acStack56);
      if (puVar1 == (u_char *)0x0)
      {
        pXVar3->xaFileInfo[0].startPos = 0;
      }
      else
      {
        iVar2 = CdPosToInt((byte *)auStack80);
        pXVar3->xaFileInfo[0].startPos = iVar2;
      }
      iVar4 = iVar4 + 1;
      pXVar3 = (XAVoiceTracker *)&pXVar3->currentSector;
    } while (iVar4 < 0x1e);
  }
  return;
}

void processCdCommands(XAVoiceTracker *vt, u_char cdCommand, int numParams, u_char *params)

{
  u_char uVar1;
  u_char *puVar2;
  int iVar3;
  int iVar4;

  iVar3 = 0;
  vt->cdCmdQueue[vt->cdCmdIn].cdCommand = cdCommand;
  puVar2 = params;
  if (0 < numParams)
  {
    do
    {
      iVar4 = iVar3 + 1;
      vt->cdCmdQueue[vt->cdCmdIn].cdCmdParam[iVar3] = *puVar2;
      puVar2 = params + iVar4;
      iVar3 = iVar4;
    } while (iVar4 < numParams);
  }
  if (vt->cdCmdsQueued < 7)
  {
    vt->cdCmdsQueued = vt->cdCmdsQueued + 1;
    uVar1 = vt->cdCmdIn + '\x01';
    vt->cdCmdIn = uVar1;
    if (uVar1 == '\b')
    {
      vt->cdCmdIn = '\0';
    }
  }
  return;
}

void VOICEXA_CdSyncCallback(u_char status, u_char *result)

{
  if (status == '\x02')
  {
    voiceTracker.cdStatus = '\0';
    voiceTracker.cdCmdOut = voiceTracker.cdCmdOut + '\x01';
    if (voiceTracker.cdCmdOut == '\b')
    {
      voiceTracker.cdCmdOut = '\0';
    }
    voiceTracker.cdCmdsQueued = voiceTracker.cdCmdsQueued + -1;
    CdSyncCallback(voiceTracker.prevCallback);
  }
  else
  {
    voiceTracker.cdStatus = '\x02';
  }
  return;
}

void putCdCommand(XAVoiceTracker *vt)

{
  _func_65 *p_Var1;
  byte bVar2;
  CdCommand *pCVar3;

  if (vt->cdStatus == '\x02')
  {
    vt->cdStatus = '\x01';
    pCVar3 = vt->cdCmdQueue + vt->cdCmdOut;
    bVar2 = pCVar3->cdCommand;
  }
  else
  {
    if (vt->cdCmdsQueued == '\0')
    {
      return;
    }
    if (vt->cdStatus == '\x01')
    {
      return;
    }
    vt->cdStatus = '\x01';
    pCVar3 = vt->cdCmdQueue + vt->cdCmdOut;
    p_Var1 = (_func_65 *)CdSyncCallback(VOICEXA_CdSyncCallback);
    vt->prevCallback = p_Var1;
    bVar2 = pCVar3->cdCommand;
  }
  CdControlF(bVar2, pCVar3->cdCmdParam, vt->cdResult);
  return;
}

void processVoiceCommands(XAVoiceTracker *vt, u_char voiceCmd, u_char nextVoiceStatus, int voiceCmdParam)

{
  u_char uVar1;

  vt->voiceCmdQueue[vt->voiceCmdIn].voiceCmd = voiceCmd;
  vt->voiceCmdQueue[vt->voiceCmdIn].nextVoiceStatus = nextVoiceStatus;
  vt->voiceCmdQueue[vt->voiceCmdIn].voiceCmdParam = (u_short)voiceCmdParam;
  if (vt->voiceCmdsQueued < 0xf)
  {
    vt->voiceCmdsQueued = vt->voiceCmdsQueued + 1;
    uVar1 = vt->voiceCmdIn + '\x01';
    vt->voiceCmdIn = uVar1;
    if (uVar1 == '\x10')
    {
      vt->voiceCmdIn = '\0';
    }
  }
  return;
}

void putVoiceCommand(XAVoiceTracker *vt)

{
  u_int uVar1;
  VoiceCommand *pVVar2;

  if (vt->voiceCmdsQueued != '\0')
  {
    vt->voiceCmdsQueued = vt->voiceCmdsQueued + -1;
    uVar1 = (u_int)vt->voiceCmdOut + 1;
    pVVar2 = vt->voiceCmdQueue + (u_int)vt->voiceCmdOut;
    vt->voiceCmdOut = (u_char)uVar1;
    if ((uVar1 & 0xff) == 0x10)
    {
      vt->voiceCmdOut = '\0';
    }
    if (pVVar2->voiceCmd < 5)
    {
      (*(code *)(&voiceCmdTbl)[pVVar2->voiceCmd])(vt, (int)(short)pVVar2->voiceCmdParam);
      vt->voiceStatus = pVVar2->nextVoiceStatus;
    }
  }
  return;
}

void voiceCmdPlay(XAVoiceTracker *vt, short voiceIndex)

{
  u_short *puVar1;
  XAFileInfo *pXVar2;
  u_char local_58;
  byte local_57;
  u_char auStack80[8];
  undefined *local_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  short local_38;
  short local_36;
  u_char local_34;
  u_char local_30;
  undefined2 local_2c;
  undefined2 local_2a;
  u_char local_28;
  u_char local_24;
  u_char local_20[8];

  if (voiceList != (XAVoiceListEntry *)0x0)
  {
    puVar1 = &voiceList->length;
    vt->fileNum = voiceIndex >> 4;
    pXVar2 = vt->xaFileInfo + ((int)((u_int)(u_short)voiceIndex << 0x10) >> 0x14);
    processCdCommands(vt, '\t', 0, (u_char *)0x0);
    local_58 = '\x01';
    local_57 = (byte)voiceIndex & 0xf;
    processCdCommands(vt, '\r', 4, &local_58);
    local_20[0] = -0x38;
    processCdCommands(vt, '\x0e', 1, local_20);
    CdIntToPos(pXVar2->startPos, (char *)vt);
    vt->endSector =
        pXVar2->startPos +
        ((u_int) * (u_short *)((int)puVar1 + ((int)((u_int)(u_short)voiceIndex << 0x10) >> 0xf)) - 0x96);
    CdIntToPos(pXVar2->startPos, (char *)auStack80);
    processCdCommands(vt, '\x1b', 4, auStack80);
    local_48 = &DAT_00003fcf;
    local_44 = 0x3fff;
    local_42 = 0x3fff;
    local_40 = 0;
    local_3e = 0;
    local_34 = 0;
    local_30 = 1;
    local_2c = 0x7fff;
    local_2a = 0x7fff;
    local_28 = 0;
    local_24 = 1;
    local_38 = (short)gameTrackerX.sound.gVoiceVol << 8;
    local_36 = local_38;
    SpuSetCommonCDMix((u_int *)&local_48);
    if (0x3c < gameTrackerX.sound.gMusicVol)
    {
      aadStartMasterVolumeFade(0x3c, -1, (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
    }
  }
  return;
}

void voiceCmdResume(XAVoiceTracker *vt, short cmdParam)

{
  undefined *local_30[6];
  u_char local_18;
  u_char local_c;

  if (vt->voiceStatus != '\0')
  {
    processCdCommands(vt, '\t', 0, (u_char *)0x0);
    local_30[0] = &DAT_00002200;
    local_18 = 0;
    local_c = 0;
    SpuSetCommonCDMix((u_int *)local_30);
    aadStartMasterVolumeFade(gameTrackerX.sound.gMusicVol, 1,
                             (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
  }
  return;
}

void voiceCmdPause(XAVoiceTracker *vt, short cmdParam)

{
  if ((u_int)vt->voiceStatus - 1 < 2)
  {
    processCdCommands(vt, '\t', 0, (u_char *)0x0);
  }
  return;
}

void voiceCmdStop(XAVoiceTracker *vt, short cmdParam)

{
  if (vt->voiceStatus == '\x03')
  {
    processCdCommands(vt, '\x1b', 4, (u_char *)vt);
  }
  return;
}

void voiceCmdNull(XAVoiceTracker *vt, short cmdParam)

{
  return;
}

void VOICEXA_Init(int voiceIndex, int queueRequests)

{
  u_char uVar1;

  if ((((gameTrackerX.debugFlags & 0x80000U) != 0) &&
       (voiceTracker.xaFileInfo[voiceIndex >> 4].startPos != 0)) &&
      (gameTrackerX.sound.gVoiceOn != '\0'))
  {
    if (queueRequests == 0)
    {
      processVoiceCommands(&voiceTracker, '\0', '\x01', voiceIndex);
    }
    else
    {
      voiceTracker.requestQueue[voiceTracker.reqIn] = (u_short)voiceIndex;
      uVar1 = voiceTracker.reqsQueued + '\x01';
      if (voiceTracker.reqsQueued < 3)
      {
        voiceTracker.reqIn = voiceTracker.reqIn + '\x01';
        voiceTracker.reqsQueued = uVar1;
        if (voiceTracker.reqIn == '\x04')
        {
          voiceTracker.reqIn = '\0';
        }
      }
    }
  }
  return;
}

int VOICEXA_FinalStatus(XAVoiceTracker *vt)

{
  int iVar1;

  if (vt->voiceCmdsQueued == '\0')
  {
    return (u_int)vt->voiceStatus;
  }
  iVar1 = (u_int)vt->voiceCmdIn - 1;
  if (vt->voiceCmdIn == 0)
  {
    iVar1 = 0xf;
  }
  return (u_int)vt->voiceCmdQueue[iVar1].nextVoiceStatus;
}

void VOICEXA_Resume(void)

{
  int iVar1;
  u_char voiceCmd;
  u_char nextVoiceStatus;

  iVar1 = VOICEXA_FinalStatus(&voiceTracker);
  if ((gameTrackerX.debugFlags & 0x80000U) != 0)
  {
    voiceCmd = '\x02';
    if (iVar1 - 1U < 2)
    {
      nextVoiceStatus = '\x03';
    }
    else
    {
      if (iVar1 != 0)
      {
        return;
      }
      voiceCmd = '\x04';
      nextVoiceStatus = '\x04';
    }
    processVoiceCommands(&voiceTracker, voiceCmd, nextVoiceStatus, 0);
  }
  return;
}

void VOICEXA_Pause(void)

{
  int iVar1;
  u_char voiceCmd;
  u_char nextVoiceStatus;

  iVar1 = VOICEXA_FinalStatus(&voiceTracker);
  if ((gameTrackerX.debugFlags & 0x80000U) != 0)
  {
    voiceCmd = '\x03';
    if (iVar1 == 3)
    {
      nextVoiceStatus = '\x01';
    }
    else
    {
      if (iVar1 != 4)
      {
        return;
      }
      voiceCmd = '\x04';
      nextVoiceStatus = '\0';
    }
    processVoiceCommands(&voiceTracker, voiceCmd, nextVoiceStatus, 0);
  }
  return;
}

void VOICEXA_Tick(void)

{
  if ((gameTrackerX.debugFlags & 0x80000U) != 0)
  {
    putVoiceCommand(&voiceTracker);
    putCdCommand(&voiceTracker);
    if (((voiceTracker.cdCmdsQueued == '\0') && (voiceTracker.voiceCmdsQueued == '\0')) &&
        (voiceTracker.voiceStatus < 3))
    {
      if (voiceTracker.voiceStatus == '\0')
      {
        if (voiceTracker.reqsQueued != '\0')
        {
          processVoiceCommands(&voiceTracker, '\0', '\x01', (u_int)voiceTracker.requestQueue[voiceTracker.reqOut]);
          voiceTracker.reqsQueued = voiceTracker.reqsQueued + -1;
          voiceTracker.reqOut = voiceTracker.reqOut + '\x01';
          if (voiceTracker.reqOut == '\x04')
          {
            voiceTracker.reqOut = '\0';
          }
        }
      }
      else
      {
        CdControlB(0x10, (byte *)0x0, voiceTracker.cdResult);
        if ((voiceTracker.cdResult[3] & 2) != 0)
        {
          voiceTracker.voiceStatus = '\x02';
          voiceTracker.currentPos.track = '\0';
          voiceTracker.currentPos.minute = voiceTracker.cdResult[0];
          voiceTracker.currentPos.second = voiceTracker.cdResult[1];
          voiceTracker.currentPos.sector = voiceTracker.cdResult[2];
          voiceTracker.currentSector = CdPosToInt((byte *)&voiceTracker);
          voiceTracker.currentSector = voiceTracker.currentSector + -0x96;
          if (voiceTracker.endSector <= voiceTracker.currentSector)
          {
            processVoiceCommands(&voiceTracker, '\x01', '\0', 0);
          }
        }
      }
    }
  }
  return;
}

int VOICEXA_IsPlaying(void)

{
  int iVar1;

  iVar1 = 2;
  if ((voiceTracker.voiceStatus != '\x02') &&
      ((voiceTracker.voiceStatus == '\x01' || (iVar1 = 0, voiceTracker.cdStatus != '\0'))))
  {
    return 1;
  }
  return iVar1;
}
