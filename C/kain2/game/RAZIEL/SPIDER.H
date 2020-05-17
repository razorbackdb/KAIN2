#ifndef SPIDER_H
#define SPIDER_H


extern void StateHandlerWallGrab(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A0D88

extern void StateHandlerWallIdle(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A0FF8

extern void StateHandlerWallDismount(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A18E0


#endif
