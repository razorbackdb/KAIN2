#ifndef MISSILE_H
#define MISSILE_H


extern void MISSILE_Process(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007CD60

extern void MISSILE_Collide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007CDB8

extern struct _Instance * MISSILE_Find(struct _Instance *instance, struct _MonsterMissile *missiledef); // 0x8007CDF4

extern struct _Instance * MISSILE_Birth(struct _Instance *instance, struct _MonsterMissile *missiledef); // 0x8007CE70

extern struct _Instance * MISSILE_Fire(struct _Instance *instance, struct _MonsterMissile *missiledef, void *target, int type); // 0x8007CF00

extern struct _Instance * MISSILE_FireAtInstance(struct _Instance *instance, struct _MonsterMissile *missiledef, struct _Instance *target); // 0x8007CFCC


#endif
