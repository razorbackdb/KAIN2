#include "THISDUST.H"
#include "AADSEQEV.H"


// autogenerated function stub: 
// int /*$ra*/ aadQueueNextEvent(struct _AadSequenceSlot *slot /*$t0*/, int track /*$a1*/)
int aadQueueNextEvent(struct _AadSequenceSlot *slot, int track)
{ // line 24, offset 0x80054e18
	/* begin block 1 */
		// Start line: 25
		// Start offset: 0x80054E18
		// Variables:
			struct AadSeqEvent seqEvent; // stack offset -16
			unsigned char *seqData; // $a2
			unsigned long deltaTime; // $v1
			int c; // $a0
			int n; // $a3
			int i; // $a0
	/* end block 1 */
	// End offset: 0x80055004
	// End Line: 99

	/* begin block 2 */
		// Start line: 48
	/* end block 2 */
	// End Line: 49

	return 0;
}


// decompiled code
// original method signature: 
// void /*$ra*/ aadExecuteEvent(struct AadSeqEvent *event /*$s0*/, struct _AadSequenceSlot *slot /*$s1*/)
 // line 103, offset 0x8005500c
	/* begin block 1 */
		// Start line: 104
		// Start offset: 0x8005500C
		// Variables:
	// 		int eventType; // $v1
	/* end block 1 */
	// End offset: 0x80055090
	// End Line: 123

	/* begin block 2 */
		// Start line: 210
	/* end block 2 */
	// End Line: 211

