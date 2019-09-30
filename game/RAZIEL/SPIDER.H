#ifndef SPIDER_H
#define SPIDER_H


extern void StateHandlerWallGrab(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A0184

extern void StateHandlerWallIdle(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A03CC

extern void StateHandlerWallDismount(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A0CA0


#endif
