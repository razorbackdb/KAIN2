#ifndef HUMAN_H
#define HUMAN_H

extern void HUMAN_WaitForWeapon(struct _Instance *instance, struct GameTracker *gameTracker);

extern struct _Instance *HUMAN_CreateWeapon(struct _Instance *instance, int weaponid, int segment);

extern void HUMAN_Init(struct _Instance *instance);

extern void HUMAN_CleanUp(struct _Instance *instance);

extern unsigned long HUMAN_Query(struct _Instance *instance, unsigned long query);

extern void HUMAN_DeadEntry(struct _Instance *instance);

extern void HUMAN_Dead(struct _Instance *instance);

extern void HUMAN_StunnedEntry(struct _Instance *instance);

extern void HUMAN_Stunned(struct _Instance *instance);

extern void HUMAN_EmbraceEntry(struct _Instance *instance);

extern void HUMAN_Embrace(struct _Instance *instance);

extern void HUMAN_IdleEntry(struct _Instance *instance);

extern void HUMAN_Idle(struct _Instance *instance);

extern void HUMAN_Flee(struct _Instance *instance);

extern void HUMAN_GetAngry();

#endif
