#ifndef AADSEQEV_H
#define AADSEQEV_H


extern int aadQueueNextEvent(struct _AadSequenceSlot *slot, int track); // 0x80055F34

extern void aadExecuteEvent(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005612C

extern void midiNoteOff(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800561D0

extern void midiNoteOn(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800561D8

extern void aadUpdateChannelVolPan(struct _AadSequenceSlot *slot, int channel); // 0x80056590

extern void aadUpdateSlotVolPan(struct _AadSequenceSlot *slot); // 0x800568F0

extern void aadUpdateChannelPitchBend(struct _AadSequenceSlot *slot, int channel); // 0x80056C2C

extern void midiPolyphonicAftertouch(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056E04

extern void midiControlChange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056E0C

extern void midiProgramChange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056E4C

extern void midiChannelAftertouch(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056E64

extern void midiPitchWheelControl(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056E6C

extern void midiMetaEvent(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056EB4

extern void midiControlBankSelect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056EBC

extern void midiControlVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056F1C

extern void midiControlPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056F6C

extern void midiControlCallback(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056FBC

extern void midiControlDummy(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80057000


#endif
