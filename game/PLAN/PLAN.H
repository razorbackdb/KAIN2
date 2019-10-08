#ifndef PLAN_H
#define PLAN_H

extern long PLAN_CalcMinDistFromExistingNodes(struct _Position *pos, struct PlanningNode *planningPool, char distanceType);

extern void PLAN_UpdatePlanMkrNodes(struct PlanningNode *planningPool, struct _Position *playerPos);

extern void PLAN_UpdatePlayerNode(struct PlanningNode *planningPool, struct _Position *playerPos);

extern void PLAN_AddRandomNode(struct PlanningNode *planningPool, struct _Position *playerPos);

extern void PLAN_DeleteRandomNode(struct PlanningNode *planningPool);

extern void PLAN_DeleteOutOfRangeNodesOfSource(struct PlanningNode *planningPool, struct _Position *playerPos, char nodeSourceToCheck, long removeDist);

extern void PLAN_AddOrRemoveRandomNodes(struct PlanningNode *planningPool, struct _Position *playerPos);

extern void PLAN_AddInitialNodes(struct PlanningNode *planningPool, struct _Instance *player);

extern void PLAN_AddOrRemoveNodes(struct PlanningNode *planningPool, struct _Instance *player);

extern struct PlanningNode *PLAN_FindNodeMostInNeedOfConnectivityExpansion(struct PlanningNode *planningPool);

#endif
