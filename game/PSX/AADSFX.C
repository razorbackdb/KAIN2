#include "THISDUST.H"
#include "AADSFX.H"

u_long aadPlaySfx(u_int toneID, int volume, int pan, int pitchOffset)

{
  u_long u_longParam;

  u_longParam = createSfxHandle(toneID);
  aadPutSfxCommand(0, volume, pan, u_longParam, (int)(short)pitchOffset);
  return u_longParam;
}

u_long aadStopSfx(u_long handle)

{
  aadPutSfxCommand(1, 0, 0, handle, 0);
  return handle;
}

void aadStopAllSlots(void)

{
  aadPutSfxCommand(4, 0, 0, 0, 0);
  return;
}

int aadIsSfxPlayingOrRequested(u_long handle)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar2 = 0;
  iVar3 = 0x1dc;
  while (true)
  {
    iVar1 = (int)&aadMem->updateCounter + iVar3;
    if ((((*(char *)(iVar1 + 8) == -0x30) && (aadMem->voiceStatus[iVar2] != '\0')) &&
         (aadMem->voiceStatus[iVar2] != '\x02')) &&
        (*(u_long *)(iVar1 + 4) == handle))
      break;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x1c;
    if (0x17 < iVar2)
    {
      return 0;
    }
  }
  return 1;
}

int SndTypeIsPlayingOrRequested(u_long handle)

