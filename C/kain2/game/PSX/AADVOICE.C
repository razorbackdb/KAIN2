#include "THISDUST.H"
#include "AADVOICE.H"

// decompiled code
// original method signature:
// struct AadSynthVoice * /*$ra*/ aadAllocateVoice(int priority /*$a0*/)
// line 28, offset 0x80057a98
/* begin block 1 */
// Start line: 30
// Start offset: 0x80057A98
// Variables:
// 		int i; // $a2
// 		int lowestPriSus; // $t2
// 		int lowestPriRel; // $t1
// 		struct AadSynthVoice *lowestPriSusVoice; // $t4
// 		struct AadSynthVoice *lowestPriRelVoice; // $t3
// 		struct AadSynthVoice *voice; // $a1
/* end block 1 */
// End offset: 0x80057B84
// End Line: 90

/* begin block 2 */
// Start line: 56
/* end block 2 */
// End Line: 57

/* begin block 3 */
// Start line: 57
/* end block 3 */
// End Line: 58

/* begin block 4 */
// Start line: 63
/* end block 4 */
// End Line: 64

AadSynthVoice *aadAllocateVoice(int priority)

{
  char cVar1;
  AadSynthVoice *pAVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
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
        goto LAB_80057b48;
      }
      if (cVar1 == '\x02')
      {
        if ((uint)pAVar2->priority < uVar7)
        {
          uVar7 = (uint)pAVar2->priority;
          pAVar9 = pAVar2;
        }
      }
      else
      {
        if ((uint)pAVar2->priority < uVar8)
        {
          uVar8 = (uint)pAVar2->priority;
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
LAB_80057b48:
  pAVar2->flags = uVar3 | 2;
  return pAVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ SpuSetVoiceADSR1ADSR2(int vNum /*$a0*/, unsigned short adsr1 /*$a1*/, unsigned short adsr2 /*$a3*/)
// line 109, offset 0x80057b8c
/* begin block 1 */
// Start line: 110
// Start offset: 0x80057B8C
// Variables:
// 		unsigned short sl; // $t3
// 		unsigned short dr; // $v1
// 		unsigned short ar; // $t4
// 		unsigned short arm; // $t1
// 		unsigned short rr; // $t2
// 		unsigned short rrm; // $t0
// 		unsigned short sr; // $a3
// 		unsigned short srm; // $a1
/* end block 1 */
// End offset: 0x80057C04
// End Line: 133

/* begin block 2 */
// Start line: 291
/* end block 2 */
// End Line: 292

void SpuSetVoiceADSR1ADSR2(int vNum, ushort adsr1, ushort adsr2)

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
  SpuSetVoiceADSRAttr(vNum, (uint)(adsr1 >> 8) & 0x7f, (uint)(adsr1 >> 4) & 0xf,
                      ((uint)adsr2 & 0x1fc0) >> 6, (uint)adsr2 & 0x1f, (uint)adsr1 & 0xf, iVar3, iVar1,
                      iVar2);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ aadPlayTone(struct AadToneAtr *toneAtr /*$s0*/, unsigned long waveStartAddr /*$s3*/, struct AadProgramAtr *progAtr /*$a2*/, int midiNote /*$s2*/, int volume /*stack 16*/, int masterVolume /*stack 20*/, int masterPan /*stack 24*/, int slotVolume /*stack 28*/, int masterMasterVol /*stack 32*/, struct AadSynthVoice *voice /*stack 36*/, int pitchOffset /*stack 40*/)
// line 156, offset 0x80057c34
/* begin block 1 */
// Start line: 157
// Start offset: 0x80057C34
// Variables:
// 		struct AadVolume voiceVol; // stack offset -32
// 		int pitch; // $a1
// 		int finePitch; // $a1
// 		int pitchIndex; // $a3

/* begin block 1.1 */
// Start line: 166
// Start offset: 0x80057C9C
// Variables:
// 		unsigned long tmp; // $v0
/* end block 1.1 */
// End offset: 0x80057C9C
// End Line: 166

/* begin block 1.2 */
// Start line: 167
// Start offset: 0x80057CF8
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.2 */
// End offset: 0x80057CF8
// End Line: 167

/* begin block 1.3 */
// Start line: 168
// Start offset: 0x80057D68
// Variables:
// 		unsigned long tmp; // $v0
/* end block 1.3 */
// End offset: 0x80057D68
// End Line: 168

/* begin block 1.4 */
// Start line: 170
// Start offset: 0x80057DD0
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.4 */
// End offset: 0x80057DD0
// End Line: 170

/* begin block 1.5 */
// Start line: 170
// Start offset: 0x80057DD0
// Variables:
// 		unsigned long masterVolumeSquared; // $a1
/* end block 1.5 */
// End offset: 0x80057DD0
// End Line: 170

/* begin block 1.6 */
// Start line: 170
// Start offset: 0x80057DD0
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.6 */
// End offset: 0x80057DD0
// End Line: 170

/* begin block 1.7 */
// Start line: 170
// Start offset: 0x80057DD0
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.7 */
// End offset: 0x80057DD0
// End Line: 170
/* end block 1 */
// End offset: 0x80058030
// End Line: 205

/* begin block 2 */
// Start line: 392
/* end block 2 */
// End Line: 393

void aadPlayTone(AadToneAtr *toneAtr, ulong waveStartAddr, AadProgramAtr *progAtr, int midiNote,
                 int volume, int masterVolume, int masterPan, int slotVolume, int masterMasterVol,
                 AadSynthVoice *voice, int pitchOffset)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  short local_20;
  short local_1e;

  iVar2 = (volume + 1) * (volume + 1) + -1;
  local_20 = (short)iVar2;
  local_1e = local_20;
  if ((aadMem->flags & 1U) == 0)
  {
    if (masterPan < 0x41)
    {
      if (masterPan < 0x3f)
      {
        local_1e = (short)((iVar2 * 0x10000 >> 0x10) * ((masterPan + 1) * (masterPan + 1) + 1) >>
                           0xc);
      }
    }
    else
    {
      local_20 = (short)((uint)((iVar2 * 0x10000 >> 0x10) *
                                ((0x80 - masterPan) * (0x80 - masterPan) + -1)) >>
                         0xc);
    }
  }
  iVar2 = (uint)toneAtr->volume + 1;
  iVar2 = iVar2 * iVar2 + -1;
  local_20 = (short)((uint)(local_20 * iVar2) >> 0xe);
  local_1e = (short)((uint)(local_1e * iVar2) >> 0xe);
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = toneAtr->panPosition;
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        iVar2 = (uint)toneAtr->panPosition + 1;
        local_1e = (short)((int)local_20 * (iVar2 * iVar2 + 1) >> 0xc);
      }
    }
    else
    {
      local_20 = (short)((int)local_1e * ((0x80 - (uint)bVar1) * (0x80 - (uint)bVar1) + -1) >> 0xc);
    }
  }
  iVar3 = (masterVolume + 1) * (masterVolume + 1) + -1;
  iVar2 = (uint)progAtr->volume + 1;
  iVar6 = iVar2 * iVar2 + -1;
  iVar2 = (slotVolume + 1) * (slotVolume + 1) + -1;
  iVar4 = (masterMasterVol + 1) * (masterMasterVol + 1) + -1;
  SpuSetVoiceVolume((uint)voice->voiceNum,
                    (int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_20 *
                                                                                     iVar3) >>
                                                                              0xe) *
                                                                      iVar6) >>
                                                               0xe) *
                                                       iVar2) >>
                                                0xe) *
                                        iVar4) >>
                                 0xe),
                    (int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_1e *
                                                                                     iVar3) >>
                                                                              0xe) *
                                                                      iVar6) >>
                                                               0xe) *
                                                       iVar2) >>
                                                0xe) *
                                        iVar4) >>
                                 0xe));
  midiNote = midiNote - ((uint)toneAtr->centerNote - 0x3c);
  if ((toneAtr->centerFine & 0x80U) == 0)
  {
    sVar5 = aadPitchTable[midiNote] +
            (ushort)(aadStepsPerCent[midiNote] * 100 * (uint)(byte)toneAtr->centerFine >> 0x17);
  }
  else
  {
    sVar5 = aadPitchTable[midiNote] -
            (ushort)(aadStepsPerCent[midiNote] * 100 * (0x100 - (uint)(byte)toneAtr->centerFine) >>
                     0x17);
  }
  SpuSetVoicePitch((uint)voice->voiceNum, sVar5 + (short)pitchOffset);
  SpuSetVoiceStartAddr((uint)voice->voiceNum, waveStartAddr);
  SpuSetVoiceADSR1ADSR2((uint)voice->voiceNum, toneAtr->adsr1, toneAtr->adsr2);
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

