#ifndef CONTROL_H
#define CONTROL_H


extern void SetPhysics(struct _Instance *instance, short gravity, long x, long y, long z); // 0x8009A138

extern void ResetPhysics(struct _Instance *instance, short gravity); // 0x8009A1AC

extern void SetDampingPhysics(struct _Instance *instance, int damping); // 0x8009A268

extern void SetImpulsePhysics(struct _Instance *instance, struct __Player *player); // 0x8009A310

extern void SetDropPhysics(struct _Instance *instance, struct __Player *player); // 0x8009A440

extern void InitExternalForces(struct __Force *Forces, int MaxForces); // 0x8009A478

extern void SetExternalForce(struct __Force *In, short x, short y, short z, int Space, int Friction); // 0x8009A4B8

extern void SetExternalTransitionForce(struct __Force *in, struct _Instance *instance, int time, int x, int y, int z); // 0x8009A4F8

extern void ProcessPhysics(struct __Player *player, struct __CharacterState *In, int CurrentSection, int Mode); // 0x8009A560

extern void ApplyExternalLocalForces(struct __Player *player, struct _Instance *instance, struct __Force *Forces, int MaxForces, struct _Vector *Out); // 0x8009A758


#endif
