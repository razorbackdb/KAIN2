#ifndef ATTACK_H
#define ATTACK_H


extern int StateHandlerDecodeHold(int *Message, int *Data); // 0x80099268

extern void StateHandlerAttack2(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009943C

extern void StateHandlerCannedReaction(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009A170

extern void StateHandlerStumble(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009A404

extern void StateHandlerHitReaction(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009A738

extern void StateHandlerThrow2(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009A974

extern void PointAt(struct _Instance *instance, struct _Position *Target, struct _Rotation *Rot1); // 0x8009B4A8

extern void ThrowSetFocusPoint(struct _Instance *instance, struct _Rotation *rot); // 0x8009B5C8

extern void LimitRotation(struct _Rotation *rot); // 0x8009B70C

extern void StateHandlerGrab(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009B880


#endif
