#ifndef MISSILE_H
#define MISSILE_H

extern void MISSILE_Process(struct _Instance *instance, struct GameTracker *gameTracker);

extern void MISSILE_Collide(struct _Instance *instance, struct GameTracker *gameTracker);

extern struct _Instance *MISSILE_Find(struct _Instance *instance, struct _MonsterMissile *missiledef);

extern struct _Instance *MISSILE_Birth(struct _Instance *instance, struct _MonsterMissile *missiledef);

extern struct _Instance *MISSILE_Fire(struct _Instance *instance, struct _MonsterMissile *missiledef, void *target, int type);

extern struct _Instance *MISSILE_FireAtInstance(struct _Instance *instance, struct _MonsterMissile *missiledef, struct _Instance *target);

#endif
