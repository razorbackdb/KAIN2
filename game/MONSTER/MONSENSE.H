#ifndef MONSENSE_H
#define MONSENSE_H


extern struct _MonsterIR * MONSENSE_FindIR(struct _MonsterVars *mv, struct _Instance *instance); // 0x800856CC

extern int MONSENSE_See(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80085704

extern int MONSENSE_Hear(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x800858A0

extern int MONSENSE_Smell(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80085930

extern int MONSENSE_DetectPlayer(struct _Instance *instance); // 0x80085958

extern struct _MonsterIR * MONSENSE_FirstSense(struct _Instance *instance, struct _Instance *sensed); // 0x80085980

extern void MONSENSE_SetupMIR(struct _Instance *instance, struct evCollideInstanceStatsData *data, int flags); // 0x80085B18

extern void MONSENSE_SenseInstance(struct _Instance *instance, struct evCollideInstanceStatsData *data); // 0x80085F44

extern void MONSENSE_StartMonsterIRList(struct _Instance *instance); // 0x80086138

extern struct _MonsterIR * MONSENSE_GetMonsterIR(struct _MonsterVars *mv); // 0x8008624C

extern void MONSENSE_InitIRList(struct _MonsterVars *mv, struct _MonsterIR *list, int num); // 0x80086274

extern struct _MonsterIR * MONSENSE_SetEnemy(struct _Instance *instance, struct _Instance *newenemy); // 0x800862A0

extern void MONSENSE_ProcessIRList(struct _Instance *instance); // 0x800863C0

extern void MONSENSE_SetupSenses(struct _Instance *instance); // 0x800865C8

extern void MONSENSE_RemoveSenses(struct _Instance *instance); // 0x80086700

extern void MONSENSE_Radar(struct _Instance *instance); // 0x80086764

extern short MONSENSE_GetClosestFreeDirection(struct _Instance *instance, short angle, long range); // 0x800869A4

extern int MONSENSE_GetDistanceInDirection(struct _Instance *instance, short angle); // 0x80086AB0

extern void MONSENSE_DoSenses(struct _Instance *instance); // 0x80086AE8

extern void MONSENSE_AdjustRadarFromObjects(struct _Instance *instance); // 0x80086BE8


#endif
