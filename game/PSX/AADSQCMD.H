#ifndef AADSQCMD_H
#define AADSQCMD_H


extern void aadSubstituteVariables(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057008

extern void metaCmdSelectChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800570C0

extern void metaCmdSelectSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800570E0

extern void metaCmdAssignSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057130

extern void metaCmdUsePrimaryTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800571A0

extern void metaCmdUseSecondaryTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800571A8

extern void metaCmdSetTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800571B0

extern void metaCmdChangeTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005721C

extern void metaCmdSetTempoFromSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005728C

extern void metaCmdStartSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057308

extern void metaCmdStopSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005732C

extern void metaCmdPauseSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057350

extern void metaCmdResumeSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057374

extern void metaCmdSetSlotBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057398

extern void metaCmdSetChannelBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800573A0

extern void metaCmdSetSlotVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800573A8

extern void metaCmdSetSlotPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800573DC

extern void metaCmdSetChannelVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057410

extern void metaCmdSetChannelPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005744C

extern void metaCmdEnableSustainUpdate(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057488

extern void metaCmdDisableSustainUpdate(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800574A8

extern void metaCmdMuteChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800574CC

extern void metaCmdUnMuteChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800574FC

extern void metaCmdMuteChannelList(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005752C

extern void metaCmdSetChannelMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005755C

extern void metaCmdUnMuteChannelList(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800575D4

extern void metaCmdChannelVolumeFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057604

extern void metaCmdChannelPanFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005760C

extern void metaCmdSlotVolumeFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057614

extern void metaCmdSlotPanFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005761C

extern void metaCmdSetChannelProgram(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057624

extern void metaCmdSetChannelBasePriority(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005763C

extern void metaCmdSetChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057644

extern void metaCmdIgnoreChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005765C

extern void metaCmdRespectChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005767C

extern void metaCmdSetChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800576A0

extern void metaCmdIgnoreChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800576A8

extern void metaCmdRespectChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800576B0

extern void metaCmdGetSequenceAssigned(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800576B8

extern void metaCmdGetTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800576E8

extern void metaCmdGetSlotStatus(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005774C

extern void metaCmdGetChannelMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005777C

extern void metaCmdGetChannelVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800577CC

extern void metaCmdGetChannelPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057804

extern void metaCmdGetChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005783C

extern void metaCmdGetChannelProgram(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057844

extern void metaCmdGetChannelBasePriority(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005787C

extern void metaCmdGetChannelBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057884

extern void metaCmdGetSlotVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005788C

extern void metaCmdGetSlotPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800578BC

extern void metaCmdSetVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800578EC

extern void metaCmdCopyVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057918

extern void metaCmdAddVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057954

extern void metaCmdSubtractVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005798C

extern void metaCmdSetVariableBits(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800579C4

extern void metaCmdClearVariableBits(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800579FC

extern void aadGotoSequencePosition(struct _AadSequenceSlot *slot, int track, unsigned char *newPosition); // 0x80057A34

extern void aadGotoSequenceLabel(struct _AadSequenceSlot *slot, int track, int labelNumber); // 0x80057AA0

extern void metaCmdLoopStart(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057B58

extern void metaCmdLoopEnd(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057BC8

extern void metaCmdLoopBreak(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057C58

extern void metaCmdDefineLabel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057C60

extern void metaCmdGotoLabel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057C68

extern void metaCmdSetSequencePosition(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057C98

extern void metaCmdBranchIfVarEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057CC8

extern void metaCmdBranchIfVarNotEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057D14

extern void metaCmdBranchIfVarLess(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057D60

extern void metaCmdBranchIfVarGreater(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057DB0

extern void metaCmdBranchIfVarLessOrEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057E00

extern void metaCmdBranchIfVarGreaterOrEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057E50

extern void metaCmdBranchIfVarBitsSet(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057EA0

extern void metaCmdBranchIfVarBitsClear(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057EF0

extern void metaCmdSubstituteVariableParam1(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057F40

extern void metaCmdSubstituteVariableParam2(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057F60

extern void metaCmdSubstituteVariableParam3(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057F80

extern void metaCmdEndSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057FA0

extern void metaCmdPlaySoundEffect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057FFC

extern void metaCmdStopSoundEffect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80058004

extern void metaCmdSetSoundEffectVolumePan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005800C


#endif
