#include "THISDUST.H"
#include "AADSEQEV.H"

int aadQueueNextEvent(struct _AadSequenceSlot *slot, int track)
{

	struct AadSeqEvent seqEvent;
	unsigned char *seqData;
	unsigned long deltaTime;
	int c;
	int n;
	int i;

	return 0;
}

void aadExecuteSfxCommand(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	code *pcVar1;

	if ((event->statusByte & 0x80) == 0)
	{
		metaCmdSubstituteVariableParam2(event, slot);
		if (0x4d < event->statusByte)
		{
			return;
		}
		pcVar1 = (code *)(&midiMetaEventFunction)[(u_int)event->statusByte & 0x7f];
	}
	else
	{
		pcVar1 = *(code **)((int)&midiEventFunction + ((u_int)(event->statusByte >> 2) & 0x1c));
	}
	(*pcVar1)(event, slot);
	return;
}

void midiNoteOff(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void midiNoteOn(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	byte bVar1;
	byte bVar2;
	u_char uVar3;
	AadMemoryStruct *pAVar4;
	u_long *puVar5;
	AadSynthVoice *voice;
	u_long *puVar6;
	int iVar7;
	u_int *puVar8;
	AadToneAtr *toneAtr;
	int iVar9;
	u_int uVar10;
	AadProgramAtr *progAtr;
	u_int uVar11;
	u_int uVar12;
	u_int local_38;

	uVar12 = (u_int)event->statusByte & 0xf;
	iVar7 = (int)&(slot->tempo).currentTick + uVar12;
	if ((((int)(u_int)slot->channelMute >> uVar12 & 1U) == 0) && (*(char *)(iVar7 + 0x590) != -1))
	{
		bVar1 = event->dataByte[0];
		uVar11 = (u_int)bVar1;
		iVar9 = 0;
		if (event->dataByte[1] == '\0')
		{
			iVar7 = 0x1dc;
			do
			{
				pAVar4 = aadMem;
				puVar8 = (u_int *)((int)&aadMem->updateCounter + iVar7);
				if ((((u_int) * (byte *)(puVar8 + 2) == (slot->slotID | uVar12)) &&
					 ((u_int) * (byte *)((int)puVar8 + 10) == uVar11)) &&
					((aadMem->voiceStatus[iVar9] != '\0' && (aadMem->voiceStatus[iVar9] != '\x02'))))
				{
					aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | *puVar8;
					pAVar4->voiceKeyOnRequest = pAVar4->voiceKeyOnRequest & ~*puVar8;
					*(undefined *)(puVar8 + 2) = 0xff;
				}
				iVar9 = iVar9 + 1;
				iVar7 = iVar7 + 0x1c;
			} while (iVar9 < 0x18);
		}
		else
		{
			local_38 = uVar11;
			if (((int)(u_int)slot->ignoreTranspose >> uVar12 & 1U) == 0)
			{
				local_38 = uVar11 + *(byte *)(iVar7 + 0x5c0) & 0xff;
			}
			iVar7 = (int)&(slot->tempo).currentTick + uVar12;
			bVar2 = *(byte *)(iVar7 + 0x560);
			puVar6 = &aadMem->updateCounter + bVar2;
			if (puVar6[0x140] == 2)
			{
				progAtr = (AadProgramAtr *)(puVar6[0x136] + (u_int) * (byte *)(iVar7 + 0x590) * 8);
				uVar10 = (u_int)progAtr->firstTone;
				if (uVar10 < uVar10 + progAtr->numTones)
				{
					puVar5 = (u_long *)((int)&(slot->tempo).currentTick + uVar12 * 2);
					toneAtr = (AadToneAtr *)(puVar6[0x138] + uVar10 * 0x10);
					do
					{
						if (((toneAtr->minNote <= uVar11) && (uVar11 <= toneAtr->maxNote)) &&
							(voice = aadAllocateVoice((u_int)toneAtr->priority), voice != (AadSynthVoice *)0x0))
						{
							if ((toneAtr->pitchBendMax == '\0') || (*(short *)(puVar5 + 0x15c) == 0x2000))
							{
								aadPlayTone(toneAtr, *(u_long *)(aadMem->dynamicWaveAddr[bVar2] + (int)toneAtr->waveIndex * 4), progAtr, local_38,
											(u_int)(byte)event->dataByte[1], (u_int) * (byte *)(iVar7 + 0x5a0),
											(u_int) * (byte *)(iVar7 + 0x5b0), (u_int)slot->slotVolume,
											*slot->masterVolPtr, voice, 0);
								voice->handle = 0;
							}
							else
							{
								aadPlayTonePitchBend(toneAtr, *(u_long *)(aadMem->dynamicWaveAddr[bVar2] + (int)toneAtr->waveIndex * 4), progAtr, local_38,
													 (u_int)(byte)event->dataByte[1], (u_int) * (byte *)(iVar7 + 0x5a0),
													 (u_int) * (byte *)(iVar7 + 0x5b0), (u_int)slot->slotVolume, *slot->masterVolPtr, voice, (u_int) * (u_short *)(puVar5 + 0x15c));
								voice->handle = 0;
							}
							voice->voiceID = slot->slotID | (byte)uVar12;
							uVar3 = toneAtr->priority;
							voice->note = bVar1;
							voice->priority = uVar3;
							voice->program = *(u_char *)(iVar7 + 0x590);
							voice->volume = event->dataByte[1];
							voice->updateVol = *(u_char *)(iVar7 + 0x5a0);
							uVar3 = *(u_char *)(iVar7 + 0x5b0);
							voice->progAtr = progAtr;
							voice->toneAtr = toneAtr;
							voice->pan = uVar3;
						}
						uVar10 = uVar10 + 1;
						toneAtr = toneAtr + 1;
					} while ((int)uVar10 < (int)((u_int)progAtr->firstTone + (u_int)progAtr->numTones));
				}
			}
		}
	}
	return;
}

void aadUpdateChannelVolPan(_AadSequenceSlot *slot, int channel)

{
	byte bVar1;
	u_int uVar2;
	int iVar3;
	int iVar4;
	int vNum;
	int iVar5;
	int iVar6;
	int iVar7;
	int iVar8;
	int iVar9;
	short local_28;
	short local_26;

	vNum = 0;
	iVar4 = (int)&(slot->tempo).currentTick + channel;
	iVar5 = 0x1dc;
	do
	{
		iVar3 = (int)&aadMem->updateCounter + iVar5;
		if ((u_int) * (byte *)(iVar3 + 8) == ((u_int)slot->slotID | channel))
		{
			local_28 = (u_short) * (byte *)(iVar3 + 0xe) * (u_short) * (byte *)(iVar3 + 0xe);
			local_26 = (u_short) * (byte *)(iVar3 + 0xe) * (u_short) * (byte *)(iVar3 + 0xe);
			if ((aadMem->flags & 1U) == 0)
			{
				bVar1 = *(byte *)(iVar4 + 0x5b0);
				if (bVar1 < 0x41)
				{
					if (bVar1 < 0x3f)
					{
						local_26 = (short)((int)((int)local_28 * (u_int) * (byte *)(iVar4 + 0x5b0) *
												 (u_int) * (byte *)(iVar4 + 0x5b0)) >>
										   0xc);
					}
				}
				else
				{
					local_28 = (short)((int)local_26 * (0x7f - (u_int)bVar1) * (0x7f - (u_int)bVar1) >> 0xc);
				}
			}
			uVar2 = (u_int) * (byte *)(*(int *)(iVar3 + 0x14) + 2);
			iVar6 = uVar2 * uVar2;
			local_28 = (short)((u_int)(local_28 * iVar6) >> 0xe);
			local_26 = (short)((u_int)(local_26 * iVar6) >> 0xe);
			if ((aadMem->flags & 1U) == 0)
			{
				bVar1 = *(byte *)(*(int *)(iVar3 + 0x14) + 3);
				if (bVar1 < 0x41)
				{
					if (bVar1 < 0x3f)
					{
						uVar2 = (u_int) * (byte *)(*(int *)(iVar3 + 0x14) + 3);
						local_26 = (short)((int)((int)local_28 * uVar2 * uVar2) >> 0xc);
					}
				}
				else
				{
					local_28 = (short)((int)local_26 * (0x7f - (u_int)bVar1) * (0x7f - (u_int)bVar1) >> 0xc);
				}
			}
			iVar6 = (u_int) * (byte *)(iVar4 + 0x5a0) * (u_int) * (byte *)(iVar4 + 0x5a0);
			uVar2 = (u_int) * (byte *)(*(int *)(iVar3 + 0x18) + 4);
			iVar7 = uVar2 * uVar2;
			iVar8 = (u_int)slot->slotVolume * (u_int)slot->slotVolume;
			iVar9 = *slot->masterVolPtr * *slot->masterVolPtr;
			SpuSetVoiceADSR1ADSR2(vNum, (u_short)((u_int)((short)((u_int)((short)((u_int)((short)((u_int)(local_28 * iVar6) >> 0xe) * iVar7) >> 0xe) * iVar8) >> 0xe) * iVar9) >> 0xe),
								  (u_short)((u_int)((short)((u_int)((short)((u_int)((short)((u_int)(local_26 * iVar6) >>
																							0xe) *
																					iVar7) >>
																			0xe) *
																	iVar8) >>
															0xe) *
													iVar9) >>
											0xe));
			*(undefined *)(iVar3 + 0xf) = *(undefined *)(iVar4 + 0x5a0);
			*(undefined *)(iVar3 + 0x10) = *(undefined *)(iVar4 + 0x5b0);
		}
		vNum = vNum + 1;
		iVar5 = iVar5 + 0x1c;
	} while (vNum < 0x18);
	return;
}

void aadUpdateSlotVolPan(_AadSequenceSlot *slot)

{
	byte bVar1;
	u_int uVar2;
	u_int uVar3;
	int vNum;
	int iVar4;
	int iVar5;
	int iVar6;
	int iVar7;
	int iVar8;
	short local_18;
	short local_16;

	vNum = 0;
	iVar4 = 0x1dc;
	do
	{
		iVar6 = (int)&aadMem->updateCounter + iVar4;
		if (((u_int) * (byte *)(iVar6 + 8) & 0xf0) == (u_int)slot->slotID)
		{
			local_18 = (u_short) * (byte *)(iVar6 + 0xe) * (u_short) * (byte *)(iVar6 + 0xe);
			local_16 = (u_short) * (byte *)(iVar6 + 0xe) * (u_short) * (byte *)(iVar6 + 0xe);
			uVar3 = (u_int) * (byte *)(iVar6 + 8) & 0xf;
			if ((aadMem->flags & 1U) == 0)
			{
				iVar5 = (int)&(slot->tempo).currentTick + uVar3;
				bVar1 = *(byte *)(iVar5 + 0x5b0);
				if (bVar1 < 0x41)
				{
					if (bVar1 < 0x3f)
					{
						uVar2 = (u_int) * (byte *)(iVar5 + 0x5b0);
						local_16 = (short)((int)((int)local_18 * uVar2 * uVar2) >> 0xc);
					}
				}
				else
				{
					local_18 = (short)((int)local_16 * (0x7f - (u_int)bVar1) * (0x7f - (u_int)bVar1) >> 0xc);
				}
			}
			uVar2 = (u_int) * (byte *)(*(int *)(iVar6 + 0x14) + 2);
			iVar5 = uVar2 * uVar2;
			local_18 = (short)((u_int)(local_18 * iVar5) >> 0xe);
			local_16 = (short)((u_int)(local_16 * iVar5) >> 0xe);
			if ((aadMem->flags & 1U) == 0)
			{
				bVar1 = *(byte *)(*(int *)(iVar6 + 0x14) + 3);
				if (bVar1 < 0x41)
				{
					if (bVar1 < 0x3f)
					{
						uVar2 = (u_int) * (byte *)(*(int *)(iVar6 + 0x14) + 3);
						local_16 = (short)((int)((int)local_18 * uVar2 * uVar2) >> 0xc);
					}
				}
				else
				{
					local_18 = (short)((int)local_16 * (0x7f - (u_int)bVar1) * (0x7f - (u_int)bVar1) >> 0xc);
				}
			}
			iVar5 = (u_int)slot->volume[uVar3] * (u_int)slot->volume[uVar3];
			uVar3 = (u_int) * (byte *)(*(int *)(iVar6 + 0x18) + 4);
			iVar6 = uVar3 * uVar3;
			iVar7 = (u_int)slot->slotVolume * (u_int)slot->slotVolume;
			iVar8 = *slot->masterVolPtr * *slot->masterVolPtr;
			SpuSetVoiceADSR1ADSR2(vNum, (u_short)((u_int)((short)((u_int)((short)((u_int)((short)((u_int)(local_18 * iVar5) >> 0xe) * iVar6) >> 0xe) * iVar7) >> 0xe) * iVar8) >> 0xe),
								  (u_short)((u_int)((short)((u_int)((short)((u_int)((short)((u_int)(local_16 * iVar5) >>
																							0xe) *
																					iVar6) >>
																			0xe) *
																	iVar7) >>
															0xe) *
													iVar8) >>
											0xe));
		}
		vNum = vNum + 1;
		iVar4 = iVar4 + 0x1c;
	} while (vNum < 0x18);
	return;
}

void aadUpdateChannelPitchBend(_AadSequenceSlot *slot, int channel)

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
	iVar6 = (u_int)slot->pitchWheel[channel] - 0x2000;
	do
	{
		iVar1 = (int)&aadMem->updateCounter + iVar5;
		if ((u_int) * (byte *)(iVar1 + 8) == ((u_int)slot->slotID | channel))
		{
			iVar3 = *(int *)(iVar1 + 0x14);
			if (*(byte *)(iVar3 + 9) != 0)
			{
				(int)(u_int) * (byte *)(iVar3 + 9);
				iVar7;
				if ((*(byte *)(iVar3 + 5) & 0x80) == 0)
				{
					sVar2 = (&aadPitchTable)[iVar1] +
							(u_short)((&aadStepsPerCent)[iVar1] * 100 * (u_int) * (byte *)(iVar3 + 5) >> 0x17);
				}
				else
				{
					sVar2 = (&aadPitchTable)[iVar1] -
							(u_short)((&aadStepsPerCent)[iVar1] * 100 * (0x100 - (u_int) * (byte *)(iVar3 + 5)) >>
									  0x17);
				}
		SpuSetVoiceStartAddr

                                        iVar7));
			}
		}
		iVar4 = iVar4 + 1;
		iVar5 = iVar5 + 0x1c;
	} while (iVar4 < 0x18);
	return;
}

