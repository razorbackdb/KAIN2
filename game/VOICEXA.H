#ifndef VOICEXA_H
#define VOICEXA_H

extern void VOICEXA_Init();

extern void putCdCommand(struct XAVoiceTracker *vt, unsigned char cdCommand, int numParams, unsigned char *params);

extern void VOICEXA_CdSyncCallback(unsigned char status, unsigned char *result);

extern void processCdCommands(struct XAVoiceTracker *vt);

extern void putVoiceCommand(struct XAVoiceTracker *vt, unsigned char voiceCmd, unsigned char nextVoiceStatus, int voiceCmdParam);

extern void processVoiceCommands(struct XAVoiceTracker *vt);

extern void voiceCmdPlay(struct XAVoiceTracker *vt, short voiceIndex);

extern void voiceCmdStop(struct XAVoiceTracker *vt, short cmdParam);

extern void voiceCmdPause(struct XAVoiceTracker *vt, short cmdParam);

extern void voiceCmdResume(struct XAVoiceTracker *vt, short cmdParam);

extern void voiceCmdNull(struct XAVoiceTracker *vt, short cmdParam);

extern void VOICEXA_Play(int voiceIndex, int queueRequests);

extern int VOICEXA_FinalStatus(struct XAVoiceTracker *vt);

extern void VOICEXA_Pause();

extern void VOICEXA_Resume();

extern void VOICEXA_Tick();

extern int VOICEXA_IsPlaying();

#endif
