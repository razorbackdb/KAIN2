#ifndef PLANSRCH_H
#define PLANSRCH_H

extern struct PlanningNode *PLANSRCH_FindNodeToExpand(struct PlanningNode *planningPool, struct PlanningNode *goalNode, int validNodeTypes);

extern void PLANSRCH_ExpandNode(struct PlanningNode *planningPool, struct PlanningNode *nodeToExpand);

extern void PLANSRCH_InitNodesForSearch(struct PlanningNode *planningPool);

extern struct PlanningNode *PLANSRCH_FindPathInGraph(struct PlanningNode *planningPool, struct PlanningNode *startNode, struct PlanningNode *goalNode, int validNodeTypes);

#endif
