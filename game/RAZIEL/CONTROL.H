#ifndef CONTROL_H
#define CONTROL_H


extern void SetPhysics(struct _Instance *instance, short gravity, long x, long y, long z); // 0x80097BF0

extern void ResetPhysics(struct _Instance *instance, short gravity); // 0x80097C64

extern void SetDampingPhysics(struct _Instance *instance, int damping); // 0x80097D20

extern void SetImpulsePhysics(struct _Instance *instance, struct __Player *player); // 0x80097DC8

extern void SetDropPhysics(struct _Instance *instance, struct __Player *player); // 0x80097EF4

extern void InitExternalForces(struct __Force *Forces, int MaxForces); // 0x80097F2C

extern void SetExternalForce(struct __Force *In, short x, short y, short z, int Space, int Friction); // 0x80097F6C

extern void SetExternalTransitionForce(struct __Force *in, struct _Instance *instance, int time, int x, int y, int z); // 0x80097FAC

extern void ProcessPhysics(struct __Player *player, struct __CharacterState *In, int CurrentSection, int Mode); // 0x80098014

extern void ApplyExternalLocalForces(struct __Player *player, struct _Instance *instance, struct __Force *Forces, int MaxForces, struct _Vector *Out); // 0x8009820C


#endif