{
  u_short uVar1;
  char *pcVar2;
  int iVar3;
  u_int uVar4;
  u_int uVar5;

  ExitCriticalSection();
  uVar1 = (aadMem->sfxSlot).commandsInQueue;
  uVar5 = (u_int)uVar1;
  uVar4 = (u_int)(aadMem->sfxSlot).commandOut;
  if (uVar1 != 0)
  {
    iVar3 = uVar4 * 0xc + 0x54;
    do
    {
      pcVar2 = (char *)((int)&aadMem->updateCounter + iVar3);
      if ((*pcVar2 == '\0') && (*(u_long *)(pcVar2 + 4) == handle))
      {
        EnterCriticalSection();
        return 1;
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0xc;
      if (uVar4 == 0x20)
      {
        iVar3 = 0x54;
        uVar4 = 0;
      }
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  EnterCriticalSection();
  iVar3 = aadIsSfxPlayingOrRequested(handle);
  return iVar3;
}

int aadIsSfxTypePlaying(u_int toneID)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar2 = 0;
  iVar3 = 0x1dc;
  while ((((iVar1 = (int)&aadMem->updateCounter + iVar3, *(char *)(iVar1 + 8) != -0x30 ||
                                                             ((u_int) * (u_short *)(iVar1 + 4) != (toneID & 0xffff))) ||
           (aadMem->voiceStatus[iVar2] == '\0')) ||
          (aadMem->voiceStatus[iVar2] == '\x02')))
  {
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x1c;
    if (0x17 < iVar2)
    {
      return 0;
    }
  }
  return 1;
}

int aadIsSfxPlaying(u_int sfxToneID)

{
  u_short uVar1;
  char *pcVar2;
  int iVar3;
  u_int uVar4;
  u_int uVar5;

  ExitCriticalSection();
  uVar1 = (aadMem->sfxSlot).commandsInQueue;
  uVar5 = (u_int)uVar1;
  uVar4 = (u_int)(aadMem->sfxSlot).commandOut;
  if (uVar1 != 0)
  {
    iVar3 = uVar4 * 0xc + 0x54;
    do
    {
      pcVar2 = (char *)((int)&aadMem->updateCounter + iVar3);
      if ((*pcVar2 == '\0') && ((u_int) * (u_short *)(pcVar2 + 4) == sfxToneID))
      {
        EnterCriticalSection();
        return 1;
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0xc;
      if (uVar4 == 0x20)
      {
        iVar3 = 0x54;
        uVar4 = 0;
      }
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  EnterCriticalSection();
  iVar3 = aadIsSfxTypePlaying(sfxToneID);
  return iVar3;
}

u_long aadSetSfxVolPanPitch(u_long handle, int volume, int pan, int pitch)

{
  aadPutSfxCommand(3, volume & 0xff, pan & 0xff, handle, (int)(short)pitch);
  return handle;
}

u_long createSfxHandle(u_int toneID)

{
  u_short uVar1;
  AadMemoryStruct *pAVar2;
  u_short uVar3;

  pAVar2 = aadMem;
  uVar1 = (aadMem->sfxSlot).handleCounter;
  uVar3 = uVar1 + 1;
  (aadMem->sfxSlot).handleCounter = uVar3;
  if (uVar3 == 0)
  {
    (pAVar2->sfxSlot).handleCounter = uVar1 + 2;
  }
  return (u_int)(aadMem->sfxSlot).handleCounter << 0x10 | toneID & 0xffff;
}

void aadPutSfxCommand(int statusByte, int dataByte0, int dataByte1, u_long u_longParam, int shortParam)

{
  u_short uVar1;
  AadMemoryStruct *pAVar2;
  AadSfxCommand *pAVar3;
  u_char uVar4;

  uVar4 = (u_char)statusByte;
  uVar1 = (aadMem->sfxSlot).commandsInQueue;
  if ((uVar1 < 0x1e) || (uVar4 = '\x04', uVar1 < 0x1f))
  {
    ExitCriticalSection();
    pAVar3 = (aadMem->sfxSlot).commandQueue + (aadMem->sfxSlot).commandIn;
    pAVar3->statusByte = uVar4;
    pAVar3->dataByte[0] = (u_char)dataByte0;
    pAVar3->dataByte[1] = (u_char)dataByte1;
    pAVar2 = aadMem;
    pAVar3->u_longParam = u_longParam;
    pAVar3->shortParam = (short)shortParam;
    uVar4 = (pAVar2->sfxSlot).commandIn + '\x01';
    (pAVar2->sfxSlot).commandIn = uVar4;
    if (uVar4 == ' ')
    {
      (aadMem->sfxSlot).commandIn = '\0';
    }
    (aadMem->sfxSlot).commandsInQueue = (aadMem->sfxSlot).commandsInQueue + 1;
    EnterCriticalSection();
  }
  return;
}

void aadExecuteEvent(AadSfxCommand *sfxCmd)

{
  if (sfxCmd->statusByte < 9)
  {
    (*(code *)(&sfxCmdFunction)[sfxCmd->statusByte])();
  }
  return;
}

void sfxCmdPlayTone(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  u_char uVar2;
  u_long waveStartAddr;
  AadSynthVoice *voice;
  AadLoadedSfxToneAttr *pAVar3;
  u_int uVar4;

  uVar4 = sfxCmd->u_longParam;
  if (aadMem->sfxToneMasterList[uVar4 & 0xffff] < 0xfe)
  {
    pAVar3 = aadMem->sfxToneAttrTbl + aadMem->sfxToneMasterList[uVar4 & 0xffff];
    if (aadMem->sfxWaveMasterList[pAVar3->waveID] < 0xfe)
    {
      waveStartAddr =
          aadGetSramBlockAddr((u_int)aadMem->sfxWaveAttrTbl
                                  [aadMem->sfxWaveMasterList[pAVar3->waveID]]
                                      .sramHandle);
      bVar1 = (pAVar3->toneAttr).minNote;
      voice = aadAllocateVoice((u_int)(pAVar3->toneAttr).priority);
      if (voice != (AadSynthVoice *)0x0)
      {
        aadPlayTone(&pAVar3->toneAttr, waveStartAddr, &aadDummySfxProgram, (u_int)bVar1, 0x7f,
                    (u_int)sfxCmd->dataByte[0], (u_int)sfxCmd->dataByte[1],
                    (u_int)(aadMem->sfxSlot).sfxVolume, aadMem->sfxMasterVol, voice,
                    (int)sfxCmd->shortParam);
        voice->handle = uVar4;
        voice->voiceID = -0x30;
        uVar2 = (pAVar3->toneAttr).priority;
        voice->note = bVar1;
        voice->priority = uVar2;
        uVar2 = (pAVar3->toneAttr).parentProgram;
        voice->volume = '\x7f';
        voice->program = uVar2;
        voice->updateVol = sfxCmd->dataByte[0];
        uVar2 = sfxCmd->dataByte[1];
        voice->progAtr = &aadDummySfxProgram;
        voice->toneAtr = &pAVar3->toneAttr;
        voice->pan = uVar2;
      }
    }
  }
  return;
}

void sfxCmdStopTone(AadSfxCommand *sfxCmd)

{
  AadMemoryStruct *pAVar1;
  u_int uVar2;
  AadSynthVoice *pAVar3;
  u_int uVar4;
  u_short uVar5;
  u_long uVar6;

  uVar2 = 0;
  uVar6 = sfxCmd->u_longParam;
  uVar5 = 0;
  uVar4 = 0;
  do
  {
    pAVar3 = aadMem->synthVoice + uVar4;
    if ((((pAVar3->voiceID == -0x30) && (pAVar3->handle == uVar6)) &&
         (aadMem->voiceStatus[uVar4] != '\0')) &&
        (aadMem->voiceStatus[uVar4] != '\x02'))
    {
      pAVar3->voiceID = -1;
      uVar2 = uVar2 | pAVar3->voiceMask;
    }
    pAVar1 = aadMem;
    uVar5 = uVar5 + 1;
    uVar4 = (u_int)uVar5;
  } while (uVar5 < 0x18);
  aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | uVar2;
  pAVar1->voiceKeyOnRequest = pAVar1->voiceKeyOnRequest & ~uVar2;
  return;
}

void sfxCmdStopAllTones(AadSfxCommand *sfxCmd)

{
  AadMemoryStruct *pAVar1;
  u_int uVar2;
  AadSynthVoice *pAVar3;
  u_int uVar4;
  u_short uVar5;

  uVar2 = 0;
  uVar5 = 0;
  uVar4 = 0;
  do
  {
    pAVar3 = aadMem->synthVoice + uVar4;
    if (((pAVar3->voiceID == -0x30) && (aadMem->voiceStatus[uVar4] != '\0')) &&
        (aadMem->voiceStatus[uVar4] != '\x02'))
    {
      pAVar3->voiceID = -1;
      uVar2 = uVar2 | pAVar3->voiceMask;
    }
    pAVar1 = aadMem;
    uVar5 = uVar5 + 1;
    uVar4 = (u_int)uVar5;
  } while (uVar5 < 0x18);
  aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | uVar2;
  pAVar1->voiceKeyOnRequest = pAVar1->voiceKeyOnRequest & ~uVar2;
  return;
}

void sfxCmdSetToneVolPanPitch(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  u_int uVar2;
  AadSynthVoice *pAVar3;
  u_short uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short local_10;
  short local_e;

  uVar4 = 0;
  uVar2 = 0;
  while ((((pAVar3 = aadMem->synthVoice + uVar2, pAVar3->voiceID != -0x30 ||
                                                     (pAVar3->handle != sfxCmd->u_longParam)) ||
           (aadMem->voiceStatus[uVar2] == '\0')) ||
          (aadMem->voiceStatus[uVar2] == '\x02')))
  {
    uVar4 = uVar4 + 1;
    uVar2 = (u_int)uVar4;
    if (0x17 < uVar4)
    {
      return;
    }
  }
  local_10 = (u_short)pAVar3->volume * (u_short)pAVar3->volume;
  local_e = (u_short)pAVar3->volume * (u_short)pAVar3->volume;
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = sfxCmd->dataByte[1];
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        local_e = (short)((int)((int)local_10 * (u_int)sfxCmd->dataByte[1] *
                                (u_int)sfxCmd->dataByte[1]) >>
                          0xc);
      }
    }
    else
    {
      local_10 = (short)((int)local_e * (0x7f - (u_int)bVar1) * (0x7f - (u_int)bVar1) >> 0xc);
    }
  }
  uVar2 = (u_int)pAVar3->toneAtr->volume;
  iVar5 = uVar2 * uVar2;
  local_10 = (short)((u_int)(local_10 * iVar5) >> 0xe);
  local_e = (short)((u_int)(local_e * iVar5) >> 0xe);
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = pAVar3->toneAtr->panPosition;
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        uVar2 = (u_int)pAVar3->toneAtr->panPosition;
        local_e = (short)((int)((int)local_10 * uVar2 * uVar2) >> 0xc);
      }
    }
    else
    {
      local_10 = (short)((int)local_e * (0x7f - (u_int)bVar1) * (0x7f - (u_int)bVar1) >> 0xc);
    }
  }
  iVar5 = (u_int)sfxCmd->dataByte[0] * (u_int)sfxCmd->dataByte[0];
  pAVar3->updateVol = sfxCmd->dataByte[0];
  uVar2 = (u_int)pAVar3->progAtr->volume;
  iVar6 = uVar2 * uVar2;
  uVar2 = (u_int)(aadMem->sfxSlot).sfxVolume;
  iVar7 = uVar2 * uVar2;
  iVar8 = aadMem->sfxMasterVol * aadMem->sfxMasterVol;
  SpuSetVoiceADSR1ADSR2((u_int)uVar4,
                        (u_short)((u_int)((short)((u_int)((short)((u_int)((short)((u_int)(local_10 * iVar5) >> 0xe) * iVar6) >> 0xe) * iVar7) >> 0xe) * iVar8) >> 0xe),
                        (u_short)((u_int)((short)((u_int)((short)((u_int)((short)((u_int)(local_e * iVar5) >> 0xe) *
                                                                          iVar6) >>
                                                                  0xe) *
                                                          iVar7) >>
                                                  0xe) *
                                          iVar8) >>
                                  0xe));
  return;
}

