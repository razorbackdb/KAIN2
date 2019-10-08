#ifndef CONTROL_H
#define CONTROL_H

extern void SetPhysics(struct _Instance *instance, short gravity, long x, long y, long z);

extern void ResetPhysics(struct _Instance *instance, short gravity);

extern void SetDampingPhysics(struct _Instance *instance, int damping);

extern void SetImpulsePhysics(struct _Instance *instance, struct __Player *player);

extern void SetDropPhysics(struct _Instance *instance, struct __Player *player);

extern void InitExternalForces(struct __Force *Forces, int MaxForces);

extern void SetExternalForce(struct __Force *In, short x, short y, short z, int Space, int Friction);

extern void SetExternalTransitionForce(struct __Force *in, struct _Instance *instance, int time, int x, int y, int z);

extern void ProcessPhysics(struct __Player *player, struct __CharacterState *In, int CurrentSection, int Mode);

extern void ApplyExternalLocalForces(struct __Player *player, struct _Instance *instance, struct __Force *Forces, int MaxForces, struct _Vector *Out);

#endif
