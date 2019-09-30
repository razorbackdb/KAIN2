#ifndef AADSQCMD_H
#define AADSQCMD_H


extern void aadSubstituteVariables(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056074

extern void metaCmdSelectChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005612C

extern void metaCmdSelectSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005614C

extern void metaCmdAssignSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005619C

extern void metaCmdUsePrimaryTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056210

extern void metaCmdUseSecondaryTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056218

extern void metaCmdSetTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056220

extern void metaCmdChangeTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005628C

extern void metaCmdSetTempoFromSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800562FC

extern void metaCmdStartSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005637C

extern void metaCmdStopSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800563A0

extern void metaCmdPauseSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800563C4

extern void metaCmdResumeSlot(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800563E8

extern void metaCmdSetSlotBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005640C

extern void metaCmdSetChannelBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056414

extern void metaCmdSetSlotVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005641C

extern void metaCmdSetSlotPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056450

extern void metaCmdSetChannelVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056484

extern void metaCmdSetChannelPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800564C0

extern void metaCmdEnableSustainUpdate(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800564FC

extern void metaCmdDisableSustainUpdate(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005651C

extern void metaCmdMuteChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056540

extern void metaCmdUnMuteChannel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005656C

extern void metaCmdMuteChannelList(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056598

extern void metaCmdUnMuteChannelList(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800565C8

extern void metaCmdSetChannelMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800565F8

extern void metaCmdDelayMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005664C

extern void metaCmdUpdateMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056670

extern void metaCmdChannelVolumeFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056704

extern void metaCmdChannelPanFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005670C

extern void metaCmdSlotVolumeFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056714

extern void metaCmdSlotPanFade(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005671C

extern void metaCmdSetChannelProgram(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056724

extern void metaCmdSetChannelBasePriority(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005673C

extern void metaCmdSetChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056744

extern void metaCmdIgnoreChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005675C

extern void metaCmdRespectChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005677C

extern void metaCmdSetChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800567A0

extern void metaCmdIgnoreChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800567A8

extern void metaCmdRespectChannelPitchMap(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800567B0

extern void metaCmdGetSequenceAssigned(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800567B8

extern void metaCmdGetTempo(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800567E8

extern void metaCmdGetSlotStatus(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005684C

extern void metaCmdGetChannelMute(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005687C

extern void metaCmdGetChannelVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800568CC

extern void metaCmdGetChannelPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056904

extern void metaCmdGetChannelTranspose(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005693C

extern void metaCmdGetChannelProgram(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056944

extern void metaCmdGetChannelBasePriority(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005697C

extern void metaCmdGetChannelBendRange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056984

extern void metaCmdGetSlotVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005698C

extern void metaCmdGetSlotPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800569BC

extern void metaCmdSetVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800569EC

extern void metaCmdCopyVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056A18

extern void metaCmdAddVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056A54

extern void metaCmdSubtractVariable(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056A8C

extern void metaCmdSetVariableBits(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056AC4

extern void metaCmdClearVariableBits(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056AFC

extern void aadGotoSequencePosition(struct _AadSequenceSlot *slot, int track, unsigned char *newPosition); // 0x80056B34

extern void aadGotoSequenceLabel(struct _AadSequenceSlot *slot, int track, int labelNumber); // 0x80056BA0

extern void metaCmdLoopStart(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056C58

extern void metaCmdLoopEnd(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056CC8

extern void metaCmdLoopBreak(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056D58

extern void metaCmdDefineLabel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056D60

extern void metaCmdGotoLabel(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056D68

extern void metaCmdSetSequencePosition(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056D98

extern void metaCmdBranchIfVarEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056DC8

extern void metaCmdBranchIfVarNotEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056E14

extern void metaCmdBranchIfVarLess(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056E60

extern void metaCmdBranchIfVarGreater(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056EB0

extern void metaCmdBranchIfVarLessOrEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056F00

extern void metaCmdBranchIfVarGreaterOrEqual(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056F50

extern void metaCmdBranchIfVarBitsSet(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056FA0

extern void metaCmdBranchIfVarBitsClear(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056FF0

extern void metaCmdSubstituteVariableParam1(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057040

extern void metaCmdSubstituteVariableParam2(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057060

extern void metaCmdSubstituteVariableParam3(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057080

extern void metaCmdEndSequence(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800570A0

extern void metaCmdPlaySoundEffect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800570FC

extern void metaCmdStopSoundEffect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057104

extern void metaCmdSetSoundEffectVolumePan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005710C


#endif
