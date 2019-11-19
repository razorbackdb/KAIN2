#ifndef ENMYPLAN_H
#define ENMYPLAN_H


extern void ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool); // 0x800943E8

extern int ENMYPLAN_GetNextAvailablePlanningSlot(); // 0x80094408

extern int ENMYPLAN_GetInitializedPlanningWorkspaceFinal(); // 0x80094448

extern void ENMYPLAN_ReleasePlanningWorkspace(int slotID); // 0x800944A4

extern int ENMYPLAN_WayPointSkipped(struct _Position *currentPos, struct _Position *targetPos, struct _Position *nextTargetPos); // 0x8009450C

extern int ENMYPLAN_WayPointReached(struct _Position *currentPos, struct _Position *oldCurrentPos, struct _Position *targetPos); // 0x80094678

extern void ENMYPLAN_Replan(struct EnemyPlanSlotData *planSlot); // 0x80094728

extern int ENMYPLAN_PathClear(struct _Position *pos, struct _Position *target); // 0x80094754

extern int ENMYPLAN_MoveToTargetFinal(struct _Instance *instance, struct _Position *outputPos, int slotID, struct _Position *targetPos, int validNodeTypes); // 0x80094834

extern int ValidSlotAndState(struct EnemyPlanSlotData *pool, int slotID); // 0x80094C9C

extern int ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID); // 0x80094CE0

extern int ENMYPLAN_GetPosOfNextWaypoint(int slotID, struct _Position *pos); // 0x80094D4C

extern short ENMYPLAN_ReportCurrentGoalUnitID(int slotID); // 0x80094DEC


#endif
