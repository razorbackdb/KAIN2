#ifndef AADSFX_H
#define AADSFX_H


extern unsigned long aadPlaySfx(unsigned int toneID, int volume, int pan, int pitchOffset); // 0x80056EF8

extern unsigned long aadStopSfx(unsigned long handle); // 0x80056F5C

extern void aadStopAllSfx(); // 0x80056F98

extern int aadIsSfxPlaying(unsigned long handle); // 0x80056FC8

extern int aadIsSfxPlayingOrRequested(unsigned long handle); // 0x80057038

extern int aadIsSfxTypePlaying(unsigned int toneID); // 0x800570F0

extern int aadIsSfxTypePlayingOrRequested(unsigned int sfxToneID); // 0x80057164

extern unsigned long aadSetSfxVolPanPitch(unsigned long handle, int volume, int pan, int pitch); // 0x8005721C

extern unsigned long createSfxHandle(unsigned int toneID); // 0x80057260

extern void aadPutSfxCommand(int statusByte, int dataByte0, int dataByte1, unsigned long ulongParam, int shortParam); // 0x800572A8

extern void aadExecuteSfxCommand(struct AadSfxCommand *sfxCmd); // 0x8005739C

extern void sfxCmdPlayTone(struct AadSfxCommand *sfxCmd); // 0x800573E8

extern void sfxCmdStopTone(struct AadSfxCommand *sfxCmd); // 0x80057554

extern void sfxCmdStopAllTones(struct AadSfxCommand *sfxCmd); // 0x8005760C

extern void sfxCmdSetToneVolumeAndPan(struct AadSfxCommand *sfxCmd); // 0x800576B0

extern void sfxCmdSetToneVolPanPitch(struct AadSfxCommand *sfxCmd); // 0x80057A24

extern void sfxCmdLockVoice(struct AadSfxCommand *sfxCmd); // 0x80057E90

extern void sfxCmdSetVoiceAttr(struct AadSfxCommand *sfxCmd); // 0x80057EDC

extern void sfxCmdSetVoiceKeyOn(struct AadSfxCommand *sfxCmd); // 0x80057F68

extern void sfxCmdSetVoiceKeyOff(struct AadSfxCommand *sfxCmd); // 0x80057F84


#endif
