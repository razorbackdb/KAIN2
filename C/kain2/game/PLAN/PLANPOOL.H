#ifndef PLANPOOL_H
#define PLANPOOL_H


extern int PLANPOOL_NumNodesInPlan(struct PlanningNode *goalNode, struct PlanningNode *planningPool); // 0x800991D4

extern int PLANPOOL_CountBitsSetInLong(long mylong); // 0x80099220

extern int PLANPOOL_NumConnectionsExaminedForNode(struct PlanningNode *node); // 0x80099240

extern int PLANPOOL_NumConnectionsForNode(struct PlanningNode *node); // 0x80099264

extern struct PlanningNode * PLANPOOL_GetFirstNodeOfSource(struct PlanningNode *planningPool, char nodeSource); // 0x80099288

extern int PLANPOOL_NumberOfNodesOfType(struct PlanningNode *planningPool, char nodeType); // 0x800992D8

extern int PLANPOOL_NumberOfNodesOfSource(struct PlanningNode *planningPool, char nodeSource); // 0x80099324

extern struct PlanningNode * PLANPOOL_GetNodeWithID(struct PlanningNode *planningPool, int type, int id, long suID); // 0x80099374

extern struct PlanningNode * PLANPOOL_GetNodeByPosition(struct _Position *currentPos, struct PlanningNode *planningPool); // 0x800993E0

extern struct PlanningNode * PLANPOOL_GetClosestNode(struct _Position *pos, struct PlanningNode *planningPool, char distanceType); // 0x800994B4

extern int PLANPOOL_AppropriatePair(struct PlanningNode *node1, struct PlanningNode *node2); // 0x800995B4

extern int PLANPOOL_AreTwoNodesConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x80099728

extern void PLANPOOL_MarkTwoNodesAsConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x80099798

extern void PLANPOOL_MarkTwoNodesAsNotConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x80099894

extern struct PlanningNode * PLANPOOL_GetClosestUnexploredValidNeighbor(struct PlanningNode *startNode, struct PlanningNode *planningPool); // 0x800998F0

extern void PLANPOOL_ChangeNodePosition(struct _Position *newPos, struct PlanningNode *nodeToChange, struct PlanningNode *planningPool); // 0x80099A00

extern struct PlanningNode * PLANPOOL_AddNodeToPool(struct _Position *pos, struct PlanningNode *planningPool, short nodeType, short nodeID, long streamUnitID); // 0x80099AB8

extern void PLANPOOL_DeleteNodeFromPool(struct PlanningNode *nodeToDelete, struct PlanningNode *planningPool); // 0x80099BAC


#endif
