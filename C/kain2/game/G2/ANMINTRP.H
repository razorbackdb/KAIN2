#ifndef ANMINTRP_H
#define ANMINTRP_H


extern void G2AnimSection_InterpToKeylistAtTime(struct _G2AnimSection_Type *section, struct _G2AnimKeylist_Type *keylist, int keylistID, short targetTime, int duration); // 0x8009221C

extern void _G2AnimSection_UpdateStoredFrameFromQuat(struct _G2AnimSection_Type *section); // 0x80092500

extern void _G2AnimSection_InterpStateToQuat(struct _G2AnimSection_Type *section); // 0x800926F0

extern void _G2AnimSection_SegValueToQuat(struct _G2AnimSection_Type *section, int zeroOne); // 0x80092880

extern struct _G2AnimInterpStateBlock_Type * _G2Anim_AllocateInterpStateBlockList(struct _G2AnimSection_Type *section); // 0x80092A0C

extern void _G2Anim_FreeInterpStateBlockList(struct _G2AnimInterpStateBlock_Type *block); // 0x80092AA4


#endif