// decompiled code
// original method signature:
// void /*$ra*/ aadPlayTonePitchBend(struct AadToneAtr *toneAtr /*$s0*/, unsigned long waveStartAddr /*$s4*/, struct AadProgramAtr *progAtr /*$a2*/, int midiNote /*$s3*/, int volume /*stack 16*/, int masterVolume /*stack 20*/, int masterPan /*stack 24*/, int slotVolume /*stack 28*/, int masterMasterVol /*stack 32*/, struct AadSynthVoice *voice /*stack 36*/, int pitchWheelPos /*stack 40*/)
// line 246, offset 0x80058064
/* begin block 1 */
// Start line: 247
// Start offset: 0x80058064
// Variables:
// 		struct AadVolume voiceVol; // stack offset -32
// 		int pitch; // $a1
// 		int finePitch; // $a1
// 		int pitchIndex; // $a3
// 		long pitchValueBendAmount; // $t0

/* begin block 1.1 */
// Start line: 258
// Start offset: 0x800580D4
// Variables:
// 		unsigned long tmp; // $v0
/* end block 1.1 */
// End offset: 0x800580D4
// End Line: 258

/* begin block 1.2 */
// Start line: 259
// Start offset: 0x80058130
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.2 */
// End offset: 0x80058130
// End Line: 259

