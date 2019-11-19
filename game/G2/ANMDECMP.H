#ifndef ANMDECMP_H
#define ANMDECMP_H


extern void _G2Anim_DecompressChannel_AdaptiveDelta(struct _G2AnimDecompressChannelInfo_Type *dcInfo, struct _G2AnimChanStatus_Type *status); // 0x8008DF6C

extern void _G2Anim_DecompressChannel_Linear(struct _G2AnimDecompressChannelInfo_Type *dcInfo, struct _G2AnimChanStatus_Type *status); // 0x8008E098

extern void _G2Anim_InitializeChannel_AdaptiveDelta(struct _G2AnimDecompressChannelInfo_Type *dcInfo, struct _G2AnimChanStatus_Type *status); // 0x8008E12C

extern void _G2Anim_InitializeChannel_Linear(struct _G2AnimDecompressChannelInfo_Type *dcInfo, struct _G2AnimChanStatus_Type *status); // 0x8008E164


#endif
