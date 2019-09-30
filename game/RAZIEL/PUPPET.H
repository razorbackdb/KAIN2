#ifndef PUPPET_H
#define PUPPET_H


extern void StateHandlerPuppetShow(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009A0D4

extern void StateHandlerMoveToPosition(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009A45C

extern void DefaultPuppetStateHandler(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009A710

extern void StateHandlerWarpGate(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009A92C

extern void StateHandlerForcedGlide(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009ADA4


#endif
