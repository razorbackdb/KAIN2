#ifndef SOUND_H
#define SOUND_H


extern struct SoundEffectChannel * SndOpenSfxChannel(unsigned char *channelNum); // 0x8003EC58

extern void SndCloseSfxChannel(int channelNum); // 0x8003ECA0

extern struct SoundEffectChannel * SndGetSfxChannel(int channelNum); // 0x8003ECC8

extern void SOUND_ProcessInstanceSounds(unsigned char *sfxFileData, struct SoundInstance *soundInstTbl, struct _Position *position, int livesInOnePlace, int inSpectral, int hidden, int burning, long *triggerFlags); // 0x8003ECF0

extern void SOUND_EndInstanceSounds(unsigned char *sfxFileData, struct SoundInstance *soundInstTbl); // 0x8003EE78

extern int isOkayToPlaySound(int flags, int spectralPlane, int hidden, int burning); // 0x8003EFE4

extern void setPeriodicSoundStateOff(struct SoundInstance *soundInst, struct ObjectPeriodicSound *sound); // 0x8003F0F8

extern void processPeriodicSound(struct _Position *position, int livesInOnePlane, int inSpectral, int hidden, int burning, struct SoundInstance *soundInst, struct ObjectPeriodicSound *sound); // 0x8003F184

extern void processEventSound(struct _Position *position, struct SoundInstance *soundInst, struct ObjectEventSound *sound); // 0x8003F624

extern void SOUND_StartInstanceSound(struct SoundInstance *soundInst); // 0x8003F9C8

extern void SOUND_StopInstanceSound(struct SoundInstance *soundInst); // 0x8003F9E8

extern int SOUND_IsInstanceSoundLoaded(unsigned char *sfxFileData, long soundNumber); // 0x8003FA44

extern void SOUND_SetInstanceSoundPitch(struct SoundInstance *soundInst, long pitchChangeAmt, long time); // 0x8003FB40

extern void SOUND_SetInstanceSoundVolume(struct SoundInstance *soundInst, long volumeChangeAmt, long time); // 0x8003FC00

extern void processOneShotSound(struct _Position *position, int hidden, int burning, long *triggerFlags, struct SoundInstance *soundInst, struct ObjectOneShotSound *sound); // 0x8003FD04

extern unsigned long SOUND_Play3dSound(struct _Position *position, int sfxToneID, int pitch, int maxVolume, int minVolDist); // 0x8004004C

extern unsigned long SOUND_Update3dSound(struct _Position *position, unsigned long handle, int pitch, int maxVolume, int minVolDist); // 0x80040288

extern void SOUND_HandleGlobalValueSignal(int name, long data); // 0x800404BC

extern void SOUND_Init(); // 0x800404C4

extern void SOUND_Free(); // 0x80040578

extern void SOUND_SetMusicVariable(int variable, int value); // 0x8004059C

extern void SOUND_SetMusicVolume(int newVolume); // 0x800405BC

extern void SOUND_SetSfxVolume(int newVolume); // 0x800405F0

extern void SOUND_SetVoiceVolume(int newVolume); // 0x80040624

extern void SOUND_PauseAllSound(); // 0x80040644

extern void SOUND_ResumeAllSound(); // 0x80040674

extern void SOUND_StopAllSound(); // 0x800406A4

extern void SOUND_ResetAllSound(); // 0x800406E4

extern void SOUND_MusicOff(); // 0x80040714

extern void SOUND_MusicOn(); // 0x80040778

extern void SOUND_SfxOff(); // 0x800407B0

extern void SOUND_SfxOn(); // 0x800407D0

extern int SndIsPlaying(unsigned long handle); // 0x800407D8

extern int SndIsPlayingOrRequested(unsigned long handle); // 0x800407F8

extern int SndTypeIsPlayingOrRequested(unsigned int sfxToneID); // 0x80040818

extern unsigned long SndPlay(unsigned int sample); // 0x80040838

extern void SndEndLoop(unsigned long handle); // 0x80040870

extern unsigned long SndPlayVolPan(unsigned int sample, unsigned short vol, unsigned short pan, short pitch); // 0x80040890

extern unsigned long SndUpdateVolPanPitch(unsigned long handle, unsigned short vol, unsigned short pan, short pitch); // 0x800408CC

extern void musicLoadReturnFunc(int dynamicBankIndex, int errorStatus); // 0x80040914

extern void musicFadeoutReturnFunc(); // 0x80040928

extern void musicEndCallbackFunc(long userData, int slot, int loopFlag); // 0x8004093C

extern void SOUND_PutMusicCommand(int cmdType, int cmdData); // 0x8004099C

extern void SOUND_MusicInit(); // 0x800409E4

extern int SOUND_IsMusicLoading(); // 0x80040A10

extern void SOUND_ProcessMusicLoad(); // 0x80040A40

extern void SOUND_UpdateSound(); // 0x80040F3C

extern void SOUND_PlaneShift(int newPlane); // 0x80040FE8

extern void SOUND_ShutdownMusic(); // 0x80041024

extern void SOUND_SetMusicModifier(long modifier); // 0x800410D8

extern void SOUND_ResetMusicModifier(long modifier); // 0x80041198


#endif
