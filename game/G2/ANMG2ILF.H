#ifndef ANMG2ILF_H
#define ANMG2ILF_H

extern void G2Anim_DisableSegment(struct _G2Anim_Type *anim, int segmentID);

extern void G2Anim_EnableSegment(struct _G2Anim_Type *anim, int segmentID);

extern short G2Anim_GetElapsedTime(struct _G2Anim_Type *anim);

extern struct _G2AnimKeylist_Type *G2Anim_GetKeylist(struct _G2Anim_Type *anim);

extern void G2Anim_GetRootMotionOverInterval(struct _G2Anim_Type *anim, short intervalStart, short intervalEnd, struct _G2SVector3_Type *motionVector);

extern void G2Anim_InterpToKeylistFrame(struct _G2Anim_Type *anim, struct _G2AnimKeylist_Type *keylist, int keylistID, int targetFrame, int duration);

extern enum _G2Bool_Enum G2Anim_IsSegmentEnabled(struct _G2Anim_Type *anim, int segmentID);

extern void G2Anim_SetAlphaTable(struct _G2Anim_Type *anim, struct _G2AnimAlphaTable_Type *table);

extern void G2Anim_SetCallback(struct _G2Anim_Type *anim, TDRFuncPtr_G2Anim_SetCallback1callback callback, void *data);

extern void G2Anim_SetLooping(struct _G2Anim_Type *anim);

extern void G2Anim_SetNoLooping(struct _G2Anim_Type *anim);

extern void G2Anim_SetPaused(struct _G2Anim_Type *anim);

extern void G2Anim_SetSpeedAdjustment(struct _G2Anim_Type *anim, long adjustment);

extern void G2Anim_SetUnpaused(struct _G2Anim_Type *anim);

extern void G2Anim_SwitchToKeylist(struct _G2Anim_Type *anim, struct _G2AnimKeylist_Type *keylist, int keylistID);

extern short G2AnimKeylist_GetDuration(struct _G2AnimKeylist_Type *keylist);

extern int G2AnimKeylist_GetKeyframeCount(struct _G2AnimKeylist_Type *keylist);

extern void G2AnimSection_ClearAlarm(struct _G2AnimSection_Type *section, unsigned long flag);

extern int G2AnimSection_GetKeyframeNumber(struct _G2AnimSection_Type *section);

extern int G2AnimSection_GetStoredKeyframeNumber(struct _G2AnimSection_Type *section);

extern void G2AnimSection_InterpToKeylistFrame(struct _G2AnimSection_Type *section, struct _G2AnimKeylist_Type *keylist, int keylistID, int targetFrame, int duration);

extern enum _G2Bool_Enum G2AnimSection_IsInInterpolation(struct _G2AnimSection_Type *section);

extern short G2AnimSection_NextKeyframe(struct _G2AnimSection_Type *section);

extern void G2AnimSection_SetAlphaTable(struct _G2AnimSection_Type *section, struct _G2AnimAlphaTable_Type *table);

extern void G2AnimSection_SetInterpInfo(struct _G2AnimSection_Type *section, struct _G2AnimInterpInfo_Type *newInfoPtr);

extern void G2AnimSection_SetLooping(struct _G2AnimSection_Type *section);

extern void G2AnimSection_SetLoopRangeAll(struct _G2AnimSection_Type *section);

extern void G2AnimSection_SetNoLooping(struct _G2AnimSection_Type *section);

extern void G2AnimSection_SetNotRewinding(struct _G2AnimSection_Type *section);

extern void G2AnimSection_SetPaused(struct _G2AnimSection_Type *section);

extern void G2AnimSection_SetUnpaused(struct _G2AnimSection_Type *section);

extern void G2AnimSection_SwitchToKeylist(struct _G2AnimSection_Type *section, struct _G2AnimKeylist_Type *keylist, int keylistID);

typedef long (*TDRFuncPtr_G2Anim_SetCallback1callback)();

#endif
