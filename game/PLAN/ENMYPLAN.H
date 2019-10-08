#ifndef ENMYPLAN_H
#define ENMYPLAN_H

extern void ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool);

extern int ENMYPLAN_GetNextAvailablePlanningSlot();

extern int ENMYPLAN_GetInitializedPlanningWorkspaceFinal();

extern void ENMYPLAN_ReleasePlanningWorkspace(int slotID);

extern int ENMYPLAN_WayPointSkipped(struct _Position *currentPos, struct _Position *targetPos, struct _Position *nextTargetPos);

extern int ENMYPLAN_WayPointReached(struct _Position *currentPos, struct _Position *oldCurrentPos, struct _Position *targetPos);

extern void ENMYPLAN_Replan(struct EnemyPlanSlotData *planSlot);

extern int ENMYPLAN_PathClear(struct _Position *pos, struct _Position *target);

extern int ENMYPLAN_MoveToTargetFinal(struct _Instance *instance, struct _Position *outputPos, int slotID, struct _Position *targetPos, int validNodeTypes);

extern int ValidSlotAndState(struct EnemyPlanSlotData *pool, int slotID);

extern int ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID);

extern int ENMYPLAN_GetPosOfNextWaypoint(int slotID, struct _Position *pos);

extern short ENMYPLAN_ReportCurrentGoalUnitID(int slotID);

#endif
