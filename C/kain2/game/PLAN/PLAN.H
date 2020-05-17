#ifndef PLAN_H
#define PLAN_H


extern long PLAN_CalcMinDistFromExistingNodes(struct _Position *pos, struct PlanningNode *planningPool, int distanceType); // 0x800972C8

extern void PLAN_UpdatePlanMkrNodes(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x80097364

extern void PLAN_UpdatePlayerNode(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x800975B0

extern void PLAN_AddRandomNode(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x80097704

extern void PLAN_DeleteRandomNode(struct PlanningNode *planningPool); // 0x80097910

extern void PLAN_DeleteOutOfRangeNodesOfSource(struct PlanningNode *planningPool, struct _Position *playerPos, int nodeSourceToCheck, long removeDist); // 0x80097944

extern void PLAN_AddOrRemoveRandomNodes(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x80097A1C

extern void PLAN_AddInitialNodes(struct PlanningNode *planningPool, struct _Instance *player); // 0x80097A6C

extern void PLAN_AddOrRemoveNodes(struct PlanningNode *planningPool, struct _Instance *player); // 0x80097B28

extern struct PlanningNode * PLAN_FindNodeMostInNeedOfConnectivityExpansion(struct PlanningNode *planningPool); // 0x80097C10


#endif
