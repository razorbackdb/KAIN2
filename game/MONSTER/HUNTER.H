#ifndef HUNTER_H
#define HUNTER_H


extern void HUNTER_InitFlamethrow(struct _Instance *instance); // 0x8007C59C

extern int HUNTER_Flamethrow(struct _Instance *instance, int damage, int newPoint, int segment); // 0x8007C5D8

extern void HUNTER_Init(struct _Instance *instance); // 0x8007C9C4

extern void HUNTER_CleanUp(struct _Instance *instance); // 0x8007CA74

extern void HUNTER_ProjectileEntry(struct _Instance *instance); // 0x8007CAC4

extern void HUNTER_Projectile(struct _Instance *instance); // 0x8007CB14


#endif
