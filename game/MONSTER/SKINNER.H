#ifndef SKINNER_H
#define SKINNER_H


extern int SKINNER_BurrowInEntry(struct _Instance *instance); // 0x8008C6F4

extern int SKINNER_BurrowIn(struct _Instance *instance); // 0x8008C7DC

extern int SKINNER_GetBurrowDest(struct _Instance *instance, struct _Position *enemyPos); // 0x8008C850

extern void SKINNER_CalcBurrowingMove(struct _Instance *instance, struct _Position *enemyPos); // 0x8008C968

extern void SKINNER_PupateEntry(struct _Instance *instance); // 0x8008CA3C

extern void SKINNER_Pupate(struct _Instance *instance); // 0x8008CA88

extern void SKINNER_PursueEntry(struct _Instance *instance); // 0x8008CAD4

extern void SKINNER_Pursue(struct _Instance *instance); // 0x8008CAF4

extern void SKINNER_HideEntry(struct _Instance *instance); // 0x8008CC7C

extern void SKINNER_Hide(struct _Instance *instance); // 0x8008CCC4

extern void SKINNER_SurpriseAttackEntry(struct _Instance *instance); // 0x8008CDD0

extern void SKINNER_SurpriseAttack(struct _Instance *instance); // 0x8008CE64


#endif
