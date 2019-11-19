#ifndef SPIDER_H
#define SPIDER_H


extern void StateHandlerWallGrab(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009DBDC

extern void StateHandlerWallIdle(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009DE10

extern void StateHandlerWallDismount(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009E5A4


#endif
