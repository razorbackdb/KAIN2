#ifndef HUNTER_H
#define HUNTER_H

extern void HUNTER_InitFlamethrow(struct _Instance *instance);

extern int HUNTER_Flamethrow(struct _Instance *instance, int damage, int newPoint, int segment);

extern void HUNTER_Init(struct _Instance *instance);

extern void HUNTER_CleanUp(struct _Instance *instance);

extern void HUNTER_ProjectileEntry(struct _Instance *instance);

extern void HUNTER_Projectile(struct _Instance *instance);

#endif
