#include "THISDUST.H"
#include "AADSQCMD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ aadSubstituteVariables(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 23, offset 0x80056074
	/* begin block 1 */
		// Start line: 25
		// Start offset: 0x80056074
		// Variables:
	// 		unsigned char trackFlags; // $a2
	/* end block 1 */
	// End offset: 0x80056124
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

void metaCmdSubstituteVariableParam2(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  
  iVar2 = (int)&(slot->tempo).currentTick + (u_int)event->track;
  bVar1 = *(byte *)(iVar2 + 0x3d8);
  if (((bVar1 & 7) != 0) && (2 < (u_int)event->statusByte - 0x41)) {
    bVar3 = bVar1;
    if ((bVar1 & 1) != 0) {
      bVar3 = bVar1 & 0xfe;
      event->dataByte[0] =
           (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]];
    }
    bVar4 = bVar3;
    if ((bVar1 & 2) != 0) {
      bVar4 = bVar3 & 0xfd;
      event->dataByte[1] =
           (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1]];
    }
    if ((bVar3 & 4) != 0) {
      bVar4 = bVar4 & 0xfb;
      event->dataByte[2] =
           (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[2]];
    }
    *(byte *)(iVar2 + 0x3d8) = bVar4;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSelectChannel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 58, offset 0x8005612c
	/* begin block 1 */
		// Start line: 60
		// Start offset: 0x8005612C
		// Variables:
	// 		int channelNumber; // $v1
	/* end block 1 */
	// End offset: 0x80056144
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