void midiPolyphonicAftertouch(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void midiControlChange(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	(*(code *)(&midiControlFunction)[(u_int)(byte)event->dataByte[0] & 0xf])();
	return;
}

void midiProgramChange(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	slot->currentProgram[(u_int)event->statusByte & 0xf] = event->dataByte[0];
	return;
}

void midiChannelAftertouch(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void midiPitchWheelControl(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	u_int channel;

	channel = (u_int)event->statusByte & 0xf;
	slot->pitchWheel[channel] =
		(u_short)(byte)event->dataByte[0] | (u_short)(byte)event->dataByte[1] << 7;
	aadUpdateChannelPitchBend(slot, channel);
	return;
}

void midiMetaEvent(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void midiControlBankSelect(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}

void midiControlPan(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	u_int channel;

	channel = (u_int)event->statusByte & 0xf;
	slot->volume[channel] = event->dataByte[1];
	if (((int)(u_int)slot->enableSustainUpdate >> channel & 1U) != 0)
	{
		aadUpdateChannelVolPan(slot, channel);
	}
	return;
}

void midiControlVolume(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	u_int channel;

	channel = (u_int)event->statusByte & 0xf;
	slot->panPosition[channel] = event->dataByte[1];
	if (((int)(u_int)slot->enableSustainUpdate >> channel & 1U) != 0)
	{
		aadUpdateChannelVolPan(slot, channel);
	}
	return;
}

void midiControlCallback(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	if (aadMem->controller11Callback != (_func_48 *)0x0)
	{
		(*aadMem->controller11Callback)(aadMem->controller11CallbackData, (u_int)slot->thisSlotNumber,
										(u_int)event->statusByte & 0xf, (u_int)(byte)event->dataByte[1]);
	}
	return;
}

void midiControlDummy(AadSeqEvent *event, _AadSequenceSlot *slot)

{
	return;
}
