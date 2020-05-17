#include "THISDUST.H"
#include "AADSQCMD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ aadSubstituteVariables(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 23, offset 0x80055e58
	/* begin block 1 */
		// Start line: 25
		// Start offset: 0x80055E58
		// Variables:
	// 		unsigned char trackFlags; // $a2
	/* end block 1 */
	// End offset: 0x80055F08
	// End Line: 53

	/* begin block 2 */
		// Start line: 46
	/* end block 2 */
	// End Line: 47

	/* begin block 3 */
		// Start line: 47
	/* end block 3 */
	// End Line: 48

	/* begin block 4 */
		// Start line: 50
	/* end block 4 */
	// End Line: 51

void aadSubstituteVariables(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  
  iVar2 = (int)&(slot->tempo).currentTick + (uint)event->track;
  bVar1 = *(byte *)(iVar2 + 0x3d8);
  if (((bVar1 & 7) != 0) && (2 < (uint)event->statusByte - 0x41)) {
    bVar3 = bVar1;
    if ((bVar1 & 1) != 0) {
      bVar3 = bVar1 & 0xfe;
      event->dataByte[0] =
           (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]];
    }
    bVar4 = bVar3;
    if ((bVar1 & 2) != 0) {
      bVar4 = bVar3 & 0xfd;
      event->dataByte[1] =
           (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1]];
    }
    if ((bVar3 & 4) != 0) {
      bVar4 = bVar4 & 0xfb;
      event->dataByte[2] =
           (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[2]];
    }
    *(byte *)(iVar2 + 0x3d8) = bVar4;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSelectChannel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 58, offset 0x80055f10
	/* begin block 1 */
		// Start line: 60
		// Start offset: 0x80055F10
		// Variables:
	// 		int channelNumber; // $v1
	/* end block 1 */
	// End offset: 0x80055F28
	// End Line: 65

	/* begin block 2 */
		// Start line: 119
	/* end block 2 */
	// End Line: 120

	/* begin block 3 */
		// Start line: 120
	/* end block 3 */
	// End Line: 121

	/* begin block 4 */
		// Start line: 121
	/* end block 4 */
	// End Line: 122

