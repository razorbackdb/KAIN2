#ifndef ATTACK_H
#define ATTACK_H


extern int StateHandlerDecodeHold(int *Message, int *Data); // 0x8009BA7C

extern void StateHandlerAttack2(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009BDE4

extern void StateHandlerCannedReaction(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009CEB4

extern void StateHandlerStumble(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009D144

extern void StateHandlerHitReaction(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009D568

extern void StateHandlerThrow2(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009D7E4

extern void PointAt(struct _Instance *instance, struct _Position *Target, struct _Rotation *Rot1); // 0x8009E2F0

extern void ThrowSetFocusPoint(struct _Instance *instance, struct _Rotation *rot); // 0x8009E410

extern void LimitRotation(struct _Rotation *rot); // 0x8009E550

extern void StateHandlerGrab(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009E6C4


#endif
