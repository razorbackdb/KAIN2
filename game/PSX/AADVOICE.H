#ifndef AADVOICE_H
#define AADVOICE_H


extern struct AadSynthVoice * aadAllocateVoice(int priority); // 0x800581A8

extern void SpuSetVoiceADSR1ADSR2(int vNum, unsigned short adsr1, unsigned short adsr2); // 0x8005829C

extern void aadPlayTone(struct AadToneAtr *toneAtr, unsigned long waveStartAddr, struct AadProgramAtr *progAtr, int midiNote, int volume, int masterVolume, int masterPan, int slotVolume, int masterMasterVol, struct AadSynthVoice *voice, int pitchOffset); // 0x80058344

extern void aadPlayTonePitchBend(struct AadToneAtr *toneAtr, unsigned long waveStartAddr, struct AadProgramAtr *progAtr, int midiNote, int volume, int masterVolume, int masterPan, int slotVolume, int masterMasterVol, struct AadSynthVoice *voice, int pitchWheelPos); // 0x80058764


#endif
