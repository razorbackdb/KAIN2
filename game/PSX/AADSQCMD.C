#include "THISDUST.H"
#include "AADSQCMD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ aadSubstituteVariables(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 23, offset 0x80057008
	/* begin block 1 */
		// Start line: 25
		// Start offset: 0x80057008
		// Variables:
	// 		unsigned char trackFlags; // $a2
	/* end block 1 */
	// End offset: 0x800570B8
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
      event->dataByte[0] = *(char *)((uint)(byte)event->dataByte[0] + 0x1b6c);
    }
    bVar4 = bVar3;
    if ((bVar1 & 2) != 0) {
      bVar4 = bVar3 & 0xfd;
      event->dataByte[1] = *(char *)((uint)(byte)event->dataByte[1] + 0x1b6c);
    }
    if ((bVar3 & 4) != 0) {
      bVar4 = bVar4 & 0xfb;
      event->dataByte[2] = *(char *)((uint)(byte)event->dataByte[2] + 0x1b6c);
    }
    *(byte *)(iVar2 + 0x3d8) = bVar4;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSelectChannel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 58, offset 0x800570c0
	/* begin block 1 */
		// Start line: 60
		// Start offset: 0x800570C0
		// Variables:
	// 		int channelNumber; // $v1
	/* end block 1 */
	// End offset: 0x800570D8
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
 // line 68, offset 0x800570e0
	/* begin block 1 */
		// Start line: 70
		// Start offset: 0x800570E0
		// Variables:
	// 		int slotNumber; // $v1
	/* end block 1 */
	// End offset: 0x80057128
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
  if ((uint)bVar1 < (uint)mainMenuScreen) {
    p_Var2 = *(_AadSequenceSlot **)((uint)bVar1 * 4 + 0x1c);
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
 // line 88, offset 0x80057130
	/* begin block 1 */
		// Start line: 89
		// Start offset: 0x80057130
		// Variables:
	// 		int sequenceNumber; // $s1

		/* begin block 1.1 */
			// Start line: 89
			// Start offset: 0x80057130
		/* end block 1.1 */
		// End offset: 0x80057188
		// End Line: 101
	/* end block 1 */
	// End offset: 0x80057188
	// End Line: 107

	/* begin block 2 */
		// Start line: 182
	/* end block 2 */
	// End Line: 183

	/* begin block 3 */
		// Start line: 190
	/* end block 3 */
	// End Line: 191

void metaCmdAssignSequence(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  int iVar2;
  uint bank;
  
  bank = (uint)slot->slotFlags;
  bVar1 = event->dataByte[0];
  if ((*(char *)(bank + 0x4e8) == '\x02') &&
     (iVar2 = aadGetNumDynamicSequences(bank), (int)(uint)bVar1 < iVar2)) {
    aadAssignDynamicSequence(bank,(uint)bVar1,(uint)slot->selectedSlotNum);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUsePrimaryTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 110, offset 0x800571a0
	/* begin block 1 */
		// Start line: 239
	/* end block 1 */
	// End Line: 240

	/* begin block 2 */
		// Start line: 242
	/* end block 2 */
	// End Line: 243

void metaCmdUsePrimaryTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUseSecondaryTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 117, offset 0x800571a8
	/* begin block 1 */
		// Start line: 253
	/* end block 1 */
	// End Line: 254

	/* begin block 2 */
		// Start line: 256
	/* end block 2 */
	// End Line: 257

void metaCmdUseSecondaryTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 124, offset 0x800571b0
	/* begin block 1 */
		// Start line: 125
		// Start offset: 0x800571B0
		// Variables:
	// 		struct AadTempo tempo; // stack offset -16
	/* end block 1 */
	// End offset: 0x800571B0
	// End Line: 125

	/* begin block 2 */
		// Start line: 267
	/* end block 2 */
	// End Line: 268

void metaCmdSetTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  uint local_10;
  ushort local_c;
  
  local_10 = (uint)(byte)event->dataByte[0] << 0x10 | (uint)(byte)event->dataByte[1] << 8 |
             (uint)(byte)event->dataByte[2];
  local_c = (slot->selectedSlotPtr->tempo).ppqn;
  aadSetSlotTempo((uint)slot->selectedSlotNum,(AadTempo *)&local_10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdChangeTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 137, offset 0x8005721c
	/* begin block 1 */
		// Start line: 138
		// Start offset: 0x8005721C
		// Variables:
	// 		struct AadTempo tempo; // stack offset -16
	// 		struct _AadSequenceSlot *selectedSlot; // $a2
	/* end block 1 */
	// End offset: 0x8005721C
	// End Line: 138

	/* begin block 2 */
		// Start line: 293
	/* end block 2 */
	// End Line: 294

void metaCmdChangeTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  uint local_10;
  ushort local_c;
  
  local_10 = ((slot->selectedSlotPtr->tempo).quarterNoteTime * 100) / (uint)(byte)event->dataByte[0]
  ;
  local_c = (slot->selectedSlotPtr->tempo).ppqn;
  aadSetSlotTempo((uint)slot->selectedSlotNum,(AadTempo *)&local_10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetTempoFromSequence(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s2*/)
 // line 152, offset 0x8005728c
	/* begin block 1 */
		// Start line: 153
		// Start offset: 0x8005728C
		// Variables:
	// 		int sequenceNumber; // $s1
	// 		struct AadTempo tempo; // stack offset -24

		/* begin block 1.1 */
			// Start line: 153
			// Start offset: 0x8005728C
			// Variables:
		// 		int bank; // $s0
		/* end block 1.1 */
		// End offset: 0x800572F0
		// End Line: 170
	/* end block 1 */
	// End offset: 0x800572F0
	// End Line: 179

	/* begin block 2 */
		// Start line: 323
	/* end block 2 */
	// End Line: 324

void metaCmdSetTempoFromSequence(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  int iVar2;
  uint bank;
  AadTempo AStack24;
  
  bank = (uint)slot->slotFlags;
  bVar1 = event->dataByte[0];
  if ((*(char *)(bank + 0x4e8) == '\x02') &&
     (iVar2 = aadGetNumDynamicSequences(bank), (int)(uint)bVar1 < iVar2)) {
    aadGetTempoFromDynamicSequence(bank,(uint)bVar1,&AStack24);
    aadSetSlotTempo((uint)slot->selectedSlotNum,&AStack24);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdStartSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 182, offset 0x80057308
	/* begin block 1 */
		// Start line: 388
	/* end block 1 */
	// End Line: 389

void metaCmdStartSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadStartSlot((uint)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdStopSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 189, offset 0x8005732c
	/* begin block 1 */
		// Start line: 402
	/* end block 1 */
	// End Line: 403

void metaCmdStopSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadStopSlot((uint)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdPauseSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 196, offset 0x80057350
	/* begin block 1 */
		// Start line: 416
	/* end block 1 */
	// End Line: 417

void metaCmdPauseSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadPauseSlot((uint)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdResumeSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 203, offset 0x80057374
	/* begin block 1 */
		// Start line: 430
	/* end block 1 */
	// End Line: 431

void metaCmdResumeSlot(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadResumeSlot((uint)slot->selectedSlotNum);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSlotBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 210, offset 0x80057398
	/* begin block 1 */
		// Start line: 444
	/* end block 1 */
	// End Line: 445

	/* begin block 2 */
		// Start line: 453
	/* end block 2 */
	// End Line: 454

void metaCmdSetSlotBendRange(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 223, offset 0x800573a0
	/* begin block 1 */
		// Start line: 470
	/* end block 1 */
	// End Line: 471

	/* begin block 2 */
		// Start line: 472
	/* end block 2 */
	// End Line: 473

void metaCmdSetChannelBendRange(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSlotVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 229, offset 0x800573a8
	/* begin block 1 */
		// Start line: 230
		// Start offset: 0x800573A8
		// Variables:
	// 		int volume; // $v1
	/* end block 1 */
	// End offset: 0x800573A8
	// End Line: 230

	/* begin block 2 */
		// Start line: 482
	/* end block 2 */
	// End Line: 483

void metaCmdSetSlotVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  *(char *)&slot->selectedSlotPtr->unused = event->dataByte[0];
  aadUpdateSlotVolPan(slot->selectedSlotPtr);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSlotPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 241, offset 0x800573dc
	/* begin block 1 */
		// Start line: 242
		// Start offset: 0x800573DC
		// Variables:
	// 		int pan; // $v1
	/* end block 1 */
	// End offset: 0x800573DC
	// End Line: 242

	/* begin block 2 */
		// Start line: 506
	/* end block 2 */
	// End Line: 507

void metaCmdSetSlotPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  *(char *)((int)&slot->selectedSlotPtr->unused + 1) = event->dataByte[0];
  aadUpdateSlotVolPan(slot->selectedSlotPtr);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 253, offset 0x80057410
	/* begin block 1 */
		// Start line: 254
		// Start offset: 0x80057410
		// Variables:
	// 		int volume; // $a0
	/* end block 1 */
	// End offset: 0x80057410
	// End Line: 254

	/* begin block 2 */
		// Start line: 530
	/* end block 2 */
	// End Line: 531

void metaCmdSetChannelVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->volume[(uint)slot->selectedChannel + 4] = event->dataByte[0];
  aadUpdateChannelVolPan(slot->selectedSlotPtr,(uint)slot->selectedChannel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 265, offset 0x8005744c
	/* begin block 1 */
		// Start line: 266
		// Start offset: 0x8005744C
		// Variables:
	// 		int pan; // $a0
	/* end block 1 */
	// End offset: 0x8005744C
	// End Line: 266

	/* begin block 2 */
		// Start line: 555
	/* end block 2 */
	// End Line: 556

void metaCmdSetChannelPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->panPosition[(uint)slot->selectedChannel + 4] = event->dataByte[0];
  aadUpdateChannelVolPan(slot->selectedSlotPtr,(uint)slot->selectedChannel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdEnableSustainUpdate(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 277, offset 0x80057488
	/* begin block 1 */
		// Start line: 279
		// Start offset: 0x80057488
		// Variables:
	// 		int channel; // $a0
	/* end block 1 */
	// End offset: 0x80057488
	// End Line: 282

	/* begin block 2 */
		// Start line: 580
	/* end block 2 */
	// End Line: 581

	/* begin block 3 */
		// Start line: 581
	/* end block 3 */
	// End Line: 582

	/* begin block 4 */
		// Start line: 584
	/* end block 4 */
	// End Line: 585

void metaCmdEnableSustainUpdate(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->delayedMuteMode =
       slot->selectedSlotPtr->delayedMuteMode | (ushort)(1 << ((uint)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdDisableSustainUpdate(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 287, offset 0x800574a8
	/* begin block 1 */
		// Start line: 289
		// Start offset: 0x800574A8
		// Variables:
	// 		int channel; // $v0
	/* end block 1 */
	// End offset: 0x800574A8
	// End Line: 292

	/* begin block 2 */
		// Start line: 601
	/* end block 2 */
	// End Line: 602

	/* begin block 3 */
		// Start line: 602
	/* end block 3 */
	// End Line: 603

	/* begin block 4 */
		// Start line: 605
	/* end block 4 */
	// End Line: 606

void metaCmdDisableSustainUpdate(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->delayedMuteMode =
       slot->selectedSlotPtr->delayedMuteMode & ~(ushort)(1 << ((uint)slot->selectedChannel & 0x1f))
  ;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdMuteChannel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 297, offset 0x800574cc
	/* begin block 1 */
		// Start line: 298
		// Start offset: 0x800574CC
		// Variables:
	// 		unsigned short channelMask; // $v0
	/* end block 1 */
	// End offset: 0x800574CC
	// End Line: 298

	/* begin block 2 */
		// Start line: 622
	/* end block 2 */
	// End Line: 623

void metaCmdMuteChannel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadMuteChannels((uint)slot->selectedSlotNum,1 << ((uint)slot->selectedChannel & 0x1f) & 0xffff);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUnMuteChannel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 307, offset 0x800574fc
	/* begin block 1 */
		// Start line: 308
		// Start offset: 0x800574FC
		// Variables:
	// 		unsigned short channelMask; // $v0
	/* end block 1 */
	// End offset: 0x800574FC
	// End Line: 308

	/* begin block 2 */
		// Start line: 646
	/* end block 2 */
	// End Line: 647

void metaCmdUnMuteChannel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadUnMuteChannels((uint)slot->selectedSlotNum,1 << ((uint)slot->selectedChannel & 0x1f) & 0xffff);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdMuteChannelList(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 317, offset 0x8005752c
	/* begin block 1 */
		// Start line: 318
		// Start offset: 0x8005752C
	/* end block 1 */
	// End offset: 0x8005752C
	// End Line: 318

	/* begin block 2 */
		// Start line: 670
	/* end block 2 */
	// End Line: 671

void metaCmdMuteChannelList(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadMuteChannels((uint)slot->selectedSlotNum,(uint)*(ushort *)event->dataByte);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelMute(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s1*/)
 // line 327, offset 0x8005755c
	/* begin block 1 */
		// Start line: 328
		// Start offset: 0x8005755C
		// Variables:
	// 		int variableNum1; // $a2
	// 		int variableNum2; // $a1
	/* end block 1 */
	// End offset: 0x800575C0
	// End Line: 341

	/* begin block 2 */
		// Start line: 691
	/* end block 2 */
	// End Line: 692

void metaCmdSetChannelMute(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  uint channelList;
  
  if (((byte)event->dataByte[0] < 0x80) && ((byte)event->dataByte[1] < 0x80)) {
    channelList = (uint)CONCAT11(*(undefined *)((uint)(byte)event->dataByte[1] + 0x1b6c),
                                 *(undefined *)((uint)(byte)event->dataByte[0] + 0x1b6c));
    aadUnMuteChannels((uint)slot->selectedSlotNum,~channelList);
    aadMuteChannels((uint)slot->selectedSlotNum,channelList);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdUnMuteChannelList(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 344, offset 0x800575d4
	/* begin block 1 */
		// Start line: 345
		// Start offset: 0x800575D4
	/* end block 1 */
	// End offset: 0x800575D4
	// End Line: 345

	/* begin block 2 */
		// Start line: 726
	/* end block 2 */
	// End Line: 727

void metaCmdUnMuteChannelList(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadUnMuteChannels((uint)slot->selectedSlotNum,(uint)*(ushort *)event->dataByte);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdChannelVolumeFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 354, offset 0x80057604
	/* begin block 1 */
		// Start line: 747
	/* end block 1 */
	// End Line: 748

	/* begin block 2 */
		// Start line: 757
	/* end block 2 */
	// End Line: 758

void metaCmdChannelVolumeFade(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdChannelPanFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 368, offset 0x8005760c
	/* begin block 1 */
		// Start line: 775
	/* end block 1 */
	// End Line: 776

	/* begin block 2 */
		// Start line: 785
	/* end block 2 */
	// End Line: 786

void metaCmdChannelPanFade(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSlotVolumeFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 382, offset 0x80057614
	/* begin block 1 */
		// Start line: 803
	/* end block 1 */
	// End Line: 804

	/* begin block 2 */
		// Start line: 812
	/* end block 2 */
	// End Line: 813

void metaCmdSlotVolumeFade(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSlotPanFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 395, offset 0x8005761c
	/* begin block 1 */
		// Start line: 829
	/* end block 1 */
	// End Line: 830

	/* begin block 2 */
		// Start line: 838
	/* end block 2 */
	// End Line: 839

void metaCmdSlotPanFade(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelProgram(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 408, offset 0x80057624
	/* begin block 1 */
		// Start line: 410
		// Start offset: 0x80057624
		// Variables:
	// 		int program; // $a0
	/* end block 1 */
	// End offset: 0x80057624
	// End Line: 413

	/* begin block 2 */
		// Start line: 855
	/* end block 2 */
	// End Line: 856

	/* begin block 3 */
		// Start line: 856
	/* end block 3 */
	// End Line: 857

	/* begin block 4 */
		// Start line: 859
	/* end block 4 */
	// End Line: 860

void metaCmdSetChannelProgram(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  *(char *)((int)slot->selectedSlotPtr->pitchWheel + (uint)slot->selectedChannel + 0x14) =
       event->dataByte[0];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelBasePriority(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 418, offset 0x8005763c
	/* begin block 1 */
		// Start line: 876
	/* end block 1 */
	// End Line: 877

	/* begin block 2 */
		// Start line: 896
	/* end block 2 */
	// End Line: 897

void metaCmdSetChannelBasePriority(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 442, offset 0x80057644
	/* begin block 1 */
		// Start line: 444
		// Start offset: 0x80057644
		// Variables:
	// 		int channel; // $a2
	// 		int transpose; // $v1
	/* end block 1 */
	// End offset: 0x80057644
	// End Line: 446

	/* begin block 2 */
		// Start line: 924
	/* end block 2 */
	// End Line: 925

	/* begin block 3 */
		// Start line: 925
	/* end block 3 */
	// End Line: 926

	/* begin block 4 */
		// Start line: 927
	/* end block 4 */
	// End Line: 928

void metaCmdSetChannelTranspose(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->transpose[(uint)slot->selectedChannel + 4] = event->dataByte[0];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdIgnoreChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 453, offset 0x8005765c
	/* begin block 1 */
		// Start line: 455
		// Start offset: 0x8005765C
		// Variables:
	// 		int channel; // $a0
	/* end block 1 */
	// End offset: 0x8005765C
	// End Line: 458

	/* begin block 2 */
		// Start line: 947
	/* end block 2 */
	// End Line: 948

	/* begin block 3 */
		// Start line: 948
	/* end block 3 */
	// End Line: 949

	/* begin block 4 */
		// Start line: 951
	/* end block 4 */
	// End Line: 952

void metaCmdIgnoreChannelTranspose(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->delayedMuteCmds =
       slot->selectedSlotPtr->delayedMuteCmds | (ushort)(1 << ((uint)slot->selectedChannel & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdRespectChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 463, offset 0x8005767c
	/* begin block 1 */
		// Start line: 465
		// Start offset: 0x8005767C
		// Variables:
	// 		int channel; // $v0
	/* end block 1 */
	// End offset: 0x8005767C
	// End Line: 468

	/* begin block 2 */
		// Start line: 968
	/* end block 2 */
	// End Line: 969

	/* begin block 3 */
		// Start line: 969
	/* end block 3 */
	// End Line: 970

	/* begin block 4 */
		// Start line: 972
	/* end block 4 */
	// End Line: 973

void metaCmdRespectChannelTranspose(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  slot->selectedSlotPtr->delayedMuteCmds =
       slot->selectedSlotPtr->delayedMuteCmds & ~(ushort)(1 << ((uint)slot->selectedChannel & 0x1f))
  ;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 473, offset 0x800576a0
	/* begin block 1 */
		// Start line: 989
	/* end block 1 */
	// End Line: 990

	/* begin block 2 */
		// Start line: 1000
	/* end block 2 */
	// End Line: 1001

void metaCmdSetChannelPitchMap(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdIgnoreChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 488, offset 0x800576a8
	/* begin block 1 */
		// Start line: 1019
	/* end block 1 */
	// End Line: 1020

	/* begin block 2 */
		// Start line: 1027
	/* end block 2 */
	// End Line: 1028

void metaCmdIgnoreChannelPitchMap(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdRespectChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 500, offset 0x800576b0
	/* begin block 1 */
		// Start line: 1043
	/* end block 1 */
	// End Line: 1044

	/* begin block 2 */
		// Start line: 1051
	/* end block 2 */
	// End Line: 1052

void metaCmdRespectChannelPitchMap(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSequenceAssigned(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 512, offset 0x800576b8
	/* begin block 1 */
		// Start line: 514
		// Start offset: 0x800576B8
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x800576E0
	// End Line: 521

	/* begin block 2 */
		// Start line: 1067
	/* end block 2 */
	// End Line: 1068

	/* begin block 3 */
		// Start line: 1068
	/* end block 3 */
	// End Line: 1069

	/* begin block 4 */
		// Start line: 1070
	/* end block 4 */
	// End Line: 1071

void metaCmdGetSequenceAssigned(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    *(uchar *)((uint)(byte)event->dataByte[0] + 0x1b6c) =
         slot->selectedSlotPtr->sequenceNumberAssigned;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 524, offset 0x800576e8
	/* begin block 1 */
		// Start line: 526
		// Start offset: 0x800576E8
		// Variables:
	// 		int variableNum1; // $a2
	// 		int variableNum2; // $a3
	// 		int variableNum3; // $t0
	// 		unsigned long quarterNoteTime; // $a0
	/* end block 1 */
	// End offset: 0x80057744
	// End Line: 542

	/* begin block 2 */
		// Start line: 1091
	/* end block 2 */
	// End Line: 1092

	/* begin block 3 */
		// Start line: 1092
	/* end block 3 */
	// End Line: 1093

	/* begin block 4 */
		// Start line: 1095
	/* end block 4 */
	// End Line: 1096

void metaCmdGetTempo(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  byte bVar2;
  ulong uVar3;
  
  bVar1 = event->dataByte[1];
  bVar2 = event->dataByte[2];
  if ((((byte)event->dataByte[0] < 0x80) && (bVar1 < 0x80)) && (bVar2 < 0x80)) {
    uVar3 = (slot->selectedSlotPtr->tempo).quarterNoteTime;
    *(undefined *)((uint)(byte)event->dataByte[0] + 0x1b6c) = (char)uVar3;
    *(undefined *)((uint)bVar1 + 0x1b6c) = (char)(uVar3 >> 8);
    *(undefined *)((uint)bVar2 + 0x1b6c) = (char)(uVar3 >> 0x10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSlotStatus(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 545, offset 0x8005774c
	/* begin block 1 */
		// Start line: 547
		// Start offset: 0x8005774C
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x80057774
	// End Line: 554

	/* begin block 2 */
		// Start line: 1134
	/* end block 2 */
	// End Line: 1135

	/* begin block 3 */
		// Start line: 1135
	/* end block 3 */
	// End Line: 1136

	/* begin block 4 */
		// Start line: 1137
	/* end block 4 */
	// End Line: 1138

void metaCmdGetSlotStatus(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    *(undefined *)((uint)(byte)event->dataByte[0] + 0x1b6c) =
         *(undefined *)&slot->selectedSlotPtr->status;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelMute(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 557, offset 0x8005777c
	/* begin block 1 */
		// Start line: 559
		// Start offset: 0x8005777C
		// Variables:
	// 		int variableNum1; // $a2
	// 		int variableNum2; // $a0
	/* end block 1 */
	// End offset: 0x800577C4
	// End Line: 570

	/* begin block 2 */
		// Start line: 1158
	/* end block 2 */
	// End Line: 1159

	/* begin block 3 */
		// Start line: 1159
	/* end block 3 */
	// End Line: 1160

	/* begin block 4 */
		// Start line: 1161
	/* end block 4 */
	// End Line: 1162

void metaCmdGetChannelMute(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  
  bVar1 = event->dataByte[1];
  if (((byte)event->dataByte[0] < 0x80) && (bVar1 < 0x80)) {
    *(undefined *)((uint)(byte)event->dataByte[0] + 0x1b6c) =
         *(undefined *)&slot->selectedSlotPtr->channelMute;
    *(undefined *)((uint)bVar1 + 0x1b6c) = (char)(slot->selectedSlotPtr->channelMute >> 8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 573, offset 0x800577cc
	/* begin block 1 */
		// Start line: 575
		// Start offset: 0x800577CC
		// Variables:
	// 		int variableNum; // $a0
	// 		int channel; // $v1
	/* end block 1 */
	// End offset: 0x800577FC
	// End Line: 583

	/* begin block 2 */
		// Start line: 1190
	/* end block 2 */
	// End Line: 1191

	/* begin block 3 */
		// Start line: 1191
	/* end block 3 */
	// End Line: 1192

	/* begin block 4 */
		// Start line: 1193
	/* end block 4 */
	// End Line: 1194

void metaCmdGetChannelVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    *(uchar *)((uint)(byte)event->dataByte[0] + 0x1b6c) =
         slot->selectedSlotPtr->volume[(uint)slot->selectedChannel + 4];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 586, offset 0x80057804
	/* begin block 1 */
		// Start line: 588
		// Start offset: 0x80057804
		// Variables:
	// 		int variableNum; // $a0
	// 		int channel; // $v1
	/* end block 1 */
	// End offset: 0x80057834
	// End Line: 595

	/* begin block 2 */
		// Start line: 1216
	/* end block 2 */
	// End Line: 1217

	/* begin block 3 */
		// Start line: 1217
	/* end block 3 */
	// End Line: 1218

	/* begin block 4 */
		// Start line: 1219
	/* end block 4 */
	// End Line: 1220

void metaCmdGetChannelPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    *(uchar *)((uint)(byte)event->dataByte[0] + 0x1b6c) =
         slot->selectedSlotPtr->panPosition[(uint)slot->selectedChannel + 4];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 598, offset 0x8005783c
	/* begin block 1 */
		// Start line: 1240
	/* end block 1 */
	// End Line: 1241

	/* begin block 2 */
		// Start line: 1250
	/* end block 2 */
	// End Line: 1251

void metaCmdGetChannelTranspose(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelProgram(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 612, offset 0x80057844
	/* begin block 1 */
		// Start line: 614
		// Start offset: 0x80057844
		// Variables:
	// 		int variableNum; // $a0
	// 		int channel; // $v1
	/* end block 1 */
	// End offset: 0x80057874
	// End Line: 621

	/* begin block 2 */
		// Start line: 1268
	/* end block 2 */
	// End Line: 1269

	/* begin block 3 */
		// Start line: 1269
	/* end block 3 */
	// End Line: 1270

	/* begin block 4 */
		// Start line: 1271
	/* end block 4 */
	// End Line: 1272

void metaCmdGetChannelProgram(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    *(undefined *)((uint)(byte)event->dataByte[0] + 0x1b6c) =
         *(undefined *)((int)slot->selectedSlotPtr->pitchWheel + (uint)slot->selectedChannel + 0x14)
    ;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelBasePriority(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 624, offset 0x8005787c
	/* begin block 1 */
		// Start line: 1292
	/* end block 1 */
	// End Line: 1293

	/* begin block 2 */
		// Start line: 1309
	/* end block 2 */
	// End Line: 1310

void metaCmdGetChannelBasePriority(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetChannelBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 645, offset 0x80057884
	/* begin block 1 */
		// Start line: 1334
	/* end block 1 */
	// End Line: 1335

	/* begin block 2 */
		// Start line: 1343
	/* end block 2 */
	// End Line: 1344

void metaCmdGetChannelBendRange(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSlotVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 658, offset 0x8005788c
	/* begin block 1 */
		// Start line: 660
		// Start offset: 0x8005788C
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x800578B4
	// End Line: 667

	/* begin block 2 */
		// Start line: 1360
	/* end block 2 */
	// End Line: 1361

	/* begin block 3 */
		// Start line: 1361
	/* end block 3 */
	// End Line: 1362

	/* begin block 4 */
		// Start line: 1363
	/* end block 4 */
	// End Line: 1364

void metaCmdGetSlotVolume(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    *(undefined *)((uint)(byte)event->dataByte[0] + 0x1b6c) =
         *(undefined *)&slot->selectedSlotPtr->unused;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGetSlotPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 670, offset 0x800578bc
	/* begin block 1 */
		// Start line: 672
		// Start offset: 0x800578BC
		// Variables:
	// 		int variableNum; // $a0
	/* end block 1 */
	// End offset: 0x800578E4
	// End Line: 678

	/* begin block 2 */
		// Start line: 1384
	/* end block 2 */
	// End Line: 1385

	/* begin block 3 */
		// Start line: 1385
	/* end block 3 */
	// End Line: 1386

	/* begin block 4 */
		// Start line: 1387
	/* end block 4 */
	// End Line: 1388

void metaCmdGetSlotPan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[0] < 0x80) {
    *(undefined *)((uint)(byte)event->dataByte[0] + 0x1b6c) =
         *(undefined *)((int)&slot->selectedSlotPtr->unused + 1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 681, offset 0x800578ec
	/* begin block 1 */
		// Start line: 683
		// Start offset: 0x800578EC
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $v1
	/* end block 1 */
	// End offset: 0x80057910
	// End Line: 690

	/* begin block 2 */
		// Start line: 1406
	/* end block 2 */
	// End Line: 1407

	/* begin block 3 */
		// Start line: 1407
	/* end block 3 */
	// End Line: 1408

	/* begin block 4 */
		// Start line: 1410
	/* end block 4 */
	// End Line: 1411

void metaCmdSetVariable(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[1] < 0x80) {
    *(char *)((uint)(byte)event->dataByte[1] + 0x1b6c) = event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdCopyVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 693, offset 0x80057918
	/* begin block 1 */
		// Start line: 695
		// Start offset: 0x80057918
		// Variables:
	// 		int srcVariable; // $v1
	// 		int destVariable; // $a0
	/* end block 1 */
	// End offset: 0x8005794C
	// End Line: 703

	/* begin block 2 */
		// Start line: 1431
	/* end block 2 */
	// End Line: 1432

	/* begin block 3 */
		// Start line: 1432
	/* end block 3 */
	// End Line: 1433

	/* begin block 4 */
		// Start line: 1434
	/* end block 4 */
	// End Line: 1435

void metaCmdCopyVariable(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (((byte)event->dataByte[0] < 0x80) && ((byte)event->dataByte[1] < 0x80)) {
    *(undefined *)((uint)(byte)event->dataByte[1] + 0x1b6c) =
         *(undefined *)((uint)(byte)event->dataByte[0] + 0x1b6c);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdAddVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 706, offset 0x80057954
	/* begin block 1 */
		// Start line: 708
		// Start offset: 0x80057954
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $a1
	/* end block 1 */
	// End offset: 0x80057984
	// End Line: 715

	/* begin block 2 */
		// Start line: 1457
	/* end block 2 */
	// End Line: 1458

	/* begin block 3 */
		// Start line: 1458
	/* end block 3 */
	// End Line: 1459

	/* begin block 4 */
		// Start line: 1461
	/* end block 4 */
	// End Line: 1462

void metaCmdAddVariable(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  
  bVar1 = event->dataByte[1];
  if (bVar1 < 0x80) {
    *(char *)((uint)bVar1 + 0x1b6c) = *(char *)((uint)bVar1 + 0x1b6c) + event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSubtractVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 718, offset 0x8005798c
	/* begin block 1 */
		// Start line: 720
		// Start offset: 0x8005798C
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $a1
	/* end block 1 */
	// End offset: 0x800579BC
	// End Line: 727

	/* begin block 2 */
		// Start line: 1482
	/* end block 2 */
	// End Line: 1483

	/* begin block 3 */
		// Start line: 1483
	/* end block 3 */
	// End Line: 1484

	/* begin block 4 */
		// Start line: 1486
	/* end block 4 */
	// End Line: 1487

void metaCmdSubtractVariable(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  
  bVar1 = event->dataByte[1];
  if (bVar1 < 0x80) {
    *(char *)((uint)bVar1 + 0x1b6c) = *(char *)((uint)bVar1 + 0x1b6c) - event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetVariableBits(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 730, offset 0x800579c4
	/* begin block 1 */
		// Start line: 732
		// Start offset: 0x800579C4
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $a1
	/* end block 1 */
	// End offset: 0x800579F4
	// End Line: 739

	/* begin block 2 */
		// Start line: 1507
	/* end block 2 */
	// End Line: 1508

	/* begin block 3 */
		// Start line: 1508
	/* end block 3 */
	// End Line: 1509

	/* begin block 4 */
		// Start line: 1511
	/* end block 4 */
	// End Line: 1512

void metaCmdSetVariableBits(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  
  bVar1 = event->dataByte[1];
  if (bVar1 < 0x80) {
    *(byte *)((uint)bVar1 + 0x1b6c) = *(byte *)((uint)bVar1 + 0x1b6c) | event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdClearVariableBits(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 742, offset 0x800579fc
	/* begin block 1 */
		// Start line: 744
		// Start offset: 0x800579FC
		// Variables:
	// 		int value; // $a0
	// 		int destVariable; // $v1
	/* end block 1 */
	// End offset: 0x80057A2C
	// End Line: 751

	/* begin block 2 */
		// Start line: 1532
	/* end block 2 */
	// End Line: 1533

	/* begin block 3 */
		// Start line: 1533
	/* end block 3 */
	// End Line: 1534

	/* begin block 4 */
		// Start line: 1536
	/* end block 4 */
	// End Line: 1537

void metaCmdClearVariableBits(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  
  bVar1 = event->dataByte[1];
  if (bVar1 < 0x80) {
    *(byte *)((uint)bVar1 + 0x1b6c) = *(byte *)((uint)bVar1 + 0x1b6c) & ~event->dataByte[0];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadGotoSequencePosition(struct _AadSequenceSlot *slot /*$a0*/, int track /*$a1*/, unsigned char *newPosition /*$a2*/)
 // line 754, offset 0x80057a34
	/* begin block 1 */
		// Start line: 1557
	/* end block 1 */
	// End Line: 1558

	/* begin block 2 */
		// Start line: 1559
	/* end block 2 */
	// End Line: 1560

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
 // line 775, offset 0x80057aa0
	/* begin block 1 */
		// Start line: 776
		// Start offset: 0x80057AA0
		// Variables:
	// 		struct AadSequenceHdr *seqHdr; // $v0
	// 		unsigned long trackOffset; // $a0
	/* end block 1 */
	// End offset: 0x80057B44
	// End Line: 810

	/* begin block 2 */
		// Start line: 1604
	/* end block 2 */
	// End Line: 1605

void aadGotoSequenceLabel(_AadSequenceSlot *slot,int track,int labelNumber)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  iVar1 = (uint)slot->slotID * 4;
  iVar2 = *(int *)((uint)slot->sequenceNumberAssigned * 4 + *(int *)(iVar1 + 0x4d8));
  slot->sequencePosition[track] =
       (_func_4397 *)
       (iVar2 + *(int *)(track * 4 + iVar2 + 0x10) +
       *(int *)(labelNumber * 4 + *(int *)(iVar1 + 0x4e0)));
  iVar1 = (int)&(slot->tempo).currentTick + track;
  cVar3 = *(char *)(iVar1 + 0x338);
  while (cVar3 != '\0') {
    cVar3 = *(char *)(iVar1 + 0x328) + '\x01';
    *(char *)(iVar1 + 0x328) = cVar3;
    *(char *)(iVar1 + 0x338) = *(char *)(iVar1 + 0x338) + -1;
    if (cVar3 == '\x04') {
      *(undefined *)(iVar1 + 0x328) = 0;
    }
    cVar3 = *(char *)(iVar1 + 0x338);
  }
  track = (int)&(slot->tempo).currentTick + track;
  *(byte *)(track + 0x3d8) = *(byte *)(track + 0x3d8) & 0xe7;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdLoopStart(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 817, offset 0x80057b58
	/* begin block 1 */
		// Start line: 819
		// Start offset: 0x80057B58
		// Variables:
	// 		int nestLevel; // $a2
	// 		int track; // $a3
	/* end block 1 */
	// End offset: 0x80057BB4
	// End Line: 834

	/* begin block 2 */
		// Start line: 1700
	/* end block 2 */
	// End Line: 1701

	/* begin block 3 */
		// Start line: 1701
	/* end block 3 */
	// End Line: 1702

	/* begin block 4 */
		// Start line: 1702
	/* end block 4 */
	// End Line: 1703

void metaCmdLoopStart(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)event->track;
  iVar3 = (int)&(slot->tempo).currentTick + uVar2;
  bVar1 = *(byte *)(iVar3 + 0x4e8);
  if (bVar1 < 4) {
    *(_func_4397 **)(slot->loopSequencePosition + (uint)bVar1 * 0x10 + uVar2) =
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
 // line 838, offset 0x80057bc8
	/* begin block 1 */
		// Start line: 839
		// Start offset: 0x80057BC8
		// Variables:
	// 		int prevNestLevel; // $v1
	// 		int track; // $a1
	/* end block 1 */
	// End offset: 0x80057C48
	// End Line: 863

	/* begin block 2 */
		// Start line: 1742
	/* end block 2 */
	// End Line: 1743

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
 // line 866, offset 0x80057c58
	/* begin block 1 */
		// Start line: 1798
	/* end block 1 */
	// End Line: 1799

	/* begin block 2 */
		// Start line: 1801
	/* end block 2 */
	// End Line: 1802

void metaCmdLoopBreak(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdDefineLabel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 873, offset 0x80057c60
	/* begin block 1 */
		// Start line: 1812
	/* end block 1 */
	// End Line: 1813

	/* begin block 2 */
		// Start line: 1819
	/* end block 2 */
	// End Line: 1820

void metaCmdDefineLabel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdGotoLabel(struct AadSeqEvent *event /*$v0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 884, offset 0x80057c68
	/* begin block 1 */
		// Start line: 885
		// Start offset: 0x80057C68
	/* end block 1 */
	// End offset: 0x80057C68
	// End Line: 885

	/* begin block 2 */
		// Start line: 1834
	/* end block 2 */
	// End Line: 1835

void metaCmdGotoLabel(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[0]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSequencePosition(struct AadSeqEvent *event /*$v0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 894, offset 0x80057c98
	/* begin block 1 */
		// Start line: 895
		// Start offset: 0x80057C98
	/* end block 1 */
	// End offset: 0x80057C98
	// End Line: 895

	/* begin block 2 */
		// Start line: 1858
	/* end block 2 */
	// End Line: 1859

void metaCmdSetSequencePosition(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadGotoSequenceLabel(slot->selectedSlotPtr,(uint)event->track,(uint)(byte)event->dataByte[0]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 904, offset 0x80057cc8
	/* begin block 1 */
		// Start line: 905
		// Start offset: 0x80057CC8
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80057D04
	// End Line: 915

	/* begin block 2 */
		// Start line: 1878
	/* end block 2 */
	// End Line: 1879

void metaCmdBranchIfVarEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (*(char *)((uint)(byte)event->dataByte[0] + 0x1b6c) == event->dataByte[1]) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarNotEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 918, offset 0x80057d14
	/* begin block 1 */
		// Start line: 919
		// Start offset: 0x80057D14
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80057D50
	// End Line: 929

	/* begin block 2 */
		// Start line: 1918
	/* end block 2 */
	// End Line: 1919

void metaCmdBranchIfVarNotEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (*(char *)((uint)(byte)event->dataByte[0] + 0x1b6c) != event->dataByte[1]) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarLess(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 932, offset 0x80057d60
	/* begin block 1 */
		// Start line: 933
		// Start offset: 0x80057D60
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80057DA0
	// End Line: 943

	/* begin block 2 */
		// Start line: 1958
	/* end block 2 */
	// End Line: 1959

void metaCmdBranchIfVarLess(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (*(byte *)((uint)(byte)event->dataByte[0] + 0x1b6c) < (byte)event->dataByte[1]) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarGreater(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 946, offset 0x80057db0
	/* begin block 1 */
		// Start line: 947
		// Start offset: 0x80057DB0
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80057DF0
	// End Line: 957

	/* begin block 2 */
		// Start line: 1998
	/* end block 2 */
	// End Line: 1999

void metaCmdBranchIfVarGreater(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[1] < *(byte *)((uint)(byte)event->dataByte[0] + 0x1b6c)) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarLessOrEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 960, offset 0x80057e00
	/* begin block 1 */
		// Start line: 961
		// Start offset: 0x80057E00
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80057E40
	// End Line: 971

	/* begin block 2 */
		// Start line: 2038
	/* end block 2 */
	// End Line: 2039

void metaCmdBranchIfVarLessOrEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if (*(byte *)((uint)(byte)event->dataByte[0] + 0x1b6c) <= (byte)event->dataByte[1]) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarGreaterOrEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 974, offset 0x80057e50
	/* begin block 1 */
		// Start line: 975
		// Start offset: 0x80057E50
		// Variables:
	// 		int variableNum; // $v1
	// 		int value; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80057E90
	// End Line: 985

	/* begin block 2 */
		// Start line: 2078
	/* end block 2 */
	// End Line: 2079

void metaCmdBranchIfVarGreaterOrEqual(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((byte)event->dataByte[1] <= *(byte *)((uint)(byte)event->dataByte[0] + 0x1b6c)) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarBitsSet(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 988, offset 0x80057ea0
	/* begin block 1 */
		// Start line: 989
		// Start offset: 0x80057EA0
		// Variables:
	// 		int variableNum; // $v1
	// 		int mask; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80057EE0
	// End Line: 998

	/* begin block 2 */
		// Start line: 2118
	/* end block 2 */
	// End Line: 2119

void metaCmdBranchIfVarBitsSet(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((*(byte *)((uint)(byte)event->dataByte[0] + 0x1b6c) & event->dataByte[1]) != 0) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdBranchIfVarBitsClear(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
 // line 1001, offset 0x80057ef0
	/* begin block 1 */
		// Start line: 1002
		// Start offset: 0x80057EF0
		// Variables:
	// 		int variableNum; // $v1
	// 		int mask; // $v1
	// 		int labelNum; // $a2
	/* end block 1 */
	// End offset: 0x80057F30
	// End Line: 1011

	/* begin block 2 */
		// Start line: 2153
	/* end block 2 */
	// End Line: 2154

void metaCmdBranchIfVarBitsClear(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  if ((*(byte *)((uint)(byte)event->dataByte[0] + 0x1b6c) & event->dataByte[1]) == 0) {
    aadGotoSequenceLabel(slot,(uint)event->track,(uint)(byte)event->dataByte[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSubstituteVariableParam1(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1014, offset 0x80057f40
	/* begin block 1 */
		// Start line: 2188
	/* end block 1 */
	// End Line: 2189

	/* begin block 2 */
		// Start line: 2189
	/* end block 2 */
	// End Line: 2190

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
 // line 1021, offset 0x80057f60
	/* begin block 1 */
		// Start line: 2202
	/* end block 1 */
	// End Line: 2203

	/* begin block 2 */
		// Start line: 2203
	/* end block 2 */
	// End Line: 2204

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
 // line 1028, offset 0x80057f80
	/* begin block 1 */
		// Start line: 2216
	/* end block 1 */
	// End Line: 2217

	/* begin block 2 */
		// Start line: 2217
	/* end block 2 */
	// End Line: 2218

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
 // line 1034, offset 0x80057fa0
	/* begin block 1 */
		// Start line: 2228
	/* end block 1 */
	// End Line: 2229

void metaCmdEndSequence(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  aadInitSequenceSlot(slot);
  aadAllNotesOff((uint)slot->thisSlotNumber);
  if (pcRam00001b60 != (code *)0x0) {
    (*pcRam00001b60)(uRam00001b68,(uint)slot->thisSlotNumber,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdPlaySoundEffect(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1152, offset 0x80057ffc
	/* begin block 1 */
		// Start line: 2464
	/* end block 1 */
	// End Line: 2465

	/* begin block 2 */
		// Start line: 2465
	/* end block 2 */
	// End Line: 2466

void metaCmdPlaySoundEffect(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdStopSoundEffect(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1155, offset 0x80058004
	/* begin block 1 */
		// Start line: 2470
	/* end block 1 */
	// End Line: 2471

	/* begin block 2 */
		// Start line: 2471
	/* end block 2 */
	// End Line: 2472

void metaCmdStopSoundEffect(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ metaCmdSetSoundEffectVolumePan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
 // line 1158, offset 0x8005800c
	/* begin block 1 */
		// Start line: 2476
	/* end block 1 */
	// End Line: 2477

	/* begin block 2 */
		// Start line: 2477
	/* end block 2 */
	// End Line: 2478

void metaCmdSetSoundEffectVolumePan(AadSeqEvent *event,_AadSequenceSlot *slot)

{
  return;
}





