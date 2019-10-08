#ifndef SPIDER_H
#define SPIDER_H

extern void StateHandlerWallGrab(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerWallIdle(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerWallDismount(struct __CharacterState *In, int CurrentSection, int Data);

#endif
