#ifndef REAVER_H
#define REAVER_H


extern void SoulReaverInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80079FF0

extern void SoulReaverCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007A090

extern void SoulReaverProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007A200

extern void CollideReaverProjectile(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007A24C

extern unsigned long SoulReaverQuery(struct _Instance *instance, unsigned long query); // 0x8007A3A8

extern void SoulReaverImbue(struct _Instance *instance, int number); // 0x8007A42C

extern void SoulReaverCharge(struct _Instance *instance, struct __ReaverData *data); // 0x8007A4B8

extern void StopSoulReaverCharge(struct __ReaverData *data, struct _Instance *instance); // 0x8007A5DC

extern void SoulReaverPost(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8007A61C

extern unsigned long REAVER_GetGlowColor(struct _Instance *instance); // 0x8007A978

extern void _SoulReaverAnimate(struct _Instance *instance); // 0x8007A99C

extern int SoulReaverFire(); // 0x8007AB58


#endif
