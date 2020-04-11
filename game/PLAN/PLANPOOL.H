#ifndef PLANPOOL_H
#define PLANPOOL_H


extern int PLANPOOL_NumNodesInPlan(struct PlanningNode *goalNode, struct PlanningNode *planningPool); // 0x800988F4

extern int PLANPOOL_CountBitsSetInLong(long mylong); // 0x80098940

extern int PLANPOOL_NumConnectionsExaminedForNode(struct PlanningNode *node); // 0x80098960

extern int PLANPOOL_NumConnectionsForNode(struct PlanningNode *node); // 0x80098984

extern struct PlanningNode * PLANPOOL_GetFirstNodeOfSource(struct PlanningNode *planningPool, char nodeSource); // 0x800989A8

extern int PLANPOOL_NumberOfNodesOfType(struct PlanningNode *planningPool, char nodeType); // 0x800989F8

extern int PLANPOOL_NumberOfNodesOfSource(struct PlanningNode *planningPool, char nodeSource); // 0x80098A44

extern struct PlanningNode * PLANPOOL_GetNodeWithID(struct PlanningNode *planningPool, short type, short id); // 0x80098A94

extern struct PlanningNode * PLANPOOL_GetNodeByPosition(struct _Position *currentPos, struct PlanningNode *planningPool); // 0x80098B00

extern struct PlanningNode * PLANPOOL_GetClosestNode(struct _Position *pos, struct PlanningNode *planningPool, char distanceType); // 0x80098BD4

extern int PLANPOOL_AppropriatePair(struct PlanningNode *node1, struct PlanningNode *node2); // 0x80098CD4

extern int PLANPOOL_AreTwoNodesConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x80098E48

extern void PLANPOOL_MarkTwoNodesAsConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x80098EB8

extern void PLANPOOL_MarkTwoNodesAsNotConnected(struct PlanningNode *node1, struct PlanningNode *node2, struct PlanningNode *planningPool); // 0x80098FFC

extern struct PlanningNode * PLANPOOL_GetClosestUnexploredValidNeighbor(struct PlanningNode *startNode, struct PlanningNode *planningPool); // 0x800990AC

extern void PLANPOOL_ChangeNodePosition(struct _Position *newPos, struct PlanningNode *nodeToChange, struct PlanningNode *planningPool); // 0x800991BC

extern struct PlanningNode * PLANPOOL_AddNodeToPool(struct _Position *pos, struct PlanningNode *planningPool, short nodeType, short nodeID, long streamUnitID); // 0x80099274

extern void PLANPOOL_DeleteNodeFromPool(struct PlanningNode *nodeToDelete, struct PlanningNode *planningPool); // 0x80099368


#endif
