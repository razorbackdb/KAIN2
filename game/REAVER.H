#ifndef REAVER_H
#define REAVER_H


extern void SoulReaverInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007933C

extern void SoulReaverCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800793D4

extern void SoulReaverProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80079510

extern void CollideReaverProjectile(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80079530

extern unsigned long SoulReaverQuery(struct _Instance *instance, unsigned long query); // 0x80079644

extern void SoulReaverImbue(struct _Instance *instance, int number); // 0x800796C8

extern void SoulReaverPost(struct _Instance *instance, unsigned long message, unsigned long data); // 0x80079754

extern void _SoulReaverAnimate(struct _Instance *instance); // 0x800799FC


#endif
