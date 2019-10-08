#ifndef AADSFX_H
#define AADSFX_H

extern unsigned long aadPlaySfx(unsigned int toneID, int volume, int pan, int pitchOffset);

extern unsigned long aadStopSfx(unsigned long handle);

extern void aadStopAllSfx();

extern int aadIsSfxPlaying(unsigned long handle);

extern int aadIsSfxPlayingOrRequested(unsigned long handle);

extern int aadIsSfxTypePlaying(unsigned int toneID);

extern int aadIsSfxTypePlayingOrRequested(unsigned int sfxToneID);

extern unsigned long aadSetSfxVolPanPitch(unsigned long handle, int volume, int pan, int pitch);

extern unsigned long createSfxHandle(unsigned int toneID);

extern void aadPutSfxCommand(int statusByte, int dataByte0, int dataByte1, unsigned long u_longParam, int shortParam);

extern void aadExecuteSfxCommand(struct AadSfxCommand *sfxCmd);

extern void sfxCmdPlayTone(struct AadSfxCommand *sfxCmd);

extern void sfxCmdStopTone(struct AadSfxCommand *sfxCmd);

extern void sfxCmdStopAllTones(struct AadSfxCommand *sfxCmd);

extern void sfxCmdSetToneVolumeAndPan(struct AadSfxCommand *sfxCmd);

extern void sfxCmdSetToneVolPanPitch(struct AadSfxCommand *sfxCmd);

extern void sfxCmdLockVoice(struct AadSfxCommand *sfxCmd);

extern void sfxCmdSetVoiceAttr(struct AadSfxCommand *sfxCmd);

extern void sfxCmdSetVoiceKeyOn(struct AadSfxCommand *sfxCmd);

extern void sfxCmdSetVoiceKeyOff(struct AadSfxCommand *sfxCmd);

#endif
