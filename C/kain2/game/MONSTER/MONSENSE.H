#ifndef MONSENSE_H
#define MONSENSE_H


extern struct _MonsterIR * MONSENSE_FindIR(struct _MonsterVars *mv, struct _Instance *instance); // 0x80085C70

extern int MONSENSE_See(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80085CA8

extern int MONSENSE_Hear(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80085E44

extern int MONSENSE_Smell(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80085ED4

extern struct _MonsterIR * MONSENSE_FirstSense(struct _Instance *instance, struct _Instance *sensed); // 0x80085EFC

extern void MONSENSE_SetupMIR(struct _Instance *instance, struct evCollideInstanceStatsData *data, int flags); // 0x80086094

extern void MONSENSE_SenseInstance(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x800864C0

extern void MONSENSE_StartMonsterIRList(struct _Instance *instance); // 0x800866B4

extern struct _MonsterIR * MONSENSE_GetMonsterIR(struct _MonsterVars *mv); // 0x800867C8

extern void MONSENSE_InitIRList(struct _MonsterVars *mv, struct _MonsterIR *list, int num); // 0x800867F0

extern struct _MonsterIR * MONSENSE_SetEnemy(struct _Instance *instance, struct _Instance *newenemy); // 0x8008681C

extern void MONSENSE_ProcessIRList(struct _Instance *instance); // 0x8008693C

extern void MONSENSE_SetupSenses(struct _Instance *instance); // 0x80086B5C

extern void MONSENSE_RemoveSenses(struct _Instance *instance); // 0x80086CC8

extern void MONSENSE_Radar(struct _Instance *instance); // 0x80086D68

extern short MONSENSE_GetClosestFreeDirection(struct _Instance *instance, short angle, long range); // 0x80086FA0

extern int MONSENSE_GetDistanceInDirection(struct _Instance *instance, short angle); // 0x800870A4

extern void MONSENSE_DoSenses(struct _Instance *instance); // 0x800870DC

extern void MONSENSE_AdjustRadarFromObjects(struct _Instance *instance); // 0x800871D4


#endif