/* begin block 1.3 */
// Start line: 260
// Start offset: 0x800581A0
// Variables:
// 		unsigned long tmp; // $v0
/* end block 1.3 */
// End offset: 0x800581A0
// End Line: 260

/* begin block 1.4 */
// Start line: 262
// Start offset: 0x80058208
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.4 */
// End offset: 0x80058208
// End Line: 262

/* begin block 1.5 */
// Start line: 262
// Start offset: 0x80058208
// Variables:
// 		unsigned long masterVolumeSquared; // $a1
/* end block 1.5 */
// End offset: 0x80058208
// End Line: 262

/* begin block 1.6 */
// Start line: 262
// Start offset: 0x80058208
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.6 */
// End offset: 0x80058208
// End Line: 262

/* begin block 1.7 */
// Start line: 262
// Start offset: 0x80058208
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.7 */
// End offset: 0x80058208
// End Line: 262
/* end block 1 */
// End offset: 0x800584AC
// End Line: 313

/* begin block 2 */
// Start line: 620
/* end block 2 */
// End Line: 621

void aadPlayTonePitchBend(AadToneAtr *toneAtr, ulong waveStartAddr, AadProgramAtr *progAtr, int midiNote,
                          int volume, int masterVolume, int masterPan, int slotVolume, int masterMasterVol,
                          AadSynthVoice *voice, int pitchWheelPos)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  short local_20;
  short local_1e;

  iVar2 = (volume + 1) * (volume + 1) + -1;
  local_20 = (short)iVar2;
  local_1e = local_20;
  if ((aadMem->flags & 1U) == 0)
  {
    if (masterPan < 0x41)
    {
      if (masterPan < 0x3f)
      {
        local_1e = (short)((iVar2 * 0x10000 >> 0x10) * ((masterPan + 1) * (masterPan + 1) + 1) >>
                           0xc);
      }
    }
    else
    {
      local_20 = (short)((uint)((iVar2 * 0x10000 >> 0x10) *
                                ((0x80 - masterPan) * (0x80 - masterPan) + -1)) >>
                         0xc);
    }
  }
  iVar2 = (uint)toneAtr->volume + 1;
  iVar2 = iVar2 * iVar2 + -1;
  local_20 = (short)((uint)(local_20 * iVar2) >> 0xe);
  local_1e = (short)((uint)(local_1e * iVar2) >> 0xe);
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = toneAtr->panPosition;
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        iVar2 = (uint)toneAtr->panPosition + 1;
        local_1e = (short)((int)local_20 * (iVar2 * iVar2 + 1) >> 0xc);
      }
    }
    else
    {
      local_20 = (short)((int)local_1e * ((0x80 - (uint)bVar1) * (0x80 - (uint)bVar1) + -1) >> 0xc);
    }
  }
  iVar3 = (masterVolume + 1) * (masterVolume + 1) + -1;
  iVar2 = (uint)progAtr->volume + 1;
  iVar6 = iVar2 * iVar2 + -1;
  iVar2 = (slotVolume + 1) * (slotVolume + 1) + -1;
  iVar4 = (masterMasterVol + 1) * (masterMasterVol + 1) + -1;
  SpuSetVoiceVolume((uint)voice->voiceNum,
                    (int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_20 *
                                                                                     iVar3) >>
                                                                              0xe) *
                                                                      iVar6) >>
                                                               0xe) *
                                                       iVar2) >>
                                                0xe) *
                                        iVar4) >>
                                 0xe),
                    (int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_1e *
                                                                                     iVar3) >>
                                                                              0xe) *
                                                                      iVar6) >>
                                                               0xe) *
                                                       iVar2) >>
                                                0xe) *
                                        iVar4) >>
                                 0xe));
  iVar3 = 0x2000 / (int)(uint)toneAtr->pitchBendMax;
  iVar2 = (midiNote - ((uint)toneAtr->centerNote - 0x3c)) + (pitchWheelPos + -0x2000) / iVar3;
  if ((toneAtr->centerFine & 0x80U) == 0)
  {
    sVar5 = aadPitchTable[iVar2] +
            (ushort)(aadStepsPerCent[iVar2] * 100 * (uint)(byte)toneAtr->centerFine >> 0x17);
  }
  else
  {
    sVar5 = aadPitchTable[iVar2] -
            (ushort)(aadStepsPerCent[iVar2] * 100 * (0x100 - (uint)(byte)toneAtr->centerFine) >>
                     0x17);
  }
  SpuSetVoicePitch((uint)voice->voiceNum,
                   sVar5 + (short)(((int)aadStepsPerSemitone[iVar2] *
                                    ((pitchWheelPos + -0x2000) % iVar3)) /
                                   iVar3));
  SpuSetVoiceStartAddr((uint)voice->voiceNum, waveStartAddr);
  SpuSetVoiceADSR1ADSR2((uint)voice->voiceNum, toneAtr->adsr1, toneAtr->adsr2);
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
