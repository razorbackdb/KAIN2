#include "THISDUST.H"
#include "AADSQCMD.H"

void metaCmdSubstituteVariableParam2(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	int iVar2;
	byte bVar3;
	byte bVar4;

	iVar2 = (int)&(slot->tempo).currentTick + (u_int)event->track;
	bVar1 = *(byte *)(iVar2 + 0x3d8);
	if (((bVar1 & 7) != 0) && (2 < (u_int)event->statusByte - 0x41))
	{
		bVar3 = bVar1;
		if ((bVar1 & 1) != 0)
		{
			bVar3 = bVar1 & 0xfe;
			event->dataByte[0] =
				(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]];
		}
		bVar4 = bVar3;
		if ((bVar1 & 2) != 0)
		{
			bVar4 = bVar3 & 0xfd;
			event->dataByte[1] =
				(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1]];
		}
		if ((bVar3 & 4) != 0)
		{
			bVar4 = bVar4 & 0xfb;
			event->dataByte[2] =
				(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[2]];
		}
		*(byte *)(iVar2 + 0x3d8) = bVar4;
	}
	return;
}

void metaCmdMuteChannelList(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x10)
	{
		slot->selectedChannel = event->dataByte[0];
	}
	return;
}

void metaCmdSetSlotPan(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	_AadSequenceSlot *p_Var2;

	bVar1 = event->dataByte[0];
	if ((int)(u_int)bVar1 < aadMem->numSlots)
	{
		p_Var2 = (_AadSequenceSlot *)aadMem->sequenceSlots[(u_int)bVar1];
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

void aadGetNumDynamicSequences(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	int iVar2;
	int bank;

	bank = slot->selectedDynamicBank;
	bVar1 = event->dataByte[0];
	if ((aadMem->dynamicBankStatus[bank] == 2) &&
		(iVar2 = aadGetTempoFromDynamicSequence(bank), (int)(u_int)bVar1 < iVar2))
	{
		aadGetNumDynamicSequences(bank, (u_int)bVar1, (u_int)slot->selectedSlotNum);
	}
	return;
}

void metaCmdUseSecondaryTempo(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdUsePrimaryTempo(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdSelectSlot(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	AadTempo local_10;

	local_10.quarterNoteTime =
		(u_int)(byte)event->dataByte[0] << 0x10 | (u_int)(byte)event->dataByte[1] << 8 |
		(u_int)(byte)event->dataByte[2];
	local_10.ppqn = (u_int)(slot->selectedSlotPtr->tempo).ppqn;
	aadSetSlotTempo((u_int)slot->selectedSlotNum, &local_10);
	return;
}

void metaCmdChangeTempo(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	AadTempo local_10;

	local_10.quarterNoteTime =
		(u_int)(byte)event->dataByte[0];
	local_10.ppqn = (u_int)(slot->selectedSlotPtr->tempo).ppqn;
	aadSetSlotTempo((u_int)slot->selectedSlotNum, &local_10);
	return;
}

void metaCmdSetTempoFromSequence(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	int iVar2;
	int bank;
	AadTempo AStack24;

	bank = slot->selectedDynamicBank;
	bVar1 = event->dataByte[0];
	if ((aadMem->dynamicBankStatus[bank] == 2) &&
		(iVar2 = aadGetTempoFromDynamicSequence(bank), (int)(u_int)bVar1 < iVar2))
	{
		metaCmdAssignSequence(bank, (u_int)bVar1, &AStack24);
		aadSetSlotTempo((u_int)slot->selectedSlotNum, &AStack24);
	}
	return;
}

void aadStopSlot(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	PadStartCom((u_int)slot->selectedSlotNum);
	return;
}

void metaCmdStopSlot(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadStopSfx((u_int)slot->selectedSlotNum);
	return;
}

void metaCmdPauseSlot(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadPauseSlot((u_int)slot->selectedSlotNum);
	return;
}

void aadResumeSlot(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	metaCmdResumeSlot((u_int)slot->selectedSlotNum);
	return;
}

void metaCmdGetChannelBendRange(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdGetChannelTranspose(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdSlotVolumeFade(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->slotVolume = event->dataByte[0];
	aadUpdateSlotVolPan(slot->selectedSlotPtr);
	return;
}

void metaCmdSetSlotVolume(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->slotPan = event->dataByte[0];
	aadUpdateSlotVolPan(slot->selectedSlotPtr);
	return;
}

void metaCmdSetChannelBasePriority(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->volume[slot->selectedChannel] = event->dataByte[0];
	aadUpdateChannelVolPan(slot->selectedSlotPtr, (u_int)slot->selectedChannel);
	return;
}

void metaCmdSetChannelVolume(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->panPosition[slot->selectedChannel] = event->dataByte[0];
	aadUpdateChannelVolPan(slot->selectedSlotPtr, (u_int)slot->selectedChannel);
	return;
}

void metaCmdEnableSustainUpdate(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->enableSustainUpdate =
		slot->selectedSlotPtr->enableSustainUpdate |
		(u_short)(1 << ((u_int)slot->selectedChannel & 0x1f));
	return;
}

void metaCmdDisableSustainUpdate(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->enableSustainUpdate =
		slot->selectedSlotPtr->enableSustainUpdate &
		~(u_short)(1 << ((u_int)slot->selectedChannel & 0x1f));
	return;
}

void aadMuteChannels(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadMuteChannels(slot->selectedSlotPtr, 1 << ((u_int)slot->selectedChannel & 0x1f));
	return;
}

void metaCmdUnMuteChannelList(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	metaCmdUnMuteChannel(slot->selectedSlotPtr, 1 << ((u_int)slot->selectedChannel & 0x1f));
	return;
}

void metaCmdGetChannelPan(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadMuteChannels(slot->selectedSlotPtr, (u_int) * (u_short *)event->dataByte);
	return;
}

void aadUnMuteChannels(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	metaCmdUnMuteChannel(slot->selectedSlotPtr, (u_int) * (u_short *)event->dataByte);
	return;
}

void metaCmdGetChannelVolume(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	u_short uVar1;

	uVar1 = *(u_short *)event->dataByte;
	metaCmdUnMuteChannel(slot->selectedSlotPtr, ~(u_int)uVar1);
	aadMuteChannels(slot->selectedSlotPtr, (u_int)uVar1);
	return;
}

void metaCmdDelayMute(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->delayedMuteMode =
		slot->selectedSlotPtr->delayedMuteMode | *(u_short *)event->dataByte;
	return;
}

void metaCmdUpdateMute(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	u_short uVar1;
	u_short uVar2;
	_AadSequenceSlot *slot_00;

	uVar1 = *(u_short *)event->dataByte;
	slot->selectedSlotPtr->delayedMuteMode = slot->selectedSlotPtr->delayedMuteMode & ~uVar1;
	slot_00 = slot->selectedSlotPtr;
	uVar2 = slot_00->delayedMuteCmds & uVar1;
	if (uVar2 != 0)
	{
		aadMuteChannels(slot_00, (u_int)uVar2);
		slot_00 = slot->selectedSlotPtr;
	}
	uVar1 = slot_00->delayedUnMuteCmds & uVar1;
	if (uVar1 != 0)
	{
		metaCmdUnMuteChannel(slot_00, (u_int)uVar1);
	}
	return;
}

void metaCmdChannelVolumeFade(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdChannelPanFade(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdSlotPanFade(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdStartSlot(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdSetChannelPan(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->currentProgram[slot->selectedChannel] = event->dataByte[0];
	return;
}

void metaCmdSetChannelBendRange(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdSetChannelPitchMap(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->transpose[slot->selectedChannel] = event->dataByte[0];
	return;
}

void metaCmdIgnoreChannelTranspose(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->ignoreTranspose =
		slot->selectedSlotPtr->ignoreTranspose | (u_short)(1 << ((u_int)slot->selectedChannel & 0x1f));
	return;
}

void metaCmdRespectChannelTranspose(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->selectedSlotPtr->ignoreTranspose =
		slot->selectedSlotPtr->ignoreTranspose & ~(u_short)(1 << ((u_int)slot->selectedChannel & 0x1f));
	return;
}

void metaCmdIgnoreChannelPitchMap(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdRespectChannelPitchMap(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdChannelPanFade(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdSetSequencePosition(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->sequenceNumberAssigned;
	}
	return;
}

void metaCmdGetTempo(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	byte bVar2;
	u_long uVar3;

	bVar1 = event->dataByte[1];
	bVar2 = event->dataByte[2];
	if ((((byte)event->dataByte[0] < 0x80) && (bVar1 < 0x80)) && (bVar2 < 0x80))
	{
		uVar3 = (slot->selectedSlotPtr->tempo).quarterNoteTime;
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] = (char)uVar3;
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)bVar1] = (char)(uVar3 >> 8);
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)bVar2] = (char)(uVar3 >> 0x10);
	}
	return;
}

void metaCmdGetSlotStatus(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
			*(undefined *)&slot->selectedSlotPtr->status;
	}
	return;
}

void metaCmdGetChannelMute(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;

	bVar1 = event->dataByte[1];
	if (((byte)event->dataByte[0] < 0x80) && (bVar1 < 0x80))
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
			*(undefined *)&slot->selectedSlotPtr->channelMute;
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)bVar1] =
			(char)(slot->selectedSlotPtr->channelMute >> 8);
	}
	return;
}

void metaCmdSetChannelTranspose(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->volume[slot->selectedChannel];
	}
	return;
}

void metaCmdMuteChannel(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->panPosition[slot->selectedChannel];
	}
	return;
}

void metaCmdSetSlotBendRange(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdSetChannelProgram(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->currentProgram[slot->selectedChannel];
	}
	return;
}

void metaCmdSetChannelMute(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdSelectChannel(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdGetSlotVolume(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->slotVolume;
	}
	return;
}

void metaCmdSetTempo(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[0] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] =
			slot->selectedSlotPtr->slotPan;
	}
	return;
}

void aadSetUserVariable(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[1] < 0x80)
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1]] =
			event->dataByte[0];
	}
	return;
}

