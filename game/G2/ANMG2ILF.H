#ifndef ANMG2ILF_H
#define ANMG2ILF_H


extern void G2Anim_DisableSegment(struct _G2Anim_Type *anim, int segmentID); // 0x8008F308

extern void G2Anim_EnableSegment(struct _G2Anim_Type *anim, int segmentID); // 0x8008F330

extern short G2Anim_GetElapsedTime(struct _G2Anim_Type *anim); // 0x8008F35C

extern struct _G2AnimKeylist_Type * G2Anim_GetKeylist(struct _G2Anim_Type *anim); // 0x8008F380

extern void G2Anim_GetRootMotionOverInterval(struct _G2Anim_Type *anim, short intervalStart, short intervalEnd, struct _G2SVector3_Type *motionVector); // 0x8008F3A4

extern void G2Anim_InterpToKeylistFrame(struct _G2Anim_Type *anim, struct _G2AnimKeylist_Type *keylist, int keylistID, int targetFrame, int duration); // 0x8008F3D4

extern enum _G2Bool_Enum G2Anim_IsSegmentEnabled(struct _G2Anim_Type *anim, int segmentID); // 0x8008F478

extern void G2Anim_SetAlphaTable(struct _G2Anim_Type *anim, struct _G2AnimAlphaTable_Type *table); // 0x8008F4E0

extern void G2Anim_SetCallback(struct _G2Anim_Type *anim, TDRFuncPtr_G2Anim_SetCallback1callback callback, void *data); // 0x8008F550

extern void G2Anim_SetLooping(struct _G2Anim_Type *anim); // 0x8008F58C

extern void G2Anim_SetNoLooping(struct _G2Anim_Type *anim); // 0x8008F5EC

extern void G2Anim_SetPaused(struct _G2Anim_Type *anim); // 0x8008F64C

extern void G2Anim_SetSpeedAdjustment(struct _G2Anim_Type *anim, long adjustment); // 0x8008F6AC

extern void G2Anim_SetUnpaused(struct _G2Anim_Type *anim); // 0x8008F6E0

extern void G2Anim_SwitchToKeylist(struct _G2Anim_Type *anim, struct _G2AnimKeylist_Type *keylist, int keylistID); // 0x8008F740

extern short G2AnimKeylist_GetDuration(struct _G2AnimKeylist_Type *keylist); // 0x8008F7C0

extern int G2AnimKeylist_GetKeyframeCount(struct _G2AnimKeylist_Type *keylist); // 0x8008F7E8

extern void G2AnimSection_ClearAlarm(struct _G2AnimSection_Type *section, unsigned long flag); // 0x8008F820

extern int G2AnimSection_GetKeyframeNumber(struct _G2AnimSection_Type *section); // 0x8008F834

extern int G2AnimSection_GetStoredKeyframeNumber(struct _G2AnimSection_Type *section); // 0x8008F890

extern void G2AnimSection_InterpToKeylistFrame(struct _G2AnimSection_Type *section, struct _G2AnimKeylist_Type *keylist, int keylistID, int targetFrame, int duration); // 0x8008F8B0

extern enum _G2Bool_Enum G2AnimSection_IsInInterpolation(struct _G2AnimSection_Type *section); // 0x8008F8F0

extern short G2AnimSection_NextKeyframe(struct _G2AnimSection_Type *section); // 0x8008F920

extern void G2AnimSection_SetAlphaTable(struct _G2AnimSection_Type *section, struct _G2AnimAlphaTable_Type *table); // 0x8008F97C

extern void G2AnimSection_SetInterpInfo(struct _G2AnimSection_Type *section, struct _G2AnimInterpInfo_Type *newInfoPtr); // 0x8008F998

extern void G2AnimSection_SetLooping(struct _G2AnimSection_Type *section); // 0x8008F9C8

extern void G2AnimSection_SetLoopRangeAll(struct _G2AnimSection_Type *section); // 0x8008FA08

extern void G2AnimSection_SetNoLooping(struct _G2AnimSection_Type *section); // 0x8008FA38

extern void G2AnimSection_SetNotRewinding(struct _G2AnimSection_Type *section); // 0x8008FA4C

extern void G2AnimSection_SetPaused(struct _G2AnimSection_Type *section); // 0x8008FA60

extern void G2AnimSection_SetUnpaused(struct _G2AnimSection_Type *section); // 0x8008FA74

extern void G2AnimSection_SwitchToKeylist(struct _G2AnimSection_Type *section, struct _G2AnimKeylist_Type *keylist, int keylistID); // 0x8008FA88


typedef long (*TDRFuncPtr_G2Anim_SetCallback1callback)();




#endif
