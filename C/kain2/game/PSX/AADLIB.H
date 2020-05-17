#ifndef AADLIB_H
#define AADLIB_H


extern unsigned long aadGetMemorySize(struct AadInitAttr *attributes); // 0x80051A90

extern int aadInit(struct AadInitAttr *attributes, unsigned char *memoryPtr); // 0x80051AB4

extern void aadInstallUpdateFunc(TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr, int hblanksPerUpdate); // 0x80051D5C

extern void aadInitVolume(); // 0x80051DD8

extern void aadSetMasterVolume(int volume); // 0x80051E0C

extern void aadStartMasterVolumeFade(int targetVolume, int volumeStep, TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback); // 0x80051E3C

extern void aadSetSfxMasterVolume(int volume); // 0x80051E54

extern void aadSetMusicMasterVolume(int volume); // 0x80051E64

extern void aadStartMusicMasterVolFade(int targetVolume, int volumeStep, TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback fadeCompleteCallback); // 0x80051EC8

extern void aadShutdown(); // 0x80051EE0

extern long aadSlotUpdateWrapper(); // 0x80051F68

extern void aadSlotUpdate(); // 0x80051FAC

extern unsigned long aadCreateFourCharID(char a, char b, char c, char d); // 0x800524E4

extern int aadLoadDynamicSoundBank(char *sndFileName, char *smpFileName, int dynamicBankIndex, int loadOption, TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc); // 0x8005250C

extern void aadLoadDynamicSoundBankReturn(void *loadedDataPtr, void *data, void *data2); // 0x80052664

extern void aadLoadDynamicSoundBankReturn2(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2); // 0x80052734

extern int aadFreeDynamicSoundBank(int dynamicBankIndex); // 0x80052960

extern int aadOpenDynamicSoundBank(unsigned char *soundBank, int dynamicBankIndex); // 0x800529DC

extern int aadLoadDynamicSfx(char *fileName, long directoryID, long flags); // 0x80052AFC

extern int aadFreeDynamicSfx(int handle); // 0x80052BB0

extern void aadRelocateMusicMemoryBegin(); // 0x80052C8C

extern void aadRelocateMusicMemoryEnd(void *oldAddress, int offset); // 0x80052CA8

extern void aadRelocateSfxMemory(void *oldAddress, int offset); // 0x80052E54

extern int aadGetNumLoadsQueued(); // 0x80052EBC

extern void aadPurgeLoadQueue(); // 0x80052ED0

extern void aadProcessLoadQueue(); // 0x80052EE8

extern void aadLoadDynamicSfxAbort(struct AadDynamicSfxLoadInfo *info, int error); // 0x80053228

extern void aadLoadDynamicSfxDone(struct AadDynamicSfxLoadInfo *info); // 0x800532AC

extern void aadLoadDynamicSfxReturn(void *loadedDataPtr, void *data, void *data2); // 0x800532B4

extern int aadWaveMalloc(unsigned short waveID, unsigned long waveSize); // 0x8005342C

extern unsigned long aadGetSramBlockAddr(int handle); // 0x80053674

extern void aadWaveFree(int handle); // 0x800536A0

extern void aadFreeSingleDynSfx(int sfxID); // 0x800537B0

extern void setSramFullAlarm(); // 0x80053878

extern void aadLoadSingleDynSfx(struct AadDynamicSfxLoadInfo *info); // 0x80053954

extern void HackCallback(); // 0x80053C24

extern void aadLoadDynamicSfxReturn2(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2); // 0x80053C5C

extern int aadCheckSramFragmented(); // 0x80053F24

extern void aadProcessSramDefrag(); // 0x80053FD8

extern int aadIsSfxLoaded(unsigned int toneID); // 0x8005433C

extern void aadInitSequenceSlot(struct _AadSequenceSlot *slot); // 0x80054378

extern int aadWaitForSramTransferComplete(); // 0x80054484

extern void aadInitReverb(); // 0x800544C4

extern void aadShutdownReverb(); // 0x80054548

extern int aadGetReverbMode(); // 0x80054580

extern unsigned long aadGetReverbSize(); // 0x80054588

extern int aadGetReverbDepth(); // 0x800545B8

extern int aadGetNumDynamicSequences(int bank); // 0x800545C0

extern int aadAssignDynamicSequence(int bank, int sequenceNumber, int slotNumber); // 0x800545F0

extern struct AadTempo * aadGetTempoFromDynamicSequence(int bank, int sequenceNumber, struct AadTempo *tempo); // 0x800546CC

extern void aadSetSlotTempo(int slotNumber, struct AadTempo *tempo); // 0x8005471C

extern void aadStartSlot(int slotNumber); // 0x800547D0

extern void aadStopSlot(int slotNumber); // 0x8005484C

extern void aadStopAllSlots(); // 0x800548B8

extern void aadDisableSlot(int slotNumber); // 0x80054948

extern void aadEnableSlot(int slotNumber); // 0x80054998

extern void aadPauseSlot(int slotNumber); // 0x800549D8

extern void aadResumeSlot(int slotNumber); // 0x80054A28

extern int aadGetSlotStatus(int slotNumber); // 0x80054A98

extern void aadAllNotesOff(int slotNumber); // 0x80054AB8

extern void aadMuteChannels(struct _AadSequenceSlot *slot, unsigned long channelList); // 0x80054B58

extern void aadUnMuteChannels(struct _AadSequenceSlot *slot, unsigned long channelList); // 0x80054C34

extern TDRFuncPtr_aadInstallEndSequenceCallback aadInstallEndSequenceCallback(TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc, long data); // 0x80054C6C

extern void aadSetUserVariable(int variableNumber, int value); // 0x80054C84

extern void aadSetNoUpdateMode(int noUpdate); // 0x80054C98

extern void aadPauseSound(); // 0x80054CD8

extern void aadCancelPauseSound(); // 0x80054D70

extern void aadResumeSound(); // 0x80054D8C


typedef long (*TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)();

typedef void (*TDRFuncPtr_aadLoadDynamicSoundBank4retProc)();

typedef void (*TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)();

typedef void (*TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)();




#endif
