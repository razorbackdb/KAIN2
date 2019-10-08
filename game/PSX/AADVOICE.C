#include "THISDUST.H"
#include "AADVOICE.H"

AadSynthVoice *aadAllocateVoice(int priority)

{
  char cVar1;
  AadSynthVoice *pAVar2;
  u_short uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  u_int uVar7;
  u_int uVar8;
  AadSynthVoice *pAVar9;
  AadSynthVoice *pAVar10;

  uVar7 = 0x7fff;
  uVar8 = 0x7fff;
  pAVar10 = (AadSynthVoice *)0x0;
  iVar5 = 0;
  iVar6 = 0x1dc;
  pAVar9 = (AadSynthVoice *)0x0;
  do
  {
    pAVar2 = (AadSynthVoice *)((int)&aadMem->updateCounter + iVar6);
    iVar4 = (int)&aadMem->updateCounter + iVar5;
    if ((pAVar2->flags & 1) == 0)
    {
      cVar1 = *(char *)(iVar4 + 0x47c);
      if (cVar1 == '\0')
      {
        *(undefined *)(iVar4 + 0x47c) = 1;
        uVar3 = pAVar2->flags;
        goto LAB_80058258;
      }
      if (cVar1 == '\x02')
      {
        if ((u_int)pAVar2->priority < uVar7)
        {
          uVar7 = (u_int)pAVar2->priority;
          pAVar9 = pAVar2;
        }
      }
      else
      {
        if ((u_int)pAVar2->priority < uVar8)
        {
          uVar8 = (u_int)pAVar2->priority;
          pAVar10 = pAVar2;
        }
      }
    }
    pAVar2 = pAVar9;
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x1c;
    pAVar9 = pAVar2;
  } while (iVar5 < 0x18);
  if (priority < (int)uVar7)
  {
    if (priority < (int)uVar8)
    {
      return (AadSynthVoice *)0x0;
    }
    pAVar10->flags = pAVar10->flags | 2;
    return pAVar10;
  }
  uVar3 = pAVar2->flags;
LAB_80058258:
  pAVar2->flags = uVar3 | 2;
  return pAVar2;
}

void SOUND_SetVoiceVolume(int vNum, u_short adsr1, u_short adsr2)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar3 = 1;
  if ((adsr1 & 0x8000) != 0)
  {
    iVar3 = 5;
  }
  iVar2 = 3;
  if ((adsr2 & 0x20) != 0)
  {
    iVar2 = 7;
  }
  if ((adsr2 & 0x4000) == 0)
  {
    iVar1 = 1;
    if ((adsr2 & 0x8000) != 0)
    {
      iVar1 = 5;
    }
  }
  else
  {
    iVar1 = 3;
    if ((adsr2 & 0x8000) != 0)
    {
      iVar1 = 7;
    }
  }
  sfxCmdSetVoiceAttr(vNum, (u_int)(adsr1 >> 8) & 0x7f, (u_int)(adsr1 >> 4) & 0xf,
                     ((u_int)adsr2 & 0x1fc0) >> 6, (u_int)adsr2 & 0x1f, (u_int)adsr1 & 0xf, iVar3, iVar1,
                     iVar2);
  return;
}

void aadPlayTone(AadToneAtr *toneAtr, u_long waveStartAddr, AadProgramAtr *progAtr, int midiNote,
                 int volume, int masterVolume, int masterPan, int slotVolume, int masterMasterVol,
                 AadSynthVoice *voice, int pitchOffset)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  short local_20;
  short local_1e;

  local_20 = (short)volume * (short)volume;
  local_1e = local_20;
  if ((aadMem->flags & 1U) == 0)
  {
    if (masterPan < 0x41)
    {
      if (masterPan < 0x3f)
      {
        local_1e = (short)(local_20 * masterPan * masterPan >> 0xc);
      }
    }
    else
    {
      local_20 = (short)((u_int)((int)local_20 * (0x7f - masterPan) * (0x7f - masterPan)) >> 0xc);
    }
  }
  iVar3 = (u_int)toneAtr->volume * (u_int)toneAtr->volume;
  local_20 = (short)((u_int)(local_20 * iVar3) >> 0xe);
  local_1e = (short)((u_int)(local_1e * iVar3) >> 0xe);
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = toneAtr->panPosition;
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        local_1e = (short)((int)((int)local_20 * (u_int)toneAtr->panPosition *
                                 (u_int)toneAtr->panPosition) >>
                           0xc);
      }
    }
    else
    {
      local_20 = (short)((int)local_1e * (0x7f - (u_int)bVar1) * (0x7f - (u_int)bVar1) >> 0xc);
    }
  }
  iVar3 = (u_int)progAtr->volume * (u_int)progAtr->volume;
  SpuSetVoiceADSR1ADSR2((u_int)voice->voiceNum,
                        (u_short)((u_int)((int)(short)((u_int)((int)(short)((u_int)((short)((u_int)((int)local_20 *
                                                                                                    masterVolume *
                                                                                                    masterVolume) >>
                                                                                            0xe) *
                                                                                    iVar3) >>
                                                                            0xe) *
                                                               slotVolume * slotVolume) >>
                                                       0xe) *
                                          masterMasterVol * masterMasterVol) >>
                                  0xe),
                        (u_short)((u_int)((int)(short)((u_int)((int)(short)((u_int)((short)((u_int)((int)local_1e *
                                                                                                    masterVolume *
                                                                                                    masterVolume) >>
                                                                                            0xe) *
                                                                                    iVar3) >>
                                                                            0xe) *
                                                               slotVolume * slotVolume) >>
                                                       0xe) *
                                          masterMasterVol * masterMasterVol) >>
                                  0xe));
  midiNote = midiNote - ((u_int)toneAtr->centerNote - 0x3c);
  if ((toneAtr->centerFine & 0x80U) == 0)
  {
    sVar2 = (&aadPitchTable)[midiNote] +
            (u_short)((&aadStepsPerCent)[midiNote] * 100 * (u_int)(byte)toneAtr->centerFine >> 0x17);
  }
  else
  {
    sVar2 = (&aadPitchTable)[midiNote] -
            (u_short)((&aadStepsPerCent)[midiNote] * 100 * (0x100 - (u_int)(byte)toneAtr->centerFine) >> 0x17);
  }
  SpuSetVoiceStartAddr((u_int)voice->voiceNum, sVar2 + (short)pitchOffset);
  SpuSetVoicePitch((u_int)voice->voiceNum, waveStartAddr);
  SOUND_SetVoiceVolume((u_int)voice->voiceNum, toneAtr->adsr1, toneAtr->adsr2);
  if (toneAtr->mode == '\x04')
  {
    aadMem->voiceReverbRequest = aadMem->voiceReverbRequest | voice->voiceMask;
  }
  else
  {
    aadMem->voiceReverbRequest = aadMem->voiceReverbRequest & ~voice->voiceMask;
  }
  aadMem->voiceKeyOnRequest = aadMem->voiceKeyOnRequest | voice->voiceMask;
  return;
}

