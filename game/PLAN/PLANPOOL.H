#ifndef PLANPOOL_H
#define PLANPOOL_H

extern int PLANPOOL_NumNodesInPlan(struct PlanningNode *goalNode, struct PlanningNode *planningPool);

extern int PLANPOOL_CountBitsSetInLong(long mylong);

extern int PLANPOOL_NumConnectionsExaminedForNode(struct PlanningNode *node);

extern int PLANPOOL_NumConnectionsForNode(struct PlanningNode *node);

extern struct PlanningNode *PLANPOOL_GetFirstNodeOfSource(struct PlanningNode *planningPool, char nodeSource);

extern int PLANPOOL_NumberOfNodesOfType(struct PlanningNode *planningPool, char nodeType);

extern int PLANPOOL_NumberOfNodesOfSource(struct PlanningNode *planningPool, char nodeSource);

extern struct PlanningNode *PLANPOOL_GetNodeWithID(struct PlanningNode *planningPool, short type, short id);

extern struct PlanningNode *PLANPOOL_GetNodeByPosition(struct _Position *currentPos, struct PlanningNode *planningPool);

extern struct PlanningNode *PLANPOOL_GetClosestNode(struct _Position *pos, struct PlanningNode *planningPool, char distanceType);

extern int PLANPOOL_AppropriatePair(struct PlanningNode *node1, struct PlanningNode *node2);

extern int PLANPOOL_AreTwoNodesConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool);

extern void PLANPOOL_MarkTwoNodesAsConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool);

extern void PLANPOOL_MarkTwoNodesAsNotConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool);

extern struct PlanningNode *PLANPOOL_GetClosestUnexploredValidNeighbor(struct PlanningNode *startNode, struct PlanningNode *planningPool);

extern void PLANPOOL_ChangeNodePosition(struct _Position *newPos, struct PlanningNode *nodeToChange, struct PlanningNode *planningPool);

extern struct PlanningNode *PLANPOOL_AddNodeToPool(struct _Position *pos, struct PlanningNode *planningPool, short nodeType, short nodeID, long streamUnitID);

extern void PLANPOOL_DeleteNodeFromPool(struct PlanningNode *nodeToDelete, struct PlanningNode *planningPool);

#endif
