#ifndef SOUL_H
#define SOUL_H


extern void SOUL_QueueHandler(struct _Instance *instance); // 0x8008D890

extern void SOUL_Physics(struct _Instance *instance, long time); // 0x8008D92C

extern void SOUL_Fade(struct _Instance *instance); // 0x8008D98C

extern void SOUL_MoveToDest(struct _Instance *instance, long maxAccel, long time); // 0x8008DA40

extern void SOUL_MovePastWall(struct _Instance *instance, struct _Instance *sucker); // 0x8008DB30

extern void SOUL_Init(struct _Instance *instance); // 0x8008DC24

extern void SOUL_CleanUp(struct _Instance *instance); // 0x8008DCE8

extern void SOUL_BirthEntry(struct _Instance *instance); // 0x8008DD08

extern void SOUL_Birth(struct _Instance *instance); // 0x8008DD5C

extern void SOUL_SoulSuckEntry(struct _Instance *instance); // 0x8008DDC4

extern long SOUL_CalcAccel(long delta, long vel, long magnitude); // 0x8008DDEC

extern void SOUL_SoulSuck(struct _Instance *instance); // 0x8008DE2C

extern void SOUL_WanderEntry(struct _Instance *instance); // 0x8008E3D4

extern void SOUL_Wander(struct _Instance *instance); // 0x8008E444

extern void SOUL_FleeEntry(struct _Instance *instance); // 0x8008E5D4

extern void SOUL_Flee(struct _Instance *instance); // 0x8008E604

extern void SOUL_IdleEntry(struct _Instance *instance); // 0x8008E768

extern void SOUL_Idle(struct _Instance *instance); // 0x8008E80C

extern void SOUL_ReanimateEntry(struct _Instance *instance); // 0x8008E90C

extern void SOUL_Reanimate(struct _Instance *instance); // 0x8008E974

extern void SOUL_Effect(struct _Instance *instance, struct evFXHitData *data); // 0x8008EA2C


#endif
