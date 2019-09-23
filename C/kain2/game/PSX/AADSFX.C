#include "THISDUST.H"
#include "AADSFX.H"

// AadProgramAtr @0x800CEF48, len = 0x00000008
aadDummySfxProgram =
    {
        // ushort @0x800CEF48, len = 0x00000002
        .numTones = 0x1,
        // ushort @0x800CEF4A, len = 0x00000002
        .firstTone = 0x0,
        // uchar @0x800CEF4C, len = 0x00000001
        .volume = 0x7F,
        // uchar @0x800CEF4D, len = 0x00000001
        .panPosition = 0x40,
        // ushort @0x800CEF4E, len = 0x00000002
        .unused = 0x0};
// decompiled code
// original method signature:
// unsigned long /*$ra*/ aadPlaySfx(unsigned int toneID /*$a0*/, int volume /*$s1*/, int pan /*$s2*/, int pitchOffset /*$s0*/)
// line 19, offset 0x800569dc
/* begin block 1 */
// Start line: 20
// Start offset: 0x800569DC
// Variables:
// 		unsigned long handle; // $s0
/* end block 1 */
// End offset: 0x800569DC
// End Line: 20

/* begin block 2 */
// Start line: 38
/* end block 2 */
// End Line: 39

ulong aadPlaySfx(uint toneID, int volume, int pan, int pitchOffset)

