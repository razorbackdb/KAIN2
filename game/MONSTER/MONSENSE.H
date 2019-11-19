#ifndef MONSENSE_H
#define MONSENSE_H


extern struct _MonsterIR * MONSENSE_FindHumanIR(struct _MonsterVars *mv); // 0x80084994

extern struct _MonsterIR * MONSENSE_FindIR(struct _MonsterVars *mv, struct _Instance *instance); // 0x800849E8

extern int MONSENSE_See(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80084A20

extern int MONSENSE_Hear(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80084BBC

extern int MONSENSE_Smell(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80084C4C

extern int MONSENSE_DetectPlayer(struct _Instance *instance); // 0x80084C74

extern struct _MonsterIR * MONSENSE_FirstSense(struct _Instance *instance, struct _Instance *sensed); // 0x80084C9C

extern void MONSENSE_SetupMIR(struct _Instance *instance, struct evCollideInstanceStatsData *data, int flags); // 0x80084E1C

extern void MONSENSE_SenseInstance(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80085228

extern void MONSENSE_StartMonsterIRList(struct _Instance *instance); // 0x8008541C

extern struct _MonsterIR * MONSENSE_GetMonsterIR(struct _MonsterVars *mv); // 0x80085564

extern void MONSENSE_InitIRList(struct _MonsterVars *mv, struct _MonsterIR *list, int num); // 0x8008558C

extern struct _MonsterIR * MONSENSE_SetEnemy(struct _Instance *instance, struct _Instance *newenemy); // 0x800855B8

extern void MONSENSE_ProcessIRList(struct _Instance *instance); // 0x8008569C

extern void MONSENSE_SetupSenses(struct _Instance *instance); // 0x800858A4

extern void MONSENSE_RemoveSenses(struct _Instance *instance); // 0x8008597C

extern void MONSENSE_Radar(struct _Instance *instance); // 0x800859E0

extern short MONSENSE_GetClosestFreeDirection(struct _Instance *instance, short angle, long range); // 0x80085BEC

extern int MONSENSE_GetDistanceInDirection(struct _Instance *instance, short angle); // 0x80085CA0


#endif
