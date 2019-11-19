#ifndef PLANSRCH_H
#define PLANSRCH_H


extern struct PlanningNode * PLANSRCH_FindNodeToExpand(struct PlanningNode *planningPool, struct PlanningNode *goalNode, int validNodeTypes); // 0x80097824

extern void PLANSRCH_ExpandNode(struct PlanningNode *planningPool, struct PlanningNode *nodeToExpand); // 0x8009793C

extern void PLANSRCH_InitNodesForSearch(struct PlanningNode *planningPool); // 0x80097A6C

extern struct PlanningNode * PLANSRCH_FindPathInGraph(struct PlanningNode *planningPool, struct PlanningNode *startNode, struct PlanningNode *goalNode, int validNodeTypes); // 0x80097AB8


#endif
