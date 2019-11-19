#ifndef AADLIB_H
#define AADLIB_H


extern unsigned long aadGetMemorySize(struct AadInitAttr *attributes); // 0x80053164

extern unsigned short aadInit(struct AadInitAttr *attributes, unsigned char *memoryPtr); // 0x80053190

extern void aadInstallUpdateFunc(TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr, unsigned short hblanksPerUpdate); // 0x80053474

extern void aadInitVolume(); // 0x800534F0

extern void aadSetMasterVolume(int volume); // 0x80053524

extern void aadStartMasterVolumeFade(int targetVolume, int volumeStep, TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback); // 0x80053554

extern void aadSetSfxMasterVolume(int volume); // 0x8005356C

extern void aadSetMusicMasterVolume(int volume); // 0x80053578

extern void aadStartMusicMasterVolFade(int targetVolume, int volumeStep, TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback fadeCompleteCallback); // 0x800535E4

extern void aadShutdown(); // 0x800535FC

extern long aadSlotUpdateWrapper(); // 0x80053684

extern void aadSlotUpdate(); // 0x800536C8

extern unsigned long aadCreateFourCharID(char a, char b, char c, char d); // 0x80053BF4

extern unsigned short aadLoadDynamicSoundBank(char *sndFileName, char *smpFileName, int dynamicBankIndex, int loadOption, TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc); // 0x80053C1C

extern void aadLoadDynamicSoundBankReturn(void *loadedDataPtr, void *data, void *data2); // 0x80053D50

extern void aadLoadDynamicSoundBankReturn2(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2); // 0x80053E3C

extern void aadFreeLoadBuffer(); // 0x800540A0

extern unsigned short aadFreeDynamicSoundBank(int dynamicBankIndex); // 0x800540E8

extern unsigned short aadOpenDynamicSoundBank(unsigned char *soundBank, int dynamicBankIndex); // 0x8005417C

extern unsigned short aadLoadDynamicSfx(char *fileName, unsigned long userData, TDRFuncPtr_aadLoadDynamicSfx2userReturnProc userReturnProc); // 0x8005429C

extern unsigned short aadFreeDynamicSfx(unsigned short handle); // 0x8005438C

extern void aadFreeAllSfx(); // 0x80054424

extern int aadGetNumLoadsQueued(); // 0x80054500

extern void aadPurgeLoadQueue(); // 0x80054514

extern void aadProcessLoadQueue(); // 0x80054538

extern void aadLoadDynamicSfxAbort(struct AadDynamicSfxLoadInfo *info, unsigned short error); // 0x800547EC

extern void aadLoadDynamicSfxDone(struct AadDynamicSfxLoadInfo *info); // 0x80054898

extern void aadLoadDynamicSfxReturn(void *loadedDataPtr, void *data, void *data2); // 0x800548DC

extern unsigned char aadWaveMalloc(unsigned short waveID, unsigned long waveSize); // 0x80054A2C

extern unsigned long aadGetSramBlockAddr(unsigned char handle); // 0x80054C64

extern void aadWaveFree(unsigned char handle); // 0x80054C94

extern void aadFreeSingleDynSfx(unsigned short sfxID); // 0x80054D8C

extern void aadLoadSingleDynSfx(struct AadDynamicSfxLoadInfo *info); // 0x80054E50

extern void HackCallback(); // 0x800550D0

extern void aadLoadDynamicSfxReturn2(void *loadedDataPtr, long loadedDataSize, short status, void *data1, void *data2); // 0x80055108

extern int aadIsSfxLoaded(unsigned int toneID); // 0x800553D8

extern void aadInitSequenceSlot(struct _AadSequenceSlot *slot); // 0x800553F8

extern int aadWaitForSramTransferComplete(); // 0x800554FC

extern void aadInitReverb(); // 0x80055538

extern void aadShutdownReverb(); // 0x800555BC

extern int aadGetReverbMode(); // 0x800555F4

extern unsigned long aadGetReverbSize(); // 0x800555FC

extern int aadGetReverbDepth(); // 0x80055630

extern int aadGetDynamicBankStatus(int bank); // 0x80055638

extern int aadGetNumDynamicSequences(int bank); // 0x80055650

extern unsigned short aadAssignDynamicSequence(int bank, int sequenceNumber, int slotNumber); // 0x8005568C

extern struct AadTempo * aadGetTempoFromDynamicSequence(int bank, int sequenceNumber, struct AadTempo *tempo); // 0x80055764

extern void aadSetSlotTempo(int slotNumber, struct AadTempo *tempo); // 0x800557B8

extern void aadStartSlot(int slotNumber); // 0x80055870

extern void aadStopSlot(int slotNumber); // 0x800558EC

extern void aadStopAllSlots(); // 0x80055958

extern void aadDisableSlot(int slotNumber); // 0x800559E8

extern void aadEnableSlot(int slotNumber); // 0x80055A38

extern void aadPauseSlot(int slotNumber); // 0x80055A78

extern void aadResumeSlot(int slotNumber); // 0x80055AC8

extern int aadGetSlotStatus(int slotNumber); // 0x80055B38

extern void aadAllNotesOff(int slotNumber); // 0x80055B58

extern void aadGetVoiceStatus(char *voiceStatusArray); // 0x80055BF8

extern struct AadSynthVoice * aadGetVoicePointer(int voiceIndex); // 0x80055C68

extern void aadMuteChannels(int slotNumber, unsigned long channelList); // 0x80055C84

extern void aadUnMuteChannels(int slotNumber, unsigned long channelList); // 0x80055D4C

extern TDRFuncPtr_aadInstallEndSequenceCallback aadInstallEndSequenceCallback(TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc, long data); // 0x80055D74

extern void aadSetUserVariable(int variableNumber, int value); // 0x80055D8C

extern int aadGetUserVariable(int variableNumber); // 0x80055DA0

extern void aadSetNoUpdateMode(int noUpdate); // 0x80055DB8

extern void aadPauseSound(); // 0x80055DF8

extern void aadCancelPauseSound(); // 0x80055E90

extern void aadResumeSound(); // 0x80055EAC


typedef long (*TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)();

typedef void (*TDRFuncPtr_aadLoadDynamicSfx2userReturnProc)();

typedef void (*TDRFuncPtr_aadLoadDynamicSoundBank4retProc)();

typedef void (*TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)();

typedef void (*TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)();




#endif
