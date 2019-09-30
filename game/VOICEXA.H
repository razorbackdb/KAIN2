#ifndef VOICEXA_H
#define VOICEXA_H


extern void VOICEXA_Init(); // 0x800B5754

extern void putCdCommand(struct XAVoiceTracker *vt, unsigned char cdCommand, int numParams, unsigned char *params); // 0x800B5824

extern void VOICEXA_CdSyncCallback(unsigned char status, unsigned char *result); // 0x800B58A8

extern void processCdCommands(struct XAVoiceTracker *vt); // 0x800B5918

extern void putVoiceCommand(struct XAVoiceTracker *vt, unsigned char voiceCmd, unsigned char nextVoiceStatus, int voiceCmdParam); // 0x800B59C0

extern void processVoiceCommands(struct XAVoiceTracker *vt); // 0x800B5A3C

extern void voiceCmdPlay(struct XAVoiceTracker *vt, short voiceIndex); // 0x800B5AF0

extern void voiceCmdStop(struct XAVoiceTracker *vt, short cmdParam); // 0x800B5C60

extern void voiceCmdPause(struct XAVoiceTracker *vt, short cmdParam); // 0x800B5CBC

extern void voiceCmdResume(struct XAVoiceTracker *vt, short cmdParam); // 0x800B5CF8

extern void voiceCmdNull(struct XAVoiceTracker *vt, short cmdParam); // 0x800B5D2C

extern void VOICEXA_Play(int voiceIndex, int queueRequests); // 0x800B5D34

extern int VOICEXA_FinalStatus(struct XAVoiceTracker *vt); // 0x800B5DFC

extern void VOICEXA_Pause(); // 0x800B5E40

extern void VOICEXA_Resume(); // 0x800B5EB4

extern void VOICEXA_Tick(); // 0x800B5F28

extern int VOICEXA_IsPlaying(); // 0x800B6084


#endif
