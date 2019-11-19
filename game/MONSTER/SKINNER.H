#ifndef SKINNER_H
#define SKINNER_H


extern int SKINNER_BurrowInEntry(struct _Instance *instance); // 0x8008B040

extern int SKINNER_BurrowIn(struct _Instance *instance); // 0x8008B114

extern int SKINNER_GetBurrowDest(struct _Instance *instance, struct _Position *enemyPos); // 0x8008B1A4

extern void SKINNER_CalcBurrowingMove(struct _Instance *instance, struct _Position *enemyPos); // 0x8008B2BC

extern void SKINNER_PursueEntry(struct _Instance *instance); // 0x8008B390

extern void SKINNER_Pursue(struct _Instance *instance); // 0x8008B3B0

extern void SKINNER_HideEntry(struct _Instance *instance); // 0x8008B538

extern void SKINNER_Hide(struct _Instance *instance); // 0x8008B580

extern void SKINNER_SurpriseAttackEntry(struct _Instance *instance); // 0x8008B68C

extern void SKINNER_SurpriseAttack(struct _Instance *instance); // 0x8008B714


#endif
