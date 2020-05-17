#ifndef PLANSRCH_H
#define PLANSRCH_H


extern struct PlanningNode * PLANSRCH_FindNodeToExpand(struct PlanningNode *planningPool, struct PlanningNode *goalNode, int validNodeTypes); // 0x80099D78

extern void PLANSRCH_ExpandNode(struct PlanningNode *planningPool, struct PlanningNode *nodeToExpand); // 0x80099E90

extern void PLANSRCH_InitNodesForSearch(struct PlanningNode *planningPool); // 0x80099FB4

extern struct PlanningNode * PLANSRCH_FindPathInGraph(struct PlanningNode *planningPool, struct PlanningNode *startNode, struct PlanningNode *goalNode, int validNodeTypes); // 0x8009A000


#endif
