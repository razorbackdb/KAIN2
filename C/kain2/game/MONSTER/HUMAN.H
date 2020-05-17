#ifndef HUMAN_H
#define HUMAN_H


extern void HUMAN_WaitForWeapon(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007CD70

extern struct _Instance * HUMAN_CreateWeapon(struct _Instance *instance, int weaponid, int segment); // 0x8007CDE0

extern void HUMAN_Init(struct _Instance *instance); // 0x8007CEB4

extern void HUMAN_CleanUp(struct _Instance *instance); // 0x8007CFAC

extern unsigned long HUMAN_Query(struct _Instance *instance, unsigned long query); // 0x8007CFCC

extern void HUMAN_DeadEntry(struct _Instance *instance); // 0x8007D0BC

extern void HUMAN_Dead(struct _Instance *instance); // 0x8007D134

extern void HUMAN_StunnedEntry(struct _Instance *instance); // 0x8007D21C

extern void HUMAN_Stunned(struct _Instance *instance); // 0x8007D294

extern void HUMAN_EmbraceEntry(struct _Instance *instance); // 0x8007D33C

extern void HUMAN_Embrace(struct _Instance *instance); // 0x8007D398

extern void HUMAN_IdleEntry(struct _Instance *instance); // 0x8007D560

extern void HUMAN_Idle(struct _Instance *instance); // 0x8007D5A8

extern void HUMAN_Flee(struct _Instance *instance); // 0x8007D760

extern void HUMAN_GetAngry(); // 0x8007D8B8

extern int HUMAN_TypeOfHuman(struct _Instance *instance); // 0x8007D980


#endif
