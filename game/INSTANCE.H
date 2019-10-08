#ifndef INSTANCE_H
#define INSTANCE_H

extern void INSTANCE_Deactivate(struct _Instance *instance);

extern void INSTANCE_Reactivate(struct _Instance *instance);

extern void INSTANCE_ForceActive(struct _Instance *instance);

extern void INSTANCE_DeactivatedProcess(struct _Instance *instance, struct GameTracker *gameTracker);

extern void INSTANCE_DeactivateFarInstances(struct GameTracker *gameTracker);

extern void INSTANCE_InitInstanceList(struct _InstanceList *list, struct _InstancePool *pool);

extern struct _Instance *INSTANCE_NewInstance(struct _InstanceList *list);

extern long INSTANCE_InstanceGroupNumber(struct _Instance *instance);

extern void INSTANCE_InsertInstanceGroup(struct _InstanceList *list, struct _Instance *instance);

extern void INSTANCE_ReallyRemoveInstance(struct _InstanceList *list, struct _Instance *instance, long reset);

extern void INSTANCE_CleanUpInstanceList(struct _InstanceList *list, long reset);

extern long INSTANCE_Introduced(struct Intro *intro, short streamUnitID);

extern struct INICommand *INSTANCE_GetIntroCommand(struct INICommand *command, int cmd);

extern struct INICommand *INSTANCE_FindIntroCommand(struct _Instance *instance, int cmd);

extern void INSTANCE_ProcessIntro(struct _Instance *instance);

extern void INSTANCE_InitEffects(struct _Instance *instance, struct Object *object);

extern struct _Instance *INSTANCE_IntroduceInstance(struct Intro *intro, short streamUnitID);

extern void INSTANCE_AdditionalCollideFunctions(struct _InstanceList *instanceList);

extern long INSTANCE_GetSplineFrameNumber(struct _Instance *instance, struct MultiSpline *spline);

extern void INSTANCE_ProcessFunctions(struct _InstanceList *instanceList);

extern struct _Instance *INSTANCE_BirthObject(struct _Instance *parent, struct Object *object, int modelNum);

extern void INSTANCE_BuildStaticShadow(struct _Instance *instance);

extern void INSTANCE_DefaultInit(struct _Instance *instance, struct Object *object, int modelNum);

extern void INSTANCE_PlainDeath(struct _Instance *instance);

extern void INSTANCE_KillInstance(struct _Instance *instance);

extern unsigned long INSTANCE_Query(struct _Instance *Inst, int Query);

extern void INSTANCE_Post(struct _Instance *Inst, int Message, int Data);

extern void INSTANCE_Broadcast(struct _Instance *sender, long whatAmIMask, int Message, int Data);

extern int INSTANCE_InPlane(struct _Instance *instance, int plane);

extern long INSTANCE_FindWithID(long uniqueID);

extern struct _Instance *INSTANCE_FindWithName(long areaID, char *instanceName, struct _Instance *startInstance);

extern struct Intro *INSTANCE_FindIntro(long areaID, long introUniqueID);

extern struct _Instance *INSTANCE_Find(long introUniqueID);

extern struct _Instance *INSTANCE_IntroduceSavedInstance(struct _SavedIntro *savedIntro, struct _StreamUnit *streamUnit);

extern struct _Instance *INSTANCE_IntroduceSavedInstanceWithIntro(struct _SavedIntroWithIntro *savedIntro, struct _StreamUnit *streamUnit);

extern void INSTANCE_SpatialRelationships(struct _InstanceList *instanceList);

extern int INSTANCE_SetStatsData(struct _Instance *instance, struct _Instance *checkee, struct _Vector *checkPoint, struct evCollideInstanceStatsData *data, struct MATRIX *mat);

extern void INSTANCE_LinkToParent(struct _Instance *instance, struct _Instance *parent, int node);

extern void INSTANCE_UnlinkFromParent(struct _Instance *instance);

extern void INSTANCE_UnlinkChildren(struct _Instance *instance);

extern void INSTANCE_UpdateFamilyStreamUnitID(struct _Instance *instance);

extern struct _Instance *INSTANCE_GetChildLinkedToSegment(struct _Instance *instance, int segment);

extern int INSTANCE_Linked(struct _Instance *instance1, struct _Instance *instance2);

extern int INSTANCE_GetFadeValue(struct _Instance *instance);

extern unsigned long INSTANCE_DefaultAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, struct _Instance *instance);

#endif
