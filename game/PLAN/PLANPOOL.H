#ifndef PLANPOOL_H
#define PLANPOOL_H


extern int PLANPOOL_NumNodesInPlan(struct PlanningNode *goalNode, struct PlanningNode *planningPool); // 0x80096BE4

extern int PLANPOOL_CountBitsSetInLong(long mylong); // 0x80096C30

extern int PLANPOOL_NumConnectionsExaminedForNode(struct PlanningNode *node); // 0x80096C50

extern int PLANPOOL_NumConnectionsForNode(struct PlanningNode *node); // 0x80096C74

extern struct PlanningNode * PLANPOOL_GetFirstNodeOfSource(struct PlanningNode *planningPool, char nodeSource); // 0x80096C98

extern int PLANPOOL_NumberOfNodesOfType(struct PlanningNode *planningPool, char nodeType); // 0x80096CE8

extern int PLANPOOL_NumberOfNodesOfSource(struct PlanningNode *planningPool, char nodeSource); // 0x80096D34

extern struct PlanningNode * PLANPOOL_GetNodeWithID(struct PlanningNode *planningPool, short type, short id); // 0x80096D84

extern struct PlanningNode * PLANPOOL_GetNodeByPosition(struct _Position *currentPos, struct PlanningNode *planningPool); // 0x80096DF0

extern struct PlanningNode * PLANPOOL_GetClosestNode(struct _Position *pos, struct PlanningNode *planningPool, char distanceType); // 0x80096EC4

extern int PLANPOOL_AppropriatePair(struct PlanningNode *node1, struct PlanningNode *node2); // 0x80096FC4

extern int PLANPOOL_AreTwoNodesConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x80097138

extern void PLANPOOL_MarkTwoNodesAsConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x800971A8

extern void PLANPOOL_MarkTwoNodesAsNotConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x800972EC

extern struct PlanningNode * PLANPOOL_GetClosestUnexploredValidNeighbor(struct PlanningNode *startNode, struct PlanningNode *planningPool); // 0x8009739C

extern void PLANPOOL_ChangeNodePosition(struct _Position *newPos, struct PlanningNode *nodeToChange, struct PlanningNode *planningPool); // 0x800974AC

extern struct PlanningNode * PLANPOOL_AddNodeToPool(struct _Position *pos, struct PlanningNode *planningPool, short nodeType, short nodeID, long streamUnitID); // 0x80097564

extern void PLANPOOL_DeleteNodeFromPool(struct PlanningNode *nodeToDelete, struct PlanningNode *planningPool); // 0x80097658


#endif
