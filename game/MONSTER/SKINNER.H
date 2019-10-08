#ifndef SKINNER_H
#define SKINNER_H

extern int SKINNER_BurrowInEntry(struct _Instance *instance);

extern int SKINNER_BurrowIn(struct _Instance *instance);

extern int SKINNER_GetBurrowDest(struct _Instance *instance, struct _Position *enemyPos);

extern void SKINNER_CalcBurrowingMove(struct _Instance *instance, struct _Position *enemyPos);

extern void SKINNER_PupateEntry(struct _Instance *instance);

extern void SKINNER_Pupate(struct _Instance *instance);

extern void SKINNER_PursueEntry(struct _Instance *instance);

extern void SKINNER_Pursue(struct _Instance *instance);

extern void SKINNER_HideEntry(struct _Instance *instance);

extern void SKINNER_Hide(struct _Instance *instance);

extern void SKINNER_SurpriseAttackEntry(struct _Instance *instance);

extern void SKINNER_SurpriseAttack(struct _Instance *instance);

#endif
