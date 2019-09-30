#ifndef REAVER_H
#define REAVER_H


extern void SoulReaverInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80079730

extern void SoulReaverCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800797CC

extern void SoulReaverProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007993C

extern void CollideReaverProjectile(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007995C

extern unsigned long SoulReaverQuery(struct _Instance *instance, unsigned long query); // 0x80079ADC

extern void SoulReaverImbue(struct _Instance *instance, int number); // 0x80079B60

extern void SoulReaverCharge(struct _Instance *instance, struct __ReaverData *data); // 0x80079BEC

extern void StopSoulReaverCharge(struct __ReaverData *data, struct _Instance *instance); // 0x80079D20

extern void SoulReaverPost(struct _Instance *instance, unsigned long message, unsigned long data); // 0x80079D60

extern unsigned long REAVER_GetGlowColor(struct _Instance *instance); // 0x8007A088

extern void _SoulReaverAnimate(struct _Instance *instance); // 0x8007A0AC


#endif
