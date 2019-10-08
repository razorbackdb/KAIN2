#ifndef AADSQCMD_H
#define AADSQCMD_H

extern void aadSubstituteVariables(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSelectChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSelectSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdAssignSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdUsePrimaryTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdUseSecondaryTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdChangeTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetTempoFromSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdStartSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdStopSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdPauseSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdResumeSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetSlotBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetChannelBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetSlotVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetSlotPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetChannelVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetChannelPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdEnableSustainUpdate(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdDisableSustainUpdate(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdMuteChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdUnMuteChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdMuteChannelList(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdUnMuteChannelList(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetChannelMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdDelayMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdUpdateMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdChannelVolumeFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdChannelPanFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSlotVolumeFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSlotPanFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetChannelProgram(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetChannelBasePriority(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdIgnoreChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdRespectChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdIgnoreChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdRespectChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetSequenceAssigned(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetSlotStatus(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetChannelMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetChannelVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetChannelPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetChannelProgram(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetChannelBasePriority(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetChannelBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetSlotVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGetSlotPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdCopyVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdAddVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSubtractVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetVariableBits(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdClearVariableBits(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void aadGotoSequencePosition(struct _AadSequenceSlot *slot, int track, unsigned char *newPosition);

extern void aadGotoSequenceLabel(struct _AadSequenceSlot *slot, int track, int labelNumber);

extern void metaCmdLoopStart(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdLoopEnd(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdLoopBreak(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdDefineLabel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdGotoLabel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetSequencePosition(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdBranchIfVarEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdBranchIfVarNotEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdBranchIfVarLess(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdBranchIfVarGreater(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdBranchIfVarLessOrEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdBranchIfVarGreaterOrEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdBranchIfVarBitsSet(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdBranchIfVarBitsClear(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSubstituteVariableParam1(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSubstituteVariableParam2(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSubstituteVariableParam3(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdEndSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdPlaySoundEffect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdStopSoundEffect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void metaCmdSetSoundEffectVolumePan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

#endif
