#ifndef ANMDECMP_H
#define ANMDECMP_H


extern void _G2Anim_DecompressChannel_AdaptiveDelta(struct _G2AnimDecompressChannelInfo_Type *dcInfo, struct _G2AnimChanStatus_Type *status); // 0x80090234

extern void _G2Anim_DecompressChannel_Linear(struct _G2AnimDecompressChannelInfo_Type *dcInfo, struct _G2AnimChanStatus_Type *status); // 0x80090360

extern void _G2Anim_InitializeChannel_AdaptiveDelta(struct _G2AnimDecompressChannelInfo_Type *dcInfo, struct _G2AnimChanStatus_Type *status); // 0x800903F4

extern void _G2Anim_InitializeChannel_Linear(struct _G2AnimDecompressChannelInfo_Type *dcInfo, struct _G2AnimChanStatus_Type *status); // 0x8009042C


#endif