void aadPlayTonePitchBend(AadToneAtr *toneAtr, u_long waveStartAddr, AadProgramAtr *progAtr, int midiNote,
                          int volume, int masterVolume, int masterPan, int slotVolume, int masterMasterVol,
                          AadSynthVoice *voice, int pitchWheelPos)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short local_20;
  short local_1e;

  local_20 = (short)volume * (short)volume;
  local_1e = local_20;
  if ((aadMem->flags & 1U) == 0)
  {
    if (masterPan < 0x41)
    {
      if (masterPan < 0x3f)
      {
        local_1e = (short)(local_20 * masterPan * masterPan >> 0xc);
      }
    }
    else
    {
      local_20 = (short)((u_int)((int)local_20 * (0x7f - masterPan) * (0x7f - masterPan)) >> 0xc);
    }
  }
  iVar3 = (u_int)toneAtr->volume * (u_int)toneAtr->volume;
  local_20 = (short)((u_int)(local_20 * iVar3) >> 0xe);
  local_1e = (short)((u_int)(local_1e * iVar3) >> 0xe);
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = toneAtr->panPosition;
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        local_1e = (short)((int)((int)local_20 * (u_int)toneAtr->panPosition *
                                 (u_int)toneAtr->panPosition) >>
                           0xc);
      }
    }
    else
    {
      local_20 = (short)((int)local_1e * (0x7f - (u_int)bVar1) * (0x7f - (u_int)bVar1) >> 0xc);
    }
  }
  iVar3 = (u_int)progAtr->volume * (u_int)progAtr->volume;
  SpuSetVoiceADSR1ADSR2((u_int)voice->voiceNum,
                        (u_short)((u_int)((int)(short)((u_int)((int)(short)((u_int)((short)((u_int)((int)local_20 *
                                                                                                    masterVolume *
                                                                                                    masterVolume) >>
                                                                                            0xe) *
                                                                                    iVar3) >>
                                                                            0xe) *
                                                               slotVolume * slotVolume) >>
                                                       0xe) *
                                          masterMasterVol * masterMasterVol) >>
                                  0xe),
                        (u_short)((u_int)((int)(short)((u_int)((int)(short)((u_int)((short)((u_int)((int)local_1e *
                                                                                                    masterVolume *
                                                                                                    masterVolume) >>
                                                                                            0xe) *
                                                                                    iVar3) >>
                                                                            0xe) *
                                                               slotVolume * slotVolume) >>
                                                       0xe) *
                                          masterMasterVol * masterMasterVol) >>
                                  0xe));
  (int)(u_int) toneAtr->pitchBendMax;
  iVar4;
  if ((toneAtr->centerFine & 0x80U) == 0)
  {
    sVar2 = (&aadPitchTable)[iVar3] +
            (u_short)((&aadStepsPerCent)[iVar3] * 100 * (u_int)(byte)toneAtr->centerFine >> 0x17);
  }
  else
  {
    sVar2 = (&aadPitchTable)[iVar3] -
            (u_short)((&aadStepsPerCent)[iVar3] * 100 * (0x100 - (u_int)(byte)toneAtr->centerFine) >>
                      0x17);
  }
  SpuSetVoiceStartAddr
            ((u_int)voice->voiceNum,
             sVar2 + (short)(((int)(&aadStepsPerSemitone)[iVar3] *
 iVar4));
  SpuSetVoicePitch((u_int)voice->voiceNum,waveStartAddr);
  SOUND_SetVoiceVolume((u_int)voice->voiceNum,toneAtr->adsr1,toneAtr->adsr2);
  if (toneAtr->mode == '\x04') {
    aadMem->voiceReverbRequest = aadMem->voiceReverbRequest | voice->voiceMask;
  }
  else {
    aadMem->voiceReverbRequest = aadMem->voiceReverbRequest & ~voice->voiceMask;
  }
  aadMem->voiceKeyOnRequest = aadMem->voiceKeyOnRequest | voice->voiceMask;
  return;
}
