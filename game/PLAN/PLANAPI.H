#ifndef PLANAPI_H
#define PLANAPI_H


extern void PLANAPI_ConvertPlanIntoEnmyPlanDataFormat(struct PlanningNode *goalNode, struct EnemyPlanData *planData, struct PlanningNode *planningPool); // 0x800957FC

extern int PLANAPI_FindPathBetweenNodes(struct PlanningNode *startNode, struct PlanningNode *goalNode, struct EnemyPlanData *planData, int validNodeTypes); // 0x800958B0

extern void PLANAPI_DoTimingCalcsAndDrawing(long startTime, struct PlanningNode *planningPool); // 0x80095938

extern int PLANAPI_AddNodeOfTypeToPool(struct _Position *pos, int type); // 0x80095A58

extern void PLANAPI_DeleteNodesFromPoolByType(int nodeSource); // 0x80095B38

extern void PLANAPI_DeleteNodeFromPoolByUnit(long streamUnitID); // 0x80095BD4

extern int PLANAPI_FindPathInGraphToTarget(struct _Position *startPos, struct EnemyPlanData *planData, int validNodeTypes); // 0x80095C6C

extern void PLANAPI_InitPlanning(void *planningPool); // 0x80095CD0

extern short PLANAPI_PairType(struct PlanningNode *node1, struct PlanningNode *node2); // 0x80095D58

extern int PLANAPI_PassThroughHit(struct PlanningNode *node1, struct PlanningNode *node2); // 0x80095DA0

extern void PLANAPI_UpdatePlanningDatabase(struct GameTracker *gameTracker, struct _Instance *player); // 0x80095DFC

extern int PLANAPI_NumNodesInPool(void *planningPool); // 0x8009611C

extern void PLANAPI_InitPlanMkrList(struct _StreamUnit *streamUnit); // 0x80096130

extern int PLANAPI_GetFlags(int type); // 0x80096254

extern int PLANAPI_FindNodePositionInUnit(struct _StreamUnit *streamUnit, struct _Position *pos, int id, int type); // 0x800962BC

extern int PLANAPI_FindClosestNodePositionInUnit(struct _StreamUnit *streamUnit, struct _Position *target, struct _Position *pos, int offset, int max, int type, int distanceCheck); // 0x8009635C


#endif
