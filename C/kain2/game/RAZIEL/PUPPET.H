#ifndef PUPPET_H
#define PUPPET_H


extern void StateHandlerPuppetShow(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009A90C

extern void StateHandlerMoveToPosition(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009ACA8

extern void DefaultPuppetStateHandler(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009AF50

extern void StateHandlerWarpGate(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009B204

extern void StateHandlerForcedGlide(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009B68C


#endif
