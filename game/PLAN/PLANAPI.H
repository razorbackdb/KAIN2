#ifndef PLANAPI_H
#define PLANAPI_H


extern void PLANAPI_ConvertPlanIntoEnmyPlanDataFormat(struct PlanningNode *goalNode, struct EnemyPlanData *planData, struct PlanningNode *planningPool); // 0x800974EC

extern int PLANAPI_FindPathBetweenNodes(struct PlanningNode *startNode, struct PlanningNode *goalNode, struct EnemyPlanData *planData, int validNodeTypes); // 0x800975A0

extern void PLANAPI_DoTimingCalcsAndDrawing(long startTime, struct PlanningNode *planningPool); // 0x80097628

extern int PLANAPI_AddNodeOfTypeToPool(struct _Position *pos, int type); // 0x80097748

extern void PLANAPI_DeleteNodesFromPoolByType(int nodeSource); // 0x80097828

extern void PLANAPI_DeleteNodeFromPoolByUnit(long streamUnitID); // 0x800978C4

extern int PLANAPI_FindPathInGraphToTarget(struct _Position *startPos, struct EnemyPlanData *planData, int validNodeTypes); // 0x8009795C

extern void PLANAPI_InitPlanning(void *planningPool); // 0x800979C0

extern short PLANAPI_PairType(struct PlanningNode *node1, struct PlanningNode *node2); // 0x80097A48

extern int PLANAPI_PassThroughHit(struct PlanningNode *node1, struct PlanningNode *node2); // 0x80097A90

extern void PLANAPI_UpdatePlanningDatabase(struct GameTracker *gameTracker, struct _Instance *player); // 0x80097AFC

extern int PLANAPI_NumNodesInPool(void *planningPool); // 0x80097E28

extern void PLANAPI_InitPlanMkrList(struct _StreamUnit *streamUnit); // 0x80097E3C

extern int PLANAPI_GetFlags(int type); // 0x80097F60

extern int PLANAPI_FindNodePositionInUnit(struct _StreamUnit *streamUnit, struct _Position *pos, int id, int type); // 0x80097FC8

extern int PLANAPI_FindClosestNodePositionInUnit(struct _StreamUnit *streamUnit, struct _Position *target, struct _Position *pos, int offset, int max, int type, int distanceCheck); // 0x8009806C


#endif
