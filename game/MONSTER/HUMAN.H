#ifndef HUMAN_H
#define HUMAN_H


extern void HUMAN_WaitForWeapon(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007C378

extern struct _Instance * HUMAN_CreateWeapon(struct _Instance *instance, int weaponid, int segment); // 0x8007C3E8

extern void HUMAN_Init(struct _Instance *instance); // 0x8007C4BC

extern void HUMAN_CleanUp(struct _Instance *instance); // 0x8007C620

extern unsigned long HUMAN_Query(struct _Instance *instance, unsigned long query); // 0x8007C640

extern void HUMAN_DeadEntry(struct _Instance *instance); // 0x8007C730

extern void HUMAN_Dead(struct _Instance *instance); // 0x8007C7A8

extern void HUMAN_StunnedEntry(struct _Instance *instance); // 0x8007C890

extern void HUMAN_Stunned(struct _Instance *instance); // 0x8007C908

extern void HUMAN_EmbraceEntry(struct _Instance *instance); // 0x8007C9B0

extern void HUMAN_Embrace(struct _Instance *instance); // 0x8007CA0C

extern void HUMAN_IdleEntry(struct _Instance *instance); // 0x8007CBD4

extern void HUMAN_Idle(struct _Instance *instance); // 0x8007CC1C

extern void HUMAN_Flee(struct _Instance *instance); // 0x8007CD8C

extern void HUMAN_GetAngry(); // 0x8007CEA4


#endif
