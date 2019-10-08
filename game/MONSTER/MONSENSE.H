#ifndef MONSENSE_H
#define MONSENSE_H

extern struct _MonsterIR *MONSENSE_FindIR(struct _MonsterVars *mv, struct _Instance *instance);

extern int MONSENSE_See(struct _Instance *instance, struct evCollideInstanceStatsData *data);

extern int MONSENSE_Hear(struct _Instance *instance, struct evCollideInstanceStatsData *data);

extern int MONSENSE_Smell(struct _Instance *instance, struct evCollideInstanceStatsData *data);

extern int MONSENSE_DetectPlayer(struct _Instance *instance);

extern struct _MonsterIR *MONSENSE_FirstSense(struct _Instance *instance, struct _Instance *sensed);

extern void MONSENSE_SetupMIR(struct _Instance *instance, struct evCollideInstanceStatsData *data, int flags);

extern void MONSENSE_SenseInstance(struct _Instance *instance, struct evCollideInstanceStatsData *data);

extern void MONSENSE_StartMonsterIRList(struct _Instance *instance);

extern struct _MonsterIR *MONSENSE_GetMonsterIR(struct _MonsterVars *mv);

extern void MONSENSE_InitIRList(struct _MonsterVars *mv, struct _MonsterIR *list, int num);

extern struct _MonsterIR *MONSENSE_SetEnemy(struct _Instance *instance, struct _Instance *newenemy);

extern void MONSENSE_ProcessIRList(struct _Instance *instance);

extern void MONSENSE_SetupSenses(struct _Instance *instance);

extern void MONSENSE_RemoveSenses(struct _Instance *instance);

extern void MONSENSE_Radar(struct _Instance *instance);

extern short MONSENSE_GetClosestFreeDirection(struct _Instance *instance, short angle, long range);

extern int MONSENSE_GetDistanceInDirection(struct _Instance *instance, short angle);

extern void MONSENSE_DoSenses(struct _Instance *instance);

extern void MONSENSE_AdjustRadarFromObjects(struct _Instance *instance);

#endif
