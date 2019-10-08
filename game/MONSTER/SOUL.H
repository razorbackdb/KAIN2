#ifndef SOUL_H
#define SOUL_H

extern void SOUL_QueueHandler(struct _Instance *instance);

extern void SOUL_Physics(struct _Instance *instance, long time);

extern void SOUL_Fade(struct _Instance *instance);

extern void SOUL_MoveToDest(struct _Instance *instance, long maxAccel, long time);

extern void SOUL_Init(struct _Instance *instance);

extern void SOUL_CleanUp(struct _Instance *instance);

extern void SOUL_BirthEntry(struct _Instance *instance);

extern void SOUL_Birth(struct _Instance *instance);

extern void SOUL_SoulSuckEntry(struct _Instance *instance);

extern long SOUL_CalcAccel(long delta, long vel, long magnitude);

extern void SOUL_SoulSuck(struct _Instance *instance);

extern void SOUL_WanderEntry(struct _Instance *instance);

extern void SOUL_Wander(struct _Instance *instance);

extern void SOUL_FleeEntry(struct _Instance *instance);

extern void SOUL_Flee(struct _Instance *instance);

extern void SOUL_IdleEntry(struct _Instance *instance);

extern void SOUL_Idle(struct _Instance *instance);

extern void SOUL_ReanimateEntry(struct _Instance *instance);

extern void SOUL_Reanimate(struct _Instance *instance);

extern void SOUL_Effect(struct _Instance *instance, struct evFXHitData *data);

#endif
