#ifndef AADSQCMD_H
#define AADSQCMD_H


extern void aadSubstituteVariables(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055E58

extern void metaCmdSelectChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055F10

extern void metaCmdSelectSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055F30

extern void metaCmdAssignSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055F80

extern void metaCmdUsePrimaryTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055FF4

extern void metaCmdUseSecondaryTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055FFC

extern void metaCmdSetTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056004

extern void metaCmdChangeTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056070

extern void metaCmdSetTempoFromSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800560E0

extern void metaCmdStartSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056160

extern void metaCmdStopSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056184

extern void metaCmdPauseSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800561A8

extern void metaCmdResumeSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800561CC

extern void metaCmdSetSlotBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800561F0

extern void metaCmdSetChannelBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800561F8

extern void metaCmdSetSlotVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056200

extern void metaCmdSetSlotPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056234

extern void metaCmdSetChannelVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056268

extern void metaCmdSetChannelPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800562A4

extern void metaCmdEnableSustainUpdate(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800562E0

extern void metaCmdDisableSustainUpdate(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056300

extern void metaCmdMuteChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056324

extern void metaCmdUnMuteChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056350

extern void metaCmdMuteChannelList(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005637C

extern void metaCmdUnMuteChannelList(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800563AC

extern void metaCmdSetChannelMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800563DC

extern void metaCmdDelayMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056430

extern void metaCmdUpdateMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056454

extern void metaCmdChannelVolumeFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800564E8

extern void metaCmdChannelPanFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800564F0

extern void metaCmdSlotVolumeFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800564F8

extern void metaCmdSlotPanFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056500

extern void metaCmdSetChannelProgram(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056508

extern void metaCmdSetChannelBasePriority(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056520

extern void metaCmdSetChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056528

extern void metaCmdIgnoreChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056540

extern void metaCmdRespectChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056560

extern void metaCmdSetChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056584

extern void metaCmdIgnoreChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005658C

extern void metaCmdRespectChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056594

extern void metaCmdGetSequenceAssigned(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005659C

extern void metaCmdGetTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800565CC

extern void metaCmdGetSlotStatus(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056630

extern void metaCmdGetChannelMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056660

extern void metaCmdGetChannelVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800566B0

extern void metaCmdGetChannelPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800566E8

extern void metaCmdGetChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056720

extern void metaCmdGetChannelProgram(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056728

extern void metaCmdGetChannelBasePriority(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056760

extern void metaCmdGetChannelBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056768

extern void metaCmdGetSlotVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056770

extern void metaCmdGetSlotPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800567A0

extern void metaCmdSetVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800567D0

extern void metaCmdCopyVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800567FC

extern void metaCmdAddVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056838

extern void metaCmdSubtractVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056870

extern void metaCmdSetVariableBits(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800568A8

extern void metaCmdClearVariableBits(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800568E0

extern void aadGotoSequencePosition(struct _AadSequenceSlot *slot, int track, unsigned char *newPosition); // 0x80056918

extern void aadGotoSequenceLabel(struct _AadSequenceSlot *slot, int track, int labelNumber); // 0x80056984

extern void metaCmdLoopStart(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056A3C

extern void metaCmdLoopEnd(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056AAC

extern void metaCmdLoopBreak(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056B3C

extern void metaCmdDefineLabel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056B44

extern void metaCmdGotoLabel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056B4C

extern void metaCmdSetSequencePosition(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056B7C

extern void metaCmdBranchIfVarEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056BAC

extern void metaCmdBranchIfVarNotEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056BF8

extern void metaCmdBranchIfVarLess(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056C44

extern void metaCmdBranchIfVarGreater(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056C94

extern void metaCmdBranchIfVarLessOrEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056CE4

extern void metaCmdBranchIfVarGreaterOrEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056D34

extern void metaCmdBranchIfVarBitsSet(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056D84

extern void metaCmdBranchIfVarBitsClear(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056DD4

extern void metaCmdSubstituteVariableParam1(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056E24

extern void metaCmdSubstituteVariableParam2(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056E44

extern void metaCmdSubstituteVariableParam3(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056E64

extern void metaCmdEndSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056E84

extern void metaCmdPlaySoundEffect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056EE0

extern void metaCmdStopSoundEffect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056EE8

extern void metaCmdSetSoundEffectVolumePan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056EF0


#endif
