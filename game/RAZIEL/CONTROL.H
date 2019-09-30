#ifndef CONTROL_H
#define CONTROL_H


extern void SetPhysics(struct _Instance *instance, short gravity, long x, long y, long z); // 0x80099900

extern void ResetPhysics(struct _Instance *instance, short gravity); // 0x80099974

extern void SetDampingPhysics(struct _Instance *instance, int damping); // 0x80099A30

extern void SetImpulsePhysics(struct _Instance *instance, struct __Player *player); // 0x80099AD8

extern void SetDropPhysics(struct _Instance *instance, struct __Player *player); // 0x80099C08

extern void InitExternalForces(struct __Force *Forces, int MaxForces); // 0x80099C40

extern void SetExternalForce(struct __Force *In, short x, short y, short z, int Space, int Friction); // 0x80099C80

extern void SetExternalTransitionForce(struct __Force *in, struct _Instance *instance, int time, int x, int y, int z); // 0x80099CC0

extern void ProcessPhysics(struct __Player *player, struct __CharacterState *In, int CurrentSection, int Mode); // 0x80099D28

extern void ApplyExternalLocalForces(struct __Player *player, struct _Instance *instance, struct __Force *Forces, int MaxForces, struct _Vector *Out); // 0x80099F20


#endif
