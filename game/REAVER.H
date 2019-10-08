#ifndef REAVER_H
#define REAVER_H

extern void SoulReaverInit(struct _Instance *instance, struct GameTracker *gameTracker);

extern void SoulReaverCollide(struct _Instance *instance, struct GameTracker *gameTracker);

extern void SoulReaverProcess(struct _Instance *instance, struct GameTracker *gameTracker);

extern void CollideReaverProjectile(struct _Instance *instance, struct GameTracker *gameTracker);

extern unsigned long SoulReaverQuery(struct _Instance *instance, unsigned long query);

extern void SoulReaverImbue(struct _Instance *instance, int number);

extern void SoulReaverCharge(struct _Instance *instance, struct __ReaverData *data);

extern void StopSoulReaverCharge(struct __ReaverData *data, struct _Instance *instance);

extern void SoulReaverPost(struct _Instance *instance, unsigned long message, unsigned long data);

extern unsigned long REAVER_GetGlowColor(struct _Instance *instance);

extern void _SoulReaverAnimate(struct _Instance *instance);

#endif
