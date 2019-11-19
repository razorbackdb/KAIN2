#ifndef PUPPET_H
#define PUPPET_H


extern void StateHandlerPuppetShow(struct __CharacterState *In, int CurrentSection, int Data); // 0x800983C0

extern void StateHandlerMoveToPosition(struct __CharacterState *In, int CurrentSection, int Data); // 0x80098748

extern void DefaultPuppetStateHandler(struct __CharacterState *In, int CurrentSection, int Data); // 0x800989FC

extern void StateHandlerWarpGate(struct __CharacterState *In, int CurrentSection, int Data); // 0x80098C70

extern void StateHandlerForcedGlide(struct __CharacterState *In, int CurrentSection, int Data); // 0x80098E88


#endif