void metaCmdSetVariableBits(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if (((byte)event->dataByte[0] < 0x80) && ((byte)event->dataByte[1] < 0x80))
	{
		(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1]] =
			(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]];
	}
	return;
}

void metaCmdAddVariable(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	if ((byte)event->dataByte[1] < 0x80)
	{
		iVar1 = (int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1];
		(&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] + event->dataByte[0];
	}
	return;
}

void metaCmdSubtractVariable(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	if ((byte)event->dataByte[1] < 0x80)
	{
		iVar1 = (int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1];
		(&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] - event->dataByte[0];
	}
	return;
}

void metaCmdSetVariable(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	if ((byte)event->dataByte[1] < 0x80)
	{
		iVar1 = (int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1];
		(&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] | event->dataByte[0];
	}
	return;
}

void metaCmdCopyVariable(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	if ((byte)event->dataByte[1] < 0x80)
	{
		iVar1 = (int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[1];
		(&DAT_00001c08)[iVar1] = (&DAT_00001c08)[iVar1] & ~event->dataByte[0];
	}
	return;
}

void metaCmdGetSequenceAssigned(_AadSequenceSlot *slot, int track, u_char *newPosition)

{
	char cVar1;
	int iVar2;

	iVar2 = (int)&(slot->tempo).currentTick + track;
	*(u_char **)(slot->sequencePosition + track) = newPosition;
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

void aadGotoSequencePosition(_AadSequenceSlot *slot, int track, int labelNumber)

{
	int iVar1;
	char cVar2;

	iVar1 = *(int *)((&aadMem->updateCounter + slot->sequenceAssignedDynamicBank)[0x13c] +
					 (u_int)slot->sequenceNumberAssigned * 4);
	slot->sequencePosition[track] =
		(_func_9 *)(iVar1 + *(int *)((&aadMem->updateCounter + slot->sequenceAssignedDynamicBank)[0x13e] + labelNumber * 4) + *(int *)(iVar1 + track * 4 + 0x10));
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

void metaCmdLoopStart(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	u_int uVar2;
	int iVar3;

	uVar2 = (u_int)event->track;
	iVar3 = (int)&(slot->tempo).currentTick + uVar2;
	bVar1 = *(byte *)(iVar3 + 0x4e8);
	if (bVar1 < 4)
	{
		*(_func_9 **)(slot->loopSequencePosition + (u_int)bVar1 * 0x10 + uVar2) =
			slot->sequencePosition[uVar2];
		slot->loopCounter[uVar2 + (u_int)bVar1 * 0x10] = event->dataByte[0];
		*(char *)(iVar3 + 0x4e8) = *(char *)(iVar3 + 0x4e8) + '\x01';
	}
	*(byte *)(iVar3 + 0x3d8) = *(byte *)(iVar3 + 0x3d8) & 0xef;
	return;
}

void metaCmdLoopEnd(AadSeqEvent *event, _AadSequenceSlot *slot)

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
	if (bVar1 != 0)
	{
		iVar4 = (int)&(slot->tempo).currentTick + track + iVar3 * 0x10;
		cVar2 = *(char *)(iVar4 + 0x4f8);
		if ((cVar2 == '\0') || (*(char *)(iVar4 + 0x4f8) = cVar2 + -1, cVar2 != '\x01'))
		{
			metaCmdGetSequenceAssigned(slot, track, (u_char *)slot->loopSequencePosition[iVar3 * 0x10 + track]);
		}
		else
		{
			*(undefined *)(iVar5 + 0x4e8) = (char)iVar3;
		}
	}
	return;
}

void metaCmdLoopBreak(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdDefineLabel(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdGotoLabel(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadGotoSequencePosition(slot, (u_int)event->track, (u_int)(byte)event->dataByte[0]);
	return;
}

void aadGotoSequenceLabel(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadGotoSequencePosition(slot->selectedSlotPtr, (u_int)event->track, (u_int)(byte)event->dataByte[0]);
	return;
}

void metaCmdBranchIfVarEqual(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] ==
		event->dataByte[1])
	{
		aadGotoSequencePosition(slot, (u_int)event->track, (u_int)(byte)event->dataByte[2]);
	}
	return;
}

void metaCmdBranchIfVarGreater(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] !=
		event->dataByte[1])
	{
		aadGotoSequencePosition(slot, (u_int)event->track, (u_int)(byte)event->dataByte[2]);
	}
	return;
}

