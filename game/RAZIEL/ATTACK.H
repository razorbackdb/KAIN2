#ifndef ATTACK_H
#define ATTACK_H

extern int StateHandlerDecodeHold(int *Message, int *Data);

extern void StateHandlerAttack2(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerCannedReaction(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerStumble(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerHitReaction(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerThrow2(struct __CharacterState *In, int CurrentSection, int Data);

extern void PointAt(struct _Instance *instance, struct _Position *Target, struct _Rotation *Rot1);

extern void ThrowSetFocusPoint(struct _Instance *instance, struct _Rotation *rot);

extern void LimitRotation(struct _Rotation *rot);

extern void StateHandlerGrab(struct __CharacterState *In, int CurrentSection, int Data);

#endif
