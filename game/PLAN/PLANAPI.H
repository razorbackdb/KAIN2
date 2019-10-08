#ifndef PLANAPI_H
#define PLANAPI_H

extern void PLANAPI_ConvertPlanIntoEnmyPlanDataFormat(struct PlanningNode *goalNode, struct EnemyPlanData *planData, struct PlanningNode *planningPool);

extern int PLANAPI_FindPathBetweenNodes(struct PlanningNode *startNode, struct PlanningNode *goalNode, struct EnemyPlanData *planData, int validNodeTypes);

extern void PLANAPI_DoTimingCalcsAndDrawing(long startTime, struct PlanningNode *planningPool);

extern int PLANAPI_AddNodeOfTypeToPool(struct _Position *pos, int type);

extern void PLANAPI_DeleteNodesFromPoolByType(int nodeSource);

extern void PLANAPI_DeleteNodeFromPoolByUnit(long streamUnitID);

extern int PLANAPI_FindPathInGraphToTarget(struct _Position *startPos, struct EnemyPlanData *planData, int validNodeTypes);

extern void PLANAPI_InitPlanning(void *planningPool);

extern short PLANAPI_PairType(struct PlanningNode *node1, struct PlanningNode *node2);

extern int PLANAPI_PassThroughHit(struct PlanningNode *node1, struct PlanningNode *node2);

extern void PLANAPI_UpdatePlanningDatabase(struct GameTracker *gameTracker, struct _Instance *player);

extern int PLANAPI_NumNodesInPool(void *planningPool);

extern void PLANAPI_InitPlanMkrList(struct _StreamUnit *streamUnit);

extern int PLANAPI_GetFlags(int type);

extern int PLANAPI_FindNodePositionInUnit(struct _StreamUnit *streamUnit, struct _Position *pos, int id, int type);

extern int PLANAPI_FindClosestNodePositionInUnit(struct _StreamUnit *streamUnit, struct _Position *target, struct _Position *pos, int offset, int max, int type, int distanceCheck);

#endif
