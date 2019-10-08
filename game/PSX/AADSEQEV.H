#ifndef AADSEQEV_H
#define AADSEQEV_H

extern int aadQueueNextEvent(struct _AadSequenceSlot *slot, int track);

extern void aadExecuteEvent(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiNoteOff(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiNoteOn(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void aadUpdateChannelVolPan(struct _AadSequenceSlot *slot, int channel);

extern void aadUpdateSlotVolPan(struct _AadSequenceSlot *slot);

extern void aadUpdateChannelPitchBend(struct _AadSequenceSlot *slot, int channel);

extern void midiPolyphonicAftertouch(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiControlChange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiProgramChange(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiChannelAftertouch(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiPitchWheelControl(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiMetaEvent(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiControlBankSelect(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiControlVolume(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiControlPan(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiControlCallback(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

extern void midiControlDummy(struct AadSeqEvent *event, struct _AadSequenceSlot *slot);

#endif
