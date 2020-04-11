#ifndef AADSFX_H
#define AADSFX_H


extern unsigned long aadPlaySfx(unsigned int toneID, int volume, int pan, int pitchOffset); // 0x80057114

extern unsigned long aadStopSfx(unsigned long handle); // 0x80057178

extern void aadStopAllSfx(); // 0x800571B4

extern int aadIsSfxPlaying(unsigned long handle); // 0x800571E4

extern int aadIsSfxPlayingOrRequested(unsigned long handle); // 0x80057254

extern int aadIsSfxTypePlaying(unsigned int toneID); // 0x8005730C

extern int aadIsSfxTypePlayingOrRequested(unsigned int sfxToneID); // 0x80057380

extern unsigned long aadSetSfxVolPanPitch(unsigned long handle, int volume, int pan, int pitch); // 0x80057438

extern unsigned long createSfxHandle(unsigned int toneID); // 0x8005747C

extern void aadPutSfxCommand(int statusByte, int dataByte0, int dataByte1, unsigned long ulongParam, int shortParam); // 0x800574C4

extern void aadExecuteSfxCommand(struct AadSfxCommand *sfxCmd); // 0x800575B8

extern void sfxCmdPlayTone(struct AadSfxCommand *sfxCmd); // 0x80057608

extern void sfxCmdStopTone(struct AadSfxCommand *sfxCmd); // 0x80057778

extern void sfxCmdStopAllTones(struct AadSfxCommand *sfxCmd); // 0x80057830

extern void sfxCmdSetToneVolumeAndPan(struct AadSfxCommand *sfxCmd); // 0x800578D4

extern void sfxCmdSetToneVolPanPitch(struct AadSfxCommand *sfxCmd); // 0x80057C28

extern void sfxCmdLockVoice(struct AadSfxCommand *sfxCmd); // 0x80058084

extern void sfxCmdSetVoiceAttr(struct AadSfxCommand *sfxCmd); // 0x800580D0

extern void sfxCmdSetVoiceKeyOn(struct AadSfxCommand *sfxCmd); // 0x8005815C

extern void sfxCmdSetVoiceKeyOff(struct AadSfxCommand *sfxCmd); // 0x80058178


#endif
