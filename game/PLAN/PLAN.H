#ifndef PLAN_H
#define PLAN_H


extern long PLAN_CalcMinDistFromExistingNodes(struct _Position *pos, struct PlanningNode *planningPool, char distanceType); // 0x80094E24

extern void PLAN_UpdatePlanMkrNodes(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x80094EC4

extern void PLAN_UpdatePlayerNode(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x8009510C

extern void PLAN_AddRandomNode(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x80095234

extern void PLAN_DeleteRandomNode(struct PlanningNode *planningPool); // 0x80095440

extern void PLAN_DeleteOutOfRangeNodesOfSource(struct PlanningNode *planningPool, struct _Position *playerPos, char nodeSourceToCheck, long removeDist); // 0x80095474

extern void PLAN_AddOrRemoveRandomNodes(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x8009554C

extern void PLAN_AddInitialNodes(struct PlanningNode *planningPool, struct _Instance *player); // 0x8009559C

extern void PLAN_AddOrRemoveNodes(struct PlanningNode *planningPool, struct _Instance *player); // 0x80095658

extern struct PlanningNode * PLAN_FindNodeMostInNeedOfConnectivityExpansion(struct PlanningNode *planningPool); // 0x80095740


#endif
