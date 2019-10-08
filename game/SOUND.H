#ifndef SOUND_H
#define SOUND_H

extern struct SoundEffectChannel *SndOpenSfxChannel(unsigned char *channelNum);

extern void SndCloseSfxChannel(int channelNum);

extern struct SoundEffectChannel *SndGetSfxChannel(int channelNum);

extern void SOUND_ProcessInstanceSounds(unsigned char *sfxFileData, struct SoundInstance *soundInstTbl, struct _Position *position, int livesInOnePlace, int inSpectral, int hidden, long *triggerFlags);

extern void SOUND_EndInstanceSounds(unsigned char *sfxFileData, struct SoundInstance *soundInstTbl);

extern int isOkayToPlaySound(int flags, int spectralPlane, int hidden);

extern void setPeriodicSoundStateOff(struct SoundInstance *soundInst, struct ObjectPeriodicSound *sound);

extern void processPeriodicSound(struct _Position *position, int livesInOnePlane, int inSpectral, int hidden, struct SoundInstance *soundInst, struct ObjectPeriodicSound *sound);

extern void processEventSound(struct _Position *position, struct SoundInstance *soundInst, struct ObjectEventSound *sound);

extern void SOUND_StartInstanceSound(struct SoundInstance *soundInst);

extern void SOUND_StopInstanceSound(struct SoundInstance *soundInst);

extern int SOUND_IsInstanceSoundLoaded(unsigned char *sfxFileData, long soundNumber);

extern void SOUND_SetInstanceSoundPitch(struct SoundInstance *soundInst, long pitchChangeAmt, long time);

extern void SOUND_SetInstanceSoundVolume(struct SoundInstance *soundInst, long volumeChangeAmt, long time);

extern void processOneShotSound(struct _Position *position, int hidden, long *triggerFlags, struct SoundInstance *soundInst, struct ObjectOneShotSound *sound);

extern unsigned long SOUND_Play3dSound(struct _Position *position, int sfxToneID, int pitch, int maxVolume, int minVolDist);

extern unsigned long SOUND_Update3dSound(struct _Position *position, unsigned long handle, int pitch, int maxVolume, int minVolDist);

extern void SOUND_HandleGlobalValueSignal(int name, long data);

extern void SOUND_Init();

extern void SOUND_Free();

extern void SOUND_SetMusicVariable(int variable, int value);

extern void SOUND_SetMusicVolume(int newVolume);

extern void SOUND_SetSfxVolume(int newVolume);

extern void SOUND_SetVoiceVolume(int newVolume);

extern void SOUND_PauseAllSound();

extern void SOUND_ResumeAllSound();

extern void SOUND_StopAllSound();

extern void SOUND_ResetAllSound();

extern void SOUND_MusicOff();

extern void SOUND_MusicOn();

extern void SOUND_SfxOff();

extern void SOUND_SfxOn();

extern int SndIsPlaying(unsigned long handle);

extern int SndIsPlayingOrRequested(unsigned long handle);

extern int SndTypeIsPlayingOrRequested(unsigned int sfxToneID);

extern unsigned long SndPlay(unsigned int sample);

extern void SndEndLoop(unsigned long handle);

extern unsigned long SndPlayVolPan(unsigned int sample, unsigned short vol, unsigned short pan, short pitch);

extern unsigned long SndUpdateVolPanPitch(unsigned long handle, unsigned short vol, unsigned short pan, short pitch);

extern void transitionMusicEndCallback(long userData, int slot, int loopFlag);

extern void loadMainMusicReturn(int dynamicBankIndex, int errorStatus);

extern void mainMusicEndCallback(long userData, int slot, int loopFlag);

extern void loadTransitionMusicReturn(int dynamicBankIndex, int errorStatus);

extern void initialLoadMainMusicReturn(int dynamicBankIndex, int errorStatus);

extern void musicFadeoutDone();

extern void SOUND_UpdateSound();

extern void musicPlaneShiftFadeoutDone();

extern void SOUND_PlaneShift(int newPlane);

extern void SOUND_FreeDynamicMusic();

extern void SOUND_SetMusicModifier(long modifier);

extern void SOUND_ResetMusicModifier(long modifier);

#endif
