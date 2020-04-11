#ifndef AADSEQEV_H
#define AADSEQEV_H


extern int aadQueueNextEvent(struct _AadSequenceSlot *slot, int track); // 0x80055064

extern void aadExecuteEvent(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005525C

extern void midiNoteOff(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800552FC

extern void midiNoteOn(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055304

extern void aadUpdateChannelVolPan(struct _AadSequenceSlot *slot, int channel); // 0x80055678

extern void aadUpdateSlotVolPan(struct _AadSequenceSlot *slot); // 0x800559D8

extern void aadUpdateChannelPitchBend(struct _AadSequenceSlot *slot, int channel); // 0x80055D0C

extern void midiPolyphonicAftertouch(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055EC8

extern void midiControlChange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055ED0

extern void midiProgramChange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055F10

extern void midiChannelAftertouch(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055F28

extern void midiPitchWheelControl(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055F30

extern void midiMetaEvent(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055F78

extern void midiControlBankSelect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055F80

extern void midiControlVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055F88

extern void midiControlPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055FD8

extern void midiControlCallback(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80056028

extern void midiControlDummy(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005606C


#endif
