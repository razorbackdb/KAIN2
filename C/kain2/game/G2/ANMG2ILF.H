#ifndef ANMG2ILF_H
#define ANMG2ILF_H


extern short G2Anim_GetElapsedTime(struct _G2Anim_Type *anim); // 0x8008FB50

extern struct _G2AnimKeylist_Type * G2Anim_GetKeylist(struct _G2Anim_Type *anim); // 0x8008FB74

extern void G2Anim_GetRootMotionOverInterval(struct _G2Anim_Type *anim, short intervalStart, short intervalEnd, struct _G2SVector3_Type *motionVector); // 0x8008FB98

extern void G2Anim_InterpToKeylistFrame(struct _G2Anim_Type *anim, struct _G2AnimKeylist_Type *keylist, int keylistID, int targetFrame, int duration); // 0x8008FBC8

extern void G2Anim_SetAlphaTable(struct _G2Anim_Type *anim, struct _G2AnimAlphaTable_Type *table); // 0x8008FC6C

extern void G2Anim_SetCallback(struct _G2Anim_Type *anim, TDRFuncPtr_G2Anim_SetCallback1callback callback, void *data); // 0x8008FCDC

extern void G2Anim_SetLooping(struct _G2Anim_Type *anim); // 0x8008FD18

extern void G2Anim_SetNoLooping(struct _G2Anim_Type *anim); // 0x8008FD78

extern void G2Anim_SetPaused(struct _G2Anim_Type *anim); // 0x8008FDD8

extern void G2Anim_SetSpeedAdjustment(struct _G2Anim_Type *anim, long adjustment); // 0x8008FE38

extern void G2Anim_SetUnpaused(struct _G2Anim_Type *anim); // 0x8008FE6C

extern void G2Anim_SwitchToKeylist(struct _G2Anim_Type *anim, struct _G2AnimKeylist_Type *keylist, int keylistID); // 0x8008FECC

extern short G2AnimKeylist_GetDuration(struct _G2AnimKeylist_Type *keylist); // 0x8008FF4C

extern int G2AnimKeylist_GetKeyframeCount(struct _G2AnimKeylist_Type *keylist); // 0x8008FF74

extern void G2AnimSection_ClearAlarm(struct _G2AnimSection_Type *section, unsigned long flag); // 0x8008FFAC

extern int G2AnimSection_GetKeyframeNumber(struct _G2AnimSection_Type *section); // 0x8008FFC0

extern int G2AnimSection_GetStoredKeyframeNumber(struct _G2AnimSection_Type *section); // 0x8009001C

extern void G2AnimSection_InterpToKeylistFrame(struct _G2AnimSection_Type *section, struct _G2AnimKeylist_Type *keylist, int keylistID, int targetFrame, int duration); // 0x8009003C

extern enum _G2Bool_Enum G2AnimSection_IsInInterpolation(struct _G2AnimSection_Type *section); // 0x8009007C

extern short G2AnimSection_NextKeyframe(struct _G2AnimSection_Type *section); // 0x800900AC

extern void G2AnimSection_SetAlphaTable(struct _G2AnimSection_Type *section, struct _G2AnimAlphaTable_Type *table); // 0x80090108

extern void G2AnimSection_SetInterpInfo(struct _G2AnimSection_Type *section, struct _G2AnimInterpInfo_Type *newInfoPtr); // 0x80090124

extern void G2AnimSection_SetLooping(struct _G2AnimSection_Type *section); // 0x80090154

extern void G2AnimSection_SetLoopRangeAll(struct _G2AnimSection_Type *section); // 0x80090194

extern void G2AnimSection_SetNoLooping(struct _G2AnimSection_Type *section); // 0x800901C4

extern void G2AnimSection_SetNotRewinding(struct _G2AnimSection_Type *section); // 0x800901D8

extern void G2AnimSection_SetPaused(struct _G2AnimSection_Type *section); // 0x800901EC

extern void G2AnimSection_SetUnpaused(struct _G2AnimSection_Type *section); // 0x80090200

extern void G2AnimSection_SwitchToKeylist(struct _G2AnimSection_Type *section, struct _G2AnimKeylist_Type *keylist, int keylistID); // 0x80090214


typedef long (*TDRFuncPtr_G2Anim_SetCallback1callback)();




#endif
