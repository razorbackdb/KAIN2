#ifndef HUMAN_H
#define HUMAN_H


extern void HUMAN_WaitForWeapon(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007BB98

extern struct _Instance * HUMAN_CreateWeapon(struct _Instance *instance, int weaponid, int segment); // 0x8007BC00

extern void HUMAN_Init(struct _Instance *instance); // 0x8007BD54

extern void HUMAN_CleanUp(struct _Instance *instance); // 0x8007BEC8

extern unsigned long HUMAN_Query(struct _Instance *instance, unsigned long query); // 0x8007BEE8

extern void HUMAN_DeadEntry(struct _Instance *instance); // 0x8007C004

extern void HUMAN_Dead(struct _Instance *instance); // 0x8007C04C

extern void HUMAN_StunnedEntry(struct _Instance *instance); // 0x8007C118

extern void HUMAN_Stunned(struct _Instance *instance); // 0x8007C160

extern void HUMAN_EmbraceEntry(struct _Instance *instance); // 0x8007C1CC

extern void HUMAN_Embrace(struct _Instance *instance); // 0x8007C200

extern void HUMAN_IdleEntry(struct _Instance *instance); // 0x8007C36C

extern void HUMAN_Idle(struct _Instance *instance); // 0x8007C3AC

extern void HUMAN_Flee(struct _Instance *instance); // 0x8007C484


#endif
