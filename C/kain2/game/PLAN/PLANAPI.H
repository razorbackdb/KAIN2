#ifndef PLANAPI_H
#define PLANAPI_H


extern void PLANAPI_ConvertPlanIntoEnmyPlanDataFormat(struct PlanningNode *goalNode, struct EnemyPlanData *planData, struct PlanningNode *planningPool); // 0x80097CCC

extern int PLANAPI_FindPathBetweenNodes(struct PlanningNode *startNode, struct PlanningNode *goalNode, struct EnemyPlanData *planData, int validNodeTypes); // 0x80097D80

extern void PLANAPI_DoTimingCalcsAndDrawing(long startTime, struct PlanningNode *planningPool); // 0x80097E08

extern int PLANAPI_AddNodeOfTypeToPool(struct _Position *pos, int type); // 0x80097F24

extern void PLANAPI_DeleteNodesFromPoolByType(int nodeSource); // 0x80098004

extern void PLANAPI_DeleteNodeFromPoolByUnit(long streamUnitID); // 0x800980A0

extern int PLANAPI_FindPathInGraphToTarget(struct _Position *startPos, struct EnemyPlanData *planData, int validNodeTypes); // 0x80098138

extern void PLANAPI_InitPlanning(void *planningPool); // 0x8009819C

extern short PLANAPI_PairType(struct PlanningNode *node1, struct PlanningNode *node2); // 0x8009821C

extern int PLANAPI_PassThroughHit(struct PlanningNode *node1, struct PlanningNode *node2); // 0x80098264

extern void PLANAPI_UpdatePlanningDatabase(struct GameTracker *gameTracker, struct _Instance *player); // 0x800982D0

extern int PLANAPI_NumNodesInPool(void *planningPool); // 0x80098718

extern void PLANAPI_InitPlanMkrList(struct _StreamUnit *streamUnit); // 0x8009872C

extern int PLANAPI_GetFlags(int type); // 0x80098850

extern int PLANAPI_FindNodePositionInUnit(struct _StreamUnit *streamUnit, struct _Position *pos, int id, int type); // 0x800988B8

extern int PLANAPI_FindClosestNodePositionInUnit(struct _StreamUnit *streamUnit, struct _Position *target, struct _Position *pos, int offset, int max, int type, int distanceCheck); // 0x8009895C


#endif