void aadExecuteEvent(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  code *pcVar1;
  
  if ((event->statusByte & 0x80) == 0) {
    aadSubstituteVariables(event,slot);
    if (0x4d < event->statusByte) {
      return;
    }
    pcVar1 = (code *)(&midiMetaEventFunction)[(uint)event->statusByte & 0x7f];
  }
  else {
    pcVar1 = *(code **)((int)&midiEventFunction + ((uint)(event->statusByte >> 2) & 0x1c));
  }
  (*pcVar1)(event,slot);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiNoteOff(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 127, offset 0x800550a4
	/* begin block 1 */
		// Start line: 258
	/* end block 1 */
	// End Line: 259

	/* begin block 2 */
		// Start line: 262
	/* end block 2 */
	// End Line: 263

void midiNoteOff(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiNoteOn(struct AadSeqEvent *event /*$fp*/, struct _AadSequenceSlot *slot /*$s5*/)
 // line 139, offset 0x800550ac
	/* begin block 1 */
		// Start line: 140
		// Start offset: 0x800550AC
		// Variables:
	// 		struct AadProgramAtr *progAtr; // $s4
	// 		struct AadToneAtr *toneAtrTbl; // $v1
	// 		struct AadSynthVoice *voice; // $s0
	// 		int channel; // $s7
	// 		int midiNote; // $s6
	// 		int transposedNote; // stack offset -56
	// 		int t; // $s2
	// 		int dynBank; // stack offset -52

		/* begin block 1.1 */
			// Start line: 220
			// Start offset: 0x8005528C
			// Variables:
		// 		unsigned long waveStartAddr; // $a1
		/* end block 1.1 */
		// End offset: 0x800553D4
		// End Line: 245
	/* end block 1 */
	// End offset: 0x800553F0
	// End Line: 249

	/* begin block 2 */
		// Start line: 282
	/* end block 2 */
	// End Line: 283

void midiNoteOn(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  byte bVar2;
  uchar uVar3;
  AadMemoryStruct *pAVar4;
  ulong *puVar5;
  AadSynthVoice *voice;
  ulong *puVar6;
  int iVar7;
  uint *puVar8;
  AadToneAtr *toneAtr;
  int iVar9;
  uint uVar10;
  AadProgramAtr *progAtr;
  uint uVar11;
  uint uVar12;
  uint local_38;
  
  uVar12 = (uint)event->statusByte & 0xf;
  iVar7 = (int)&(slot->tempo).currentTick + uVar12;
  if ((((int)(uint)slot->channelMute >> uVar12 & 1U) == 0) && (*(char *)(iVar7 + 0x590) != -1)) {
    bVar1 = event->dataByte[0];
    uVar11 = (uint)bVar1;
    iVar9 = 0;
    if (event->dataByte[1] == '\0') {
      iVar7 = 0x1dc;
      do {
        pAVar4 = aadMem;
        puVar8 = (uint *)((int)&aadMem->updateCounter + iVar7);
        if ((((uint)*(byte *)(puVar8 + 2) == (slot->slotID | uVar12)) &&
            ((uint)*(byte *)((int)puVar8 + 10) == uVar11)) &&
           ((aadMem->voiceStatus[iVar9] != '\0' && (aadMem->voiceStatus[iVar9] != '\x02')))) {
          aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | *puVar8;
          pAVar4->voiceKeyOnRequest = pAVar4->voiceKeyOnRequest & ~*puVar8;
          *(undefined *)(puVar8 + 2) = 0xff;
        }
        iVar9 = iVar9 + 1;
        iVar7 = iVar7 + 0x1c;
      } while (iVar9 < 0x18);
    }
    else {
      local_38 = uVar11;
      if (((int)(uint)slot->ignoreTranspose >> uVar12 & 1U) == 0) {
        local_38 = uVar11 + *(byte *)(iVar7 + 0x5c0) & 0xff;
      }
      iVar7 = (int)&(slot->tempo).currentTick + uVar12;
      bVar2 = *(byte *)(iVar7 + 0x560);
      puVar6 = &aadMem->updateCounter + bVar2;
      if (puVar6[0x140] == 2) {
        progAtr = (AadProgramAtr *)(puVar6[0x136] + (uint)*(byte *)(iVar7 + 0x590) * 8);
        uVar10 = (uint)progAtr->firstTone;
        if (uVar10 < uVar10 + progAtr->numTones) {
          puVar5 = (ulong *)((int)&(slot->tempo).currentTick + uVar12 * 2);
          toneAtr = (AadToneAtr *)(puVar6[0x138] + uVar10 * 0x10);
          do {
            if (((toneAtr->minNote <= uVar11) && (uVar11 <= toneAtr->maxNote)) &&
               (voice = aadAllocateVoice((uint)toneAtr->priority), voice != (AadSynthVoice *)0x0)) {
              if ((toneAtr->pitchBendMax == '\0') || (*(short *)(puVar5 + 0x15c) == 0x2000)) {
                aadPlayTone(toneAtr,*(ulong *)(aadMem->dynamicWaveAddr[bVar2] +
                                              (int)toneAtr->waveIndex * 4),progAtr,local_38,
                            (uint)(byte)event->dataByte[1],(uint)*(byte *)(iVar7 + 0x5a0),
                            (uint)*(byte *)(iVar7 + 0x5b0),(uint)slot->slotVolume,
                            *slot->masterVolPtr,voice,0);
                voice->handle = 0;
              }
              else {
                aadPlayTonePitchBend
                          (toneAtr,*(ulong *)(aadMem->dynamicWaveAddr[bVar2] +
                                             (int)toneAtr->waveIndex * 4),progAtr,local_38,
                           (uint)(byte)event->dataByte[1],(uint)*(byte *)(iVar7 + 0x5a0),
                           (uint)*(byte *)(iVar7 + 0x5b0),(uint)slot->slotVolume,*slot->masterVolPtr
                           ,voice,(uint)*(ushort *)(puVar5 + 0x15c));
                voice->handle = 0;
              }
              voice->voiceID = slot->slotID | (byte)uVar12;
              uVar3 = toneAtr->priority;
              voice->note = bVar1;
              voice->priority = uVar3;
              voice->program = *(uchar *)(iVar7 + 0x590);
              voice->volume = event->dataByte[1];
              voice->updateVol = *(uchar *)(iVar7 + 0x5a0);
              uVar3 = *(uchar *)(iVar7 + 0x5b0);
              voice->progAtr = progAtr;
              voice->toneAtr = toneAtr;
              voice->pan = uVar3;
            }
            uVar10 = uVar10 + 1;
            toneAtr = toneAtr + 1;
          } while ((int)uVar10 < (int)((uint)progAtr->firstTone + (uint)progAtr->numTones));
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadUpdateChannelVolPan(struct _AadSequenceSlot *slot /*$s4*/, int channel /*$s5*/)
 // line 253, offset 0x80055420
	/* begin block 1 */
		// Start line: 254
		// Start offset: 0x80055420
		// Variables:
	// 		struct AadSynthVoice *voice; // $s0
	// 		int i; // $s2
	// 		struct AadVolume newVoiceVol; // stack offset -40

		/* begin block 1.1 */
			// Start line: 267
			// Start offset: 0x800554C0
			// Variables:
		// 		unsigned long tmp; // $v0
		/* end block 1.1 */
		// End offset: 0x800554C0
		// End Line: 267

		/* begin block 1.2 */
			// Start line: 268
			// Start offset: 0x80055528
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.2 */
		// End offset: 0x80055528
		// End Line: 268

		/* begin block 1.3 */
			// Start line: 269
			// Start offset: 0x800555A8
			// Variables:
		// 		unsigned long tmp; // $v0
		/* end block 1.3 */
		// End offset: 0x800555A8
		// End Line: 269

		/* begin block 1.4 */
			// Start line: 270
			// Start offset: 0x80055614
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.4 */
		// End offset: 0x80055614
		// End Line: 270

		/* begin block 1.5 */
			// Start line: 270
			// Start offset: 0x80055614
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.5 */
		// End offset: 0x80055614
		// End Line: 270

		/* begin block 1.6 */
			// Start line: 270
			// Start offset: 0x80055614
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.6 */
		// End offset: 0x80055614
		// End Line: 270

		/* begin block 1.7 */
			// Start line: 270
			// Start offset: 0x80055614
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.7 */
		// End offset: 0x80055614
		// End Line: 270
	/* end block 1 */
	// End offset: 0x80055780
	// End Line: 282

	/* begin block 2 */
		// Start line: 583
	/* end block 2 */
	// End Line: 584

void aadUpdateChannelVolPan(_AadSequenceSlot *slot,int channel)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short local_28;
  short local_26;
  
  iVar8 = 0;
  iVar7 = (int)&(slot->tempo).currentTick + channel;
  iVar9 = 0x1dc;
  do {
    iVar6 = (int)&aadMem->updateCounter + iVar9;
    if ((uint)*(byte *)(iVar6 + 8) == ((uint)slot->slotID | channel)) {
      local_28 = (ushort)*(byte *)(iVar6 + 0xe) * (ushort)*(byte *)(iVar6 + 0xe);
      local_26 = (ushort)*(byte *)(iVar6 + 0xe) * (ushort)*(byte *)(iVar6 + 0xe);
      if ((aadMem->flags & 1U) == 0) {
        bVar1 = *(byte *)(iVar7 + 0x5b0);
        if (bVar1 < 0x41) {
          if (bVar1 < 0x3f) {
            iVar2 = (uint)*(byte *)(iVar7 + 0x5b0) + 1;
            local_26 = (short)((int)local_28 * (iVar2 * iVar2 + 1) >> 0xc);
          }
        }
        else {
          local_28 = (short)((int)local_26 * ((0x80 - (uint)bVar1) * (0x80 - (uint)bVar1) + -1) >>
                            0xc);
        }
      }
      iVar2 = (uint)*(byte *)(*(int *)(iVar6 + 0x14) + 2) + 1;
      iVar2 = iVar2 * iVar2 + -1;
      local_28 = (short)((uint)(local_28 * iVar2) >> 0xe);
      local_26 = (short)((uint)(local_26 * iVar2) >> 0xe);
      if ((aadMem->flags & 1U) == 0) {
        bVar1 = *(byte *)(*(int *)(iVar6 + 0x14) + 3);
        if (bVar1 < 0x41) {
          if (bVar1 < 0x3f) {
            iVar2 = (uint)*(byte *)(*(int *)(iVar6 + 0x14) + 3) + 1;
            local_26 = (short)((int)local_28 * (iVar2 * iVar2 + 1) >> 0xc);
          }
        }
        else {
          local_28 = (short)((int)local_26 * ((0x80 - (uint)bVar1) * (0x80 - (uint)bVar1) + -1) >>
                            0xc);
        }
      }
      iVar2 = (uint)*(byte *)(iVar7 + 0x5a0) + 1;
      iVar5 = iVar2 * iVar2 + -1;
      iVar2 = (uint)*(byte *)(*(int *)(iVar6 + 0x18) + 4) + 1;
      iVar2 = iVar2 * iVar2 + -1;
      iVar3 = (uint)slot->slotVolume + 1;
      iVar3 = iVar3 * iVar3 + -1;
      iVar4 = *slot->masterVolPtr + 1;
      iVar4 = iVar4 * iVar4 + -1;
      SpuSetVoiceVolume(iVar8,(int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(
                                                  local_28 * iVar5) >> 0xe) * iVar2) >> 0xe) * iVar3
                                                  ) >> 0xe) * iVar4) >> 0xe),
                        (int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_26 *
                                                                                        iVar5) >>
                                                                                 0xe) * iVar2) >>
                                                                  0xe) * iVar3) >> 0xe) * iVar4) >>
                                    0xe));
      *(undefined *)(iVar6 + 0xf) = *(undefined *)(iVar7 + 0x5a0);
      *(undefined *)(iVar6 + 0x10) = *(undefined *)(iVar7 + 0x5b0);
    }
    iVar8 = iVar8 + 1;
    iVar9 = iVar9 + 0x1c;
  } while (iVar8 < 0x18);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadUpdateSlotVolPan(struct _AadSequenceSlot *slot /*$s1*/)
 // line 286, offset 0x800557a4
	/* begin block 1 */
		// Start line: 287
		// Start offset: 0x800557A4
		// Variables:
	// 		struct AadSynthVoice *voice; // $t0
	// 		int channel; // $t1
	// 		int i; // $s0
	// 		struct AadVolume newVoiceVol; // stack offset -24

		/* begin block 1.1 */
			// Start line: 302
			// Start offset: 0x80055838
			// Variables:
		// 		unsigned long tmp; // $v0
		/* end block 1.1 */
		// End offset: 0x80055838
		// End Line: 302

		/* begin block 1.2 */
			// Start line: 303
			// Start offset: 0x800558A4
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.2 */
		// End offset: 0x800558A4
		// End Line: 303

		/* begin block 1.3 */
			// Start line: 304
			// Start offset: 0x80055924
			// Variables:
		// 		unsigned long tmp; // $v0
		/* end block 1.3 */
		// End offset: 0x80055924
		// End Line: 304

		/* begin block 1.4 */
			// Start line: 305
			// Start offset: 0x80055990
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.4 */
		// End offset: 0x80055990
		// End Line: 305

		/* begin block 1.5 */
			// Start line: 305
			// Start offset: 0x80055990
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.5 */
		// End offset: 0x80055990
		// End Line: 305

		/* begin block 1.6 */
			// Start line: 305
			// Start offset: 0x80055990
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.6 */
		// End offset: 0x80055990
		// End Line: 305

		/* begin block 1.7 */
			// Start line: 305
			// Start offset: 0x80055990
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.7 */
		// End offset: 0x80055990
		// End Line: 305
	/* end block 1 */
	// End offset: 0x80055AE8
	// End Line: 314

	/* begin block 2 */
		// Start line: 686
	/* end block 2 */
	// End Line: 687

