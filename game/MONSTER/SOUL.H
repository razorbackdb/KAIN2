#ifndef SOUL_H
#define SOUL_H


extern void SOUL_QueueHandler(struct _Instance *instance); // 0x8008D504

extern void SOUL_Physics(struct _Instance *instance, long time); // 0x8008D5A0

extern void SOUL_Fade(struct _Instance *instance); // 0x8008D600

extern void SOUL_MoveToDest(struct _Instance *instance, long maxAccel, long time); // 0x8008D6BC

extern void SOUL_Init(struct _Instance *instance); // 0x8008D7AC

extern void SOUL_CleanUp(struct _Instance *instance); // 0x8008D87C

extern void SOUL_BirthEntry(struct _Instance *instance); // 0x8008D89C

extern void SOUL_Birth(struct _Instance *instance); // 0x8008D8F0

extern void SOUL_SoulSuckEntry(struct _Instance *instance); // 0x8008D958

extern long SOUL_CalcAccel(long delta, long vel, long magnitude); // 0x8008D980

extern void SOUL_SoulSuck(struct _Instance *instance); // 0x8008D9C0

extern void SOUL_WanderEntry(struct _Instance *instance); // 0x8008DF08

extern void SOUL_Wander(struct _Instance *instance); // 0x8008DF78

extern void SOUL_FleeEntry(struct _Instance *instance); // 0x8008E108

extern void SOUL_Flee(struct _Instance *instance); // 0x8008E138

extern void SOUL_IdleEntry(struct _Instance *instance); // 0x8008E29C

extern void SOUL_Idle(struct _Instance *instance); // 0x8008E340

extern void SOUL_ReanimateEntry(struct _Instance *instance); // 0x8008E440

extern void SOUL_Reanimate(struct _Instance *instance); // 0x8008E4A8

extern void SOUL_Effect(struct _Instance *instance, struct evFXHitData *data); // 0x8008E560


#endif
