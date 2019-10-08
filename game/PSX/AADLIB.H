#ifndef AADLIB_H
#define AADLIB_H

extern unsigned long aadGetMemorySize(struct AadInitAttr *attributes);

extern int aadInit(struct AadInitAttr *attributes, unsigned char *memoryPtr);

extern void aadInstallUpdateFunc(TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr, int hblanksPerUpdate);

extern void aadInitVolume();

extern void aadSetMasterVolume(int volume);

extern void aadStartMasterVolumeFade(int targetVolume, int volumeStep, TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback);

extern void aadSetSfxMasterVolume(int volume);

extern void aadSetMusicMasterVolume(int volume);

extern void aadStartMusicMasterVolFade(int targetVolume, int volumeStep, TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback fadeCompleteCallback);

extern void aadShutdown();

extern long aadSlotUpdateWrapper();

extern void aadSlotUpdate();

extern unsigned long aadCreateFourCharID(char a, char b, char c, char d);

extern int aadLoadDynamicSoundBank(char *sndFileName, char *smpFileName, int dynamicBankIndex, int loadOption, TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc);

extern void aadLoadDynamicSoundBankReturn(void *loadedDataPtr, void *data, void *data2);

extern void aadLoadDynamicSoundBankReturn2(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2);

extern int aadFreeDynamicSoundBank(int dynamicBankIndex);

extern int aadOpenDynamicSoundBank(unsigned char *soundBank, int dynamicBankIndex);

extern int aadLoadDynamicSfx(char *fileName, long directoryID, long flags);

extern int aadFreeDynamicSfx(int handle);

extern void aadRelocateMusicMemoryBegin();

extern void aadRelocateMusicMemoryEnd(void *oldAddress, int offset);

extern void aadRelocateSfxMemory(void *oldAddress, int offset);

extern int aadGetNumLoadsQueued();

extern void aadPurgeLoadQueue();

extern void aadProcessLoadQueue();

extern void aadLoadDynamicSfxAbort(struct AadDynamicSfxLoadInfo *info, int error);

extern void aadLoadDynamicSfxDone(struct AadDynamicSfxLoadInfo *info);

extern void aadLoadDynamicSfxReturn(void *loadedDataPtr, void *data, void *data2);

extern int aadWaveMalloc(unsigned short waveID, unsigned long waveSize);

extern unsigned long aadGetSramBlockAddr(int handle);

extern void aadWaveFree(int handle);

extern void aadFreeSingleDynSfx(int sfxID);

extern void setSramFullAlarm();

extern void aadLoadSingleDynSfx(struct AadDynamicSfxLoadInfo *info);

extern void HackCallback();

extern void aadLoadDynamicSfxReturn2(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2);

extern int aadCheckSramFragmented();

extern void aadProcessSramDefrag();

extern int aadIsSfxLoaded(unsigned int toneID);

extern void aadInitSequenceSlot(struct _AadSequenceSlot *slot);

extern int aadWaitForSramTransferComplete();

extern void aadInitReverb();

extern void aadShutdownReverb();

extern int aadGetReverbMode();

extern unsigned long aadGetReverbSize();

extern int aadGetReverbDepth();

extern int aadGetDynamicBankStatus(int bank);

extern int aadGetNumDynamicSequences(int bank);

extern int aadAssignDynamicSequence(int bank, int sequenceNumber, int slotNumber);

extern struct AadTempo *aadGetTempoFromDynamicSequence(int bank, int sequenceNumber, struct AadTempo *tempo);

extern void aadSetSlotTempo(int slotNumber, struct AadTempo *tempo);

extern void aadStartSlot(int slotNumber);

extern void aadStopSlot(int slotNumber);

extern void aadStopAllSlots();

extern void aadDisableSlot(int slotNumber);

extern void aadEnableSlot(int slotNumber);

extern void aadPauseSlot(int slotNumber);

extern void aadResumeSlot(int slotNumber);

extern int aadGetSlotStatus(int slotNumber);

extern void aadAllNotesOff(int slotNumber);

extern void aadMuteChannels(struct _AadSequenceSlot *slot, unsigned long channelList);

extern void aadUnMuteChannels(struct _AadSequenceSlot *slot, unsigned long channelList);

extern TDRFuncPtr_aadInstallEndSequenceCallback aadInstallEndSequenceCallback(TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc, long data);

extern void aadSetUserVariable(int variableNumber, int value);

extern void aadSetNoUpdateMode(int noUpdate);

extern void aadPauseSound();

extern void aadCancelPauseSound();

extern void aadResumeSound();

typedef long (*TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)();

typedef void (*TDRFuncPtr_aadLoadDynamicSoundBank4retProc)();

typedef void (*TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)();

typedef void (*TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)();

#endif