void aadUpdateSlotVolPan(_AadSequenceSlot *slot)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  short local_18;
  short local_16;
  
  iVar7 = 0;
  iVar8 = 0x1dc;
  do {
    iVar3 = (int)&aadMem->updateCounter + iVar8;
    if (((uint)*(byte *)(iVar3 + 8) & 0xf0) == (uint)slot->slotID) {
      local_18 = (ushort)*(byte *)(iVar3 + 0xe) * (ushort)*(byte *)(iVar3 + 0xe);
      local_16 = (ushort)*(byte *)(iVar3 + 0xe) * (ushort)*(byte *)(iVar3 + 0xe);
      uVar6 = (uint)*(byte *)(iVar3 + 8) & 0xf;
      if ((aadMem->flags & 1U) == 0) {
        iVar2 = (int)&(slot->tempo).currentTick + uVar6;
        bVar1 = *(byte *)(iVar2 + 0x5b0);
        if (bVar1 < 0x41) {
          if (bVar1 < 0x3f) {
            iVar2 = (uint)*(byte *)(iVar2 + 0x5b0) + 1;
            local_16 = (short)((int)local_18 * (iVar2 * iVar2 + 1) >> 0xc);
          }
        }
        else {
          local_18 = (short)((int)local_16 * ((0x80 - (uint)bVar1) * (0x80 - (uint)bVar1) + -1) >>
                            0xc);
        }
      }
      iVar2 = (uint)*(byte *)(*(int *)(iVar3 + 0x14) + 2) + 1;
      iVar2 = iVar2 * iVar2 + -1;
      local_18 = (short)((uint)(local_18 * iVar2) >> 0xe);
      local_16 = (short)((uint)(local_16 * iVar2) >> 0xe);
      if ((aadMem->flags & 1U) == 0) {
        bVar1 = *(byte *)(*(int *)(iVar3 + 0x14) + 3);
        if (bVar1 < 0x41) {
          if (bVar1 < 0x3f) {
            iVar2 = (uint)*(byte *)(*(int *)(iVar3 + 0x14) + 3) + 1;
            local_16 = (short)((int)local_18 * (iVar2 * iVar2 + 1) >> 0xc);
          }
        }
        else {
          local_18 = (short)((int)local_16 * ((0x80 - (uint)bVar1) * (0x80 - (uint)bVar1) + -1) >>
                            0xc);
        }
      }
      iVar2 = (uint)slot->volume[uVar6] + 1;
      iVar5 = iVar2 * iVar2 + -1;
      iVar3 = (uint)*(byte *)(*(int *)(iVar3 + 0x18) + 4) + 1;
      iVar3 = iVar3 * iVar3 + -1;
      iVar2 = (uint)slot->slotVolume + 1;
      iVar2 = iVar2 * iVar2 + -1;
      iVar4 = *slot->masterVolPtr + 1;
      iVar4 = iVar4 * iVar4 + -1;
      SpuSetVoiceVolume(iVar7,(int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(
                                                  local_18 * iVar5) >> 0xe) * iVar3) >> 0xe) * iVar2
                                                  ) >> 0xe) * iVar4) >> 0xe),
                        (int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_16 *
                                                                                        iVar5) >>
                                                                                 0xe) * iVar3) >>
                                                                  0xe) * iVar2) >> 0xe) * iVar4) >>
                                    0xe));
    }
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 0x1c;
  } while (iVar7 < 0x18);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadUpdateChannelPitchBend(struct _AadSequenceSlot *slot /*$s5*/, int channel /*$s6*/)
 // line 318, offset 0x80055b00
	/* begin block 1 */
		// Start line: 319
		// Start offset: 0x80055B00
		// Variables:
	// 		struct AadSynthVoice *voice; // $a0
	// 		int i; // $s0
	// 		int finePitch; // $a1
	// 		int newPitch; // $a1
	// 		int pitchWheelPos; // $s2
	// 		int pitchIndex; // $a0
	// 		long pitchValueBendAmount; // $a2
	/* end block 1 */
	// End offset: 0x80055C88
	// End Line: 366

	/* begin block 2 */
		// Start line: 785
	/* end block 2 */
	// End Line: 786

