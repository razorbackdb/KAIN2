#ifndef ENMYPLAN_H
#define ENMYPLAN_H


extern void ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool); // 0x800966E4

extern int ENMYPLAN_GetNextAvailablePlanningSlot(); // 0x80096704

extern int ENMYPLAN_GetInitializedPlanningWorkspaceFinal(); // 0x80096744

extern void ENMYPLAN_ReleasePlanningWorkspace(int slotID); // 0x800967A0

extern int ENMYPLAN_WayPointSkipped(struct _Position *currentPos, struct _Position *targetPos, struct _Position *nextTargetPos); // 0x80096808

extern int ENMYPLAN_WayPointReached(struct _Position *currentPos, struct _Position *oldCurrentPos, struct _Position *targetPos); // 0x80096974

extern void ENMYPLAN_Replan(struct EnemyPlanSlotData *planSlot); // 0x80096A24

extern int ENMYPLAN_PathClear(struct _Position *pos, struct _Position *target); // 0x80096A50

extern int ENMYPLAN_MoveToTargetFinal(struct _Instance *instance, struct _Position *outputPos, int slotID, struct _Position *targetPos, int validNodeTypes); // 0x80096BD0

extern int ValidSlotAndState(struct EnemyPlanSlotData *pool, int slotID); // 0x800970DC

extern int ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID); // 0x80097120

extern int ENMYPLAN_GetPosOfNextWaypoint(int slotID, struct _Position *pos); // 0x8009718C

extern void ENMYPLAN_RelocatePlanPositions(int slotID, struct _Position *offset); // 0x8009722C


#endif
