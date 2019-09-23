#include "THISDUST.H"
#include "AADSQCMD.H"

// decompiled code
// original method signature:
// void /*$ra*/ aadSubstituteVariables(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 23, offset 0x80055928
/* begin block 1 */
// Start line: 25
// Start offset: 0x80055928
// Variables:
// 		unsigned char trackFlags; // $a2
/* end block 1 */
// End offset: 0x800559D8
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

void aadSubstituteVariables(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	int iVar2;
	byte bVar3;
	byte bVar4;

	iVar2 = (int)&(slot->tempo).currentTick + (uint)event->track;
	bVar1 = *(byte *)(iVar2 + 0x3d8);
	if (((bVar1 & 7) != 0) && (2 < (uint)event->statusByte - 0x41))
	{
		bVar3 = bVar1;
		if ((bVar1 & 1) != 0)
		{
			bVar3 = bVar1 & 0xfe;
			event->dataByte[0] =
				(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]];
		}
		bVar4 = bVar3;
		if ((bVar1 & 2) != 0)
		{
			bVar4 = bVar3 & 0xfd;
			event->dataByte[1] =
				(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1]];
		}
		if ((bVar3 & 4) != 0)
		{
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
// line 58, offset 0x800559e0
/* begin block 1 */
// Start line: 60
// Start offset: 0x800559E0
// Variables:
// 		int channelNumber; // $v1
/* end block 1 */
// End offset: 0x800559F8
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

void metaCmdSelectChannel(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x10)
	{
		slot->selectedChannel = event->dataByte[0];
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSelectSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 68, offset 0x80055a00
/* begin block 1 */
// Start line: 70
// Start offset: 0x80055A00
// Variables:
// 		int slotNumber; // $v1
/* end block 1 */
// End offset: 0x80055A48
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

void metaCmdSelectSlot(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	_AadSequenceSlot *p_Var2;

	bVar1 = event->dataByte[0];
	if ((int)(uint)bVar1 < aadMem->numSlots)
	{
		p_Var2 = (_AadSequenceSlot *)aadMem->sequenceSlots[(uint)bVar1];
		slot->selectedSlotNum = bVar1;
		slot->selectedSlotPtr = p_Var2;
		return;
	}
	if (bVar1 == 0x7f)
	{
		slot->selectedSlotPtr = slot;
		slot->selectedSlotNum = slot->thisSlotNumber;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdAssignSequence(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s2*/)
// line 88, offset 0x80055a50
/* begin block 1 */
// Start line: 89
// Start offset: 0x80055A50
// Variables:
// 		int sequenceNumber; // $s1

/* begin block 1.1 */
// Start line: 89
// Start offset: 0x80055A50
// Variables:
// 		int bank; // $s0
/* end block 1.1 */
// End offset: 0x80055AAC
// End Line: 101
/* end block 1 */
// End offset: 0x80055AAC
// End Line: 107

/* begin block 2 */
// Start line: 182
/* end block 2 */
// End Line: 183

void metaCmdAssignSequence(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	int iVar2;
	int bank;

	bank = slot->selectedDynamicBank;
	bVar1 = event->dataByte[0];
	if ((aadMem->dynamicBankStatus[bank] == 2) &&
		(iVar2 = aadGetNumDynamicSequences(bank), (int)(uint)bVar1 < iVar2))
	{
		aadAssignDynamicSequence(bank, (uint)bVar1, (uint)slot->selectedSlotNum);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdUsePrimaryTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 110, offset 0x80055ac4
/* begin block 1 */
// Start line: 231
/* end block 1 */
// End Line: 232

/* begin block 2 */
// Start line: 234
/* end block 2 */
// End Line: 235

void metaCmdUsePrimaryTempo(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdUseSecondaryTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 117, offset 0x80055acc
/* begin block 1 */
// Start line: 245
/* end block 1 */
// End Line: 246

/* begin block 2 */
// Start line: 248
/* end block 2 */
// End Line: 249

void metaCmdUseSecondaryTempo(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 124, offset 0x80055ad4
/* begin block 1 */
// Start line: 125
// Start offset: 0x80055AD4
// Variables:
// 		struct AadTempo tempo; // stack offset -16
/* end block 1 */
// End offset: 0x80055B38
// End Line: 135

/* begin block 2 */
// Start line: 259
/* end block 2 */
// End Line: 260

void metaCmdSetTempo(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	AadTempo local_10;

	local_10.quarterNoteTime =
		(uint)(byte)event->dataByte[0] << 0x10 | (uint)(byte)event->dataByte[1] << 8 |
		(uint)(byte)event->dataByte[2];
	if ((slot->selectedSlotPtr->tempo).ticksPerUpdate == 0)
	{
		local_10.ppqn = 0x1e0;
	}
	else
	{
		local_10.ppqn = (uint)(slot->selectedSlotPtr->tempo).ppqn;
	}
	aadSetSlotTempo((uint)slot->selectedSlotNum, &local_10);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdChangeTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 140, offset 0x80055b54
/* begin block 1 */
// Start line: 141
// Start offset: 0x80055B54
// Variables:
// 		struct AadTempo tempo; // stack offset -16
// 		struct _AadSequenceSlot *selectedSlot; // $a2
/* end block 1 */
// End offset: 0x80055B54
// End Line: 141

/* begin block 2 */
// Start line: 291
/* end block 2 */
// End Line: 292

void metaCmdChangeTempo(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	AadTempo local_10;

	local_10.quarterNoteTime =
		((slot->selectedSlotPtr->tempo).quarterNoteTime * 100) / (uint)(byte)event->dataByte[0];
	local_10.ppqn = (uint)(slot->selectedSlotPtr->tempo).ppqn;
	aadSetSlotTempo((uint)slot->selectedSlotNum, &local_10);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetTempoFromSequence(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s2*/)
// line 155, offset 0x80055bc4
/* begin block 1 */
// Start line: 156
// Start offset: 0x80055BC4
// Variables:
// 		int sequenceNumber; // $s1
// 		struct AadTempo tempo; // stack offset -24

/* begin block 1.1 */
// Start line: 156
// Start offset: 0x80055BC4
// Variables:
// 		int bank; // $s0
/* end block 1.1 */
// End offset: 0x80055C2C
// End Line: 173
/* end block 1 */
// End offset: 0x80055C2C
// End Line: 182

/* begin block 2 */
// Start line: 321
/* end block 2 */
// End Line: 322

void metaCmdSetTempoFromSequence(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	int iVar2;
	int bank;
	AadTempo AStack24;

	bank = slot->selectedDynamicBank;
	bVar1 = event->dataByte[0];
	if ((aadMem->dynamicBankStatus[bank] == 2) &&
		(iVar2 = aadGetNumDynamicSequences(bank), (int)(uint)bVar1 < iVar2))
	{
		aadGetTempoFromDynamicSequence(bank, (uint)bVar1, &AStack24);
		aadSetSlotTempo((uint)slot->selectedSlotNum, &AStack24);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdStartSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 185, offset 0x80055c44
/* begin block 1 */
// Start line: 386
/* end block 1 */
// End Line: 387

void metaCmdStartSlot(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadStartSlot((uint)slot->selectedSlotNum);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdStopSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 192, offset 0x80055c68
/* begin block 1 */
// Start line: 400
/* end block 1 */
// End Line: 401

void metaCmdStopSlot(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadStopSlot((uint)slot->selectedSlotNum);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdPauseSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 199, offset 0x80055c8c
/* begin block 1 */
// Start line: 414
/* end block 1 */
// End Line: 415

void metaCmdPauseSlot(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadPauseSlot((uint)slot->selectedSlotNum);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdResumeSlot(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 206, offset 0x80055cb0
/* begin block 1 */
// Start line: 428
/* end block 1 */
// End Line: 429

void metaCmdResumeSlot(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadResumeSlot((uint)slot->selectedSlotNum);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetSlotBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 213, offset 0x80055cd4
/* begin block 1 */
// Start line: 442
/* end block 1 */
// End Line: 443

/* begin block 2 */
// Start line: 451
/* end block 2 */
// End Line: 452

void metaCmdSetSlotBendRange(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetChannelBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 226, offset 0x80055cdc
/* begin block 1 */
// Start line: 468
/* end block 1 */
// End Line: 469

/* begin block 2 */
// Start line: 470
/* end block 2 */
// End Line: 471

void metaCmdSetChannelBendRange(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetSlotVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 232, offset 0x80055ce4
/* begin block 1 */
// Start line: 233
// Start offset: 0x80055CE4
// Variables:
// 		int volume; // $v1
/* end block 1 */
// End offset: 0x80055CE4
// End Line: 233

/* begin block 2 */
// Start line: 480
/* end block 2 */
// End Line: 481

void metaCmdSetSlotVolume(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->slotVolume = event->dataByte[0];
	aadUpdateSlotVolPan(slot->selectedSlotPtr);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetSlotPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 244, offset 0x80055d18
/* begin block 1 */
// Start line: 245
// Start offset: 0x80055D18
// Variables:
// 		int pan; // $v1
/* end block 1 */
// End offset: 0x80055D18
// End Line: 245

/* begin block 2 */
// Start line: 504
/* end block 2 */
// End Line: 505

void metaCmdSetSlotPan(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->slotPan = event->dataByte[0];
	aadUpdateSlotVolPan(slot->selectedSlotPtr);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetChannelVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 256, offset 0x80055d4c
/* begin block 1 */
// Start line: 257
// Start offset: 0x80055D4C
// Variables:
// 		int volume; // $a0
/* end block 1 */
// End offset: 0x80055D4C
// End Line: 257

/* begin block 2 */
// Start line: 528
/* end block 2 */
// End Line: 529

void metaCmdSetChannelVolume(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->volume[(uint)slot->selectedChannel] = event->dataByte[0];
	aadUpdateChannelVolPan(slot->selectedSlotPtr, (uint)slot->selectedChannel);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetChannelPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 268, offset 0x80055d88
/* begin block 1 */
// Start line: 269
// Start offset: 0x80055D88
// Variables:
// 		int pan; // $a0
/* end block 1 */
// End offset: 0x80055D88
// End Line: 269

/* begin block 2 */
// Start line: 553
/* end block 2 */
// End Line: 554

void metaCmdSetChannelPan(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->panPosition[(uint)slot->selectedChannel] = event->dataByte[0];
	aadUpdateChannelVolPan(slot->selectedSlotPtr, (uint)slot->selectedChannel);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdEnableSustainUpdate(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 280, offset 0x80055dc4
/* begin block 1 */
// Start line: 282
// Start offset: 0x80055DC4
// Variables:
// 		int channel; // $a0
/* end block 1 */
// End offset: 0x80055DC4
// End Line: 285

/* begin block 2 */
// Start line: 578
/* end block 2 */
// End Line: 579

/* begin block 3 */
// Start line: 579
/* end block 3 */
// End Line: 580

/* begin block 4 */
// Start line: 582
/* end block 4 */
// End Line: 583

void metaCmdEnableSustainUpdate(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->enableSustainUpdate =
		slot->selectedSlotPtr->enableSustainUpdate |
		(ushort)(1 << ((uint)slot->selectedChannel & 0x1f));
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdDisableSustainUpdate(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 290, offset 0x80055de4
/* begin block 1 */
// Start line: 292
// Start offset: 0x80055DE4
// Variables:
// 		int channel; // $v0
/* end block 1 */
// End offset: 0x80055DE4
// End Line: 295

/* begin block 2 */
// Start line: 599
/* end block 2 */
// End Line: 600

/* begin block 3 */
// Start line: 600
/* end block 3 */
// End Line: 601

/* begin block 4 */
// Start line: 603
/* end block 4 */
// End Line: 604

void metaCmdDisableSustainUpdate(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->enableSustainUpdate =
		slot->selectedSlotPtr->enableSustainUpdate &
		~(ushort)(1 << ((uint)slot->selectedChannel & 0x1f));
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdMuteChannel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 300, offset 0x80055e08
/* begin block 1 */
// Start line: 301
// Start offset: 0x80055E08
/* end block 1 */
// End offset: 0x80055E08
// End Line: 301

/* begin block 2 */
// Start line: 620
/* end block 2 */
// End Line: 621

void metaCmdMuteChannel(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadMuteChannels(slot->selectedSlotPtr, 1 << ((uint)slot->selectedChannel & 0x1f));
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdUnMuteChannel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 310, offset 0x80055e34
/* begin block 1 */
// Start line: 311
// Start offset: 0x80055E34
/* end block 1 */
// End offset: 0x80055E34
// End Line: 311

/* begin block 2 */
// Start line: 643
/* end block 2 */
// End Line: 644

void metaCmdUnMuteChannel(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadUnMuteChannels(slot->selectedSlotPtr, 1 << ((uint)slot->selectedChannel & 0x1f));
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdMuteChannelList(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 320, offset 0x80055e60
/* begin block 1 */
// Start line: 321
// Start offset: 0x80055E60
/* end block 1 */
// End offset: 0x80055E60
// End Line: 321

/* begin block 2 */
// Start line: 666
/* end block 2 */
// End Line: 667

void metaCmdMuteChannelList(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadMuteChannels(slot->selectedSlotPtr, (uint) * (ushort *)event->dataByte);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdUnMuteChannelList(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 330, offset 0x80055e90
/* begin block 1 */
// Start line: 331
// Start offset: 0x80055E90
/* end block 1 */
// End offset: 0x80055E90
// End Line: 331

/* begin block 2 */
// Start line: 687
/* end block 2 */
// End Line: 688

void metaCmdUnMuteChannelList(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadUnMuteChannels(slot->selectedSlotPtr, (uint) * (ushort *)event->dataByte);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetChannelMute(struct AadSeqEvent *event /*$v0*/, struct _AadSequenceSlot *slot /*$s1*/)
// line 340, offset 0x80055ec0
/* begin block 1 */
// Start line: 341
// Start offset: 0x80055EC0
// Variables:
// 		unsigned long muteChannelMask; // $s0
/* end block 1 */
// End offset: 0x80055EC0
// End Line: 341

/* begin block 2 */
// Start line: 708
/* end block 2 */
// End Line: 709

void metaCmdSetChannelMute(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	ushort uVar1;

	uVar1 = *(ushort *)event->dataByte;
	aadUnMuteChannels(slot->selectedSlotPtr, ~(uint)uVar1);
	aadMuteChannels(slot->selectedSlotPtr, (uint)uVar1);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdDelayMute(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 352, offset 0x80055f14
/* begin block 1 */
// Start line: 354
// Start offset: 0x80055F14
// Variables:
// 		unsigned long channelMask; // $v1
/* end block 1 */
// End offset: 0x80055F14
// End Line: 356

/* begin block 2 */
// Start line: 733
/* end block 2 */
// End Line: 734

/* begin block 3 */
// Start line: 734
/* end block 3 */
// End Line: 735

/* begin block 4 */
// Start line: 736
/* end block 4 */
// End Line: 737

void metaCmdDelayMute(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->delayedMuteMode =
		slot->selectedSlotPtr->delayedMuteMode | *(ushort *)event->dataByte;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdUpdateMute(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s1*/)
// line 365, offset 0x80055f38
/* begin block 1 */
// Start line: 366
// Start offset: 0x80055F38
// Variables:
// 		unsigned long channelMask; // $s0
// 		unsigned long mask; // $a1
/* end block 1 */
// End offset: 0x80055FB8
// End Line: 379

/* begin block 2 */
// Start line: 763
/* end block 2 */
// End Line: 764

void metaCmdUpdateMute(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	ushort uVar1;
	ushort uVar2;
	_AadSequenceSlot *slot_00;

	uVar1 = *(ushort *)event->dataByte;
	slot->selectedSlotPtr->delayedMuteMode = slot->selectedSlotPtr->delayedMuteMode & ~uVar1;
	slot_00 = slot->selectedSlotPtr;
	uVar2 = slot_00->delayedMuteCmds & uVar1;
	if (uVar2 != 0)
	{
		aadMuteChannels(slot_00, (uint)uVar2);
		slot_00 = slot->selectedSlotPtr;
	}
	uVar1 = slot_00->delayedUnMuteCmds & uVar1;
	if (uVar1 != 0)
	{
		aadUnMuteChannels(slot_00, (uint)uVar1);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdChannelVolumeFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 382, offset 0x80055fcc
/* begin block 1 */
// Start line: 799
/* end block 1 */
// End Line: 800

/* begin block 2 */
// Start line: 809
/* end block 2 */
// End Line: 810

void metaCmdChannelVolumeFade(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdChannelPanFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 396, offset 0x80055fd4
/* begin block 1 */
// Start line: 827
/* end block 1 */
// End Line: 828

/* begin block 2 */
// Start line: 837
/* end block 2 */
// End Line: 838

void metaCmdChannelPanFade(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSlotVolumeFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 410, offset 0x80055fdc
/* begin block 1 */
// Start line: 855
/* end block 1 */
// End Line: 856

/* begin block 2 */
// Start line: 864
/* end block 2 */
// End Line: 865

void metaCmdSlotVolumeFade(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSlotPanFade(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 423, offset 0x80055fe4
/* begin block 1 */
// Start line: 881
/* end block 1 */
// End Line: 882

/* begin block 2 */
// Start line: 890
/* end block 2 */
// End Line: 891

void metaCmdSlotPanFade(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetChannelProgram(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 436, offset 0x80055fec
/* begin block 1 */
// Start line: 438
// Start offset: 0x80055FEC
// Variables:
// 		int program; // $a0
/* end block 1 */
// End offset: 0x80055FEC
// End Line: 441

/* begin block 2 */
// Start line: 907
/* end block 2 */
// End Line: 908

/* begin block 3 */
// Start line: 908
/* end block 3 */
// End Line: 909

/* begin block 4 */
// Start line: 911
/* end block 4 */
// End Line: 912

void metaCmdSetChannelProgram(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->currentProgram[(uint)slot->selectedChannel] = event->dataByte[0];
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetChannelBasePriority(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 446, offset 0x80056004
/* begin block 1 */
// Start line: 928
/* end block 1 */
// End Line: 929

/* begin block 2 */
// Start line: 948
/* end block 2 */
// End Line: 949

void metaCmdSetChannelBasePriority(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 470, offset 0x8005600c
/* begin block 1 */
// Start line: 472
// Start offset: 0x8005600C
// Variables:
// 		int channel; // $a2
// 		int transpose; // $v1
/* end block 1 */
// End offset: 0x8005600C
// End Line: 474

/* begin block 2 */
// Start line: 976
/* end block 2 */
// End Line: 977

/* begin block 3 */
// Start line: 977
/* end block 3 */
// End Line: 978

/* begin block 4 */
// Start line: 979
/* end block 4 */
// End Line: 980

void metaCmdSetChannelTranspose(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->transpose[(uint)slot->selectedChannel] = event->dataByte[0];
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdIgnoreChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 481, offset 0x80056024
/* begin block 1 */
// Start line: 483
// Start offset: 0x80056024
// Variables:
// 		int channel; // $a0
/* end block 1 */
// End offset: 0x80056024
// End Line: 486

/* begin block 2 */
// Start line: 999
/* end block 2 */
// End Line: 1000

/* begin block 3 */
// Start line: 1000
/* end block 3 */
// End Line: 1001

/* begin block 4 */
// Start line: 1003
/* end block 4 */
// End Line: 1004

void metaCmdIgnoreChannelTranspose(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->ignoreTranspose =
		slot->selectedSlotPtr->ignoreTranspose | (ushort)(1 << ((uint)slot->selectedChannel & 0x1f));
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdRespectChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 491, offset 0x80056044
/* begin block 1 */
// Start line: 493
// Start offset: 0x80056044
// Variables:
// 		int channel; // $v0
/* end block 1 */
// End offset: 0x80056044
// End Line: 496

/* begin block 2 */
// Start line: 1020
/* end block 2 */
// End Line: 1021

/* begin block 3 */
// Start line: 1021
/* end block 3 */
// End Line: 1022

/* begin block 4 */
// Start line: 1024
/* end block 4 */
// End Line: 1025

void metaCmdRespectChannelTranspose(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->ignoreTranspose =
		slot->selectedSlotPtr->ignoreTranspose & ~(ushort)(1 << ((uint)slot->selectedChannel & 0x1f));
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 501, offset 0x80056068
/* begin block 1 */
// Start line: 1041
/* end block 1 */
// End Line: 1042

/* begin block 2 */
// Start line: 1052
/* end block 2 */
// End Line: 1053

void metaCmdSetChannelPitchMap(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdIgnoreChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 516, offset 0x80056070
/* begin block 1 */
// Start line: 1071
/* end block 1 */
// End Line: 1072

/* begin block 2 */
// Start line: 1079
/* end block 2 */
// End Line: 1080

void metaCmdIgnoreChannelPitchMap(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdRespectChannelPitchMap(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 528, offset 0x80056078
/* begin block 1 */
// Start line: 1095
/* end block 1 */
// End Line: 1096

/* begin block 2 */
// Start line: 1103
/* end block 2 */
// End Line: 1104

void metaCmdRespectChannelPitchMap(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdGetSequenceAssigned(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 540, offset 0x80056080
/* begin block 1 */
// Start line: 542
// Start offset: 0x80056080
// Variables:
// 		int variableNum; // $a0
/* end block 1 */
// End offset: 0x800560A8
// End Line: 549

/* begin block 2 */
// Start line: 1119
/* end block 2 */
// End Line: 1120

/* begin block 3 */
// Start line: 1120
/* end block 3 */
// End Line: 1121

/* begin block 4 */
// Start line: 1122
/* end block 4 */
// End Line: 1123

void metaCmdGetSequenceAssigned(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->sequenceNumberAssigned;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdGetTempo(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 552, offset 0x800560b0
/* begin block 1 */
// Start line: 554
// Start offset: 0x800560B0
// Variables:
// 		int variableNum1; // $a2
// 		int variableNum2; // $a3
// 		int variableNum3; // $t0
// 		unsigned long quarterNoteTime; // $a0
/* end block 1 */
// End offset: 0x8005610C
// End Line: 570

/* begin block 2 */
// Start line: 1143
/* end block 2 */
// End Line: 1144

/* begin block 3 */
// Start line: 1144
/* end block 3 */
// End Line: 1145

/* begin block 4 */
// Start line: 1147
/* end block 4 */
// End Line: 1148

void metaCmdGetTempo(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	byte bVar2;
	ulong uVar3;

	bVar1 = event->dataByte[1];
	bVar2 = event->dataByte[2];
	if ((((byte)event->dataByte[0] < 0x80) && (bVar1 < 0x80)) && (bVar2 < 0x80))
	{
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
// line 573, offset 0x80056114
/* begin block 1 */
// Start line: 575
// Start offset: 0x80056114
// Variables:
// 		int variableNum; // $a0
/* end block 1 */
// End offset: 0x8005613C
// End Line: 582

/* begin block 2 */
// Start line: 1186
/* end block 2 */
// End Line: 1187

/* begin block 3 */
// Start line: 1187
/* end block 3 */
// End Line: 1188

/* begin block 4 */
// Start line: 1189
/* end block 4 */
// End Line: 1190

void metaCmdGetSlotStatus(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
			*(undefined *)&slot->selectedSlotPtr->status;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdGetChannelMute(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 585, offset 0x80056144
/* begin block 1 */
// Start line: 587
// Start offset: 0x80056144
// Variables:
// 		int variableNum1; // $a2
// 		int variableNum2; // $a0
/* end block 1 */
// End offset: 0x8005618C
// End Line: 598

/* begin block 2 */
// Start line: 1210
/* end block 2 */
// End Line: 1211

/* begin block 3 */
// Start line: 1211
/* end block 3 */
// End Line: 1212

/* begin block 4 */
// Start line: 1213
/* end block 4 */
// End Line: 1214

void metaCmdGetChannelMute(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;

	bVar1 = event->dataByte[1];
	if (((byte)event->dataByte[0] < 0x80) && (bVar1 < 0x80))
	{
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
// line 601, offset 0x80056194
/* begin block 1 */
// Start line: 603
// Start offset: 0x80056194
// Variables:
// 		int variableNum; // $a0
// 		int channel; // $v1
/* end block 1 */
// End offset: 0x800561C4
// End Line: 611

/* begin block 2 */
// Start line: 1242
/* end block 2 */
// End Line: 1243

/* begin block 3 */
// Start line: 1243
/* end block 3 */
// End Line: 1244

/* begin block 4 */
// Start line: 1245
/* end block 4 */
// End Line: 1246

void metaCmdGetChannelVolume(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->volume[(uint)slot->selectedChannel];
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdGetChannelPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 614, offset 0x800561cc
/* begin block 1 */
// Start line: 616
// Start offset: 0x800561CC
// Variables:
// 		int variableNum; // $a0
// 		int channel; // $v1
/* end block 1 */
// End offset: 0x800561FC
// End Line: 623

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

void metaCmdGetChannelPan(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->panPosition[(uint)slot->selectedChannel];
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdGetChannelTranspose(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 626, offset 0x80056204
/* begin block 1 */
// Start line: 1292
/* end block 1 */
// End Line: 1293

/* begin block 2 */
// Start line: 1302
/* end block 2 */
// End Line: 1303

void metaCmdGetChannelTranspose(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdGetChannelProgram(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 640, offset 0x8005620c
/* begin block 1 */
// Start line: 642
// Start offset: 0x8005620C
// Variables:
// 		int variableNum; // $a0
// 		int channel; // $v1
/* end block 1 */
// End offset: 0x8005623C
// End Line: 649

/* begin block 2 */
// Start line: 1320
/* end block 2 */
// End Line: 1321

/* begin block 3 */
// Start line: 1321
/* end block 3 */
// End Line: 1322

/* begin block 4 */
// Start line: 1323
/* end block 4 */
// End Line: 1324

void metaCmdGetChannelProgram(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->currentProgram[(uint)slot->selectedChannel];
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdGetChannelBasePriority(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 652, offset 0x80056244
/* begin block 1 */
// Start line: 1344
/* end block 1 */
// End Line: 1345

/* begin block 2 */
// Start line: 1361
/* end block 2 */
// End Line: 1362

void metaCmdGetChannelBasePriority(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdGetChannelBendRange(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 673, offset 0x8005624c
/* begin block 1 */
// Start line: 1386
/* end block 1 */
// End Line: 1387

/* begin block 2 */
// Start line: 1395
/* end block 2 */
// End Line: 1396

void metaCmdGetChannelBendRange(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdGetSlotVolume(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 686, offset 0x80056254
/* begin block 1 */
// Start line: 688
// Start offset: 0x80056254
// Variables:
// 		int variableNum; // $a0
/* end block 1 */
// End offset: 0x8005627C
// End Line: 695

/* begin block 2 */
// Start line: 1412
/* end block 2 */
// End Line: 1413

/* begin block 3 */
// Start line: 1413
/* end block 3 */
// End Line: 1414

/* begin block 4 */
// Start line: 1415
/* end block 4 */
// End Line: 1416

void metaCmdGetSlotVolume(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->slotVolume;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdGetSlotPan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 698, offset 0x80056284
/* begin block 1 */
// Start line: 700
// Start offset: 0x80056284
// Variables:
// 		int variableNum; // $a0
/* end block 1 */
// End offset: 0x800562AC
// End Line: 706

/* begin block 2 */
// Start line: 1436
/* end block 2 */
// End Line: 1437

/* begin block 3 */
// Start line: 1437
/* end block 3 */
// End Line: 1438

/* begin block 4 */
// Start line: 1439
/* end block 4 */
// End Line: 1440

void metaCmdGetSlotPan(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->slotPan;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 709, offset 0x800562b4
/* begin block 1 */
// Start line: 711
// Start offset: 0x800562B4
// Variables:
// 		int value; // $a0
// 		int destVariable; // $v1
/* end block 1 */
// End offset: 0x800562D8
// End Line: 718

/* begin block 2 */
// Start line: 1458
/* end block 2 */
// End Line: 1459

/* begin block 3 */
// Start line: 1459
/* end block 3 */
// End Line: 1460

/* begin block 4 */
// Start line: 1462
/* end block 4 */
// End Line: 1463

void metaCmdSetVariable(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[1] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1]] =
			event->dataByte[0];
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdCopyVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 721, offset 0x800562e0
/* begin block 1 */
// Start line: 723
// Start offset: 0x800562E0
// Variables:
// 		int srcVariable; // $v1
// 		int destVariable; // $a0
/* end block 1 */
// End offset: 0x80056314
// End Line: 731

/* begin block 2 */
// Start line: 1483
/* end block 2 */
// End Line: 1484

/* begin block 3 */
// Start line: 1484
/* end block 3 */
// End Line: 1485

/* begin block 4 */
// Start line: 1486
/* end block 4 */
// End Line: 1487

void metaCmdCopyVariable(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if (((byte)event->dataByte[0] < 0x80) && ((byte)event->dataByte[1] < 0x80))
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1]] =
			(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]];
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdAddVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 734, offset 0x8005631c
/* begin block 1 */
// Start line: 736
// Start offset: 0x8005631C
// Variables:
// 		int value; // $a0
// 		int destVariable; // $a1
/* end block 1 */
// End offset: 0x8005634C
// End Line: 743

/* begin block 2 */
// Start line: 1509
/* end block 2 */
// End Line: 1510

/* begin block 3 */
// Start line: 1510
/* end block 3 */
// End Line: 1511

/* begin block 4 */
// Start line: 1513
/* end block 4 */
// End Line: 1514

void metaCmdAddVariable(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	if ((byte)event->dataByte[1] < 0x80)
	{
		iVar1 = (int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1];
		(&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] + event->dataByte[0];
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSubtractVariable(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 746, offset 0x80056354
/* begin block 1 */
// Start line: 748
// Start offset: 0x80056354
// Variables:
// 		int value; // $a0
// 		int destVariable; // $a1
/* end block 1 */
// End offset: 0x80056384
// End Line: 755

/* begin block 2 */
// Start line: 1534
/* end block 2 */
// End Line: 1535

/* begin block 3 */
// Start line: 1535
/* end block 3 */
// End Line: 1536

/* begin block 4 */
// Start line: 1538
/* end block 4 */
// End Line: 1539

void metaCmdSubtractVariable(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	if ((byte)event->dataByte[1] < 0x80)
	{
		iVar1 = (int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1];
		(&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] - event->dataByte[0];
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetVariableBits(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 758, offset 0x8005638c
/* begin block 1 */
// Start line: 760
// Start offset: 0x8005638C
// Variables:
// 		int value; // $a0
// 		int destVariable; // $a1
/* end block 1 */
// End offset: 0x800563BC
// End Line: 767

/* begin block 2 */
// Start line: 1559
/* end block 2 */
// End Line: 1560

/* begin block 3 */
// Start line: 1560
/* end block 3 */
// End Line: 1561

/* begin block 4 */
// Start line: 1563
/* end block 4 */
// End Line: 1564

void metaCmdSetVariableBits(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	if ((byte)event->dataByte[1] < 0x80)
	{
		iVar1 = (int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1];
		(&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] | event->dataByte[0];
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdClearVariableBits(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 770, offset 0x800563c4
/* begin block 1 */
// Start line: 772
// Start offset: 0x800563C4
// Variables:
// 		int value; // $a0
// 		int destVariable; // $v1
/* end block 1 */
// End offset: 0x800563F4
// End Line: 779

/* begin block 2 */
// Start line: 1584
/* end block 2 */
// End Line: 1585

/* begin block 3 */
// Start line: 1585
/* end block 3 */
// End Line: 1586

/* begin block 4 */
// Start line: 1588
/* end block 4 */
// End Line: 1589

void metaCmdClearVariableBits(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	if ((byte)event->dataByte[1] < 0x80)
	{
		iVar1 = (int)&aadMem->updateCounter + (uint)(byte)event->dataByte[1];
		(&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] & ~event->dataByte[0];
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ aadGotoSequencePosition(struct _AadSequenceSlot *slot /*$a0*/, int track /*$a1*/, unsigned char *newPosition /*$a2*/)
// line 782, offset 0x800563fc
/* begin block 1 */
// Start line: 1609
/* end block 1 */
// End Line: 1610

/* begin block 2 */
// Start line: 1611
/* end block 2 */
// End Line: 1612

void aadGotoSequencePosition(_AadSequenceSlot *slot, int track, uchar *newPosition)

{
	char cVar1;
	int iVar2;

	iVar2 = (int)&(slot->tempo).currentTick + track;
	*(uchar **)(slot->sequencePosition + track) = newPosition;
	cVar1 = *(char *)(iVar2 + 0x338);
	while (cVar1 != '\0')
	{
		cVar1 = *(char *)(iVar2 + 0x328) + '\x01';
		*(char *)(iVar2 + 0x328) = cVar1;
		*(char *)(iVar2 + 0x338) = *(char *)(iVar2 + 0x338) + -1;
		if (cVar1 == '\x04')
		{
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
// line 803, offset 0x80056468
/* begin block 1 */
// Start line: 804
// Start offset: 0x80056468
// Variables:
// 		struct AadSequenceHdr *seqHdr; // $v0
// 		unsigned long trackOffset; // $a0
// 		int bank; // $v0
/* end block 1 */
// End offset: 0x8005650C
// End Line: 838

/* begin block 2 */
// Start line: 1656
/* end block 2 */
// End Line: 1657

void aadGotoSequenceLabel(_AadSequenceSlot *slot, int track, int labelNumber)

{
	int iVar1;
	char cVar2;

	iVar1 = *(int *)((&aadMem->updateCounter + slot->sequenceAssignedDynamicBank)[0x13c] +
					 (uint)slot->sequenceNumberAssigned * 4);
	slot->sequencePosition[track] =
		(_func_10 *)(iVar1 + *(int *)((&aadMem->updateCounter + slot->sequenceAssignedDynamicBank)[0x13e] + labelNumber * 4) + *(int *)(iVar1 + track * 4 + 0x10));
	iVar1 = (int)&(slot->tempo).currentTick + track;
	cVar2 = *(char *)(iVar1 + 0x338);
	while (cVar2 != '\0')
	{
		cVar2 = *(char *)(iVar1 + 0x328) + '\x01';
		*(char *)(iVar1 + 0x328) = cVar2;
		*(char *)(iVar1 + 0x338) = *(char *)(iVar1 + 0x338) + -1;
		if (cVar2 == '\x04')
		{
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
// line 845, offset 0x80056520
/* begin block 1 */
// Start line: 847
// Start offset: 0x80056520
// Variables:
// 		int nestLevel; // $a2
// 		int track; // $a3
/* end block 1 */
// End offset: 0x8005657C
// End Line: 862

/* begin block 2 */
// Start line: 1756
/* end block 2 */
// End Line: 1757

/* begin block 3 */
// Start line: 1757
/* end block 3 */
// End Line: 1758

/* begin block 4 */
// Start line: 1758
/* end block 4 */
// End Line: 1759

void metaCmdLoopStart(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	uint uVar2;
	int iVar3;

	uVar2 = (uint)event->track;
	iVar3 = (int)&(slot->tempo).currentTick + uVar2;
	bVar1 = *(byte *)(iVar3 + 0x4e8);
	if (bVar1 < 4)
	{
		*(_func_10 **)(slot->loopSequencePosition + (uint)bVar1 * 0x10 + uVar2) =
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
// line 866, offset 0x80056590
/* begin block 1 */
// Start line: 867
// Start offset: 0x80056590
// Variables:
// 		int prevNestLevel; // $v1
// 		int track; // $a1
/* end block 1 */
// End offset: 0x80056610
// End Line: 891

/* begin block 2 */
// Start line: 1798
/* end block 2 */
// End Line: 1799

void metaCmdLoopEnd(AadSeqEvent *event, _AadSequenceSlot *slot)

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
	if (bVar1 != 0)
	{
		iVar4 = (int)&(slot->tempo).currentTick + track + iVar3 * 0x10;
		cVar2 = *(char *)(iVar4 + 0x4f8);
		if ((cVar2 == '\0') || (*(char *)(iVar4 + 0x4f8) = cVar2 + -1, cVar2 != '\x01'))
		{
			aadGotoSequencePosition(slot, track, (uchar *)slot->loopSequencePosition[iVar3 * 0x10 + track]);
		}
		else
		{
			*(undefined *)(iVar5 + 0x4e8) = (char)iVar3;
		}
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdLoopBreak(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 894, offset 0x80056620
/* begin block 1 */
// Start line: 1854
/* end block 1 */
// End Line: 1855

/* begin block 2 */
// Start line: 1857
/* end block 2 */
// End Line: 1858

void metaCmdLoopBreak(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdDefineLabel(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 901, offset 0x80056628
/* begin block 1 */
// Start line: 1868
/* end block 1 */
// End Line: 1869

/* begin block 2 */
// Start line: 1875
/* end block 2 */
// End Line: 1876

void metaCmdDefineLabel(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdGotoLabel(struct AadSeqEvent *event /*$v0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 912, offset 0x80056630
/* begin block 1 */
// Start line: 913
// Start offset: 0x80056630
/* end block 1 */
// End offset: 0x80056630
// End Line: 913

/* begin block 2 */
// Start line: 1890
/* end block 2 */
// End Line: 1891

void metaCmdGotoLabel(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadGotoSequenceLabel(slot, (uint)event->track, (uint)(byte)event->dataByte[0]);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetSequencePosition(struct AadSeqEvent *event /*$v0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 922, offset 0x80056660
/* begin block 1 */
// Start line: 923
// Start offset: 0x80056660
/* end block 1 */
// End offset: 0x80056660
// End Line: 923

/* begin block 2 */
// Start line: 1914
/* end block 2 */
// End Line: 1915

void metaCmdSetSequencePosition(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadGotoSequenceLabel(slot->selectedSlotPtr, (uint)event->track, (uint)(byte)event->dataByte[0]);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdBranchIfVarEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
// line 932, offset 0x80056690
/* begin block 1 */
// Start line: 933
// Start offset: 0x80056690
// Variables:
// 		int variableNum; // $v1
// 		int value; // $v1
// 		int labelNum; // $a2
/* end block 1 */
// End offset: 0x800566CC
// End Line: 943

/* begin block 2 */
// Start line: 1934
/* end block 2 */
// End Line: 1935

void metaCmdBranchIfVarEqual(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] ==
		event->dataByte[1])
	{
		aadGotoSequenceLabel(slot, (uint)event->track, (uint)(byte)event->dataByte[2]);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdBranchIfVarNotEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
// line 946, offset 0x800566dc
/* begin block 1 */
// Start line: 947
// Start offset: 0x800566DC
// Variables:
// 		int variableNum; // $v1
// 		int value; // $v1
// 		int labelNum; // $a2
/* end block 1 */
// End offset: 0x80056718
// End Line: 957

/* begin block 2 */
// Start line: 1974
/* end block 2 */
// End Line: 1975

void metaCmdBranchIfVarNotEqual(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] !=
		event->dataByte[1])
	{
		aadGotoSequenceLabel(slot, (uint)event->track, (uint)(byte)event->dataByte[2]);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdBranchIfVarLess(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
// line 960, offset 0x80056728
/* begin block 1 */
// Start line: 961
// Start offset: 0x80056728
// Variables:
// 		int variableNum; // $v1
// 		int value; // $v1
// 		int labelNum; // $a2
/* end block 1 */
// End offset: 0x80056768
// End Line: 971

/* begin block 2 */
// Start line: 2014
/* end block 2 */
// End Line: 2015

void metaCmdBranchIfVarLess(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] <
		(byte)event->dataByte[1])
	{
		aadGotoSequenceLabel(slot, (uint)event->track, (uint)(byte)event->dataByte[2]);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdBranchIfVarGreater(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
// line 974, offset 0x80056778
/* begin block 1 */
// Start line: 975
// Start offset: 0x80056778
// Variables:
// 		int variableNum; // $v1
// 		int value; // $v1
// 		int labelNum; // $a2
/* end block 1 */
// End offset: 0x800567B8
// End Line: 985

/* begin block 2 */
// Start line: 2054
/* end block 2 */
// End Line: 2055

void metaCmdBranchIfVarGreater(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[1] <
		(byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]])
	{
		aadGotoSequenceLabel(slot, (uint)event->track, (uint)(byte)event->dataByte[2]);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdBranchIfVarLessOrEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
// line 988, offset 0x800567c8
/* begin block 1 */
// Start line: 989
// Start offset: 0x800567C8
// Variables:
// 		int variableNum; // $v1
// 		int value; // $v1
// 		int labelNum; // $a2
/* end block 1 */
// End offset: 0x80056808
// End Line: 999

/* begin block 2 */
// Start line: 2094
/* end block 2 */
// End Line: 2095

void metaCmdBranchIfVarLessOrEqual(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] <=
		(byte)event->dataByte[1])
	{
		aadGotoSequenceLabel(slot, (uint)event->track, (uint)(byte)event->dataByte[2]);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdBranchIfVarGreaterOrEqual(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
// line 1002, offset 0x80056818
/* begin block 1 */
// Start line: 1003
// Start offset: 0x80056818
// Variables:
// 		int variableNum; // $v1
// 		int value; // $v1
// 		int labelNum; // $a2
/* end block 1 */
// End offset: 0x80056858
// End Line: 1013

/* begin block 2 */
// Start line: 2134
/* end block 2 */
// End Line: 2135

void metaCmdBranchIfVarGreaterOrEqual(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[1] <=
		(byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]])
	{
		aadGotoSequenceLabel(slot, (uint)event->track, (uint)(byte)event->dataByte[2]);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdBranchIfVarBitsSet(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
// line 1016, offset 0x80056868
/* begin block 1 */
// Start line: 1017
// Start offset: 0x80056868
// Variables:
// 		int variableNum; // $v1
// 		int mask; // $v1
// 		int labelNum; // $a2
/* end block 1 */
// End offset: 0x800568A8
// End Line: 1026

/* begin block 2 */
// Start line: 2174
/* end block 2 */
// End Line: 2175

void metaCmdBranchIfVarBitsSet(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if (((&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] &
		 event->dataByte[1]) != 0)
	{
		aadGotoSequenceLabel(slot, (uint)event->track, (uint)(byte)event->dataByte[2]);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdBranchIfVarBitsClear(struct AadSeqEvent *event /*$a3*/, struct _AadSequenceSlot *slot /*$a0*/)
// line 1029, offset 0x800568b8
/* begin block 1 */
// Start line: 1030
// Start offset: 0x800568B8
// Variables:
// 		int variableNum; // $v1
// 		int mask; // $v1
// 		int labelNum; // $a2
/* end block 1 */
// End offset: 0x800568F8
// End Line: 1039

/* begin block 2 */
// Start line: 2209
/* end block 2 */
// End Line: 2210

void metaCmdBranchIfVarBitsClear(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if (((&DAT_00001c08)[(int)&aadMem->updateCounter + (uint)(byte)event->dataByte[0]] &
		 event->dataByte[1]) == 0)
	{
		aadGotoSequenceLabel(slot, (uint)event->track, (uint)(byte)event->dataByte[2]);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSubstituteVariableParam1(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 1042, offset 0x80056908
/* begin block 1 */
// Start line: 2244
/* end block 1 */
// End Line: 2245

/* begin block 2 */
// Start line: 2245
/* end block 2 */
// End Line: 2246

void metaCmdSubstituteVariableParam1(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	iVar1 = (int)&(slot->tempo).currentTick + (uint)event->track;
	*(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 1;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSubstituteVariableParam2(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 1049, offset 0x80056928
/* begin block 1 */
// Start line: 2258
/* end block 1 */
// End Line: 2259

/* begin block 2 */
// Start line: 2259
/* end block 2 */
// End Line: 2260

void metaCmdSubstituteVariableParam2(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	iVar1 = (int)&(slot->tempo).currentTick + (uint)event->track;
	*(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 2;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSubstituteVariableParam3(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 1056, offset 0x80056948
/* begin block 1 */
// Start line: 2272
/* end block 1 */
// End Line: 2273

/* begin block 2 */
// Start line: 2273
/* end block 2 */
// End Line: 2274

void metaCmdSubstituteVariableParam3(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	iVar1 = (int)&(slot->tempo).currentTick + (uint)event->track;
	*(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 4;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdEndSequence(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$s0*/)
// line 1062, offset 0x80056968
/* begin block 1 */
// Start line: 2284
/* end block 1 */
// End Line: 2285

void metaCmdEndSequence(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadInitSequenceSlot(slot);
	aadAllNotesOff((uint)slot->thisSlotNumber);
	if (aadMem->endSequenceCallback != (_func_78 *)0x0)
	{
		(*aadMem->endSequenceCallback)(aadMem->endSequenceCallbackData, (uint)slot->thisSlotNumber, 0);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdPlaySoundEffect(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 1180, offset 0x800569c4
/* begin block 1 */
// Start line: 2520
/* end block 1 */
// End Line: 2521

/* begin block 2 */
// Start line: 2521
/* end block 2 */
// End Line: 2522

void metaCmdPlaySoundEffect(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdStopSoundEffect(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 1183, offset 0x800569cc
/* begin block 1 */
// Start line: 2526
/* end block 1 */
// End Line: 2527

/* begin block 2 */
// Start line: 2527
/* end block 2 */
// End Line: 2528

void metaCmdStopSoundEffect(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ metaCmdSetSoundEffectVolumePan(struct AadSeqEvent *event /*$a0*/, struct _AadSequenceSlot *slot /*$a1*/)
// line 1186, offset 0x800569d4
/* begin block 1 */
// Start line: 2532
/* end block 1 */
// End Line: 2533

/* begin block 2 */
// Start line: 2533
/* end block 2 */
// End Line: 2534

void metaCmdSetSoundEffectVolumePan(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}
