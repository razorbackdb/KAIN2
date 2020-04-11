#ifndef ATTACK_H
#define ATTACK_H


extern int StateHandlerDecodeHold(int *Message, int *Data); // 0x8009B184

extern void StateHandlerAttack2(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009B4B4

extern void StateHandlerCannedReaction(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009C3C8

extern void StateHandlerStumble(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009C65C

extern void StateHandlerHitReaction(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009CA54

extern void StateHandlerThrow2(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009CCD0

extern void PointAt(struct _Instance *instance, struct _Position *Target, struct _Rotation *Rot1); // 0x8009D750

extern void ThrowSetFocusPoint(struct _Instance *instance, struct _Rotation *rot); // 0x8009D870

extern void LimitRotation(struct _Rotation *rot); // 0x8009D9B4

extern void StateHandlerGrab(struct __CharacterState *In, int CurrentSection, int Data); // 0x8009DB28


#endif