void metaCmdBranchIfVarLess(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] <
		(byte)event->dataByte[1])
	{
		aadGotoSequencePosition(slot, (u_int)event->track, (u_int)(byte)event->dataByte[2]);
	}
	return;
}

void metaCmdBranchIfVarNotEqual(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[1] <
		(byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]])
	{
		aadGotoSequencePosition(slot, (u_int)event->track, (u_int)(byte)event->dataByte[2]);
	}
	return;
}

void metaCmdBranchIfVarLessOrEqual(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] <=
		(byte)event->dataByte[1])
	{
		aadGotoSequencePosition(slot, (u_int)event->track, (u_int)(byte)event->dataByte[2]);
	}
	return;
}

void metaCmdBranchIfVarBitsSet(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if ((byte)event->dataByte[1] <=
		(byte)(&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]])
	{
		aadGotoSequencePosition(slot, (u_int)event->track, (u_int)(byte)event->dataByte[2]);
	}
	return;
}

void metaCmdBranchIfVarGreaterOrEqual(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if (((&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] &
		 event->dataByte[1]) != 0)
	{
		aadGotoSequencePosition(slot, (u_int)event->track, (u_int)(byte)event->dataByte[2]);
	}
	return;
}

void metaCmdBranchIfVarBitsClear(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if (((&DAT_00001c08)[(int)&aadMem->updateCounter + (u_int)(byte)event->dataByte[0]] &
		 event->dataByte[1]) == 0)
	{
		aadGotoSequencePosition(slot, (u_int)event->track, (u_int)(byte)event->dataByte[2]);
	}
	return;
}

void metaCmdSubstituteVariableParam3(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	iVar1 = (int)&(slot->tempo).currentTick + (u_int)event->track;
	*(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 1;
	return;
}

void metaCmdSubstituteVariableParam1(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	iVar1 = (int)&(slot->tempo).currentTick + (u_int)event->track;
	*(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 2;
	return;
}

void aadSubstituteVariables(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	int iVar1;

	iVar1 = (int)&(slot->tempo).currentTick + (u_int)event->track;
	*(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 4;
	return;
}

void aadAssignDynamicSequence(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	aadInitSequenceSlot(slot);
	aadAllNotesOff((u_int)slot->thisSlotNumber);
	if (aadMem->endSequenceCallback != (_func_49 *)0x0)
	{
		(*aadMem->endSequenceCallback)(aadMem->endSequenceCallbackData, (u_int)slot->thisSlotNumber, 0);
	}
	return;
}

void metaCmdPlaySoundEffect(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdSetSoundEffectVolumePan(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void metaCmdStopSoundEffect(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}
