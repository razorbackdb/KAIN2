#ifndef VOICEXA_H
#define VOICEXA_H


extern void VOICEXA_Init(); // 0x800B0F84

extern void putCdCommand(struct XAVoiceTracker *vt, unsigned char cdCommand, int numParams, unsigned char *params); // 0x800B1054

extern void VOICEXA_CdSyncCallback(unsigned char status, unsigned char *result); // 0x800B10D8

extern void processCdCommands(struct XAVoiceTracker *vt); // 0x800B1148

extern void putVoiceCommand(struct XAVoiceTracker *vt, unsigned char voiceCmd, unsigned char nextVoiceStatus, int voiceCmdParam); // 0x800B11F0

extern void processVoiceCommands(struct XAVoiceTracker *vt); // 0x800B126C

extern void voiceCmdPlay(struct XAVoiceTracker *vt, short voiceIndex); // 0x800B1320

extern void voiceCmdStop(struct XAVoiceTracker *vt, short cmdParam); // 0x800B1490

extern void voiceCmdPause(struct XAVoiceTracker *vt, short cmdParam); // 0x800B14EC

extern void voiceCmdResume(struct XAVoiceTracker *vt, short cmdParam); // 0x800B1520

extern void voiceCmdNull(struct XAVoiceTracker *vt, short cmdParam); // 0x800B1554

extern void VOICEXA_Play(int voiceIndex, int queueRequests); // 0x800B155C

extern int VOICEXA_FinalStatus(struct XAVoiceTracker *vt); // 0x800B1624

extern void VOICEXA_Pause(); // 0x800B1668

extern void VOICEXA_Resume(); // 0x800B16D8

extern void VOICEXA_Tick(); // 0x800B174C

extern int VOICEXA_IsPlaying(); // 0x800B189C


#endif
