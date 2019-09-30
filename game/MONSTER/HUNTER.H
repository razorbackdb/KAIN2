#ifndef HUNTER_H
#define HUNTER_H


extern void HUNTER_InitFlamethrow(struct _Instance *instance); // 0x8007CF6C

extern int HUNTER_Flamethrow(struct _Instance *instance, int damage, int newPoint, int segment); // 0x8007CFAC

extern void HUNTER_Init(struct _Instance *instance); // 0x8007D398

extern void HUNTER_CleanUp(struct _Instance *instance); // 0x8007D45C

extern void HUNTER_ProjectileEntry(struct _Instance *instance); // 0x8007D4AC

extern void HUNTER_Projectile(struct _Instance *instance); // 0x8007D4FC


#endif