void sfxCmdSetToneVolumeAndPan(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  u_int uVar2;
  short sVar3;
  AadToneAtr *pAVar4;
  AadSynthVoice *pAVar5;
  u_short uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  short local_18;
  short local_16;

  uVar6 = 0;
  uVar2 = 0;
  while ((((pAVar5 = aadMem->synthVoice + uVar2, pAVar5->voiceID != -0x30 ||
                                                     (pAVar5->handle != sfxCmd->u_longParam)) ||
           (aadMem->voiceStatus[uVar2] == '\0')) ||
          (aadMem->voiceStatus[uVar2] == '\x02')))
  {
    uVar6 = uVar6 + 1;
    uVar2 = (u_int)uVar6;
    if (0x17 < uVar6)
    {
      return;
    }
  }
  local_18 = (u_short)pAVar5->volume * (u_short)pAVar5->volume;
  local_16 = (u_short)pAVar5->volume * (u_short)pAVar5->volume;
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = sfxCmd->dataByte[1];
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        local_16 = (short)((int)((int)local_18 * (u_int)sfxCmd->dataByte[1] *
                                 (u_int)sfxCmd->dataByte[1]) >>
                           0xc);
      }
    }
    else
    {
      local_18 = (short)((int)local_16 * (0x7f - (u_int)bVar1) * (0x7f - (u_int)bVar1) >> 0xc);
    }
  }
  uVar2 = (u_int)pAVar5->toneAtr->volume;
  iVar7 = uVar2 * uVar2;
  local_18 = (short)((u_int)(local_18 * iVar7) >> 0xe);
  local_16 = (short)((u_int)(local_16 * iVar7) >> 0xe);
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = pAVar5->toneAtr->panPosition;
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        uVar2 = (u_int)pAVar5->toneAtr->panPosition;
        local_16 = (short)((int)((int)local_18 * uVar2 * uVar2) >> 0xc);
      }
    }
    else
    {
      local_18 = (short)((int)local_16 * (0x7f - (u_int)bVar1) * (0x7f - (u_int)bVar1) >> 0xc);
    }
  }
  iVar7 = (u_int)sfxCmd->dataByte[0] * (u_int)sfxCmd->dataByte[0];
  pAVar5->updateVol = sfxCmd->dataByte[0];
  uVar2 = (u_int)pAVar5->progAtr->volume;
  iVar8 = uVar2 * uVar2;
  uVar2 = (u_int)(aadMem->sfxSlot).sfxVolume;
  iVar9 = uVar2 * uVar2;
  iVar10 = aadMem->sfxMasterVol * aadMem->sfxMasterVol;
  SpuSetVoiceADSR1ADSR2((u_int)uVar6,
                        (u_short)((u_int)((short)((u_int)((short)((u_int)((short)((u_int)(local_18 * iVar7) >> 0xe) * iVar8) >> 0xe) * iVar9) >> 0xe) * iVar10) >> 0xe),
                        (u_short)((u_int)((short)((u_int)((short)((u_int)((short)((u_int)(local_16 * iVar7) >> 0xe) * iVar8) >> 0xe) * iVar9) >> 0xe) * iVar10) >> 0xe));
  pAVar4 = pAVar5->toneAtr;
  uVar2 = (u_int)pAVar5->note - ((u_int)pAVar4->centerNote - 0x3c);
  if ((pAVar4->centerFine & 0x80U) == 0)
  {
    uVar2 = uVar2 & 0xffff;
    sVar3 = (&aadPitchTable)[uVar2] +
            (u_short)((&aadStepsPerCent)[uVar2] * 100 * (u_int)(byte)pAVar4->centerFine >> 0x17);
  }
  else
  {
    uVar2 = uVar2 & 0xffff;
    sVar3 = (&aadPitchTable)[uVar2] -
            (u_short)((&aadStepsPerCent)[uVar2] * 100 *
                          (0x100 - (u_int)(byte)pAVar4->centerFine & 0xffff) >>
                      0x17);
  }
  SpuSetVoiceStartAddr((u_int)uVar6, sVar3 + sfxCmd->shortParam);
  return;
}