{
  ulong ulongParam;

  ulongParam = createSfxHandle(toneID);
  aadPutSfxCommand(0, volume, pan, ulongParam, (int)(short)pitchOffset);
  return ulongParam;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ aadStopSfx(unsigned long handle /*$s0*/)
// line 37, offset 0x80056a40
/* begin block 1 */
// Start line: 75
/* end block 1 */
// End Line: 76

ulong aadStopSfx(ulong handle)

{
  aadPutSfxCommand(1, 0, 0, handle, 0);
  return handle;
}

// decompiled code
// original method signature:
// void /*$ra*/ aadStopAllSfx()
// line 45, offset 0x80056a7c
/* begin block 1 */
// Start line: 92
/* end block 1 */
// End Line: 93

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadStopAllSfx(void)

{
  aadPutSfxCommand(4, 0, 0, 0, 0);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ aadIsSfxPlaying(unsigned long handle /*$a0*/)
// line 53, offset 0x80056aac
/* begin block 1 */
// Start line: 55
// Start offset: 0x80056AAC
// Variables:
// 		struct AadSynthVoice *voice; // $v1
// 		int i; // $a1
/* end block 1 */
// End offset: 0x80056B14
// End Line: 69

/* begin block 2 */
// Start line: 109
/* end block 2 */
// End Line: 110

/* begin block 3 */
// Start line: 110
/* end block 3 */
// End Line: 111

/* begin block 4 */
// Start line: 114
/* end block 4 */
// End Line: 115

int aadIsSfxPlaying(ulong handle)

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
        (*(ulong *)(iVar1 + 4) == handle))
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

// decompiled code
// original method signature:
// int /*$ra*/ aadIsSfxPlayingOrRequested(unsigned long handle /*$s0*/)
// line 72, offset 0x80056b1c
/* begin block 1 */
// Start line: 73
// Start offset: 0x80056B1C
// Variables:
// 		int commandOut; // $a1
// 		int i; // $a2
// 		struct AadSfxCommand *sfxCmd; // $v1
/* end block 1 */
// End offset: 0x80056BC4
// End Line: 89

/* begin block 2 */
// Start line: 154
/* end block 2 */
// End Line: 155

int aadIsSfxPlayingOrRequested(ulong handle)

{
  ushort uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;

  EnterCriticalSection();
  uVar1 = (aadMem->sfxSlot).commandsInQueue;
  uVar5 = (uint)uVar1;
  uVar4 = (uint)(aadMem->sfxSlot).commandOut;
  if (uVar1 != 0)
  {
    iVar3 = uVar4 * 0xc + 0x54;
    do
    {
      pcVar2 = (char *)((int)&aadMem->updateCounter + iVar3);
      if ((*pcVar2 == '\0') && (*(ulong *)(pcVar2 + 4) == handle))
      {
        ExitCriticalSection();
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
  ExitCriticalSection();
  iVar3 = aadIsSfxPlaying(handle);
  return iVar3;
}

// decompiled code
// original method signature:
// int /*$ra*/ aadIsSfxTypePlaying(unsigned int toneID /*$a0*/)
// line 93, offset 0x80056bd4
/* begin block 1 */
// Start line: 95
// Start offset: 0x80056BD4
// Variables:
// 		struct AadSynthVoice *voice; // $v1
// 		int i; // $a1
/* end block 1 */
// End offset: 0x80056C40
// End Line: 108

/* begin block 2 */
// Start line: 202
/* end block 2 */
// End Line: 203

/* begin block 3 */
// Start line: 203
/* end block 3 */
// End Line: 204

/* begin block 4 */
// Start line: 207
/* end block 4 */
// End Line: 208

int aadIsSfxTypePlaying(uint toneID)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar2 = 0;
  iVar3 = 0x1dc;
  while ((((iVar1 = (int)&aadMem->updateCounter + iVar3, *(char *)(iVar1 + 8) != -0x30 ||
                                                             ((uint) * (ushort *)(iVar1 + 4) != (toneID & 0xffff))) ||
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

// decompiled code
// original method signature:
// int /*$ra*/ aadIsSfxTypePlayingOrRequested(unsigned int sfxToneID /*$s0*/)
// line 111, offset 0x80056c48
/* begin block 1 */
// Start line: 112
// Start offset: 0x80056C48
// Variables:
// 		int commandOut; // $a1
// 		int i; // $a2
// 		struct AadSfxCommand *sfxCmd; // $v1
/* end block 1 */
// End offset: 0x80056CF0
// End Line: 129

/* begin block 2 */
// Start line: 244
/* end block 2 */
// End Line: 245

int aadIsSfxTypePlayingOrRequested(uint sfxToneID)

{
  ushort uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;

  EnterCriticalSection();
  uVar1 = (aadMem->sfxSlot).commandsInQueue;
  uVar5 = (uint)uVar1;
  uVar4 = (uint)(aadMem->sfxSlot).commandOut;
  if (uVar1 != 0)
  {
    iVar3 = uVar4 * 0xc + 0x54;
    do
    {
      pcVar2 = (char *)((int)&aadMem->updateCounter + iVar3);
      if ((*pcVar2 == '\0') && ((uint) * (ushort *)(pcVar2 + 4) == sfxToneID))
      {
        ExitCriticalSection();
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
  ExitCriticalSection();
  iVar3 = aadIsSfxTypePlaying(sfxToneID);
  return iVar3;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ aadSetSfxVolPanPitch(unsigned long handle /*$s0*/, int volume /*$a1*/, int pan /*$a2*/, int pitch /*$a3*/)
// line 160, offset 0x80056d00
/* begin block 1 */
// Start line: 320
/* end block 1 */
// End Line: 321

ulong aadSetSfxVolPanPitch(ulong handle, int volume, int pan, int pitch)

{
  aadPutSfxCommand(3, volume & 0xff, pan & 0xff, handle, (int)(short)pitch);
  return handle;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ createSfxHandle(unsigned int toneID /*$a0*/)
// line 168, offset 0x80056d44
/* begin block 1 */
// Start line: 334
/* end block 1 */
// End Line: 335

/* begin block 2 */
// Start line: 335
/* end block 2 */
// End Line: 336

ulong createSfxHandle(uint toneID)

{
  ushort uVar1;
  AadMemoryStruct *pAVar2;
  ushort uVar3;

  pAVar2 = aadMem;
  uVar1 = (aadMem->sfxSlot).handleCounter;
  uVar3 = uVar1 + 1;
  (aadMem->sfxSlot).handleCounter = uVar3;
  if (uVar3 == 0)
  {
    (pAVar2->sfxSlot).handleCounter = uVar1 + 2;
  }
  return (uint)(aadMem->sfxSlot).handleCounter << 0x10 | toneID & 0xffff;
}

// decompiled code
// original method signature:
// void /*$ra*/ aadPutSfxCommand(int statusByte /*$s0*/, int dataByte0 /*$s2*/, int dataByte1 /*$s3*/, unsigned long ulongParam /*$s4*/, int shortParam /*stack 16*/)
// line 177, offset 0x80056d8c
/* begin block 1 */
// Start line: 178
// Start offset: 0x80056D8C
// Variables:
// 		struct AadSfxCommand *sfxCmd; // $v1
/* end block 1 */
// End offset: 0x80056E60
// End Line: 209

/* begin block 2 */
// Start line: 352
/* end block 2 */
// End Line: 353

/* begin block 3 */
// Start line: 354
/* end block 3 */
// End Line: 355

void aadPutSfxCommand(int statusByte, int dataByte0, int dataByte1, ulong ulongParam, int shortParam)

{
  ushort uVar1;
  AadMemoryStruct *pAVar2;
  AadSfxCommand *pAVar3;
  uchar uVar4;

  uVar4 = (uchar)statusByte;
  uVar1 = (aadMem->sfxSlot).commandsInQueue;
  if ((uVar1 < 0x1e) || (uVar4 = '\x04', uVar1 < 0x1f))
  {
    EnterCriticalSection();
    pAVar3 = (aadMem->sfxSlot).commandQueue + (uint)(aadMem->sfxSlot).commandIn;
    pAVar3->statusByte = uVar4;
    pAVar3->dataByte[0] = (uchar)dataByte0;
    pAVar3->dataByte[1] = (uchar)dataByte1;
    pAVar2 = aadMem;
    pAVar3->ulongParam = ulongParam;
    pAVar3->shortParam = (short)shortParam;
    uVar4 = (pAVar2->sfxSlot).commandIn + '\x01';
    (pAVar2->sfxSlot).commandIn = uVar4;
    if (uVar4 == ' ')
    {
      (aadMem->sfxSlot).commandIn = '\0';
    }
    (aadMem->sfxSlot).commandsInQueue = (aadMem->sfxSlot).commandsInQueue + 1;
    ExitCriticalSection();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ aadExecuteSfxCommand(struct AadSfxCommand *sfxCmd /*$a0*/)
// line 229, offset 0x80056e80
/* begin block 1 */
// Start line: 463
/* end block 1 */
// End Line: 464

void aadExecuteSfxCommand(AadSfxCommand *sfxCmd)

{
  if (sfxCmd->statusByte < 9)
  {
    (*(code *)sfxCmdFunction[(uint)sfxCmd->statusByte])();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ sfxCmdPlayTone(struct AadSfxCommand *sfxCmd /*$s4*/)
// line 248, offset 0x80056ecc
/* begin block 1 */
// Start line: 249
// Start offset: 0x80056ECC
// Variables:
// 		unsigned long handle; // $s7
// 		struct AadProgramAtr *progAtr; // $fp
// 		struct AadToneAtr *toneAtr; // $s2
// 		struct AadSynthVoice *voice; // $s1
// 		unsigned short midiNote; // $s5
// 		unsigned long waveAddr; // $s6
// 		struct AadLoadedSfxToneAttr *sfxToneAttr; // $s3
// 		struct AadLoadedSfxWaveAttr *sfxWaveAttr; // $v0
// 		int i; // $v1
/* end block 1 */
// End offset: 0x80057008
// End Line: 340

/* begin block 2 */
// Start line: 501
/* end block 2 */
// End Line: 502

void sfxCmdPlayTone(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  uchar uVar2;
  ulong waveStartAddr;
  AadSynthVoice *voice;
  AadLoadedSfxToneAttr *pAVar3;
  uint uVar4;

  uVar4 = sfxCmd->ulongParam;
  if (aadMem->sfxToneMasterList[uVar4 & 0xffff] < 0xfe)
  {
    pAVar3 = aadMem->sfxToneAttrTbl + (uint)aadMem->sfxToneMasterList[uVar4 & 0xffff];
    if (aadMem->sfxWaveMasterList[(uint)pAVar3->waveID] < 0xfe)
    {
      waveStartAddr =
          aadGetSramBlockAddr((uint)aadMem->sfxWaveAttrTbl
                                  [(uint)aadMem->sfxWaveMasterList[(uint)pAVar3->waveID]]
                                      .sramHandle);
      bVar1 = (pAVar3->toneAttr).minNote;
      voice = aadAllocateVoice((uint)(pAVar3->toneAttr).priority);
      if (voice != (AadSynthVoice *)0x0)
      {
        aadPlayTone(&pAVar3->toneAttr, waveStartAddr, &aadDummySfxProgram, (uint)bVar1, 0x7f,
                    (uint)sfxCmd->dataByte[0], (uint)sfxCmd->dataByte[1],
                    (uint)(aadMem->sfxSlot).sfxVolume, aadMem->sfxMasterVol, voice,
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

// decompiled code
// original method signature:
// void /*$ra*/ sfxCmdStopTone(struct AadSfxCommand *sfxCmd /*$a0*/)
// line 344, offset 0x80057038
/* begin block 1 */
// Start line: 346
// Start offset: 0x80057038
// Variables:
// 		unsigned long handle; // $t0
// 		struct AadSynthVoice *voice; // $a0
// 		unsigned short i; // $a3
// 		unsigned long vmask; // $v1
/* end block 1 */
// End offset: 0x800570C4
// End Line: 366

/* begin block 2 */
// Start line: 749
/* end block 2 */
// End Line: 750

/* begin block 3 */
// Start line: 750
/* end block 3 */
// End Line: 751

/* begin block 4 */
// Start line: 753
/* end block 4 */
// End Line: 754

void sfxCmdStopTone(AadSfxCommand *sfxCmd)

{
  AadMemoryStruct *pAVar1;
  uint uVar2;
  AadSynthVoice *pAVar3;
  uint uVar4;
  ushort uVar5;
  ulong uVar6;

  uVar2 = 0;
  uVar6 = sfxCmd->ulongParam;
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
    uVar4 = (uint)uVar5;
  } while (uVar5 < 0x18);
  aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | uVar2;
  pAVar1->voiceKeyOnRequest = pAVar1->voiceKeyOnRequest & ~uVar2;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ sfxCmdStopAllTones(struct AadSfxCommand *sfxCmd /*$a0*/)
// line 372, offset 0x800570f0
/* begin block 1 */
// Start line: 374
// Start offset: 0x800570F0
// Variables:
// 		struct AadSynthVoice *voice; // $a0
// 		unsigned long vmask; // $v1
// 		unsigned short i; // $a3
/* end block 1 */
// End offset: 0x80057168
// End Line: 393

/* begin block 2 */
// Start line: 816
/* end block 2 */
// End Line: 817

/* begin block 3 */
// Start line: 817
/* end block 3 */
// End Line: 818

/* begin block 4 */
// Start line: 821
/* end block 4 */
// End Line: 822

void sfxCmdStopAllTones(AadSfxCommand *sfxCmd)

{
  AadMemoryStruct *pAVar1;
  uint uVar2;
  AadSynthVoice *pAVar3;
  uint uVar4;
  ushort uVar5;

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
    uVar4 = (uint)uVar5;
  } while (uVar5 < 0x18);
  aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | uVar2;
  pAVar1->voiceKeyOnRequest = pAVar1->voiceKeyOnRequest & ~uVar2;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ sfxCmdSetToneVolumeAndPan(struct AadSfxCommand *sfxCmd /*$a0*/)
// line 399, offset 0x80057194
/* begin block 1 */
// Start line: 400
// Start offset: 0x80057194
// Variables:
// 		unsigned long handle; // $a3
// 		struct AadSynthVoice *voice; // $t0
// 		unsigned short i; // $t1
// 		struct AadVolume newVoiceVol; // stack offset -16

/* begin block 1.1 */
// Start line: 418
// Start offset: 0x80057248
// Variables:
// 		unsigned long tmp; // $v0
/* end block 1.1 */
// End offset: 0x80057248
// End Line: 418

/* begin block 1.2 */
// Start line: 419
// Start offset: 0x800572B0
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.2 */
// End offset: 0x800572B0
// End Line: 419

/* begin block 1.3 */
// Start line: 420
// Start offset: 0x80057330
// Variables:
// 		unsigned long tmp; // $v0
/* end block 1.3 */
// End offset: 0x80057330
// End Line: 420

/* begin block 1.4 */
// Start line: 421
// Start offset: 0x8005739C
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.4 */
// End offset: 0x8005739C
// End Line: 421

/* begin block 1.5 */
// Start line: 421
// Start offset: 0x8005739C
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.5 */
// End offset: 0x8005739C
// End Line: 421

/* begin block 1.6 */
// Start line: 421
// Start offset: 0x8005739C
// Variables:
// 		unsigned long masterVolumeSquared; // $v0
/* end block 1.6 */
// End offset: 0x8005739C
// End Line: 421

/* begin block 1.7 */
// Start line: 421
// Start offset: 0x8005739C
// Variables:
// 		unsigned long masterVolumeSquared; // $v0
/* end block 1.7 */
// End offset: 0x8005739C
// End Line: 421
/* end block 1 */
// End offset: 0x800574F8
// End Line: 436

/* begin block 2 */
// Start line: 881
/* end block 2 */
// End Line: 882

void sfxCmdSetToneVolumeAndPan(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  AadSynthVoice *pAVar7;
  ushort uVar8;
  short local_10;
  short local_e;

  uVar8 = 0;
  uVar6 = 0;
  while ((((pAVar7 = aadMem->synthVoice + uVar6, pAVar7->voiceID != -0x30 ||
                                                     (pAVar7->handle != sfxCmd->ulongParam)) ||
           (aadMem->voiceStatus[uVar6] == '\0')) ||
          (aadMem->voiceStatus[uVar6] == '\x02')))
  {
    uVar8 = uVar8 + 1;
    uVar6 = (uint)uVar8;
    if (0x17 < uVar8)
    {
      return;
    }
  }
  local_10 = (ushort)pAVar7->volume * (ushort)pAVar7->volume;
  local_e = (ushort)pAVar7->volume * (ushort)pAVar7->volume;
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = sfxCmd->dataByte[1];
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        iVar2 = (uint)sfxCmd->dataByte[1] + 1;
        local_e = (short)((int)local_10 * (iVar2 * iVar2 + 1) >> 0xc);
      }
    }
    else
    {
      local_10 = (short)((int)local_e * ((0x80 - (uint)bVar1) * (0x80 - (uint)bVar1) + -1) >> 0xc);
    }
  }
  iVar2 = (uint)pAVar7->toneAtr->volume + 1;
  iVar2 = iVar2 * iVar2 + -1;
  local_10 = (short)((uint)((int)local_10 * iVar2) >> 0xe);
  local_e = (short)((uint)((int)local_e * iVar2) >> 0xe);
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = pAVar7->toneAtr->panPosition;
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        iVar2 = (uint)pAVar7->toneAtr->panPosition + 1;
        local_e = (short)((int)local_10 * (iVar2 * iVar2 + 1) >> 0xc);
      }
    }
    else
    {
      local_10 = (short)((int)local_e * ((0x80 - (uint)bVar1) * (0x80 - (uint)bVar1) + -1) >> 0xc);
    }
  }
  iVar2 = (uint)sfxCmd->dataByte[0] + 1;
  iVar4 = iVar2 * iVar2 + -1;
  pAVar7->updateVol = sfxCmd->dataByte[0];
  iVar2 = (uint)pAVar7->progAtr->volume + 1;
  iVar5 = iVar2 * iVar2 + -1;
  iVar2 = (uint)(aadMem->sfxSlot).sfxVolume + 1;
  iVar2 = iVar2 * iVar2 + -1;
  iVar3 = aadMem->sfxMasterVol + 1;
  iVar3 = iVar3 * iVar3 + -1;
  SpuSetVoiceVolume((uint)uVar8,
                    (int)(short)((uint)((int)(short)((uint)((int)(short)((uint)((int)(short)((uint)(
                                                                                                 (int)local_10 * iVar4) >>
                                                                                             0xe) *
                                                                                iVar5) >>
                                                                         0xe) *
                                                            iVar2) >>
                                                     0xe) *
                                        iVar3) >>
                                 0xe),
                    (int)(short)((uint)((int)(short)((uint)((int)(short)((uint)((int)(short)((uint)(
                                                                                                 (int)local_e * iVar4) >>
                                                                                             0xe) *
                                                                                iVar5) >>
                                                                         0xe) *
                                                            iVar2) >>
                                                     0xe) *
                                        iVar3) >>
                                 0xe));
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ sfxCmdSetToneVolPanPitch(struct AadSfxCommand *sfxCmd /*$s2*/)
// line 439, offset 0x80057508
/* begin block 1 */
// Start line: 440
// Start offset: 0x80057508
// Variables:
// 		unsigned long handle; // $a2
// 		struct AadSynthVoice *voice; // $s0
// 		unsigned short i; // $s1
// 		struct AadVolume newVoiceVol; // stack offset -24
// 		unsigned short newPitch; // $a1
// 		unsigned short finePitch; // $a1
// 		unsigned short pitchIndex; // $a0

/* begin block 1.1 */
// Start line: 459
// Start offset: 0x800575CC
// Variables:
// 		unsigned long tmp; // $v0
/* end block 1.1 */
// End offset: 0x800575CC
// End Line: 459

/* begin block 1.2 */
// Start line: 460
// Start offset: 0x80057634
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.2 */
// End offset: 0x80057634
// End Line: 460

/* begin block 1.3 */
// Start line: 461
// Start offset: 0x800576B4
// Variables:
// 		unsigned long tmp; // $v0
/* end block 1.3 */
// End offset: 0x800576B4
// End Line: 461

/* begin block 1.4 */
// Start line: 462
// Start offset: 0x80057720
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.4 */
// End offset: 0x80057720
// End Line: 462

/* begin block 1.5 */
// Start line: 462
// Start offset: 0x80057720
// Variables:
// 		unsigned long masterVolumeSquared; // $v1
/* end block 1.5 */
// End offset: 0x80057720
// End Line: 462

/* begin block 1.6 */
// Start line: 462
// Start offset: 0x80057720
// Variables:
// 		unsigned long masterVolumeSquared; // $v0
/* end block 1.6 */
// End offset: 0x80057720
// End Line: 462

/* begin block 1.7 */
// Start line: 462
// Start offset: 0x80057720
// Variables:
// 		unsigned long masterVolumeSquared; // $v0
/* end block 1.7 */
// End offset: 0x80057720
// End Line: 462
/* end block 1 */
// End offset: 0x8005795C
// End Line: 494

/* begin block 2 */
// Start line: 999
/* end block 2 */
// End Line: 1000

void sfxCmdSetToneVolPanPitch(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  AadToneAtr *pAVar8;
  AadSynthVoice *pAVar9;
  ushort uVar10;
  short local_18;
  short local_16;

  uVar10 = 0;
  uVar6 = 0;
  while ((((pAVar9 = aadMem->synthVoice + uVar6, pAVar9->voiceID != -0x30 ||
                                                     (pAVar9->handle != sfxCmd->ulongParam)) ||
           (aadMem->voiceStatus[uVar6] == '\0')) ||
          (aadMem->voiceStatus[uVar6] == '\x02')))
  {
    uVar10 = uVar10 + 1;
    uVar6 = (uint)uVar10;
    if (0x17 < uVar10)
    {
      return;
    }
  }
  local_18 = (ushort)pAVar9->volume * (ushort)pAVar9->volume;
  local_16 = (ushort)pAVar9->volume * (ushort)pAVar9->volume;
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = sfxCmd->dataByte[1];
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        iVar2 = (uint)sfxCmd->dataByte[1] + 1;
        local_16 = (short)((int)local_18 * (iVar2 * iVar2 + 1) >> 0xc);
      }
    }
    else
    {
      local_18 = (short)((int)local_16 * ((0x80 - (uint)bVar1) * (0x80 - (uint)bVar1) + -1) >> 0xc);
    }
  }
  iVar2 = (uint)pAVar9->toneAtr->volume + 1;
  iVar2 = iVar2 * iVar2 + -1;
  local_18 = (short)((uint)((int)local_18 * iVar2) >> 0xe);
  local_16 = (short)((uint)((int)local_16 * iVar2) >> 0xe);
  if ((aadMem->flags & 1U) == 0)
  {
    bVar1 = pAVar9->toneAtr->panPosition;
    if (bVar1 < 0x41)
    {
      if (bVar1 < 0x3f)
      {
        iVar2 = (uint)pAVar9->toneAtr->panPosition + 1;
        local_16 = (short)((int)local_18 * (iVar2 * iVar2 + 1) >> 0xc);
      }
    }
    else
    {
      local_18 = (short)((int)local_16 * ((0x80 - (uint)bVar1) * (0x80 - (uint)bVar1) + -1) >> 0xc);
    }
  }
  iVar2 = (uint)sfxCmd->dataByte[0] + 1;
  iVar4 = iVar2 * iVar2 + -1;
  pAVar9->updateVol = sfxCmd->dataByte[0];
  iVar2 = (uint)pAVar9->progAtr->volume + 1;
  iVar5 = iVar2 * iVar2 + -1;
  iVar2 = (uint)(aadMem->sfxSlot).sfxVolume + 1;
  iVar2 = iVar2 * iVar2 + -1;
  iVar3 = aadMem->sfxMasterVol + 1;
  iVar3 = iVar3 * iVar3 + -1;
  SpuSetVoiceVolume((uint)uVar10,
                    (int)(short)((uint)((int)(short)((uint)((int)(short)((uint)((int)(short)((uint)(
                                                                                                 (int)local_18 * iVar4) >>
                                                                                             0xe) *
                                                                                iVar5) >>
                                                                         0xe) *
                                                            iVar2) >>
                                                     0xe) *
                                        iVar3) >>
                                 0xe),
                    (int)(short)((uint)((int)(short)((uint)((int)(short)((uint)((int)(short)((uint)(
                                                                                                 (int)local_16 * iVar4) >>
                                                                                             0xe) *
                                                                                iVar5) >>
                                                                         0xe) *
                                                            iVar2) >>
                                                     0xe) *
                                        iVar3) >>
                                 0xe));
  pAVar8 = pAVar9->toneAtr;
  uVar6 = (uint)pAVar9->note - ((uint)pAVar8->centerNote - 0x3c);
  if ((pAVar8->centerFine & 0x80U) == 0)
  {
    uVar6 = uVar6 & 0xffff;
    sVar7 = aadPitchTable[uVar6] +
            (ushort)(aadStepsPerCent[uVar6] * 100 * (uint)(byte)pAVar8->centerFine >> 0x17);
  }
  else
  {
    uVar6 = uVar6 & 0xffff;
    sVar7 = aadPitchTable[uVar6] -
            (ushort)(aadStepsPerCent[uVar6] * 100 *
                         (0x100 - (uint)(byte)pAVar8->centerFine & 0xffff) >>
                     0x17);
  }
  SpuSetVoicePitch((uint)uVar10, sVar7 + sfxCmd->shortParam);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ sfxCmdLockVoice(struct AadSfxCommand *sfxCmd /*$a0*/)
// line 498, offset 0x80057974
/* begin block 1 */
// Start line: 499
// Start offset: 0x80057974
// Variables:
// 		void (*callbackProc)(); // $s0
// 		struct AadSynthVoice *voice; // $v1
/* end block 1 */
// End offset: 0x800579B0
// End Line: 513

/* begin block 2 */
// Start line: 1183
/* end block 2 */
// End Line: 1184

void sfxCmdLockVoice(AadSfxCommand *sfxCmd)

{
  AadSynthVoice *pAVar1;
  ulong uVar2;
  code *pcVar3;

  pcVar3 = (code *)sfxCmd->ulongParam;
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

// decompiled code
// original method signature:
// void /*$ra*/ sfxCmdSetVoiceAttr(struct AadSfxCommand *sfxCmd /*$a0*/)
// line 516, offset 0x800579c0
/* begin block 1 */
// Start line: 517
// Start offset: 0x800579C0
// Variables:
// 		unsigned long v; // $s0
// 		unsigned long vmask; // $v1
// 		struct SpuVoiceAttr *voiceAttr; // $s1
/* end block 1 */
// End offset: 0x80057A00
// End Line: 528

/* begin block 2 */
// Start line: 1220
/* end block 2 */
// End Line: 1221

void sfxCmdSetVoiceAttr(AadSfxCommand *sfxCmd)

{
  uint uVar1;
  uint vNum;
  uint *puVar2;

  vNum = 0;
  puVar2 = (uint *)sfxCmd->ulongParam;
  uVar1 = 1;
  do
  {
    if ((uVar1 & *puVar2) != 0)
      break;
    vNum = vNum + 1;
    uVar1 = uVar1 << 1;
  } while (vNum < 0x18);
  SpuSetVoiceVolume(vNum, (int)*(short *)(puVar2 + 2), (int)*(short *)((int)puVar2 + 10));
  SpuSetVoicePitch(vNum, *(undefined2 *)(puVar2 + 5));
  SpuSetVoiceStartAddr(vNum, puVar2[7]);
  SpuSetVoiceADSR1ADSR2(vNum, *(ushort *)((int)puVar2 + 0x3a), *(ushort *)(puVar2 + 0xf));
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ sfxCmdSetVoiceKeyOn(struct AadSfxCommand *sfxCmd /*$a0*/)
// line 535, offset 0x80057a4c
/* begin block 1 */
// Start line: 1265
/* end block 1 */
// End Line: 1266

/* begin block 2 */
// Start line: 1266
/* end block 2 */
// End Line: 1267

void sfxCmdSetVoiceKeyOn(AadSfxCommand *sfxCmd)

{
  aadMem->voiceKeyOnRequest = aadMem->voiceKeyOnRequest | sfxCmd->ulongParam;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ sfxCmdSetVoiceKeyOff(struct AadSfxCommand *sfxCmd /*$a0*/)
// line 541, offset 0x80057a68
/* begin block 1 */
// Start line: 1277
/* end block 1 */
// End Line: 1278

/* begin block 2 */
// Start line: 1278
/* end block 2 */
// End Line: 1279

void sfxCmdSetVoiceKeyOff(AadSfxCommand *sfxCmd)

{
  AadMemoryStruct *pAVar1;

  pAVar1 = aadMem;
  aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | sfxCmd->ulongParam;
  pAVar1->voiceKeyOnRequest = pAVar1->voiceKeyOnRequest & ~sfxCmd->ulongParam;
  return;
}