void aadUpdateChannelPitchBend(_AadSequenceSlot *slot,int channel)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = 0;
  iVar5 = 0x1dc;
  iVar6 = (uint)slot->pitchWheel[channel] - 0x2000;
  do {
    iVar1 = (int)&aadMem->updateCounter + iVar5;
    if ((uint)*(byte *)(iVar1 + 8) == ((uint)slot->slotID | channel)) {
      iVar3 = *(int *)(iVar1 + 0x14);
      if (*(byte *)(iVar3 + 9) != 0) {
        iVar7 = 0x2000 / (int)(uint)*(byte *)(iVar3 + 9);
        iVar1 = ((uint)*(byte *)(iVar1 + 10) - ((uint)*(byte *)(iVar3 + 4) - 0x3c)) + iVar6 / iVar7;
        if ((*(byte *)(iVar3 + 5) & 0x80) == 0) {
          sVar2 = (&aadPitchTable)[iVar1] +
                  (ushort)((&aadStepsPerCent)[iVar1] * 100 * (uint)*(byte *)(iVar3 + 5) >> 0x17);
        }
        else {
          sVar2 = (&aadPitchTable)[iVar1] -
                  (ushort)((&aadStepsPerCent)[iVar1] * 100 * (0x100 - (uint)*(byte *)(iVar3 + 5)) >>
                          0x17);
        }
        SpuSetVoicePitch(iVar4,sVar2 + (short)(((int)(&aadStepsPerSemitone)[iVar1] * (iVar6 % iVar7)
                                               ) / iVar7));
      }
    }
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 0x1c;
  } while (iVar4 < 0x18);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiPolyphonicAftertouch(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 369, offset 0x80055cb0
	/* begin block 1 */
		// Start line: 974
	/* end block 1 */
	// End Line: 975

	/* begin block 2 */
		// Start line: 975
	/* end block 2 */
	// End Line: 976

void midiPolyphonicAftertouch(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiControlChange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 374, offset 0x80055cb8
	/* begin block 1 */
		// Start line: 375
		// Start offset: 0x80055CB8
		// Variables:
	// 		int controlNumber; // $v0
	/* end block 1 */
	// End offset: 0x80055CB8
	// End Line: 375

	/* begin block 2 */
		// Start line: 984
	/* end block 2 */
	// End Line: 985

void midiControlChange(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  (*(code *)(&midiControlFunction)[(uint)(byte)event->dataByte[0] & 0xf])();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiProgramChange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 385, offset 0x80055cf4
	/* begin block 1 */
		// Start line: 387
		// Start offset: 0x80055CF4
		// Variables:
	// 		int channel; // $v0
	/* end block 1 */
	// End offset: 0x80055CF4
	// End Line: 389

	/* begin block 2 */
		// Start line: 1007
	/* end block 2 */
	// End Line: 1008

	/* begin block 3 */
		// Start line: 1008
	/* end block 3 */
	// End Line: 1009

	/* begin block 4 */
		// Start line: 1010
	/* end block 4 */
	// End Line: 1011

void midiProgramChange(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->currentProgram[(uint)event->statusByte & 0xf] = event->dataByte[0];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiChannelAftertouch(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 396, offset 0x80055d0c
	/* begin block 1 */
		// Start line: 1030
	/* end block 1 */
	// End Line: 1031

	/* begin block 2 */
		// Start line: 1031
	/* end block 2 */
	// End Line: 1032

void midiChannelAftertouch(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiPitchWheelControl(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a3*/)
 // line 401, offset 0x80055d14
	/* begin block 1 */
		// Start line: 402
		// Start offset: 0x80055D14
		// Variables:
	// 		int channel; // $a1
	/* end block 1 */
	// End offset: 0x80055D14
	// End Line: 402

	/* begin block 2 */
		// Start line: 1040
	/* end block 2 */
	// End Line: 1041

void midiPitchWheelControl(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  uint channel;
  
  channel = (uint)event->statusByte & 0xf;
  slot->pitchWheel[channel] =
       (ushort)(byte)event->dataByte[0] | (ushort)(byte)event->dataByte[1] << 7;
  aadUpdateChannelPitchBend(slot,channel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiMetaEvent(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 413, offset 0x80055d5c
	/* begin block 1 */
		// Start line: 1067
	/* end block 1 */
	// End Line: 1068

	/* begin block 2 */
		// Start line: 1070
	/* end block 2 */
	// End Line: 1071

void midiMetaEvent(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiControlBankSelect(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 421, offset 0x80055d64
	/* begin block 1 */
		// Start line: 1083
	/* end block 1 */
	// End Line: 1084

	/* begin block 2 */
		// Start line: 1104
	/* end block 2 */
	// End Line: 1105

void midiControlBankSelect(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiControlVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a2*/)
 // line 446, offset 0x80055d6c
	/* begin block 1 */
		// Start line: 447
		// Start offset: 0x80055D6C
		// Variables:
	// 		int channel; // $a1
	/* end block 1 */
	// End offset: 0x80055DAC
	// End Line: 458

	/* begin block 2 */
		// Start line: 1133
	/* end block 2 */
	// End Line: 1134

void midiControlVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  uint channel;
  
  channel = (uint)event->statusByte & 0xf;
  slot->volume[channel] = event->dataByte[1];
  if (((int)(uint)slot->enableSustainUpdate >> channel & 1U) != 0) {
    aadUpdateChannelVolPan(slot,channel);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiControlPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a2*/)
 // line 461, offset 0x80055dbc
	/* begin block 1 */
		// Start line: 462
		// Start offset: 0x80055DBC
		// Variables:
	// 		int channel; // $a1
	/* end block 1 */
	// End offset: 0x80055DFC
	// End Line: 473

	/* begin block 2 */
		// Start line: 1164
	/* end block 2 */
	// End Line: 1165

void midiControlPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  uint channel;
  
  channel = (uint)event->statusByte & 0xf;
  slot->panPosition[channel] = event->dataByte[1];
  if (((int)(uint)slot->enableSustainUpdate >> channel & 1U) != 0) {
    aadUpdateChannelVolPan(slot,channel);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiControlCallback(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 476, offset 0x80055e0c
	/* begin block 1 */
		// Start line: 477
		// Start offset: 0x80055E0C
	/* end block 1 */
	// End offset: 0x80055E40
	// End Line: 488

	/* begin block 2 */
		// Start line: 1195
	/* end block 2 */
	// End Line: 1196

	/* begin block 3 */
		// Start line: 1198
	/* end block 3 */
	// End Line: 1199

void midiControlCallback(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (aadMem->controller11Callback != (_func_48 *)0x0) {
    (*aadMem->controller11Callback)
              (aadMem->controller11CallbackData,(uint)slot->thisSlotNumber,
               (uint)event->statusByte & 0xf,(uint)(byte)event->dataByte[1]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ midiControlDummy(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 491, offset 0x80055e50
	/* begin block 1 */
		// Start line: 1228
	/* end block 1 */
	// End Line: 1229

	/* begin block 2 */
		// Start line: 1229
	/* end block 2 */
	// End Line: 1230

void midiControlDummy(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}





