#ifndef PLAN_H
#define PLAN_H


extern long PLAN_CalcMinDistFromExistingNodes(struct _Position *pos, struct PlanningNode *planningPool, char distanceType); // 0x80096B14

extern void PLAN_UpdatePlanMkrNodes(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x80096BB4

extern void PLAN_UpdatePlayerNode(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x80096DFC

extern void PLAN_AddRandomNode(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x80096F24

extern void PLAN_DeleteRandomNode(struct PlanningNode *planningPool); // 0x80097130

extern void PLAN_DeleteOutOfRangeNodesOfSource(struct PlanningNode *planningPool, struct _Position *playerPos, char nodeSourceToCheck, long removeDist); // 0x80097164

extern void PLAN_AddOrRemoveRandomNodes(struct PlanningNode *planningPool, struct _Position *playerPos); // 0x8009723C

extern void PLAN_AddInitialNodes(struct PlanningNode *planningPool, struct _Instance *player); // 0x8009728C

extern void PLAN_AddOrRemoveNodes(struct PlanningNode *planningPool, struct _Instance *player); // 0x80097348

extern struct PlanningNode * PLAN_FindNodeMostInNeedOfConnectivityExpansion(struct PlanningNode *planningPool); // 0x80097430


#endif