void sfxCmdLockVoice(AadSfxCommand *sfxCmd)

{
  AadSynthVoice *pAVar1;
  u_long uVar2;
  code *pcVar3;

  pcVar3 = (code *)sfxCmd->u_longParam;
  pAVar1 = aadAllocateVoice(0xff);
  uVar2 = 0;
  if (pAVar1 != (AadSynthVoice *)0x0)
  {
    uVar2 = pAVar1->voiceMask;
    pAVar1->flags = pAVar1->flags | 1;
  }
  (*pcVar3)(uVar2);
  return;
}

void sfxCmdSetVoiceKeyOff(AadSfxCommand *sfxCmd)

{
  u_int uVar1;
  u_int vNum;
  u_int *puVar2;

  vNum = 0;
  puVar2 = (u_int *)sfxCmd->u_longParam;
  uVar1 = 1;
  do
  {
    if ((uVar1 & *puVar2) != 0)
      break;
    vNum = vNum + 1;
    uVar1 = uVar1 << 1;
  } while (vNum < 0x18);
  SpuSetVoiceADSR1ADSR2(vNum, *(u_short *)(puVar2 + 2), *(u_short *)((int)puVar2 + 10));
  SpuSetVoiceStartAddr(vNum, *(word *)(puVar2 + 5));
  SpuSetVoicePitch(vNum, puVar2[7]);
  SOUND_SetVoiceVolume(vNum, *(u_short *)((int)puVar2 + 0x3a), *(u_short *)(puVar2 + 0xf));
  return;
}

void sfxCmdSetVoiceKeyOn(AadSfxCommand *sfxCmd)

{
  aadMem->voiceKeyOnRequest = aadMem->voiceKeyOnRequest | sfxCmd->u_longParam;
  return;
}

void sfxCmdSetVoiceKeyOff(AadSfxCommand *sfxCmd)

{
  AadMemoryStruct *pAVar1;

  pAVar1 = aadMem;
  aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | sfxCmd->u_longParam;
  pAVar1->voiceKeyOnRequest = pAVar1->voiceKeyOnRequest & ~sfxCmd->u_longParam;
  return;
}
