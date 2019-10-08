#ifndef PUPPET_H
#define PUPPET_H

extern void StateHandlerPuppetShow(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerMoveToPosition(struct __CharacterState *In, int CurrentSection, int Data);

extern void DefaultPuppetStateHandler(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerWarpGate(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerForcedGlide(struct __CharacterState *In, int CurrentSection, int Data);

#endif
