#ifndef INSTANCE_H
#define INSTANCE_H


extern void INSTANCE_Deactivate(struct _Instance *instance); // 0x800321B4

extern void INSTANCE_Reactivate(struct _Instance *instance); // 0x80032270

extern void INSTANCE_ForceActive(struct _Instance *instance); // 0x80032308

extern void INSTANCE_DeactivatedProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8003233C

extern void INSTANCE_DeactivateFarInstances(struct GameTracker *gameTracker); // 0x80032344

extern void INSTANCE_InitInstanceList(struct _InstanceList *list, struct _InstancePool *pool); // 0x800325C0

extern struct _Instance * INSTANCE_NewInstance(struct _InstanceList *list); // 0x80032660

extern long INSTANCE_InstanceGroupNumber(struct _Instance *instance); // 0x800326EC

extern void INSTANCE_InsertInstanceGroup(struct _InstanceList *list, struct _Instance *instance); // 0x80032808

extern void INSTANCE_ReallyRemoveInstance(struct _InstanceList *list, struct _Instance *instance, long reset); // 0x80032850

extern void INSTANCE_CleanUpInstanceList(struct _InstanceList *list, long reset); // 0x80032ABC

extern long INSTANCE_Introduced(struct Intro *intro, short streamUnitID); // 0x80032B78

extern struct INICommand * INSTANCE_GetIntroCommand(struct INICommand *command, int cmd); // 0x80032C30

extern struct INICommand * INSTANCE_FindIntroCommand(struct _Instance *instance, int cmd); // 0x80032C80

extern void INSTANCE_ProcessIntro(struct _Instance *instance); // 0x80032CA4

extern void INSTANCE_InitEffects(struct _Instance *instance, struct Object *object); // 0x80032D20

extern struct _Instance * INSTANCE_IntroduceInstance(struct Intro *intro, short streamUnitID); // 0x80032DA8

extern void INSTANCE_AdditionalCollideFunctions(struct _InstanceList *instanceList); // 0x800334C8

extern long INSTANCE_GetSplineFrameNumber(struct _Instance *instance, struct MultiSpline *spline); // 0x800335F0

extern void INSTANCE_ProcessFunctions(struct _InstanceList *instanceList); // 0x80033628

extern struct _Instance * INSTANCE_BirthObject(struct _Instance *parent, struct Object *object, int modelNum); // 0x80033EB0

extern void INSTANCE_BuildStaticShadow(struct _Instance *instance); // 0x80034120

extern void INSTANCE_DefaultInit(struct _Instance *instance, struct Object *object, int modelNum); // 0x80034128

extern void INSTANCE_PlainDeath(struct _Instance *instance); // 0x800344E4

extern void INSTANCE_KillInstance(struct _Instance *instance); // 0x80034614

extern unsigned long INSTANCE_Query(struct _Instance *Inst, int Query); // 0x80034648

extern void INSTANCE_Post(struct _Instance *Inst, int Message, int Data); // 0x80034684

extern void INSTANCE_Broadcast(struct _Instance *sender, long whatAmIMask, int Message, int Data); // 0x800346E8

extern int INSTANCE_InPlane(struct _Instance *instance, int plane); // 0x80034794

extern long INSTANCE_FindWithID(long uniqueID); // 0x800347F0

extern struct _Instance * INSTANCE_FindWithName(long areaID, char *instanceName, struct _Instance *startInstance); // 0x80034830

extern struct Intro * INSTANCE_FindIntro(long areaID, long introUniqueID); // 0x80034904

extern struct _Instance * INSTANCE_Find(long introUniqueID); // 0x80034988

extern struct _Instance * INSTANCE_IntroduceSavedInstance(struct _SavedIntro *savedIntro, struct _StreamUnit *streamUnit, int *deleted); // 0x800349C8

extern struct _Instance * INSTANCE_IntroduceSavedInstanceWithIntro(struct _SavedIntroWithIntro *savedIntro, struct _StreamUnit *streamUnit, int *deleted); // 0x80034E34

extern void INSTANCE_SpatialRelationships(struct _InstanceList *instanceList); // 0x800352A8

extern int INSTANCE_SetStatsData(struct _Instance *instance, struct _Instance *checkee, struct _Vector *checkPoint, struct evCollideInstanceStatsData *data, struct MATRIX *mat); // 0x8003540C

extern void INSTANCE_LinkToParent(struct _Instance *instance, struct _Instance *parent, int node); // 0x8003551C

extern void INSTANCE_UnlinkFromParent(struct _Instance *instance); // 0x800355D8

extern void INSTANCE_UnlinkChildren(struct _Instance *instance); // 0x8003573C

extern void INSTANCE_UpdateFamilyStreamUnitID(struct _Instance *instance); // 0x800357A8

extern void INSTANCE_ReallyRemoveAllChildren(struct _Instance *instance); // 0x80035800

extern struct _Instance * INSTANCE_GetChildLinkedToSegment(struct _Instance *instance, int segment); // 0x8003585C

extern int INSTANCE_Linked(struct _Instance *instance1, struct _Instance *instance2); // 0x80035894

extern int INSTANCE_GetFadeValue(struct _Instance *instance); // 0x800358E4

extern unsigned long INSTANCE_DefaultAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, struct _Instance *instance); // 0x800359C8


#endif
