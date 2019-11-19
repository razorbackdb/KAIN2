#ifndef ANMG2ILF_H
#define ANMG2ILF_H


extern void G2Anim_DisableSegment(struct _G2Anim_Type *anim, int segmentID); // 0x8008D80C

extern void G2Anim_EnableSegment(struct _G2Anim_Type *anim, int segmentID); // 0x8008D834

extern short G2Anim_GetElapsedTime(struct _G2Anim_Type *anim); // 0x8008D860

extern struct _G2AnimKeylist_Type * G2Anim_GetKeylist(struct _G2Anim_Type *anim); // 0x8008D884

extern void G2Anim_GetRootMotionOverInterval(struct _G2Anim_Type *anim, short intervalStart, short intervalEnd, struct _G2SVector3_Type *motionVector); // 0x8008D8A8

extern void G2Anim_InterpToKeylistFrame(struct _G2Anim_Type *anim, struct _G2AnimKeylist_Type *keylist, int keylistID, int targetFrame, int duration); // 0x8008D8D8

extern enum _G2Bool_Enum G2Anim_IsSegmentEnabled(struct _G2Anim_Type *anim, int segmentID); // 0x8008D97C

extern void G2Anim_SetAlphaTable(struct _G2Anim_Type *anim, struct _G2AnimAlphaTable_Type *table); // 0x8008D9A4

extern void G2Anim_SetCallback(struct _G2Anim_Type *anim, TDRFuncPtr_G2Anim_SetCallback1callback callback, void *data); // 0x8008DA14

extern void G2Anim_SetLooping(struct _G2Anim_Type *anim); // 0x8008DA50

extern void G2Anim_SetNoLooping(struct _G2Anim_Type *anim); // 0x8008DAB0

extern void G2Anim_SetPaused(struct _G2Anim_Type *anim); // 0x8008DB10

extern void G2Anim_SetSpeedAdjustment(struct _G2Anim_Type *anim, long adjustment); // 0x8008DB70

extern void G2Anim_SetUnpaused(struct _G2Anim_Type *anim); // 0x8008DBA4

extern void G2Anim_SwitchToKeylist(struct _G2Anim_Type *anim, struct _G2AnimKeylist_Type *keylist, int keylistID); // 0x8008DC04

extern short G2AnimKeylist_GetDuration(struct _G2AnimKeylist_Type *keylist); // 0x8008DC84

extern int G2AnimKeylist_GetKeyframeCount(struct _G2AnimKeylist_Type *keylist); // 0x8008DCAC

extern void G2AnimSection_ClearAlarm(struct _G2AnimSection_Type *section, unsigned long flag); // 0x8008DCE4

extern int G2AnimSection_GetKeyframeNumber(struct _G2AnimSection_Type *section); // 0x8008DCF8

extern int G2AnimSection_GetStoredKeyframeNumber(struct _G2AnimSection_Type *section); // 0x8008DD54

extern void G2AnimSection_InterpToKeylistFrame(struct _G2AnimSection_Type *section, struct _G2AnimKeylist_Type *keylist, int keylistID, int targetFrame, int duration); // 0x8008DD74

extern enum _G2Bool_Enum G2AnimSection_IsInInterpolation(struct _G2AnimSection_Type *section); // 0x8008DDB4

extern short G2AnimSection_NextKeyframe(struct _G2AnimSection_Type *section); // 0x8008DDE4

extern void G2AnimSection_SetAlphaTable(struct _G2AnimSection_Type *section, struct _G2AnimAlphaTable_Type *table); // 0x8008DE40

extern void G2AnimSection_SetInterpInfo(struct _G2AnimSection_Type *section, struct _G2AnimInterpInfo_Type *newInfoPtr); // 0x8008DE5C

extern void G2AnimSection_SetLooping(struct _G2AnimSection_Type *section); // 0x8008DE8C

extern void G2AnimSection_SetLoopRangeAll(struct _G2AnimSection_Type *section); // 0x8008DECC

extern void G2AnimSection_SetNoLooping(struct _G2AnimSection_Type *section); // 0x8008DEFC

extern void G2AnimSection_SetNotRewinding(struct _G2AnimSection_Type *section); // 0x8008DF10

extern void G2AnimSection_SetPaused(struct _G2AnimSection_Type *section); // 0x8008DF24

extern void G2AnimSection_SetUnpaused(struct _G2AnimSection_Type *section); // 0x8008DF38

extern void G2AnimSection_SwitchToKeylist(struct _G2AnimSection_Type *section, struct _G2AnimKeylist_Type *keylist, int keylistID); // 0x8008DF4C


typedef long (*TDRFuncPtr_G2Anim_SetCallback1callback)();




#endif
