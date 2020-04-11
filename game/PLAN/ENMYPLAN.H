#ifndef ENMYPLAN_H
#define ENMYPLAN_H


extern void ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool); // 0x80095FE8

extern int ENMYPLAN_GetNextAvailablePlanningSlot(); // 0x80096008

extern int ENMYPLAN_GetInitializedPlanningWorkspaceFinal(); // 0x80096048

extern void ENMYPLAN_ReleasePlanningWorkspace(int slotID); // 0x800960A4

extern int ENMYPLAN_WayPointSkipped(struct _Position *currentPos, struct _Position *targetPos, struct _Position *nextTargetPos); // 0x8009610C

extern int ENMYPLAN_WayPointReached(struct _Position *currentPos, struct _Position *oldCurrentPos, struct _Position *targetPos); // 0x80096278

extern void ENMYPLAN_Replan(struct EnemyPlanSlotData *planSlot); // 0x80096328

extern int ENMYPLAN_PathClear(struct _Position *pos, struct _Position *target); // 0x80096354

extern int ENMYPLAN_MoveToTargetFinal(struct _Instance *instance, struct _Position *outputPos, int slotID, struct _Position *targetPos, int validNodeTypes); // 0x800964B0

extern int ValidSlotAndState(struct EnemyPlanSlotData *pool, int slotID); // 0x8009698C

extern int ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID); // 0x800969D0

extern int ENMYPLAN_GetPosOfNextWaypoint(int slotID, struct _Position *pos); // 0x80096A3C

extern short ENMYPLAN_ReportCurrentGoalUnitID(int slotID); // 0x80096ADC


#endif
