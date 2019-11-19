#ifndef AADSFX_H
#define AADSFX_H


extern unsigned long aadPlaySfx(unsigned int toneID, int volume, int pan, int pitchOffset); // 0x80058014

extern unsigned long aadStopSfx(unsigned long handle); // 0x80058078

extern void aadStopAllSfx(); // 0x800580B4

extern int aadIsSfxPlaying(unsigned long handle); // 0x800580E4

extern int aadIsSfxPlayingOrRequested(unsigned long handle); // 0x80058154

extern int aadIsSfxTypePlaying(unsigned int toneID); // 0x8005820C

extern int aadIsSfxTypePlayingOrRequested(unsigned int sfxToneID); // 0x80058280

extern unsigned long aadSetSfxVolPanPitch(unsigned long handle, int volume, int pan, int pitch); // 0x80058338

extern unsigned long createSfxHandle(unsigned int toneID); // 0x8005837C

extern void aadPutSfxCommand(int statusByte, int dataByte0, int dataByte1, unsigned long ulongParam, int shortParam); // 0x800583C4

extern void aadExecuteSfxCommand(struct AadSfxCommand *sfxCmd); // 0x800584B8

extern void sfxCmdPlayTone(struct AadSfxCommand *sfxCmd); // 0x80058508

extern void sfxCmdStopTone(struct AadSfxCommand *sfxCmd); // 0x80058670

extern void sfxCmdStopAllTones(struct AadSfxCommand *sfxCmd); // 0x80058728

extern void sfxCmdSetToneVolumeAndPan(struct AadSfxCommand *sfxCmd); // 0x800587CC

extern void sfxCmdSetToneVolPanPitch(struct AadSfxCommand *sfxCmd); // 0x80058B20

extern void sfxCmdLockVoice(struct AadSfxCommand *sfxCmd); // 0x80058F7C

extern void sfxCmdSetVoiceAttr(struct AadSfxCommand *sfxCmd); // 0x80058FC8

extern void sfxCmdSetVoiceKeyOn(struct AadSfxCommand *sfxCmd); // 0x80059054

extern void sfxCmdSetVoiceKeyOff(struct AadSfxCommand *sfxCmd); // 0x80059070


#endif
