#include "THISDUST.H"
#include "AADVOICE.H"


// decompiled code
// original method signature: 
// struct AadSynthVoice * /*$ra*/ aadAllocateVoice(int priority /*$a0*/)
 // line 28, offset 0x800590a0
	/* begin block 1 */
		// Start line: 30
		// Start offset: 0x800590A0
		// Variables:
	// 		int i; // $a2
	// 		int lowestPriSus; // $t2
	// 		int lowestPriRel; // $t1
	// 		struct AadSynthVoice *lowestPriSusVoice; // $t4
	// 		struct AadSynthVoice *lowestPriRelVoice; // $t3
	// 		struct AadSynthVoice *voice; // $a1
	/* end block 1 */
	// End offset: 0x8005918C
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

AadSynthVoice * aadAllocateVoice(int priority)

{
  ushort uVar1;
  int iVar2;
  AadSynthVoice *pAVar3;
  uint uVar4;
  uint uVar5;
  AadSynthVoice *pAVar6;
  AadSynthVoice *pAVar7;
  
  uVar4 = 0x7fff;
  uVar5 = 0x7fff;
  pAVar6 = (AadSynthVoice *)0x0;
  pAVar7 = (AadSynthVoice *)0x0;
  iVar2 = 0;
  pAVar3 = (AadSynthVoice *)0x1c4;
  do {
    if ((pAVar3->flags & 1) == 0) {
      if (*(char *)(iVar2 + 0x464) == '\0') {
        *(undefined *)(iVar2 + 0x464) = 1;
        uVar1 = pAVar3->flags;
        goto LAB_80059150;
      }
      if (*(char *)(iVar2 + 0x464) == '\x02') {
        if ((uint)pAVar3->priority < uVar4) {
          uVar4 = (uint)pAVar3->priority;
          pAVar6 = pAVar3;
        }
      }
      else {
        if ((uint)pAVar3->priority < uVar5) {
          uVar5 = (uint)pAVar3->priority;
          pAVar7 = pAVar3;
        }
      }
    }
    iVar2 = iVar2 + 1;
    pAVar3 = pAVar3 + 1;
  } while (iVar2 < 0x18);
  if (priority < (int)uVar4) {
    if (priority < (int)uVar5) {
      return (AadSynthVoice *)0x0;
    }
    pAVar7->flags = pAVar7->flags | 2;
    return pAVar7;
  }
  uVar1 = pAVar6->flags;
  pAVar3 = pAVar6;
LAB_80059150:
  pAVar3->flags = uVar1 | 2;
  return pAVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SpuSetVoiceADSR1ADSR2(int vNum /*$a0*/, unsigned short adsr1 /*$a1*/, unsigned short adsr2 /*$a3*/)
 // line 109, offset 0x80059194
	/* begin block 1 */
		// Start line: 110
		// Start offset: 0x80059194
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
	// End offset: 0x8005920C
	// End Line: 133

	/* begin block 2 */
		// Start line: 291
	/* end block 2 */
	// End Line: 292

void SpuSetVoiceADSR1ADSR2(int vNum,ushort adsr1,ushort adsr2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  if ((adsr1 & 0x8000) != 0) {
    iVar3 = 5;
  }
  iVar2 = 3;
  if ((adsr2 & 0x20) != 0) {
    iVar2 = 7;
  }
  if ((adsr2 & 0x4000) == 0) {
    iVar1 = 1;
    if ((adsr2 & 0x8000) != 0) {
      iVar1 = 5;
    }
  }
  else {
    iVar1 = 3;
    if ((adsr2 & 0x8000) != 0) {
      iVar1 = 7;
    }
  }
  SpuSetVoiceADSRAttr(vNum,(uint)(adsr1 >> 8) & 0x7f,(uint)(adsr1 >> 4) & 0xf,
                      ((uint)adsr2 & 0x1fc0) >> 6,(uint)adsr2 & 0x1f,(uint)adsr1 & 0xf,iVar3,iVar1,
                      iVar2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPlayTone(struct AadToneAtr *toneAtr /*$s0*/, unsigned long waveStartAddr /*$s3*/, struct AadProgramAtr *progAtr /*$a2*/, int midiNote /*$s2*/, int volume /*stack 16*/, int masterVolume /*stack 20*/, int masterPan /*stack 24*/, int slotVolume /*stack 28*/, int masterMasterVol /*stack 32*/, struct AadSynthVoice *voice /*stack 36*/, int pitchOffset /*stack 40*/)
 // line 156, offset 0x8005923c
	/* begin block 1 */
		// Start line: 157
		// Start offset: 0x8005923C
		// Variables:
	// 		struct AadVolume voiceVol; // stack offset -32
	// 		int pitch; // $a1
	// 		int finePitch; // $a1
	// 		int pitchIndex; // $a3

		/* begin block 1.1 */
			// Start line: 167
			// Start offset: 0x800592A8
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.1 */
		// End offset: 0x800592A8
		// End Line: 167

		/* begin block 1.2 */
			// Start line: 168
			// Start offset: 0x80059308
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.2 */
		// End offset: 0x80059308
		// End Line: 168

		/* begin block 1.3 */
			// Start line: 169
			// Start offset: 0x80059374
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.3 */
		// End offset: 0x80059374
		// End Line: 169

		/* begin block 1.4 */
			// Start line: 171
			// Start offset: 0x800593DC
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.4 */
		// End offset: 0x800593DC
		// End Line: 171

		/* begin block 1.5 */
			// Start line: 171
			// Start offset: 0x800593DC
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.5 */
		// End offset: 0x800593DC
		// End Line: 171

		/* begin block 1.6 */
			// Start line: 171
			// Start offset: 0x800593DC
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.6 */
		// End offset: 0x800593DC
		// End Line: 171

		/* begin block 1.7 */
			// Start line: 171
			// Start offset: 0x800593DC
			// Variables:
		// 		unsigned long masterVolumeSquared; // $a0
		/* end block 1.7 */
		// End offset: 0x800593DC
		// End Line: 171
	/* end block 1 */
	// End offset: 0x80059628
	// End Line: 206

	/* begin block 2 */
		// Start line: 392
	/* end block 2 */
	// End Line: 393

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadPlayTone(AadToneAtr *toneAtr,ulong waveStartAddr,AadProgramAtr *progAtr,int midiNote,
                int volume,int masterVolume,int masterPan,int slotVolume,int masterMasterVol,
                AadSynthVoice *voice,int pitchOffset)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  short local_20;
  short local_1e;
  
  local_20 = (short)volume * (short)volume;
  local_1e = local_20;
  if ((_DAT_00000012 & 1) == 0) {
    if (masterPan < 0x41) {
      if (masterPan < 0x3f) {
        local_1e = (short)(local_20 * masterPan * masterPan >> 0xc);
      }
    }
    else {
      local_20 = (short)((uint)((int)local_20 * (0x7f - masterPan) * (0x7f - masterPan)) >> 0xc);
    }
  }
  iVar3 = (uint)toneAtr->volume * (uint)toneAtr->volume;
  local_20 = (short)((uint)(local_20 * iVar3) >> 0xe);
  local_1e = (short)((uint)(local_1e * iVar3) >> 0xe);
  if ((_DAT_00000012 & 1) == 0) {
    bVar1 = toneAtr->panPosition;
    if (bVar1 < 0x41) {
      if (bVar1 < 0x3f) {
        local_1e = (short)((int)((int)local_20 * (uint)toneAtr->panPosition *
                                (uint)toneAtr->panPosition) >> 0xc);
      }
    }
    else {
      local_20 = (short)((int)local_1e * (0x7f - (uint)bVar1) * (0x7f - (uint)bVar1) >> 0xc);
    }
  }
  iVar3 = (uint)progAtr->volume * (uint)progAtr->volume;
  SpuSetVoiceVolume((uint)voice->voiceNum,
                    (int)(short)((uint)((int)(short)((uint)((int)(short)((uint)((short)((uint)((int)
                                                  local_20 * masterVolume * masterVolume) >> 0xe) *
                                                  iVar3) >> 0xe) * slotVolume * slotVolume) >> 0xe)
                                       * masterMasterVol * masterMasterVol) >> 0xe),
                    (int)(short)((uint)((int)(short)((uint)((int)(short)((uint)((short)((uint)((int)
                                                  local_1e * masterVolume * masterVolume) >> 0xe) *
                                                  iVar3) >> 0xe) * slotVolume * slotVolume) >> 0xe)
                                       * masterMasterVol * masterMasterVol) >> 0xe));
  midiNote = midiNote - ((uint)toneAtr->centerNote - 0x3c);
  if ((toneAtr->centerFine & 0x80U) == 0) {
    sVar2 = (&aadPitchTable)[midiNote] +
            (ushort)((&aadStepsPerCent)[midiNote] * 100 * (uint)(byte)toneAtr->centerFine >> 0x17);
  }
  else {
    sVar2 = (&aadPitchTable)[midiNote] -
            (ushort)((&aadStepsPerCent)[midiNote] * 100 * (0x100 - (uint)(byte)toneAtr->centerFine)
                    >> 0x17);
  }
  SpuSetVoicePitch((uint)voice->voiceNum,sVar2 + (short)pitchOffset);
  SpuSetVoiceStartAddr((uint)voice->voiceNum,waveStartAddr);
  SpuSetVoiceADSR1ADSR2((uint)voice->voiceNum,toneAtr->adsr1,toneAtr->adsr2);
  if (toneAtr->mode == '\x04') {
    uRam000004b4 = uRam000004b4 | voice->voiceMask;
  }
  else {
    uRam000004b4 = uRam000004b4 & ~voice->voiceMask;
  }
  uRam000004b0 = uRam000004b0 | voice->voiceMask;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPlayTonePitchBend(struct AadToneAtr *toneAtr /*$s0*/, unsigned long waveStartAddr /*$s4*/, struct AadProgramAtr *progAtr /*$a2*/, int midiNote /*$s3*/, int volume /*stack 16*/, int masterVolume /*stack 20*/, int masterPan /*stack 24*/, int slotVolume /*stack 28*/, int masterMasterVol /*stack 32*/, struct AadSynthVoice *voice /*stack 36*/, int pitchWheelPos /*stack 40*/)
 // line 247, offset 0x8005965c
	/* begin block 1 */
		// Start line: 248
		// Start offset: 0x8005965C
		// Variables:
	// 		struct AadVolume voiceVol; // stack offset -32
	// 		int pitch; // $a1
	// 		int finePitch; // $a1
	// 		int pitchIndex; // $a3
	// 		long pitchValueBendAmount; // $t0

		/* begin block 1.1 */
			// Start line: 260
			// Start offset: 0x800596D0
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.1 */
		// End offset: 0x800596D0
		// End Line: 260

		/* begin block 1.2 */
			// Start line: 261
			// Start offset: 0x80059730
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.2 */
		// End offset: 0x80059730
		// End Line: 261

		/* begin block 1.3 */
			// Start line: 262
			// Start offset: 0x8005979C
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.3 */
		// End offset: 0x8005979C
		// End Line: 262

		/* begin block 1.4 */
			// Start line: 264
			// Start offset: 0x80059804
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.4 */
		// End offset: 0x80059804
		// End Line: 264

		/* begin block 1.5 */
			// Start line: 264
			// Start offset: 0x80059804
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.5 */
		// End offset: 0x80059804
		// End Line: 264

		/* begin block 1.6 */
			// Start line: 264
			// Start offset: 0x80059804
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.6 */
		// End offset: 0x80059804
		// End Line: 264

		/* begin block 1.7 */
			// Start line: 264
			// Start offset: 0x80059804
			// Variables:
		// 		unsigned long masterVolumeSquared; // $a0
		/* end block 1.7 */
		// End offset: 0x80059804
		// End Line: 264
	/* end block 1 */
	// End offset: 0x80059A98
	// End Line: 315

	/* begin block 2 */
		// Start line: 607
	/* end block 2 */
	// End Line: 608

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadPlayTonePitchBend
               (AadToneAtr *toneAtr,ulong waveStartAddr,AadProgramAtr *progAtr,int midiNote,
               int volume,int masterVolume,int masterPan,int slotVolume,int masterMasterVol,
               AadSynthVoice *voice,int pitchWheelPos)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short local_20;
  short local_1e;
  
  local_20 = (short)volume * (short)volume;
  local_1e = local_20;
  if ((_DAT_00000012 & 1) == 0) {
    if (masterPan < 0x41) {
      if (masterPan < 0x3f) {
        local_1e = (short)(local_20 * masterPan * masterPan >> 0xc);
      }
    }
    else {
      local_20 = (short)((uint)((int)local_20 * (0x7f - masterPan) * (0x7f - masterPan)) >> 0xc);
    }
  }
  iVar3 = (uint)toneAtr->volume * (uint)toneAtr->volume;
  local_20 = (short)((uint)(local_20 * iVar3) >> 0xe);
  local_1e = (short)((uint)(local_1e * iVar3) >> 0xe);
  if ((_DAT_00000012 & 1) == 0) {
    bVar1 = toneAtr->panPosition;
    if (bVar1 < 0x41) {
      if (bVar1 < 0x3f) {
        local_1e = (short)((int)((int)local_20 * (uint)toneAtr->panPosition *
                                (uint)toneAtr->panPosition) >> 0xc);
      }
    }
    else {
      local_20 = (short)((int)local_1e * (0x7f - (uint)bVar1) * (0x7f - (uint)bVar1) >> 0xc);
    }
  }
  iVar3 = (uint)progAtr->volume * (uint)progAtr->volume;
  SpuSetVoiceVolume((uint)voice->voiceNum,
                    (int)(short)((uint)((int)(short)((uint)((int)(short)((uint)((short)((uint)((int)
                                                  local_20 * masterVolume * masterVolume) >> 0xe) *
                                                  iVar3) >> 0xe) * slotVolume * slotVolume) >> 0xe)
                                       * masterMasterVol * masterMasterVol) >> 0xe),
                    (int)(short)((uint)((int)(short)((uint)((int)(short)((uint)((short)((uint)((int)
                                                  local_1e * masterVolume * masterVolume) >> 0xe) *
                                                  iVar3) >> 0xe) * slotVolume * slotVolume) >> 0xe)
                                       * masterMasterVol * masterMasterVol) >> 0xe));
  iVar4 = 0x2000 / (int)(uint)toneAtr->pitchBendMax;
  iVar3 = (midiNote - ((uint)toneAtr->centerNote - 0x3c)) + (pitchWheelPos + -0x2000) / iVar4;
  if ((toneAtr->centerFine & 0x80U) == 0) {
    sVar2 = (&aadPitchTable)[iVar3] +
            (ushort)((&aadStepsPerCent)[iVar3] * 100 * (uint)(byte)toneAtr->centerFine >> 0x17);
  }
  else {
    sVar2 = (&aadPitchTable)[iVar3] -
            (ushort)((&aadStepsPerCent)[iVar3] * 100 * (0x100 - (uint)(byte)toneAtr->centerFine) >>
                    0x17);
  }
  SpuSetVoicePitch((uint)voice->voiceNum,
                   sVar2 + (short)(((int)(&aadStepsPerSemitone)[iVar3] *
                                   ((pitchWheelPos + -0x2000) % iVar4)) / iVar4));
  SpuSetVoiceStartAddr((uint)voice->voiceNum,waveStartAddr);
  SpuSetVoiceADSR1ADSR2((uint)voice->voiceNum,toneAtr->adsr1,toneAtr->adsr2);
  if (toneAtr->mode == '\x04') {
    uRam000004b4 = uRam000004b4 | voice->voiceMask;
  }
  else {
    uRam000004b4 = uRam000004b4 & ~voice->voiceMask;
  }
  uRam000004b0 = uRam000004b0 | voice->voiceMask;
  return;
}





