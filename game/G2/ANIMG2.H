#ifndef ANIMG2_H
#define ANIMG2_H


extern enum _G2Bool_Enum G2Anim_Install(); // 0x80092380

extern void G2Anim_ResetInternalState(); // 0x800923F8

extern void G2Anim_Init(struct _G2Anim_Type *anim, struct _Model *modelData); // 0x80092460

extern struct _G2AnimSection_Type * G2Anim_AddSection(struct _G2Anim_Type *anim, int firstSegID, int segCount); // 0x800924F4

extern void G2Anim_Free(struct _G2Anim_Type *anim); // 0x80092590

extern void G2Anim_Restore(struct _G2Anim_Type *anim); // 0x8009264C

extern void G2Anim_BuildTransforms(struct _G2Anim_Type *anim); // 0x800926CC

extern void G2Anim_UpdateStoredFrame(struct _G2Anim_Type *anim); // 0x80092798

extern struct _G2AnimSection_Type * G2Anim_GetSectionWithSeg(struct _G2Anim_Type *anim, int segNumber); // 0x80092914

extern enum _G2Bool_Enum G2Anim_SegmentHasActiveChannels(struct _G2Anim_Type *anim, int segNumber, unsigned short chanMask); // 0x80092980

extern void G2Anim_GetSegChannelValue(struct _G2Anim_Type *anim, int segIndex, unsigned short *valueTable, unsigned short channelMask); // 0x80092AC0

extern void G2Anim_GetRootMotionFromTimeForDuration(struct _G2Anim_Type *anim, short durationStart, short duration, struct _G2SVector3_Type *motionVector); // 0x80092B70

extern void G2AnimSection_SwitchToKeylistAtTime(struct _G2AnimSection_Type *section, struct _G2AnimKeylist_Type *keylist, int keylistID, short targetTime); // 0x80092E4C

extern void G2AnimSection_JumpToTime(struct _G2AnimSection_Type *section, short targetTime); // 0x80093004

extern short G2AnimSection_UpdateOverInterval(struct _G2AnimSection_Type *section, short interval); // 0x800930A4

extern short G2AnimSection_AdvanceOverInterval(struct _G2AnimSection_Type *section, short interval); // 0x80093298

extern short G2AnimSection_RewindOverInterval(struct _G2AnimSection_Type *section, short interval); // 0x80093670

extern void _G2Anim_BuildTransformsNoControllers(struct _G2Anim_Type *anim); // 0x800938B0

extern void _G2Anim_BuildSegTransformNoControllers(struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix, enum _G2Bool_Enum bRootTransUpdated, int segIndex); // 0x80093A04

extern void _G2Anim_BuildSegLocalRotMatrix(struct _G2AnimSegValue_Type *segValue, struct _G2Matrix_Type *segMatrix); // 0x80093C30

extern void wombat(unsigned char *segKeyList, int flagBitOffset, struct _G2AnimSegKeyflagInfo_Type *kfInfo); // 0x80093C90

extern unsigned long kangaroo(struct _G2AnimSegKeyflagInfo_Type *kfInfo); // 0x80093CC8

extern void _G2Anim_InitializeSegValue(struct _G2Anim_Type *anim, struct _G2AnimSegValue_Type *segValue, int segIndex); // 0x80093D50

extern void _G2AnimSection_InitStatus(struct _G2AnimSection_Type *section, struct _G2Anim_Type *anim); // 0x80093DA4

extern void FooBar(struct _G2AnimSection_Type *section, struct _G2Anim_Type *anim, int decompressedKey, int targetKey, long timeOffset); // 0x80094058

extern void _G2AnimSection_UpdateStoredFrameFromData(struct _G2AnimSection_Type *section, struct _G2Anim_Type *anim); // 0x800944E4

extern struct _G2Anim_Type * _G2AnimSection_GetAnim(struct _G2AnimSection_Type *section); // 0x800945B4

extern void _G2AnimSection_TriggerEffects(struct _G2AnimSection_Type *section, short startTime, short endTime); // 0x800945D4

extern void _G2Anim_FreeChanStatusBlockList(struct _G2AnimChanStatusBlock_Type *block); // 0x80094700

extern long _G2AnimAlphaTable_GetValue(struct _G2AnimAlphaTable_Type *table, long trueAlpha); // 0x80094744


#endif
