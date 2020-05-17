#ifndef AADSEQEV_H
#define AADSEQEV_H


extern int aadQueueNextEvent(struct _AadSequenceSlot *slot, int track); // 0x80054E18

extern void aadExecuteEvent(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x8005500C

extern void midiNoteOff(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800550A4

extern void midiNoteOn(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x800550AC

extern void aadUpdateChannelVolPan(struct _AadSequenceSlot *slot, int channel); // 0x80055420

extern void aadUpdateSlotVolPan(struct _AadSequenceSlot *slot); // 0x800557A4

extern void aadUpdateChannelPitchBend(struct _AadSequenceSlot *slot, int channel); // 0x80055B00

extern void midiPolyphonicAftertouch(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055CB0

extern void midiControlChange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055CB8

extern void midiProgramChange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055CF4

extern void midiChannelAftertouch(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055D0C

extern void midiPitchWheelControl(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055D14

extern void midiMetaEvent(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055D5C

extern void midiControlBankSelect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055D64

extern void midiControlVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055D6C

extern void midiControlPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055DBC

extern void midiControlCallback(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055E0C

extern void midiControlDummy(struct AadSeqEvent *event, struct _AadSequenceSlot *slot); // 0x80055E50


#endif
