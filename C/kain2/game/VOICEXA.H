#ifndef VOICEXA_H
#define VOICEXA_H


extern void VOICEXA_Init(); // 0x800B6AE0

extern void putCdCommand(struct XAVoiceTracker *vt, unsigned char cdCommand, int numParams, unsigned char *params); // 0x800B6BAC

extern void VOICEXA_CdSyncCallback(unsigned char status, unsigned char *result); // 0x800B6C30

extern void processCdCommands(struct XAVoiceTracker *vt); // 0x800B6C9C

extern void putVoiceCommand(struct XAVoiceTracker *vt, unsigned char voiceCmd, unsigned char nextVoiceStatus, int voiceCmdParam); // 0x800B6D44

extern void processVoiceCommands(struct XAVoiceTracker *vt); // 0x800B6DC0

extern void voiceCmdPlay(struct XAVoiceTracker *vt, short voiceIndex); // 0x800B6E70

extern void voiceCmdStop(struct XAVoiceTracker *vt, short cmdParam); // 0x800B6FE0

extern void voiceCmdPause(struct XAVoiceTracker *vt, short cmdParam); // 0x800B703C

extern void voiceCmdResume(struct XAVoiceTracker *vt, short cmdParam); // 0x800B7078

extern void voiceCmdNull(struct XAVoiceTracker *vt, short cmdParam); // 0x800B70AC

extern void VOICEXA_Play(int voiceIndex, int queueRequests); // 0x800B70B4

extern int VOICEXA_FinalStatus(struct XAVoiceTracker *vt); // 0x800B7178

extern void VOICEXA_Pause(); // 0x800B71BC

extern void VOICEXA_Resume(); // 0x800B722C

extern void VOICEXA_Tick(); // 0x800B729C

extern int VOICEXA_IsPlaying(); // 0x800B73F4


#endif
