#ifndef SOUL_H
#define SOUL_H


extern void SOUL_QueueHandler(struct _Instance *instance); // 0x8008BD4C

extern void SOUL_Physics(struct _Instance *instance, long time); // 0x8008BDE8

extern void SOUL_Fade(struct _Instance *instance); // 0x8008BE48

extern void SOUL_MoveToDest(struct _Instance *instance, long maxAccel, long time); // 0x8008BF04

extern void SOUL_Init(struct _Instance *instance); // 0x8008BFF4

extern void SOUL_CleanUp(struct _Instance *instance); // 0x8008C0B4

extern void SOUL_BirthEntry(struct _Instance *instance); // 0x8008C0D4

extern void SOUL_Birth(struct _Instance *instance); // 0x8008C128

extern void SOUL_SoulSuckEntry(struct _Instance *instance); // 0x8008C190

extern long SOUL_CalcAccel(long delta, long vel, long magnitude); // 0x8008C1B8

extern void SOUL_SoulSuck(struct _Instance *instance); // 0x8008C1F8

extern void SOUL_WanderEntry(struct _Instance *instance); // 0x8008C700

extern void SOUL_Wander(struct _Instance *instance); // 0x8008C770

extern void SOUL_FleeEntry(struct _Instance *instance); // 0x8008C900

extern void SOUL_Flee(struct _Instance *instance); // 0x8008C930

extern void SOUL_IdleEntry(struct _Instance *instance); // 0x8008CA94

extern void SOUL_Idle(struct _Instance *instance); // 0x8008CB38

extern void SOUL_ReanimateEntry(struct _Instance *instance); // 0x8008CC38

extern void SOUL_Reanimate(struct _Instance *instance); // 0x8008CCA0

extern void SOUL_Effect(struct _Instance *instance, struct evFXHitData *data); // 0x8008CD58


#endif
