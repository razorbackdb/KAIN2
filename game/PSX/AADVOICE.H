#ifndef AADVOICE_H
#define AADVOICE_H

extern struct AadSynthVoice *aadAllocateVoice(int priority);

extern void SpuSetVoiceADSR1ADSR2(int vNum, unsigned short adsr1, unsigned short adsr2);

extern void aadPlayTone(struct AadToneAtr *toneAtr, unsigned long waveStartAddr, struct AadProgramAtr *progAtr, int midiNote, int volume, int masterVolume, int masterPan, int slotVolume, int masterMasterVol, struct AadSynthVoice *voice, int pitchOffset);

extern void aadPlayTonePitchBend(struct AadToneAtr *toneAtr, unsigned long waveStartAddr, struct AadProgramAtr *progAtr, int midiNote, int volume, int masterVolume, int masterPan, int slotVolume, int masterMasterVol, struct AadSynthVoice *voice, int pitchWheelPos);

#endif
