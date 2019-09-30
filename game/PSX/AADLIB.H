#ifndef AADLIB_H
#define AADLIB_H

typedef unsigned char TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr;

typedef unsigned char TDRFuncPtr_aadInstallEndSequenceCallback;

typedef unsigned char TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc;

typedef unsigned char TDRFuncPtr_aadLoadDynamicSoundBank4retProc;

typedef unsigned char TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback;

typedef unsigned char TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback;

/* typedef long (*TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)();

typedef void (*TDRFuncPtr_aadLoadDynamicSoundBank4retProc)();

typedef void (*TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)();

typedef void (*TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)(); */


extern unsigned long aadGetMemorySize(struct AadInitAttr *attributes); // 0x80051D1C

extern int aadInit(struct AadInitAttr *attributes, unsigned char *memoryPtr); // 0x80051D40

extern void aadInstallUpdateFunc(TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr, int hblanksPerUpdate); // 0x80051FEC

extern void aadInitVolume(); // 0x80052068

extern void aadSetMasterVolume(int volume); // 0x8005209C

extern void aadStartMasterVolumeFade(int targetVolume, int volumeStep, TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback); // 0x800520CC

extern void aadSetSfxMasterVolume(int volume); // 0x800520E4

extern void aadSetMusicMasterVolume(int volume); // 0x800520F4

extern void aadStartMusicMasterVolFade(int targetVolume, int volumeStep, TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback fadeCompleteCallback); // 0x80052158

extern void aadShutdown(); // 0x80052170

extern long aadSlotUpdateWrapper(); // 0x800521F8

extern void aadSlotUpdate(); // 0x8005223C

extern unsigned long aadCreateFourCharID(char a, char b, char c, char d); // 0x80052768

extern int aadLoadDynamicSoundBank(char *sndFileName, char *smpFileName, int dynamicBankIndex, int loadOption, TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc); // 0x80052790

extern void aadLoadDynamicSoundBankReturn(void *loadedDataPtr, void *data, void *data2); // 0x800528E8

extern void aadLoadDynamicSoundBankReturn2(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2); // 0x800529B8

extern int aadFreeDynamicSoundBank(int dynamicBankIndex); // 0x80052BE4

extern int aadOpenDynamicSoundBank(unsigned char *soundBank, int dynamicBankIndex); // 0x80052C60

extern int aadLoadDynamicSfx(char *fileName, long directoryID, long flags); // 0x80052D80

extern int aadFreeDynamicSfx(int handle); // 0x80052E34

extern void aadRelocateMusicMemoryBegin(); // 0x80052EA4

extern void aadRelocateMusicMemoryEnd(void *oldAddress, int offset); // 0x80052EC0

extern void aadRelocateSfxMemory(void *oldAddress, int offset); // 0x8005306C

extern int aadGetNumLoadsQueued(); // 0x800530D4

extern void aadPurgeLoadQueue(); // 0x800530E8

extern void aadProcessLoadQueue(); // 0x80053100

extern void aadLoadDynamicSfxAbort(struct AadDynamicSfxLoadInfo *info, int error); // 0x8005346C

extern void aadLoadDynamicSfxDone(struct AadDynamicSfxLoadInfo *info); // 0x800534F0

extern void aadLoadDynamicSfxReturn(void *loadedDataPtr, void *data, void *data2); // 0x800534F8

extern int aadWaveMalloc(unsigned short waveID, unsigned long waveSize); // 0x80053670

extern unsigned long aadGetSramBlockAddr(int handle); // 0x800538B0

extern void aadWaveFree(int handle); // 0x800538DC

extern void aadFreeSingleDynSfx(int sfxID); // 0x800539EC

extern void setSramFullAlarm(); // 0x80053AB4

extern void aadLoadSingleDynSfx(struct AadDynamicSfxLoadInfo *info); // 0x80053B90

extern void HackCallback(); // 0x80053E60

extern void aadLoadDynamicSfxReturn2(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2); // 0x80053E98

extern int aadCheckSramFragmented(); // 0x80054160

extern void aadProcessSramDefrag(); // 0x80054214

extern int aadIsSfxLoaded(unsigned int toneID); // 0x80054568

extern void aadInitSequenceSlot(struct _AadSequenceSlot *slot); // 0x800545A4

extern int aadWaitForSramTransferComplete(); // 0x800546B0

extern void aadInitReverb(); // 0x800546F0

extern void aadShutdownReverb(); // 0x80054774

extern int aadGetReverbMode(); // 0x800547AC

extern unsigned long aadGetReverbSize(); // 0x800547B4

extern int aadGetReverbDepth(); // 0x800547E8

extern int aadGetDynamicBankStatus(int bank); // 0x800547F0

extern int aadGetNumDynamicSequences(int bank); // 0x80054808

extern int aadAssignDynamicSequence(int bank, int sequenceNumber, int slotNumber); // 0x80054838

extern struct AadTempo * aadGetTempoFromDynamicSequence(int bank, int sequenceNumber, struct AadTempo *tempo); // 0x80054914

extern void aadSetSlotTempo(int slotNumber, struct AadTempo *tempo); // 0x80054964

extern void aadStartSlot(int slotNumber); // 0x80054A1C

extern void aadStopSlot(int slotNumber); // 0x80054A98

extern void aadStopAllSlots(); // 0x80054B04

extern void aadDisableSlot(int slotNumber); // 0x80054B94

extern void aadEnableSlot(int slotNumber); // 0x80054BE4

extern void aadPauseSlot(int slotNumber); // 0x80054C24

extern void aadResumeSlot(int slotNumber); // 0x80054C74

extern int aadGetSlotStatus(int slotNumber); // 0x80054CE4

extern void aadAllNotesOff(int slotNumber); // 0x80054D04

extern void aadMuteChannels(struct _AadSequenceSlot *slot, unsigned long channelList); // 0x80054DA4

extern void aadUnMuteChannels(struct _AadSequenceSlot *slot, unsigned long channelList); // 0x80054E80

extern TDRFuncPtr_aadInstallEndSequenceCallback aadInstallEndSequenceCallback(TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc, long data); // 0x80054EB8

extern void aadSetUserVariable(int variableNumber, int value); // 0x80054ED0

extern void aadSetNoUpdateMode(int noUpdate); // 0x80054EE4

extern void aadPauseSound(); // 0x80054F24

extern void aadCancelPauseSound(); // 0x80054FBC

extern void aadResumeSound(); // 0x80054FD8




#endif
