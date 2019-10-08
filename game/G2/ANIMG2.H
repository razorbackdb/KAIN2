#ifndef ANIMG2_H
#define ANIMG2_H

extern enum _G2Bool_Enum G2Anim_Install();

extern void G2Anim_ResetInternalState();

extern void G2Anim_Init(struct _G2Anim_Type *anim, struct _Model *modelData);

extern struct _G2AnimSection_Type *G2Anim_AddSection(struct _G2Anim_Type *anim, int firstSegID, int segCount);

extern void G2Anim_Free(struct _G2Anim_Type *anim);

extern void G2Anim_Restore(struct _G2Anim_Type *anim);

extern void G2Anim_BuildTransforms(struct _G2Anim_Type *anim);

extern void G2Anim_UpdateStoredFrame(struct _G2Anim_Type *anim);

extern struct _G2AnimSection_Type *G2Anim_GetSectionWithSeg(struct _G2Anim_Type *anim, int segNumber);

extern enum _G2Bool_Enum G2Anim_SegmentHasActiveChannels(struct _G2Anim_Type *anim, int segNumber, unsigned short chanMask);

extern void G2Anim_GetSegChannelValue(struct _G2Anim_Type *anim, int segIndex, unsigned short *valueTable, unsigned short channelMask);

extern void G2Anim_GetRootMotionFromTimeForDuration(struct _G2Anim_Type *anim, short durationStart, short duration, struct _G2SVector3_Type *motionVector);

extern void G2AnimSection_SwitchToKeylistAtTime(struct _G2AnimSection_Type *section, struct _G2AnimKeylist_Type *keylist, int keylistID, short targetTime);

extern void G2AnimSection_JumpToTime(struct _G2AnimSection_Type *section, short targetTime);

extern short G2AnimSection_UpdateOverInterval(struct _G2AnimSection_Type *section, short interval);

extern short G2AnimSection_AdvanceOverInterval(struct _G2AnimSection_Type *section, short interval);

extern short G2AnimSection_RewindOverInterval(struct _G2AnimSection_Type *section, short interval);

extern void _G2Anim_BuildTransformsNoControllers(struct _G2Anim_Type *anim);

extern void _G2Anim_BuildSegTransformNoControllers(struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix, enum _G2Bool_Enum bRootTransUpdated, int segIndex);

extern void _G2Anim_BuildSegLocalRotMatrix(struct _G2AnimSegValue_Type *segValue, struct _G2Matrix_Type *segMatrix);

extern void wombat(unsigned char *segKeyList, int flagBitOffset, struct _G2AnimSegKeyflagInfo_Type *kfInfo);

extern unsigned long kangaroo(struct _G2AnimSegKeyflagInfo_Type *kfInfo);

extern void _G2Anim_InitializeSegValue(struct _G2Anim_Type *anim, struct _G2AnimSegValue_Type *segValue, int segIndex);

extern void _G2AnimSection_InitStatus(struct _G2AnimSection_Type *section, struct _G2Anim_Type *anim);

extern void FooBar(struct _G2AnimSection_Type *section, struct _G2Anim_Type *anim, int decompressedKey, int targetKey, long timeOffset);

extern void _G2AnimSection_UpdateStoredFrameFromData(struct _G2AnimSection_Type *section, struct _G2Anim_Type *anim);

extern struct _G2Anim_Type *_G2AnimSection_GetAnim(struct _G2AnimSection_Type *section);

extern void _G2AnimSection_TriggerEffects(struct _G2AnimSection_Type *section, short startTime, short endTime);

extern void _G2Anim_FreeChanStatusBlockList(struct _G2AnimChanStatusBlock_Type *block);

extern long _G2AnimAlphaTable_GetValue(struct _G2AnimAlphaTable_Type *table, long trueAlpha);

#endif