void metaCmdMuteChannelList(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x10) {
    slot->selectedChannel = event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSelectSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 68, offset 0x8005614c
	/* begin block 1 */
		// Start line: 70
		// Start offset: 0x8005614C
		// Variables:
	// 		int slotNumber; // $v1
	/* end block 1 */
	// End offset: 0x80056194
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

void metaCmdSetSlotPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  _AadSequenceSlot *p_Var2;
  
  bVar1 = event->dataByte[0];
  if ((int)(u_int)bVar1 < aadMem->numSlots) {
    p_Var2 = (_AadSequenceSlot *)aadMem->sequenceSlots[(u_int)bVar1];
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
 // line 88, offset 0x8005619c
	/* begin block 1 */
		// Start line: 89
		// Start offset: 0x8005619C
		// Variables:
	// 		int sequenceNumber; // $s1

		/* begin block 1.1 */
			// Start line: 89
			// Start offset: 0x8005619C
			// Variables:
		// 		int bank; // $s0
		/* end block 1.1 */
		// End offset: 0x800561F8
		// End Line: 101
	/* end block 1 */
	// End offset: 0x800561F8
	// End Line: 107

	/* begin block 2 */
		// Start line: 182
	/* end block 2 */
	// End Line: 183

void aadGetNumDynamicSequences(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  int iVar2;
  int bank;
  
  bank = slot->selectedDynamicBank;
  bVar1 = event->dataByte[0];
  if ((aadMem->dynamicBankStatus[bank] == 2) &&
     (iVar2 = aadGetTempoFromDynamicSequence(bank), (int)(u_int)bVar1 < iVar2)) {
    aadGetNumDynamicSequences(bank,(u_int)bVar1,(u_int)slot->selectedSlotNum);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUsePrimaryTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 110, offset 0x80056210
	/* begin block 1 */
		// Start line: 231
	/* end block 1 */
	// End Line: 232

	/* begin block 2 */
		// Start line: 234
	/* end block 2 */
	// End Line: 235

void metaCmdUseSecondaryTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUseSecondaryTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 117, offset 0x80056218
	/* begin block 1 */
		// Start line: 245
	/* end block 1 */
	// End Line: 246

	/* begin block 2 */
		// Start line: 248
	/* end block 2 */
	// End Line: 249

void metaCmdUsePrimaryTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 124, offset 0x80056220
	/* begin block 1 */
		// Start line: 125
		// Start offset: 0x80056220
		// Variables:
	// 		struct AadTempo tempo; // stack offset -16
	/* end block 1 */
	// End offset: 0x80056220
	// End Line: 125

	/* begin block 2 */
		// Start line: 259
	/* end block 2 */
	// End Line: 260

void metaCmdSelectSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  AadTempo local_10;
  
  local_10.quarterNoteTime =
       (u_int)(byte)event->dataByte[0] << 0x10 | (u_int)(byte)event->dataByte[1] << 8 |
       (u_int)(byte)event->dataByte[2];
  local_10.ppqn = (u_int)(slot->selectedSlotPtr->tempo).ppqn;
  aadSetSlotTempo((u_int)slot->selectedSlotNum,&local_10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdChangeTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 137, offset 0x8005628c
	/* begin block 1 */
		// Start line: 138
		// Start offset: 0x8005628C
		// Variables:
	// 		struct AadTempo tempo; // stack offset -16
	// 		struct _AadSequenceSlot *selectedSlot; // $a2
	/* end block 1 */
	// End offset: 0x8005628C
	// End Line: 138

	/* begin block 2 */
		// Start line: 285
	/* end block 2 */
	// End Line: 286

void metaCmdChangeTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  AadTempo local_10;
  
  local_10.quarterNoteTime =
       ((slot->selectedSlotPtr->tempo).quarterNoteTime * 100) / (u_int)(byte)event->dataByte[0];
  local_10.ppqn = (u_int)(slot->selectedSlotPtr->tempo).ppqn;
  aadSetSlotTempo((u_int)slot->selectedSlotNum,&local_10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetTempoFromSequence(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s2*/)
 // line 152, offset 0x800562fc
	/* begin block 1 */
		// Start line: 153
		// Start offset: 0x800562FC
		// Variables:
	// 		int sequenceNumber; // $s1
	// 		struct AadTempo tempo; // stack offset -24

		/* begin block 1.1 */
			// Start line: 153
			// Start offset: 0x800562FC
			// Variables:
		// 		int bank; // $s0
		/* end block 1.1 */
		// End offset: 0x80056364
		// End Line: 170
	/* end block 1 */
	// End offset: 0x80056364
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
     (iVar2 = aadGetTempoFromDynamicSequence(bank), (int)(u_int)bVar1 < iVar2)) {
    metaCmdAssignSequence(bank,(u_int)bVar1,&AStack24);
    aadSetSlotTempo((u_int)slot->selectedSlotNum,&AStack24);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdStartSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 182, offset 0x8005637c
	/* begin block 1 */
		// Start line: 380
	/* end block 1 */
	// End Line: 381

void aadStopSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  PadStartCom((u_int)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdStopSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 189, offset 0x800563a0
	/* begin block 1 */
		// Start line: 394
	/* end block 1 */
	// End Line: 395

void metaCmdStopSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadStopSfx((u_int)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdPauseSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 196, offset 0x800563c4
	/* begin block 1 */
		// Start line: 408
	/* end block 1 */
	// End Line: 409

void metaCmdPauseSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadPauseSlot((u_int)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdResumeSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 203, offset 0x800563e8
	/* begin block 1 */
		// Start line: 422
	/* end block 1 */
	// End Line: 423

void aadResumeSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  metaCmdResumeSlot((u_int)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSlotBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 210, offset 0x8005640c
	/* begin block 1 */
		// Start line: 436
	/* end block 1 */
	// End Line: 437

	/* begin block 2 */
		// Start line: 445
	/* end block 2 */
	// End Line: 446

void metaCmdGetChannelBendRange(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 223, offset 0x80056414
	/* begin block 1 */
		// Start line: 462
	/* end block 1 */
	// End Line: 463

	/* begin block 2 */
		// Start line: 464
	/* end block 2 */
	// End Line: 465

void metaCmdGetChannelTranspose(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSlotVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 229, offset 0x8005641c
	/* begin block 1 */
		// Start line: 230
		// Start offset: 0x8005641C
		// Variables:
	// 		int volume; // $v1
	/* end block 1 */
	// End offset: 0x8005641C
	// End Line: 230

	/* begin block 2 */
		// Start line: 474
	/* end block 2 */
	// End Line: 475

void metaCmdSlotVolumeFade(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->slotVolume = event->dataByte[0];
  aadUpdateSlotVolPan(slot->selectedSlotPtr);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSlotPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 241, offset 0x80056450
	/* begin block 1 */
		// Start line: 242
		// Start offset: 0x80056450
		// Variables:
	// 		int pan; // $v1
	/* end block 1 */
	// End offset: 0x80056450
	// End Line: 242

	/* begin block 2 */
		// Start line: 498
	/* end block 2 */
	// End Line: 499

void metaCmdSetSlotVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->slotPan = event->dataByte[0];
  aadUpdateSlotVolPan(slot->selectedSlotPtr);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 253, offset 0x80056484
	/* begin block 1 */
		// Start line: 254
		// Start offset: 0x80056484
		// Variables:
	// 		int volume; // $a0
	/* end block 1 */
	// End offset: 0x80056484
	// End Line: 254

	/* begin block 2 */
		// Start line: 522
	/* end block 2 */
	// End Line: 523

void metaCmdSetChannelBasePriority(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->volume[slot->selectedChannel] = event->dataByte[0];
  aadUpdateChannelVolPan(slot->selectedSlotPtr,(u_int)slot->selectedChannel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 265, offset 0x800564c0
	/* begin block 1 */
		// Start line: 266
		// Start offset: 0x800564C0
		// Variables:
	// 		int pan; // $a0
	/* end block 1 */
	// End offset: 0x800564C0
	// End Line: 266

	/* begin block 2 */
		// Start line: 547
	/* end block 2 */
	// End Line: 548

void metaCmdSetChannelVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->panPosition[slot->selectedChannel] = event->dataByte[0];
  aadUpdateChannelVolPan(slot->selectedSlotPtr,(u_int)slot->selectedChannel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdEnableSustainUpdate(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 277, offset 0x800564fc
	/* begin block 1 */
		// Start line: 279
		// Start offset: 0x800564FC
		// Variables:
	// 		int channel; // $a0
	/* end block 1 */
	// End offset: 0x800564FC
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
       (ushort)(1 << ((u_int)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdDisableSustainUpdate(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 287, offset 0x8005651c
	/* begin block 1 */
		// Start line: 289
		// Start offset: 0x8005651C
		// Variables:
	// 		int channel; // $v0
	/* end block 1 */
	// End offset: 0x8005651C
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
       ~(ushort)(1 << ((u_int)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdMuteChannel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 297, offset 0x80056540
	/* begin block 1 */
		// Start line: 298
		// Start offset: 0x80056540
	/* end block 1 */
	// End offset: 0x80056540
	// End Line: 298

	/* begin block 2 */
		// Start line: 614
	/* end block 2 */
	// End Line: 615

void aadMuteChannels(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadMuteChannels(slot->selectedSlotPtr,1 << ((u_int)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUnMuteChannel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 307, offset 0x8005656c
	/* begin block 1 */
		// Start line: 308
		// Start offset: 0x8005656C
	/* end block 1 */
	// End offset: 0x8005656C
	// End Line: 308

	/* begin block 2 */
		// Start line: 637
	/* end block 2 */
	// End Line: 638

void metaCmdUnMuteChannelList(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  metaCmdUnMuteChannel(slot->selectedSlotPtr,1 << ((u_int)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdMuteChannelList(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 317, offset 0x80056598
	/* begin block 1 */
		// Start line: 318
		// Start offset: 0x80056598
	/* end block 1 */
	// End offset: 0x80056598
	// End Line: 318

	/* begin block 2 */
		// Start line: 660
	/* end block 2 */
	// End Line: 661

void metaCmdGetChannelPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadMuteChannels(slot->selectedSlotPtr,(u_int)*(ushort *)event->dataByte);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUnMuteChannelList(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 327, offset 0x800565c8
	/* begin block 1 */
		// Start line: 328
		// Start offset: 0x800565C8
	/* end block 1 */
	// End offset: 0x800565C8
	// End Line: 328

	/* begin block 2 */
		// Start line: 681
	/* end block 2 */
	// End Line: 682

void aadUnMuteChannels(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  metaCmdUnMuteChannel(slot->selectedSlotPtr,(u_int)*(ushort *)event->dataByte);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelMute(struct AadSeqEvent *event /*$v0*/, struct _AadSequenceSlot *slot /*$s1*/)
 // line 337, offset 0x800565f8
	/* begin block 1 */
		// Start line: 338
		// Start offset: 0x800565F8
		// Variables:
	// 		unsigned long muteChannelMask; // $s0
	/* end block 1 */
	// End offset: 0x800565F8
	// End Line: 338

	/* begin block 2 */
		// Start line: 702
	/* end block 2 */
	// End Line: 703

void metaCmdGetChannelVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)event->dataByte;
  metaCmdUnMuteChannel(slot->selectedSlotPtr,~(u_int)uVar1);
  aadMuteChannels(slot->selectedSlotPtr,(u_int)uVar1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdDelayMute(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 349, offset 0x8005664c
	/* begin block 1 */
		// Start line: 351
		// Start offset: 0x8005664C
		// Variables:
	// 		unsigned long channelMask; // $v1
	/* end block 1 */
	// End offset: 0x8005664C
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
 // line 362, offset 0x80056670
	/* begin block 1 */
		// Start line: 363
		// Start offset: 0x80056670
		// Variables:
	// 		unsigned long channelMask; // $s0
	// 		unsigned long mask; // $a1
	/* end block 1 */
	// End offset: 0x800566F0
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
    aadMuteChannels(slot_00,(u_int)uVar2);
    slot_00 = slot->selectedSlotPtr;
  }
  uVar1 = slot_00->delayedUnMuteCmds & uVar1;
  if (uVar1 != 0) {
    metaCmdUnMuteChannel(slot_00,(u_int)uVar1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdChannelVolumeFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 379, offset 0x80056704
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
 // line 393, offset 0x8005670c
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
 // line 407, offset 0x80056714
	/* begin block 1 */
		// Start line: 849
	/* end block 1 */
	// End Line: 850

	/* begin block 2 */
		// Start line: 858
	/* end block 2 */
	// End Line: 859

void metaCmdSlotPanFade(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSlotPanFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 420, offset 0x8005671c
	/* begin block 1 */
		// Start line: 875
	/* end block 1 */
	// End Line: 876

	/* begin block 2 */
		// Start line: 884
	/* end block 2 */
	// End Line: 885

void metaCmdStartSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelProgram(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 433, offset 0x80056724
	/* begin block 1 */
		// Start line: 435
		// Start offset: 0x80056724
		// Variables:
	// 		int program; // $a0
	/* end block 1 */
	// End offset: 0x80056724
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

void metaCmdSetChannelPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->currentProgram[slot->selectedChannel] = event->dataByte[0];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelBasePriority(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 443, offset 0x8005673c
	/* begin block 1 */
		// Start line: 922
	/* end block 1 */
	// End Line: 923

	/* begin block 2 */
		// Start line: 942
	/* end block 2 */
	// End Line: 943

void metaCmdSetChannelBendRange(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 467, offset 0x80056744
	/* begin block 1 */
		// Start line: 469
		// Start offset: 0x80056744
		// Variables:
	// 		int channel; // $a2
	// 		int transpose; // $v1
	/* end block 1 */
	// End offset: 0x80056744
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

void metaCmdSetChannelPitchMap(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->transpose[slot->selectedChannel] = event->dataByte[0];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdIgnoreChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 478, offset 0x8005675c
	/* begin block 1 */
		// Start line: 480
		// Start offset: 0x8005675C
		// Variables:
	// 		int channel; // $a0
	/* end block 1 */
	// End offset: 0x8005675C
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
       slot->selectedSlotPtr->ignoreTranspose | (ushort)(1 << ((u_int)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdRespectChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 488, offset 0x8005677c
	/* begin block 1 */
		// Start line: 490
		// Start offset: 0x8005677C
		// Variables:
	// 		int channel; // $v0
	/* end block 1 */
	// End offset: 0x8005677C
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
       slot->selectedSlotPtr->ignoreTranspose & ~(ushort)(1 << ((u_int)slot->selectedChannel & 0x1f))
  ;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 498, offset 0x800567a0
	/* begin block 1 */
		// Start line: 1035
	/* end block 1 */
	// End Line: 1036

	/* begin block 2 */
		// Start line: 1046
	/* end block 2 */
	// End Line: 1047

void metaCmdIgnoreChannelPitchMap(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdIgnoreChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 513, offset 0x800567a8
	/* begin block 1 */
		// Start line: 1065
	/* end block 1 */
	// End Line: 1066

	/* begin block 2 */
		// Start line: 1073
	/* end block 2 */
	// End Line: 1074

void metaCmdRespectChannelPitchMap(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdRespectChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 525, offset 0x800567b0
	/* begin block 1 */
		// Start line: 1089
	/* end block 1 */
	// End Line: 1090

	/* begin block 2 */
		// Start line: 1097
	/* end block 2 */
	// End Line: 1098

void metaCmdChannelPanFade(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSequenceAssigned(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 537, offset 0x800567b8
	/* begin block 1 */
		// Start line: 539
		// Start offset: 0x800567B8
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x800567E0
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

void metaCmdSetSequencePosition(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->sequenceNumberAssigned;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 549, offset 0x800567e8
	/* begin block 1 */
		// Start line: 551
		// Start offset: 0x800567E8
		// Variables:
	// 		int variableNum1; // $a2
	// 		int variableNum2; // $a3
	// 		int variableNum3; // $t0
	// 		unsigned long quarterNoteTime; // $a0
	/* end block 1 */
	// End offset: 0x80056844
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
  u_long uVar3;
  
  bVar1 = event->dataByte[1];
  bVar2 = event->dataByte[2];
  if ((((byte)event->dataByte[0] < 0x80) && (bVar1 < 0x80)) && (bVar2 < 0x80)) {
    uVar3 = (slot->selectedSlotPtr->tempo).quarterNoteTime;
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] = (char)uVar3;
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)bVar1] = (char)(uVar3 >> 8);
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)bVar2] = (char)(uVar3 >> 0x10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSlotStatus(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 570, offset 0x8005684c
	/* begin block 1 */
		// Start line: 572
		// Start offset: 0x8005684C
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x80056874
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
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
         *(undefined *)&slot->selectedSlotPtr->status;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelMute(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 582, offset 0x8005687c
	/* begin block 1 */
		// Start line: 584
		// Start offset: 0x8005687C
		// Variables:
	// 		int variableNum1; // $a2
	// 		int variableNum2; // $a0
	/* end block 1 */
	// End offset: 0x800568C4
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
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
         *(undefined *)&slot->selectedSlotPtr->channelMute;
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)bVar1] =
         (char)(slot->selectedSlotPtr->channelMute >> 8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 598, offset 0x800568cc
	/* begin block 1 */
		// Start line: 600
		// Start offset: 0x800568CC
		// Variables:
	// 		int variableNum; // $a0
	// 		int channel; // $v1
	/* end block 1 */
	// End offset: 0x800568FC
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

void metaCmdSetChannelTranspose(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->volume[slot->selectedChannel];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 611, offset 0x80056904
	/* begin block 1 */
		// Start line: 613
		// Start offset: 0x80056904
		// Variables:
	// 		int variableNum; // $a0
	// 		int channel; // $v1
	/* end block 1 */
	// End offset: 0x80056934
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

void metaCmdMuteChannel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->panPosition[slot->selectedChannel];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 623, offset 0x8005693c
	/* begin block 1 */
		// Start line: 1286
	/* end block 1 */
	// End Line: 1287

	/* begin block 2 */
		// Start line: 1296
	/* end block 2 */
	// End Line: 1297

void metaCmdSetSlotBendRange(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelProgram(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 637, offset 0x80056944
	/* begin block 1 */
		// Start line: 639
		// Start offset: 0x80056944
		// Variables:
	// 		int variableNum; // $a0
	// 		int channel; // $v1
	/* end block 1 */
	// End offset: 0x80056974
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

void metaCmdSetChannelProgram(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->currentProgram[slot->selectedChannel];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelBasePriority(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 649, offset 0x8005697c
	/* begin block 1 */
		// Start line: 1338
	/* end block 1 */
	// End Line: 1339

	/* begin block 2 */
		// Start line: 1355
	/* end block 2 */
	// End Line: 1356

void metaCmdSetChannelMute(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 670, offset 0x80056984
	/* begin block 1 */
		// Start line: 1380
	/* end block 1 */
	// End Line: 1381

	/* begin block 2 */
		// Start line: 1389
	/* end block 2 */
	// End Line: 1390

void metaCmdSelectChannel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSlotVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 683, offset 0x8005698c
	/* begin block 1 */
		// Start line: 685
		// Start offset: 0x8005698C
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x800569B4
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
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->slotVolume;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSlotPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 695, offset 0x800569bc
	/* begin block 1 */
		// Start line: 697
		// Start offset: 0x800569BC
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x800569E4
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

void metaCmdSetTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
         slot->selectedSlotPtr->slotPan;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 706, offset 0x800569ec
	/* begin block 1 */
		// Start line: 708
		// Start offset: 0x800569EC
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $v1
	/* end block 1 */
	// End offset: 0x80056A10
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

void aadSetUserVariable(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[1] < 0x80) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1]] =
         event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdCopyVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 718, offset 0x80056a18
	/* begin block 1 */
		// Start line: 720
		// Start offset: 0x80056A18
		// Variables:
	// 		int srcVariable; // $v1
	// 		int destVariable; // $a0
	/* end block 1 */
	// End offset: 0x80056A4C
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

void metaCmdSetVariableBits(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (((byte)event->dataByte[0] < 0x80) && ((byte)event->dataByte[1] < 0x80)) {
    (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1]] =
         (&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdAddVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 731, offset 0x80056a54
	/* begin block 1 */
		// Start line: 733
		// Start offset: 0x80056A54
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $a1
	/* end block 1 */
	// End offset: 0x80056A84
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
    iVar1 = (int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1];
    (&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] + event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSubtractVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 743, offset 0x80056a8c
	/* begin block 1 */
		// Start line: 745
		// Start offset: 0x80056A8C
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $a1
	/* end block 1 */
	// End offset: 0x80056ABC
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
    iVar1 = (int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1];
    (&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] - event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetVariableBits(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 755, offset 0x80056ac4
	/* begin block 1 */
		// Start line: 757
		// Start offset: 0x80056AC4
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $a1
	/* end block 1 */
	// End offset: 0x80056AF4
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

void metaCmdSetVariable(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  if ((byte)event->dataByte[1] < 0x80) {
    iVar1 = (int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1];
    (&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] | event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdClearVariableBits(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 767, offset 0x80056afc
	/* begin block 1 */
		// Start line: 769
		// Start offset: 0x80056AFC
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $v1
	/* end block 1 */
	// End offset: 0x80056B2C
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

void metaCmdCopyVariable(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  if ((byte)event->dataByte[1] < 0x80) {
    iVar1 = (int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1];
    (&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] & ~event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadGotoSequencePosition(struct _AadSequenceSlot *slot /*$a0*/, int track /*$a1*/, unsigned char *newPosition /*$a2*/)
 // line 779, offset 0x80056b34
	/* begin block 1 */
		// Start line: 1603
	/* end block 1 */
	// End Line: 1604

	/* begin block 2 */
		// Start line: 1605
	/* end block 2 */
	// End Line: 1606

void metaCmdGetSequenceAssigned(_AadSequenceSlot *slot,int track,u_char *newPosition)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (int)&(slot->tempo).currentTick + track;
  *(u_char **)(slot->sequencePosition + track) = newPosition;
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
 // line 800, offset 0x80056ba0
	/* begin block 1 */
		// Start line: 801
		// Start offset: 0x80056BA0
		// Variables:
	// 		struct AadSequenceHdr *seqHdr; // $v0
	// 		unsigned long trackOffset; // $a0
	// 		int bank; // $v0
	/* end block 1 */
	// End offset: 0x80056C44
	// End Line: 835

	/* begin block 2 */
		// Start line: 1650
	/* end block 2 */
	// End Line: 1651

void aadGotoSequencePosition(_AadSequenceSlot *slot,int track,int labelNumber)

{
  int iVar1;
  char cVar2;
  
  iVar1 = *(int *)((&aadMem->updateCounter + slot->sequenceAssignedDynamicBank)[0x13c] +
                  (u_int)slot->sequenceNumberAssigned * 4);
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
 // line 842, offset 0x80056c58
	/* begin block 1 */
		// Start line: 844
		// Start offset: 0x80056C58
		// Variables:
	// 		int nestLevel; // $a2
	// 		int track; // $a3
	/* end block 1 */
	// End offset: 0x80056CB4
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
  u_int uVar2;
  int iVar3;
  
  uVar2 = (u_int)event->track;
  iVar3 = (int)&(slot->tempo).currentTick + uVar2;
  bVar1 = *(byte *)(iVar3 + 0x4e8);
  if (bVar1 < 4) {
    *(_func_9 **)(slot->loopSequencePosition + (u_int)bVar1 * 0x10 + uVar2) =
         slot->sequencePosition[uVar2];
    slot->loopCounter[uVar2 + (u_int)bVar1 * 0x10] = event->dataByte[0];
    *(char *)(iVar3 + 0x4e8) = *(char *)(iVar3 + 0x4e8) + '\x01';
  }
  *(byte *)(iVar3 + 0x3d8) = *(byte *)(iVar3 + 0x3d8) & 0xef;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdLoopEnd(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a3*/)
 // line 863, offset 0x80056cc8
	/* begin block 1 */
		// Start line: 864
		// Start offset: 0x80056CC8
		// Variables:
	// 		int prevNestLevel; // $v1
	// 		int track; // $a1
	/* end block 1 */
	// End offset: 0x80056D48
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
  u_int track;
  int iVar5;
  
  track = (u_int)event->track;
  iVar5 = (int)&(slot->tempo).currentTick + track;
  bVar1 = *(byte *)(iVar5 + 0x4e8);
  iVar3 = (u_int)bVar1 - 1;
  if (bVar1 != 0) {
    iVar4 = (int)&(slot->tempo).currentTick + track + iVar3 * 0x10;
    cVar2 = *(char *)(iVar4 + 0x4f8);
    if ((cVar2 == '\0') || (*(char *)(iVar4 + 0x4f8) = cVar2 + -1, cVar2 != '\x01')) {
      metaCmdGetSequenceAssigned
                (slot,track,(u_char *)slot->loopSequencePosition[iVar3 * 0x10 + track]);
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
 // line 891, offset 0x80056d58
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
 // line 898, offset 0x80056d60
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
 // line 909, offset 0x80056d68
	/* begin block 1 */
		// Start line: 910
		// Start offset: 0x80056D68
	/* end block 1 */
	// End offset: 0x80056D68
	// End Line: 910

	/* begin block 2 */
		// Start line: 1884
	/* end block 2 */
	// End Line: 1885

void metaCmdGotoLabel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadGotoSequencePosition(slot,(u_int)event->track,(u_int)(byte)event->dataByte[0]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSequencePosition(struct AadSeqEvent *event /*$v0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 919, offset 0x80056d98
	/* begin block 1 */
		// Start line: 920
		// Start offset: 0x80056D98
	/* end block 1 */
	// End offset: 0x80056D98
	// End Line: 920

	/* begin block 2 */
		// Start line: 1908
	/* end block 2 */
	// End Line: 1909

void aadGotoSequenceLabel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadGotoSequencePosition(slot->selectedSlotPtr,(u_int)event->track,(u_int)(byte)event->dataByte[0]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 929, offset 0x80056dc8
	/* begin block 1 */
		// Start line: 930
		// Start offset: 0x80056DC8
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056E04
	// End Line: 940

	/* begin block 2 */
		// Start line: 1928
	/* end block 2 */
	// End Line: 1929

void metaCmdBranchIfVarEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] ==
      event->dataByte[1]) {
    aadGotoSequencePosition(slot,(u_int)event->track,(u_int)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarNotEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 943, offset 0x80056e14
	/* begin block 1 */
		// Start line: 944
		// Start offset: 0x80056E14
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056E50
	// End Line: 954

	/* begin block 2 */
		// Start line: 1968
	/* end block 2 */
	// End Line: 1969

void metaCmdBranchIfVarGreater(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] !=
      event->dataByte[1]) {
    aadGotoSequencePosition(slot,(u_int)event->track,(u_int)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarLess(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 957, offset 0x80056e60
	/* begin block 1 */
		// Start line: 958
		// Start offset: 0x80056E60
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056EA0
	// End Line: 968

	/* begin block 2 */
		// Start line: 2008
	/* end block 2 */
	// End Line: 2009

void metaCmdBranchIfVarLess(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] <
      (byte)event->dataByte[1]) {
    aadGotoSequencePosition(slot,(u_int)event->track,(u_int)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarGreater(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 971, offset 0x80056eb0
	/* begin block 1 */
		// Start line: 972
		// Start offset: 0x80056EB0
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056EF0
	// End Line: 982

	/* begin block 2 */
		// Start line: 2048
	/* end block 2 */
	// End Line: 2049

void metaCmdBranchIfVarNotEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[1] <
      (byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]]) {
    aadGotoSequencePosition(slot,(u_int)event->track,(u_int)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarLessOrEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 985, offset 0x80056f00
	/* begin block 1 */
		// Start line: 986
		// Start offset: 0x80056F00
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056F40
	// End Line: 996

	/* begin block 2 */
		// Start line: 2088
	/* end block 2 */
	// End Line: 2089

void metaCmdBranchIfVarLessOrEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] <=
      (byte)event->dataByte[1]) {
    aadGotoSequencePosition(slot,(u_int)event->track,(u_int)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarGreaterOrEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 999, offset 0x80056f50
	/* begin block 1 */
		// Start line: 1000
		// Start offset: 0x80056F50
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056F90
	// End Line: 1010

	/* begin block 2 */
		// Start line: 2128
	/* end block 2 */
	// End Line: 2129

void metaCmdBranchIfVarBitsSet(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[1] <=
      (byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]]) {
    aadGotoSequencePosition(slot,(u_int)event->track,(u_int)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarBitsSet(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 1013, offset 0x80056fa0
	/* begin block 1 */
		// Start line: 1014
		// Start offset: 0x80056FA0
		// Variables:
	// 		int variableNum; // $v1
	// 		int mask; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80056FE0
	// End Line: 1023

	/* begin block 2 */
		// Start line: 2168
	/* end block 2 */
	// End Line: 2169

void metaCmdBranchIfVarGreaterOrEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (((&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] &
      event->dataByte[1]) != 0) {
    aadGotoSequencePosition(slot,(u_int)event->track,(u_int)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarBitsClear(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 1026, offset 0x80056ff0
	/* begin block 1 */
		// Start line: 1027
		// Start offset: 0x80056FF0
		// Variables:
	// 		int variableNum; // $v1
	// 		int mask; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80057030
	// End Line: 1036

	/* begin block 2 */
		// Start line: 2203
	/* end block 2 */
	// End Line: 2204

void metaCmdBranchIfVarBitsClear(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (((&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] &
      event->dataByte[1]) == 0) {
    aadGotoSequencePosition(slot,(u_int)event->track,(u_int)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSubstituteVariableParam1(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1039, offset 0x80057040
	/* begin block 1 */
		// Start line: 2238
	/* end block 1 */
	// End Line: 2239

	/* begin block 2 */
		// Start line: 2239
	/* end block 2 */
	// End Line: 2240

void metaCmdSubstituteVariableParam3(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  iVar1 = (int)&(slot->tempo).currentTick + (u_int)event->track;
  *(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSubstituteVariableParam2(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1046, offset 0x80057060
	/* begin block 1 */
		// Start line: 2252
	/* end block 1 */
	// End Line: 2253

	/* begin block 2 */
		// Start line: 2253
	/* end block 2 */
	// End Line: 2254

void metaCmdSubstituteVariableParam1(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  iVar1 = (int)&(slot->tempo).currentTick + (u_int)event->track;
  *(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSubstituteVariableParam3(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1053, offset 0x80057080
	/* begin block 1 */
		// Start line: 2266
	/* end block 1 */
	// End Line: 2267

	/* begin block 2 */
		// Start line: 2267
	/* end block 2 */
	// End Line: 2268

void aadSubstituteVariables(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  int iVar1;
  
  iVar1 = (int)&(slot->tempo).currentTick + (u_int)event->track;
  *(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 4;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdEndSequence(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s0*/)
 // line 1059, offset 0x800570a0
	/* begin block 1 */
		// Start line: 2278
	/* end block 1 */
	// End Line: 2279

void aadAssignDynamicSequence(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadInitSequenceSlot(slot);
  aadAllNotesOff((u_int)slot->thisSlotNumber);
  if (aadMem->endSequenceCallback != (_func_49 *)0x0) {
    (*aadMem->endSequenceCallback)(aadMem->endSequenceCallbackData,(u_int)slot->thisSlotNumber,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdPlaySoundEffect(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1177, offset 0x800570fc
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
 // line 1180, offset 0x80057104
	/* begin block 1 */
		// Start line: 2520
	/* end block 1 */
	// End Line: 2521

	/* begin block 2 */
		// Start line: 2521
	/* end block 2 */
	// End Line: 2522

void metaCmdSetSoundEffectVolumePan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSoundEffectVolumePan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1183, offset 0x8005710c
	/* begin block 1 */
		// Start line: 2526
	/* end block 1 */
	// End Line: 2527

	/* begin block 2 */
		// Start line: 2527
	/* end block 2 */
	// End Line: 2528

void metaCmdStopSoundEffect(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}