void metaCmdSelectChannel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x10) {
    slot->selectedChannel = event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSelectSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 68, offset 0x80055f30
	/* begin block 1 */
		// Start line: 70
		// Start offset: 0x80055F30
		// Variables:
	// 		int slotNumber; // $v1
	/* end block 1 */
	// End offset: 0x80055F78
	// End Line: 85

	/* begin block 2 */
		// Start line: 139
	/* end block 2 */
	// End Line: 140

	/* begin block 3 */
		// Start line: 140
	/* end block 3 */
	// End Line: 141

	/* begin block 4 */
		// Start line: 143
	/* end block 4 */
	// End Line: 144

void metaCmdSelectSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  _AadSequenceSlot *p_Var2;
  
  bVar1 = event->dataByte[0];
  if ((int)(uint)bVar1 < aadMem->numSlots) {
    p_Var2 = (_AadSequenceSlot *)aadMem->sequenceSlots[(uint)bVar1];
    slot->selectedSlotNum = bVar1;
    slot->selectedSlotPtr = p_Var2;
    return;
  }
  if (bVar1 == 0x7f) {
    slot->selectedSlotPtr = slot;
    slot->selectedSlotNum = slot->thisSlotNumber;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdAssignSequence(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s2*/)
 // line 88, offset 0x80055f80
	/* begin block 1 */
		// Start line: 89
		// Start offset: 0x80055F80
		// Variables:
	// 		int sequenceNumber; // $s1

		/* begin block 1.1 */
			// Start line: 89
			// Start offset: 0x80055F80
			// Variables:
		// 		int bank; // $s0
		/* end block 1.1 */
		// End offset: 0x80055FDC
		// End Line: 101
	/* end block 1 */
	// End offset: 0x80055FDC
	// End Line: 107

	/* begin block 2 */
		// Start line: 182
	/* end block 2 */
	// End Line: 183

void metaCmdAssignSequence(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  int iVar2;
  int bank;
  
  bank = slot->selectedDynamicBank;
  bVar1 = event->dataByte[0];
  if ((aadMem->dynamicBankStatus[bank] == 2) &&
     (iVar2 = aadGetNumDynamicSequences(bank), (int)(uint)bVar1 < iVar2)) {
    aadAssignDynamicSequence(bank,(uint)bVar1,(uint)slot->selectedSlotNum);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUsePrimaryTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 110, offset 0x80055ff4
	/* begin block 1 */
		// Start line: 231
	/* end block 1 */
	// End Line: 232

	/* begin block 2 */
		// Start line: 234
	/* end block 2 */
	// End Line: 235

void metaCmdUsePrimaryTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUseSecondaryTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 117, offset 0x80055ffc
	/* begin block 1 */
		// Start line: 245
	/* end block 1 */
	// End Line: 246

	/* begin block 2 */
		// Start line: 248
	/* end block 2 */
	// End Line: 249

void metaCmdUseSecondaryTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 124, offset 0x80056004
	/* begin block 1 */
		// Start line: 125
		// Start offset: 0x80056004
		// Variables:
	// 		struct AadTempo tempo; // stack offset -16
	/* end block 1 */
	// End offset: 0x80056004
	// End Line: 125

	/* begin block 2 */
		// Start line: 259
	/* end block 2 */
	// End Line: 260

void metaCmdSetTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  AadTempo local_10;
  
  local_10.quarterNoteTime =
       (uint)(byte)event->dataByte[0] << 0x10 | (uint)(byte)event->dataByte[1] << 8 |
       (uint)(byte)event->dataByte[2];
  local_10.ppqn = (uint)(slot->selectedSlotPtr->tempo).ppqn;
  aadSetSlotTempo((uint)slot->selectedSlotNum,&local_10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdChangeTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 137, offset 0x80056070
	/* begin block 1 */
		// Start line: 138
		// Start offset: 0x80056070
		// Variables:
	// 		struct AadTempo tempo; // stack offset -16
	// 		struct _AadSequenceSlot *selectedSlot; // $a2
	/* end block 1 */
	// End offset: 0x80056070
	// End Line: 138

	/* begin block 2 */
		// Start line: 285
	/* end block 2 */
	// End Line: 286

void metaCmdChangeTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  AadTempo local_10;
  
  local_10.quarterNoteTime =
       ((slot->selectedSlotPtr->tempo).quarterNoteTime * 100) / (uint)(byte)event->dataByte[0];
  local_10.ppqn = (uint)(slot->selectedSlotPtr->tempo).ppqn;
  aadSetSlotTempo((uint)slot->selectedSlotNum,&local_10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetTempoFromSequence(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s2*/)
 // line 152, offset 0x800560e0
	/* begin block 1 */
		// Start line: 153
		// Start offset: 0x800560E0
		// Variables:
	// 		int sequenceNumber; // $s1
	// 		struct AadTempo tempo; // stack offset -24

		/* begin block 1.1 */
			// Start line: 153
			// Start offset: 0x800560E0
			// Variables:
		// 		int bank; // $s0
		/* end block 1.1 */
		// End offset: 0x80056148
		// End Line: 170
	/* end block 1 */
	// End offset: 0x80056148
	// End Line: 179

	/* begin block 2 */
		// Start line: 315
	/* end block 2 */
	// End Line: 316

void metaCmdSetTempoFromSequence(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  int iVar2;
  int bank;
  AadTempo AStack24;
  
  bank = slot->selectedDynamicBank;
  bVar1 = event->dataByte[0];
  if ((aadMem->dynamicBankStatus[bank] == 2) &&
     (iVar2 = aadGetNumDynamicSequences(bank), (int)(uint)bVar1 < iVar2)) {
    aadGetTempoFromDynamicSequence(bank,(uint)bVar1,&AStack24);
    aadSetSlotTempo((uint)slot->selectedSlotNum,&AStack24);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdStartSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 182, offset 0x80056160
	/* begin block 1 */
		// Start line: 380
	/* end block 1 */
	// End Line: 381

void metaCmdStartSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadStartSlot((uint)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdStopSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 189, offset 0x80056184
	/* begin block 1 */
		// Start line: 394
	/* end block 1 */
	// End Line: 395

void metaCmdStopSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadStopSlot((uint)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdPauseSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 196, offset 0x800561a8
	/* begin block 1 */
		// Start line: 408
	/* end block 1 */
	// End Line: 409

void metaCmdPauseSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadPauseSlot((uint)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdResumeSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 203, offset 0x800561cc
	/* begin block 1 */
		// Start line: 422
	/* end block 1 */
	// End Line: 423

void metaCmdResumeSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadResumeSlot((uint)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSlotBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 210, offset 0x800561f0
	/* begin block 1 */
		// Start line: 436
	/* end block 1 */
	// End Line: 437

	/* begin block 2 */
		// Start line: 445
	/* end block 2 */
	// End Line: 446

void metaCmdSetSlotBendRange(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 223, offset 0x800561f8
	/* begin block 1 */
		// Start line: 462
	/* end block 1 */
	// End Line: 463

	/* begin block 2 */
		// Start line: 464
	/* end block 2 */
	// End Line: 465

void metaCmdSetChannelBendRange(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSlotVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 229, offset 0x80056200
	/* begin block 1 */
		// Start line: 230
		// Start offset: 0x80056200
		// Variables:
	// 		int volume; // $v1
	/* end block 1 */
	// End offset: 0x80056200
	// End Line: 230

	/* begin block 2 */
		// Start line: 474
	/* end block 2 */
	// End Line: 475

void metaCmdSetSlotVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->slotVolume = event->dataByte[0];
  aadUpdateSlotVolPan(slot->selectedSlotPtr);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSlotPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 241, offset 0x80056234
	/* begin block 1 */
		// Start line: 242
		// Start offset: 0x80056234
		// Variables:
	// 		int pan; // $v1
	/* end block 1 */
	// End offset: 0x80056234
	// End Line: 242

	/* begin block 2 */
		// Start line: 498
	/* end block 2 */
	// End Line: 499

void metaCmdSetSlotPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->slotPan = event->dataByte[0];
  aadUpdateSlotVolPan(slot->selectedSlotPtr);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 253, offset 0x80056268
	/* begin block 1 */
		// Start line: 254
		// Start offset: 0x80056268
		// Variables:
	// 		int volume; // $a0
	/* end block 1 */
	// End offset: 0x80056268
	// End Line: 254

	/* begin block 2 */
		// Start line: 522
	/* end block 2 */
	// End Line: 523

void metaCmdSetChannelVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->volume[slot->selectedChannel] = event->dataByte[0];
  aadUpdateChannelVolPan(slot->selectedSlotPtr,(uint)slot->selectedChannel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 265, offset 0x800562a4
	/* begin block 1 */
		// Start line: 266
		// Start offset: 0x800562A4
		// Variables:
	// 		int pan; // $a0
	/* end block 1 */
	// End offset: 0x800562A4
	// End Line: 266

	/* begin block 2 */
		// Start line: 547
	/* end block 2 */
	// End Line: 548

void metaCmdSetChannelPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->panPosition[slot->selectedChannel] = event->dataByte[0];
  aadUpdateChannelVolPan(slot->selectedSlotPtr,(uint)slot->selectedChannel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdEnableSustainUpdate(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 277, offset 0x800562e0
	/* begin block 1 */
		// Start line: 279
		// Start offset: 0x800562E0
		// Variables:
	// 		int channel; // $a0
	/* end block 1 */
	// End offset: 0x800562E0
	// End Line: 282

	/* begin block 2 */
		// Start line: 572
	/* end block 2 */
	// End Line: 573

	/* begin block 3 */
		// Start line: 573
	/* end block 3 */
	// End Line: 574

	/* begin block 4 */
		// Start line: 576
	/* end block 4 */
	// End Line: 577

void metaCmdEnableSustainUpdate(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->enableSustainUpdate =
       slot->selectedSlotPtr->enableSustainUpdate |
       (ushort)(1 << ((uint)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdDisableSustainUpdate(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 287, offset 0x80056300
	/* begin block 1 */
		// Start line: 289
		// Start offset: 0x80056300
		// Variables:
	// 		int channel; // $v0
	/* end block 1 */
	// End offset: 0x80056300
	// End Line: 292

	/* begin block 2 */
		// Start line: 593
	/* end block 2 */
	// End Line: 594

	/* begin block 3 */
		// Start line: 594
	/* end block 3 */
	// End Line: 595

	/* begin block 4 */
		// Start line: 597
	/* end block 4 */
	// End Line: 598

void metaCmdDisableSustainUpdate(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->enableSustainUpdate =
       slot->selectedSlotPtr->enableSustainUpdate &
       ~(ushort)(1 << ((uint)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdMuteChannel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 297, offset 0x80056324
	/* begin block 1 */
		// Start line: 298
		// Start offset: 0x80056324
	/* end block 1 */
	// End offset: 0x80056324
	// End Line: 298

	/* begin block 2 */
		// Start line: 614
	/* end block 2 */
	// End Line: 615

void metaCmdMuteChannel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadMuteChannels(slot->selectedSlotPtr,1 << ((uint)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUnMuteChannel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 307, offset 0x80056350
	/* begin block 1 */
		// Start line: 308
		// Start offset: 0x80056350
	/* end block 1 */
	// End offset: 0x80056350
	// End Line: 308

	/* begin block 2 */
		// Start line: 637
	/* end block 2 */
	// End Line: 638

void metaCmdUnMuteChannel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadUnMuteChannels(slot->selectedSlotPtr,1 << ((uint)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdMuteChannelList(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 317, offset 0x8005637c
	/* begin block 1 */
		// Start line: 318
		// Start offset: 0x8005637C
	/* end block 1 */
	// End offset: 0x8005637C
	// End Line: 318

	/* begin block 2 */
		// Start line: 660
	/* end block 2 */
	// End Line: 661

void metaCmdMuteChannelList(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadMuteChannels(slot->selectedSlotPtr,(uint)*(ushort *)event->dataByte);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUnMuteChannelList(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 327, offset 0x800563ac
	/* begin block 1 */
		// Start line: 328
		// Start offset: 0x800563AC
	/* end block 1 */
	// End offset: 0x800563AC
	// End Line: 328

	/* begin block 2 */
		// Start line: 681
	/* end block 2 */
	// End Line: 682

void metaCmdUnMuteChannelList(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadUnMuteChannels(slot->selectedSlotPtr,(uint)*(ushort *)event->dataByte);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelMute(struct AadSeqEvent *event /*$v0*/, struct _AadSequenceSlot *slot /*$s1*/)
 // line 337, offset 0x800563dc
	/* begin block 1 */
		// Start line: 338
		// Start offset: 0x800563DC
		// Variables:
	// 		unsigned long muteChannelMask; // $s0
	/* end block 1 */
	// End offset: 0x800563DC
	// End Line: 338

	/* begin block 2 */
		// Start line: 702
	/* end block 2 */
	// End Line: 703

void metaCmdSetChannelMute(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)event->dataByte;
  aadUnMuteChannels(slot->selectedSlotPtr,~(uint)uVar1);
  aadMuteChannels(slot->selectedSlotPtr,(uint)uVar1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdDelayMute(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 349, offset 0x80056430
	/* begin block 1 */
		// Start line: 351
		// Start offset: 0x80056430
		// Variables:
	// 		unsigned long channelMask; // $v1
	/* end block 1 */
	// End offset: 0x80056430
	// End Line: 353

	/* begin block 2 */
		// Start line: 727
	/* end block 2 */
	// End Line: 728

	/* begin block 3 */
		// Start line: 728
	/* end block 3 */
	// End Line: 729

	/* begin block 4 */
		// Start line: 730
	/* end block 4 */
	// End Line: 731

void metaCmdDelayMute(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->delayedMuteMode =
       slot->selectedSlotPtr->delayedMuteMode | *(ushort *)event->dataByte;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUpdateMute(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s1*/)
 // line 362, offset 0x80056454
	/* begin block 1 */
		// Start line: 363
		// Start offset: 0x80056454
		// Variables:
	// 		unsigned long channelMask; // $s0
	// 		unsigned long mask; // $a1
	/* end block 1 */
	// End offset: 0x800564D4
	// End Line: 376

	/* begin block 2 */
		// Start line: 757
	/* end block 2 */
	// End Line: 758

void metaCmdUpdateMute(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  ushort uVar1;
  ushort uVar2;
  _AadSequenceSlot *slot_00;
  
  uVar1 = *(ushort *)event->dataByte;
  slot->selectedSlotPtr->delayedMuteMode = slot->selectedSlotPtr->delayedMuteMode & ~uVar1;
  slot_00 = slot->selectedSlotPtr;
  uVar2 = slot_00->delayedMuteCmds & uVar1;
  if (uVar2 != 0) {
    aadMuteChannels(slot_00,(uint)uVar2);
    slot_00 = slot->selectedSlotPtr;
  }
  uVar1 = slot_00->delayedUnMuteCmds & uVar1;
  if (uVar1 != 0) {
    aadUnMuteChannels(slot_00,(uint)uVar1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdChannelVolumeFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 379, offset 0x800564e8
	/* begin block 1 */
		// Start line: 793
	/* end block 1 */
	// End Line: 794

	/* begin block 2 */
		// Start line: 803
	/* end block 2 */
	// End Line: 804

void metaCmdChannelVolumeFade(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdChannelPanFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 393, offset 0x800564f0
	/* begin block 1 */
		// Start line: 821
	/* end block 1 */
	// End Line: 822

	/* begin block 2 */
		// Start line: 831
	/* end block 2 */
	// End Line: 832

void metaCmdChannelPanFade(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSlotVolumeFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 407, offset 0x800564f8
	/* begin block 1 */
		// Start line: 849
	/* end block 1 */
	// End Line: 850

	/* begin block 2 */
		// Start line: 858
	/* end block 2 */
	// End Line: 859

void metaCmdSlotVolumeFade(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSlotPanFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 420, offset 0x80056500
	/* begin block 1 */
		// Start line: 875
	/* end block 1 */
	// End Line: 876

	/* begin block 2 */
		// Start line: 884
	/* end block 2 */
	// End Line: 885

void metaCmdSlotPanFade(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelProgram(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 433, offset 0x80056508
	/* begin block 1 */
		// Start line: 435
		// Start offset: 0x80056508
		// Variables:
	// 		int program; // $a0
	/* end block 1 */
	// End offset: 0x80056508
	// End Line: 438

	/* begin block 2 */
		// Start line: 901
	/* end block 2 */
	// End Line: 902

	/* begin block 3 */
		// Start line: 902
	/* end block 3 */
	// End Line: 903

	/* begin block 4 */
		// Start line: 905
	/* end block 4 */
	// End Line: 906

void metaCmdSetChannelProgram(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->currentProgram[slot->selectedChannel] = event->dataByte[0];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelBasePriority(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 443, offset 0x80056520
	/* begin block 1 */
		// Start line: 922
	/* end block 1 */
	// End Line: 923

	/* begin block 2 */
		// Start line: 942
	/* end block 2 */
	// End Line: 943

void metaCmdSetChannelBasePriority(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 467, offset 0x80056528
	/* begin block 1 */
		// Start line: 469
		// Start offset: 0x80056528
		// Variables:
	// 		int channel; // $a2
	// 		int transpose; // $v1
	/* end block 1 */
	// End offset: 0x80056528
	// End Line: 471

	/* begin block 2 */
		// Start line: 970
	/* end block 2 */
	// End Line: 971

	/* begin block 3 */
		// Start line: 971
	/* end block 3 */
	// End Line: 972

	/* begin block 4 */
		// Start line: 973
	/* end block 4 */
	// End Line: 974

void metaCmdSetChannelTranspose(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->transpose[slot->selectedChannel] = event->dataByte[0];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdIgnoreChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 478, offset 0x80056540
	/* begin block 1 */
		// Start line: 480
		// Start offset: 0x80056540
		// Variables:
	// 		int channel; // $a0
	/* end block 1 */
	// End offset: 0x80056540
	// End Line: 483

	/* begin block 2 */
		// Start line: 993
	/* end block 2 */
	// End Line: 994

	/* begin block 3 */
		// Start line: 994
	/* end block 3 */
	// End Line: 995

	/* begin block 4 */
		// Start line: 997
	/* end block 4 */
	// End Line: 998

void metaCmdIgnoreChannelTranspose(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->ignoreTranspose =
       slot->selectedSlotPtr->ignoreTranspose | (ushort)(1 << ((uint)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdRespectChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 488, offset 0x80056560
	/* begin block 1 */
		// Start line: 490
		// Start offset: 0x80056560
		// Variables:
	// 		int channel; // $v0
	/* end block 1 */
	// End offset: 0x80056560
	// End Line: 493

	/* begin block 2 */
		// Start line: 1014
	/* end block 2 */
	// End Line: 1015

	/* begin block 3 */
		// Start line: 1015
	/* end block 3 */
	// End Line: 1016

	/* begin block 4 */
		// Start line: 1018
	/* end block 4 */
	// End Line: 1019

void metaCmdRespectChannelTranspose(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->ignoreTranspose =
       slot->selectedSlotPtr->ignoreTranspose & ~(ushort)(1 << ((uint)slot->selectedChannel & 0x1f))
  ;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 498, offset 0x80056584
	/* begin block 1 */
		// Start line: 1035
	/* end block 1 */
	// End Line: 1036

	/* begin block 2 */
		// Start line: 1046
	/* end block 2 */
	// End Line: 1047

void metaCmdSetChannelPitchMap(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdIgnoreChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 513, offset 0x8005658c
	/* begin block 1 */
		// Start line: 1065
	/* end block 1 */
	// End Line: 1066

	/* begin block 2 */
		// Start line: 1073
	/* end block 2 */
	// End Line: 1074

void metaCmdIgnoreChannelPitchMap(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdRespectChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 525, offset 0x80056594
	/* begin block 1 */
		// Start line: 1089
	/* end block 1 */
	// End Line: 1090

	/* begin block 2 */
		// Start line: 1097
	/* end block 2 */
	// End Line: 1098

void metaCmdRespectChannelPitchMap(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSequenceAssigned(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 537, offset 0x8005659c
	/* begin block 1 */
		// Start line: 539
		// Start offset: 0x8005659C
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x800565C4
	// End Line: 546

	/* begin block 2 */
		// Start line: 1113
	/* end block 2 */
	// End Line: 1114

	/* begin block 3 */
		// Start line: 1114
	/* end block 3 */
	// End Line: 1115

	/* begin block 4 */
		// Start line: 1116
	/* end block 4 */
	// End Line: 1117

void metaCmdGetSequenceAssigned(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->sequenceNumberAssigned;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 549, offset 0x800565cc
	/* begin block 1 */
		// Start line: 551
		// Start offset: 0x800565CC
		// Variables:
	// 		int variableNum1; // $a2
	// 		int variableNum2; // $a3
	// 		int variableNum3; // $t0
	// 		unsigned long quarterNoteTime; // $a0
	/* end block 1 */
	// End offset: 0x80056628
	// End Line: 567

	/* begin block 2 */
		// Start line: 1137
	/* end block 2 */
	// End Line: 1138

	/* begin block 3 */
		// Start line: 1138
	/* end block 3 */
	// End Line: 1139

	/* begin block 4 */
		// Start line: 1141
	/* end block 4 */
	// End Line: 1142

void metaCmdGetTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  byte bVar2;
  ulong uVar3;
  
  bVar1 = event->dataByte[1];
  bVar2 = event->dataByte[2];
  if ((((byte)event->dataByte[0] < 0x80) && (bVar1 < 0x80)) && (bVar2 < 0x80)) {
    uVar3 = (slot->selectedSlotPtr->tempo).quarterNoteTime;
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] = (char)uVar3;
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)bVar1] = (char)(uVar3 >> 8);
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)bVar2] = (char)(uVar3 >> 0x10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSlotStatus(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 570, offset 0x80056630
	/* begin block 1 */
		// Start line: 572
		// Start offset: 0x80056630
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x80056658
	// End Line: 579

	/* begin block 2 */
		// Start line: 1180
	/* end block 2 */
	// End Line: 1181

	/* begin block 3 */
		// Start line: 1181
	/* end block 3 */
	// End Line: 1182

	/* begin block 4 */
		// Start line: 1183
	/* end block 4 */
	// End Line: 1184

void metaCmdGetSlotStatus(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
         *(undefined *)&slot->selectedSlotPtr->status;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelMute(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 582, offset 0x80056660
	/* begin block 1 */
		// Start line: 584
		// Start offset: 0x80056660
		// Variables:
	// 		int variableNum1; // $a2
	// 		int variableNum2; // $a0
	/* end block 1 */
	// End offset: 0x800566A8
	// End Line: 595

	/* begin block 2 */
		// Start line: 1204
	/* end block 2 */
	// End Line: 1205

	/* begin block 3 */
		// Start line: 1205
	/* end block 3 */
	// End Line: 1206

	/* begin block 4 */
		// Start line: 1207
	/* end block 4 */
	// End Line: 1208

void metaCmdGetChannelMute(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  
  bVar1 = event->dataByte[1];
  if (((byte)event->dataByte[0] < 0x80) && (bVar1 < 0x80)) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
         *(undefined *)&slot->selectedSlotPtr->channelMute;
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)bVar1] =
         (char)(slot->selectedSlotPtr->channelMute >> 8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 598, offset 0x800566b0
	/* begin block 1 */
		// Start line: 600
		// Start offset: 0x800566B0
		// Variables:
	// 		int variableNum; // $a0
	// 		int channel; // $v1
	/* end block 1 */
	// End offset: 0x800566E0
	// End Line: 608

	/* begin block 2 */
		// Start line: 1236
	/* end block 2 */
	// End Line: 1237

	/* begin block 3 */
		// Start line: 1237
	/* end block 3 */
	// End Line: 1238

	/* begin block 4 */
		// Start line: 1239
	/* end block 4 */
	// End Line: 1240

void metaCmdGetChannelVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->volume[slot->selectedChannel];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 611, offset 0x800566e8
	/* begin block 1 */
		// Start line: 613
		// Start offset: 0x800566E8
		// Variables:
	// 		int variableNum; // $a0
	// 		int channel; // $v1
	/* end block 1 */
	// End offset: 0x80056718
	// End Line: 620

	/* begin block 2 */
		// Start line: 1262
	/* end block 2 */
	// End Line: 1263

	/* begin block 3 */
		// Start line: 1263
	/* end block 3 */
	// End Line: 1264

	/* begin block 4 */
		// Start line: 1265
	/* end block 4 */
	// End Line: 1266

void metaCmdGetChannelPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->panPosition[slot->selectedChannel];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 623, offset 0x80056720
	/* begin block 1 */
		// Start line: 1286
	/* end block 1 */
	// End Line: 1287

	/* begin block 2 */
		// Start line: 1296
	/* end block 2 */
	// End Line: 1297

void metaCmdGetChannelTranspose(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelProgram(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 637, offset 0x80056728
	/* begin block 1 */
		// Start line: 639
		// Start offset: 0x80056728
		// Variables:
	// 		int variableNum; // $a0
	// 		int channel; // $v1
	/* end block 1 */
	// End offset: 0x80056758
	// End Line: 646

	/* begin block 2 */
		// Start line: 1314
	/* end block 2 */
	// End Line: 1315

	/* begin block 3 */
		// Start line: 1315
	/* end block 3 */
	// End Line: 1316

	/* begin block 4 */
		// Start line: 1317
	/* end block 4 */
	// End Line: 1318

void metaCmdGetChannelProgram(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->currentProgram[slot->selectedChannel];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelBasePriority(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 649, offset 0x80056760
	/* begin block 1 */
		// Start line: 1338
	/* end block 1 */
	// End Line: 1339

	/* begin block 2 */
		// Start line: 1355
	/* end block 2 */
	// End Line: 1356

void metaCmdGetChannelBasePriority(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 670, offset 0x80056768
	/* begin block 1 */
		// Start line: 1380
	/* end block 1 */
	// End Line: 1381

	/* begin block 2 */
		// Start line: 1389
	/* end block 2 */
	// End Line: 1390

void metaCmdGetChannelBendRange(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSlotVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 683, offset 0x80056770
	/* begin block 1 */
		// Start line: 685
		// Start offset: 0x80056770
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x80056798
	// End Line: 692

	/* begin block 2 */
		// Start line: 1406
	/* end block 2 */
	// End Line: 1407

	/* begin block 3 */
		// Start line: 1407
	/* end block 3 */
	// End Line: 1408

	/* begin block 4 */
		// Start line: 1409
	/* end block 4 */
	// End Line: 1410

void metaCmdGetSlotVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->slotVolume;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSlotPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 695, offset 0x800567a0
	/* begin block 1 */
		// Start line: 697
		// Start offset: 0x800567A0
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x800567C8
	// End Line: 703

	/* begin block 2 */
		// Start line: 1430
	/* end block 2 */
	// End Line: 1431

	/* begin block 3 */
		// Start line: 1431
	/* end block 3 */
	// End Line: 1432

	/* begin block 4 */
		// Start line: 1433
	/* end block 4 */
	// End Line: 1434

void metaCmdGetSlotPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->slotPan;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 706, offset 0x800567d0
	/* begin block 1 */
		// Start line: 708
		// Start offset: 0x800567D0
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $v1
	/* end block 1 */
	// End offset: 0x800567F4
	// End Line: 715

	/* begin block 2 */
		// Start line: 1452
	/* end block 2 */
	// End Line: 1453

	/* begin block 3 */
		// Start line: 1453
	/* end block 3 */
	// End Line: 1454

	/* begin block 4 */
		// Start line: 1456
	/* end block 4 */
	// End Line: 1457

void metaCmdSetVariable(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[1] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1]] =
         event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdCopyVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 718, offset 0x800567fc
	/* begin block 1 */
		// Start line: 720
		// Start offset: 0x800567FC
		// Variables:
	// 		int srcVariable; // $v1
	// 		int destVariable; // $a0
	/* end block 1 */
	// End offset: 0x80056830
	// End Line: 728

	/* begin block 2 */
		// Start line: 1477
	/* end block 2 */
	// End Line: 1478

	/* begin block 3 */
		// Start line: 1478
	/* end block 3 */
	// End Line: 1479

	/* begin block 4 */
		// Start line: 1480
	/* end block 4 */
	// End Line: 1481

void metaCmdCopyVariable(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (((byte)event->dataByte[0] < 0x80) && ((byte)event->dataByte[1] < 0x80)) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1]] =
         (&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdAddVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 731, offset 0x80056838
	/* begin block 1 */
		// Start line: 733
		// Start offset: 0x80056838
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $a1
	/* end block 1 */
	// End offset: 0x80056868
	// End Line: 740

	/* begin block 2 */
		// Start line: 1503
	/* end block 2 */
	// End Line: 1504

	/* begin block 3 */
		// Start line: 1504
	/* end block 3 */
	// End Line: 1505

	/* begin block 4 */
		// Start line: 1507
	/* end block 4 */
	// End Line: 1508

void metaCmdAddVariable(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  if ((byte)event->dataByte[1] < 0x80) {
    iVar1 = (int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1];
    (&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] + event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSubtractVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 743, offset 0x80056870
	/* begin block 1 */
		// Start line: 745
		// Start offset: 0x80056870
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $a1
	/* end block 1 */
	// End offset: 0x800568A0
	// End Line: 752

	/* begin block 2 */
		// Start line: 1528
	/* end block 2 */
	// End Line: 1529

	/* begin block 3 */
		// Start line: 1529
	/* end block 3 */
	// End Line: 1530

	/* begin block 4 */
		// Start line: 1532
	/* end block 4 */
	// End Line: 1533

void metaCmdSubtractVariable(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  if ((byte)event->dataByte[1] < 0x80) {
    iVar1 = (int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1];
    (&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] - event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetVariableBits(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 755, offset 0x800568a8
	/* begin block 1 */
		// Start line: 757
		// Start offset: 0x800568A8
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $a1
	/* end block 1 */
	// End offset: 0x800568D8
	// End Line: 764

	/* begin block 2 */
		// Start line: 1553
	/* end block 2 */
	// End Line: 1554

	/* begin block 3 */
		// Start line: 1554
	/* end block 3 */
	// End Line: 1555

	/* begin block 4 */
		// Start line: 1557
	/* end block 4 */
	// End Line: 1558

void metaCmdSetVariableBits(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  if ((byte)event->dataByte[1] < 0x80) {
    iVar1 = (int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1];
    (&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] | event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdClearVariableBits(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 767, offset 0x800568e0
	/* begin block 1 */
		// Start line: 769
		// Start offset: 0x800568E0
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $v1
	/* end block 1 */
	// End offset: 0x80056910
	// End Line: 776

	/* begin block 2 */
		// Start line: 1578
	/* end block 2 */
	// End Line: 1579

	/* begin block 3 */
		// Start line: 1579
	/* end block 3 */
	// End Line: 1580

	/* begin block 4 */
		// Start line: 1582
	/* end block 4 */
	// End Line: 1583

void metaCmdClearVariableBits(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  if ((byte)event->dataByte[1] < 0x80) {
    iVar1 = (int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1];
    (&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] & ~event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadGotoSequencePosition(struct _AadSequenceSlot *slot /*$a0*/, int track /*$a1*/, unsigned char *newPosition /*$a2*/)
 // line 779, offset 0x80056918
	/* begin block 1 */
		// Start line: 1603
	/* end block 1 */
	// End Line: 1604

	/* begin block 2 */
		// Start line: 1605
	/* end block 2 */
	// End Line: 1606

void aadGotoSequencePosition(_AadSequenceSlot *slot,int track,uchar *newPosition)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (int)&(slot->tempo).currentTick + track;
  *(uchar **)(slot->sequencePosition + track) = newPosition;
  cVar1 = *(char *)(iVar2 + 0x338);
  while (cVar1 != '\0') {
    cVar1 = *(char *)(iVar2 + 0x328) + '\x01';
    *(char *)(iVar2 + 0x328) = cVar1;
    *(char *)(iVar2 + 0x338) = *(char *)(iVar2 + 0x338) + -1;
    if (cVar1 == '\x04') {
      *(undefined *)(iVar2 + 0x328) = 0;
    }
    cVar1 = *(char *)(iVar2 + 0x338);
  }
  track = (int)&(slot->tempo).currentTick + track;
  *(byte *)(track + 0x3d8) = *(byte *)(track + 0x3d8) & 0xe7;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadGotoSequenceLabel(struct _AadSequenceSlot *slot /*$a3*/, int track /*$t0*/, int labelNumber /*$a2*/)
 // line 800, offset 0x80056984
	/* begin block 1 */
		// Start line: 801
		// Start offset: 0x80056984
		// Variables:
	// 		struct AadSequenceHdr *seqHdr; // $v0
	// 		unsigned long trackOffset; // $a0
	// 		int bank; // $v0
	/* end block 1 */
	// End offset: 0x80056A28
	// End Line: 835

	/* begin block 2 */
		// Start line: 1650
	/* end block 2 */
	// End Line: 1651

void aadGotoSequenceLabel(_AadSequenceSlot *slot,int track,int labelNumber)

{
  int iVar1;
  char cVar2;
  
  iVar1 = *(int *)((&aadMem->updateCounter + slot->sequenceAssignedDynamicBank)[0x13c] +
                  (uint)slot->sequenceNumberAssigned * 4);
  slot->sequencePosition[track] =
       (_func_9 *)
       (iVar1 + *(int *)((&aadMem->updateCounter + slot->sequenceAssignedDynamicBank)[0x13e] +
                        labelNumber * 4) + *(int *)(iVar1 + track * 4 + 0x10));
  iVar1 = (int)&(slot->tempo).currentTick + track;
  cVar2 = *(char *)(iVar1 + 0x338);
  while (cVar2 != '\0') {
    cVar2 = *(char *)(iVar1 + 0x328) + '\x01';
    *(char *)(iVar1 + 0x328) = cVar2;
    *(char *)(iVar1 + 0x338) = *(char *)(iVar1 + 0x338) + -1;
    if (cVar2 == '\x04') {
      *(undefined *)(iVar1 + 0x328) = 0;
    }
    cVar2 = *(char *)(iVar1 + 0x338);
  }
  track = (int)&(slot->tempo).currentTick + track;
  *(byte *)(track + 0x3d8) = *(byte *)(track + 0x3d8) & 0xe7;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdLoopStart(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 842, offset 0x80056a3c
	/* begin block 1 */
		// Start line: 844
		// Start offset: 0x80056A3C
		// Variables:
	// 		int nestLevel; // $a2
	// 		int track; // $a3
	/* end block 1 */
	// End offset: 0x80056A98
	// End Line: 859

	/* begin block 2 */
		// Start line: 1750
	/* end block 2 */
	// End Line: 1751

	/* begin block 3 */
		// Start line: 1751
	/* end block 3 */
	// End Line: 1752

	/* begin block 4 */
		// Start line: 1752
	/* end block 4 */
	// End Line: 1753

void metaCmdLoopStart(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)event->track;
  iVar3 = (int)&(slot->tempo).currentTick + uVar2;
  bVar1 = *(byte *)(iVar3 + 0x4e8);
  if (bVar1 < 4) {
    *(_func_9 **)(slot->loopSequencePosition + (uint)bVar1 * 0x10 + uVar2) =
         slot->sequencePosition[uVar2];
    slot->loopCounter[uVar2 + (uint)bVar1 * 0x10] = event->dataByte[0];
    *(char *)(iVar3 + 0x4e8) = *(char *)(iVar3 + 0x4e8) + '\x01';
  }
  *(byte *)(iVar3 + 0x3d8) = *(byte *)(iVar3 + 0x3d8) & 0xef;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdLoopEnd(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a3*/)
 // line 863, offset 0x80056aac
	/* begin block 1 */
		// Start line: 864
		// Start offset: 0x80056AAC
		// Variables:
	// 		int prevNestLevel; // $v1
	// 		int track; // $a1
	/* end block 1 */
	// End offset: 0x80056B2C
	// End Line: 888

	/* begin block 2 */
		// Start line: 1792
	/* end block 2 */
	// End Line: 1793

void metaCmdLoopEnd(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint track;
  int iVar5;
  
  track = (uint)event->track;
  iVar5 = (int)&(slot->tempo).currentTick + track;
  bVar1 = *(byte *)(iVar5 + 0x4e8);
  iVar3 = (uint)bVar1 - 1;
  if (bVar1 != 0) {
    iVar4 = (int)&(slot->tempo).currentTick + track + iVar3 * 0x10;
    cVar2 = *(char *)(iVar4 + 0x4f8);
    if ((cVar2 == '\0') || (*(char *)(iVar4 + 0x4f8) = cVar2 + -1, cVar2 != '\x01')) {
      aadGotoSequencePosition(slot,track,(uchar *)slot->loopSequencePosition[iVar3 * 0x10 + track]);
    }
    else {
      *(undefined *)(iVar5 + 0x4e8) = (char)iVar3;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdLoopBreak(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 891, offset 0x80056b3c
	/* begin block 1 */
		// Start line: 1848
	/* end block 1 */
	// End Line: 1849

	/* begin block 2 */
		// Start line: 1851
	/* end block 2 */
	// End Line: 1852

void metaCmdLoopBreak(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdDefineLabel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 898, offset 0x80056b44
	/* begin block 1 */
		// Start line: 1862
	/* end block 1 */
	// End Line: 1863

	/* begin block 2 */
		// Start line: 1869
	/* end block 2 */
	// End Line: 1870

void metaCmdDefineLabel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGotoLabel(struct AadSeqEvent *event /*$v0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 909, offset 0x80056b4c
	/* begin block 1 */
		// Start line: 910
		// Start offset: 0x80056B4C
	/* end block 1 */
	// End offset: 0x80056B4C
	// End Line: 910

	/* begin block 2 */
		// Start line: 1884
	/* end block 2 */
	// End Line: 1885

void metaCmdGotoLabel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[0]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSequencePosition(struct AadSeqEvent *event /*$v0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 919, offset 0x80056b7c
	/* begin block 1 */
		// Start line: 920
		// Start offset: 0x80056B7C
	/* end block 1 */
	// End offset: 0x80056B7C
	// End Line: 920

	/* begin block 2 */
		// Start line: 1908
	/* end block 2 */
	// End Line: 1909

void metaCmdSetSequencePosition(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadGotoSequenceLabel(slot->selectedSlotPtr,(uint)event->track,(uint)(byte)event->dataByte[0]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 929, offset 0x80056bac
	/* begin block 1 */
		// Start line: 930
		// Start offset: 0x80056BAC
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056BE8
	// End Line: 940

	/* begin block 2 */
		// Start line: 1928
	/* end block 2 */
	// End Line: 1929

void metaCmdBranchIfVarEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] ==
      event->dataByte[1]) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarNotEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 943, offset 0x80056bf8
	/* begin block 1 */
		// Start line: 944
		// Start offset: 0x80056BF8
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056C34
	// End Line: 954

	/* begin block 2 */
		// Start line: 1968
	/* end block 2 */
	// End Line: 1969

void metaCmdBranchIfVarNotEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] !=
      event->dataByte[1]) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarLess(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 957, offset 0x80056c44
	/* begin block 1 */
		// Start line: 958
		// Start offset: 0x80056C44
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056C84
	// End Line: 968

	/* begin block 2 */
		// Start line: 2008
	/* end block 2 */
	// End Line: 2009

void metaCmdBranchIfVarLess(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] <
      (byte)event->dataByte[1]) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarGreater(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 971, offset 0x80056c94
	/* begin block 1 */
		// Start line: 972
		// Start offset: 0x80056C94
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056CD4
	// End Line: 982

	/* begin block 2 */
		// Start line: 2048
	/* end block 2 */
	// End Line: 2049

void metaCmdBranchIfVarGreater(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[1] <
      (byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]]) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarLessOrEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 985, offset 0x80056ce4
	/* begin block 1 */
		// Start line: 986
		// Start offset: 0x80056CE4
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056D24
	// End Line: 996

	/* begin block 2 */
		// Start line: 2088
	/* end block 2 */
	// End Line: 2089

void metaCmdBranchIfVarLessOrEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] <=
      (byte)event->dataByte[1]) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarGreaterOrEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 999, offset 0x80056d34
	/* begin block 1 */
		// Start line: 1000
		// Start offset: 0x80056D34
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056D74
	// End Line: 1010

	/* begin block 2 */
		// Start line: 2128
	/* end block 2 */
	// End Line: 2129

void metaCmdBranchIfVarGreaterOrEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[1] <=
      (byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]]) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarBitsSet(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 1013, offset 0x80056d84
	/* begin block 1 */
		// Start line: 1014
		// Start offset: 0x80056D84
		// Variables:
	// 		int variableNum; // $v1
	// 		int mask; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056DC4
	// End Line: 1023

	/* begin block 2 */
		// Start line: 2168
	/* end block 2 */
	// End Line: 2169

void metaCmdBranchIfVarBitsSet(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (((&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] &
      event->dataByte[1]) != 0) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarBitsClear(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 1026, offset 0x80056dd4
	/* begin block 1 */
		// Start line: 1027
		// Start offset: 0x80056DD4
		// Variables:
	// 		int variableNum; // $v1
	// 		int mask; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056E14
	// End Line: 1036

	/* begin block 2 */
		// Start line: 2203
	/* end block 2 */
	// End Line: 2204

void metaCmdBranchIfVarBitsClear(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (((&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] &
      event->dataByte[1]) == 0) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSubstituteVariableParam1(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1039, offset 0x80056e24
	/* begin block 1 */
		// Start line: 2238
	/* end block 1 */
	// End Line: 2239

	/* begin block 2 */
		// Start line: 2239
	/* end block 2 */
	// End Line: 2240

void metaCmdSubstituteVariableParam1(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  iVar1 = (int)&(slot->tempo).currentTick + (uint)event->track;
  *(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSubstituteVariableParam2(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1046, offset 0x80056e44
	/* begin block 1 */
		// Start line: 2252
	/* end block 1 */
	// End Line: 2253

	/* begin block 2 */
		// Start line: 2253
	/* end block 2 */
	// End Line: 2254

void metaCmdSubstituteVariableParam2(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  iVar1 = (int)&(slot->tempo).currentTick + (uint)event->track;
  *(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSubstituteVariableParam3(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1053, offset 0x80056e64
	/* begin block 1 */
		// Start line: 2266
	/* end block 1 */
	// End Line: 2267

	/* begin block 2 */
		// Start line: 2267
	/* end block 2 */
	// End Line: 2268

void metaCmdSubstituteVariableParam3(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  iVar1 = (int)&(slot->tempo).currentTick + (uint)event->track;
  *(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 4;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdEndSequence(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s0*/)
 // line 1059, offset 0x80056e84
	/* begin block 1 */
		// Start line: 2278
	/* end block 1 */
	// End Line: 2279

void metaCmdEndSequence(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadInitSequenceSlot(slot);
  aadAllNotesOff((uint)slot->thisSlotNumber);
  if (aadMem->endSequenceCallback != (_func_49 *)0x0) {
    (*aadMem->endSequenceCallback)(aadMem->endSequenceCallbackData,(uint)slot->thisSlotNumber,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdPlaySoundEffect(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1177, offset 0x80056ee0
	/* begin block 1 */
		// Start line: 2514
	/* end block 1 */
	// End Line: 2515

	/* begin block 2 */
		// Start line: 2515
	/* end block 2 */
	// End Line: 2516

void metaCmdPlaySoundEffect(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdStopSoundEffect(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1180, offset 0x80056ee8
	/* begin block 1 */
		// Start line: 2520
	/* end block 1 */
	// End Line: 2521

	/* begin block 2 */
		// Start line: 2521
	/* end block 2 */
	// End Line: 2522

void metaCmdStopSoundEffect(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSoundEffectVolumePan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1183, offset 0x80056ef0
	/* begin block 1 */
		// Start line: 2526
	/* end block 1 */
	// End Line: 2527

	/* begin block 2 */
		// Start line: 2527
	/* end block 2 */
	// End Line: 2528

void metaCmdSetSoundEffectVolumePan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}





