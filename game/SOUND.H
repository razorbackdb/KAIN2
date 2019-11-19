#ifndef SOUND_H
#define SOUND_H


extern struct SoundEffectChannel * SndOpenSfxChannel(unsigned char *channelNum); // 0x8003FBCC

extern void SndCloseSfxChannel(int channelNum); // 0x8003FC18

extern struct SoundEffectChannel * SndGetSfxChannel(int channelNum); // 0x8003FC44

extern void SOUND_ProcessInstanceSounds(unsigned char *sfxFileData, struct SoundInstance *soundInstTbl, struct _Position *position, int livesInOnePlace, int inSpectral, int hidden, long *triggerFlags); // 0x8003FC70

extern void SOUND_EndInstanceSounds(unsigned char *sfxFileData, struct SoundInstance *soundInstTbl); // 0x8003FDEC

extern int isOkayToPlaySound(int flags, int spectralPlane, int hidden); // 0x8003FEF0

extern void setPeriodicSoundStateOff(struct SoundInstance *soundInst, struct ObjectPeriodicSound *sound); // 0x8003FFE4

extern void processPeriodicSound(struct _Position *position, int livesInOnePlane, int inSpectral, int hidden, struct SoundInstance *soundInst, struct ObjectPeriodicSound *sound); // 0x80040070

extern void processEventSound(struct _Position *position, struct SoundInstance *soundInst, struct ObjectEventSound *sound); // 0x800404FC

extern void SOUND_StartInstanceSound(struct SoundInstance *soundInst); // 0x80040898

extern void SOUND_StopInstanceSound(struct SoundInstance *soundInst); // 0x800408B8

extern int SOUND_IsInstanceSoundLoaded(unsigned char *sfxFileData, long soundNumber); // 0x80040914

extern void SOUND_SetInstanceSoundPitch(struct SoundInstance *soundInst, long pitchChangeAmt, long time); // 0x80040A18

extern void SOUND_SetInstanceSoundVolume(struct SoundInstance *soundInst, long volumeChangeAmt, long time); // 0x80040AD8

extern void processOneShotSound(struct _Position *position, int hidden, long *triggerFlags, struct SoundInstance *soundInst, struct ObjectOneShotSound *sound); // 0x80040BDC

extern unsigned long SOUND_Play3dSound(struct _Position *position, int sfxToneID, int pitch, int maxVolume, int minVolDist); // 0x80040F24

extern unsigned long SOUND_Update3dSound(struct _Position *position, unsigned long handle, int pitch, int maxVolume, int minVolDist); // 0x8004114C

extern void SOUND_HandleGlobalValueSignal(int name, long data); // 0x80041374

extern void SOUND_Init(); // 0x8004137C

extern void SOUND_Free(); // 0x80041430

extern void SOUND_SetMusicVariable(int variable, int value); // 0x80041454

extern void SOUND_SetMusicVolume(int newVolume); // 0x80041474

extern void SOUND_SetSfxVolume(int newVolume); // 0x800414A8

extern void SOUND_SetVoiceVolume(int newVolume); // 0x800414DC

extern void SOUND_PauseAllSound(); // 0x800414FC

extern void SOUND_ResumeAllSound(); // 0x8004152C

extern void SOUND_StopAllSound(); // 0x8004155C

extern void SOUND_ResetAllSound(); // 0x8004159C

extern void SOUND_MusicOff(); // 0x800415CC

extern void SOUND_MusicOn(); // 0x80041640

extern void SOUND_SfxOff(); // 0x8004167C

extern void SOUND_SfxOn(); // 0x8004169C

extern int SndIsPlaying(unsigned long handle); // 0x800416A4

extern int SndIsPlayingOrRequested(unsigned long handle); // 0x800416C4

extern int SndTypeIsPlayingOrRequested(unsigned int sfxToneID); // 0x800416E4

extern unsigned long SndPlay(unsigned int sample); // 0x80041704

extern void SndEndLoop(unsigned long handle); // 0x8004173C

extern unsigned long SndPlayVolPan(unsigned int sample, unsigned short vol, unsigned short pan, short pitch); // 0x8004175C

extern unsigned long SndUpdateVolPanPitch(unsigned long handle, unsigned short vol, unsigned short pan, short pitch); // 0x80041798

extern void transitionMusicEndCallback(long userData, int slot, int loopFlag); // 0x800417E0

extern void loadMainMusicReturn(int dynamicBankIndex, int errorStatus); // 0x80041838

extern void mainMusicEndCallback(long userData, int slot, int loopFlag); // 0x8004187C

extern void loadTransitionMusicReturn(int dynamicBankIndex, int errorStatus); // 0x8004193C

extern void initialLoadMainMusicReturn(int dynamicBankIndex, int errorStatus); // 0x80041984

extern void SOUND_UpdateSound(); // 0x800419C0

extern void SOUND_LoadDynamicMusic(char *newMusicName); // 0x80041EEC

extern void SOUND_FreeDynamicMusic(); // 0x80041FB8

extern void SOUND_DumpAllSound(); // 0x80042010

extern void SOUND_SetMusicModifier(long modifier); // 0x80042038

extern void SOUND_ResetMusicModifier(long modifier); // 0x800420FC


#endif
