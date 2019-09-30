#ifndef INSTANCE_H
#define INSTANCE_H


extern void INSTANCE_Deactivate(struct _Instance *instance); // 0x80031C84

extern void INSTANCE_Reactivate(struct _Instance *instance); // 0x80031D34

extern void INSTANCE_ForceActive(struct _Instance *instance); // 0x80031DCC

extern void INSTANCE_DeactivatedProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80031E00

extern void INSTANCE_DeactivateFarInstances(struct GameTracker *gameTracker); // 0x80031E08

extern void INSTANCE_InitInstanceList(struct _InstanceList *list, struct _InstancePool *pool); // 0x80032074

extern struct _Instance * INSTANCE_NewInstance(struct _InstanceList *list); // 0x80032114

extern long INSTANCE_InstanceGroupNumber(struct _Instance *instance); // 0x800321A0

extern void INSTANCE_InsertInstanceGroup(struct _InstanceList *list, struct _Instance *instance); // 0x800322BC

extern void INSTANCE_ReallyRemoveInstance(struct _InstanceList *list, struct _Instance *instance, long reset); // 0x80032304

extern void INSTANCE_CleanUpInstanceList(struct _InstanceList *list, long reset); // 0x80032574

extern long INSTANCE_Introduced(struct Intro *intro, short streamUnitID); // 0x80032630

extern struct INICommand * INSTANCE_GetIntroCommand(struct INICommand *command, int cmd); // 0x800326E8

extern struct INICommand * INSTANCE_FindIntroCommand(struct _Instance *instance, int cmd); // 0x80032738

extern void INSTANCE_ProcessIntro(struct _Instance *instance); // 0x8003275C

extern void INSTANCE_InitEffects(struct _Instance *instance, struct Object *object); // 0x800327D8

extern struct _Instance * INSTANCE_IntroduceInstance(struct Intro *intro, short streamUnitID); // 0x80032860

extern void INSTANCE_AdditionalCollideFunctions(struct _InstanceList *instanceList); // 0x80032F90

extern long INSTANCE_GetSplineFrameNumber(struct _Instance *instance, struct MultiSpline *spline); // 0x800330BC

extern void INSTANCE_ProcessFunctions(struct _InstanceList *instanceList); // 0x800330F4

extern struct _Instance * INSTANCE_BirthObject(struct _Instance *parent, struct Object *object, int modelNum); // 0x800338D4

extern void INSTANCE_BuildStaticShadow(struct _Instance *instance); // 0x80033B44

extern void INSTANCE_DefaultInit(struct _Instance *instance, struct Object *object, int modelNum); // 0x80033B4C

extern void INSTANCE_PlainDeath(struct _Instance *instance); // 0x80033F04

extern void INSTANCE_KillInstance(struct _Instance *instance); // 0x8003402C

extern unsigned long INSTANCE_Query(struct _Instance *Inst, int Query); // 0x80034060

extern void INSTANCE_Post(struct _Instance *Inst, int Message, int Data); // 0x8003409C

extern void INSTANCE_Broadcast(struct _Instance *sender, long whatAmIMask, int Message, int Data); // 0x80034100

extern int INSTANCE_InPlane(struct _Instance *instance, int plane); // 0x800341AC

extern long INSTANCE_FindWithID(long uniqueID); // 0x80034208

extern struct _Instance * INSTANCE_FindWithName(long areaID, char *instanceName, struct _Instance *startInstance); // 0x80034248

extern struct Intro * INSTANCE_FindIntro(long areaID, long introUniqueID); // 0x8003431C

extern struct _Instance * INSTANCE_Find(long introUniqueID); // 0x800343A0

extern struct _Instance * INSTANCE_IntroduceSavedInstance(struct _SavedIntro *savedIntro, struct _StreamUnit *streamUnit); // 0x800343E0

extern struct _Instance * INSTANCE_IntroduceSavedInstanceWithIntro(struct _SavedIntroWithIntro *savedIntro, struct _StreamUnit *streamUnit); // 0x80034800

extern void INSTANCE_SpatialRelationships(struct _InstanceList *instanceList); // 0x80034C2C

extern int INSTANCE_SetStatsData(struct _Instance *instance, struct _Instance *checkee, struct _Vector *checkPoint, struct evCollideInstanceStatsData *data, struct MATRIX *mat); // 0x80034D90

extern void INSTANCE_LinkToParent(struct _Instance *instance, struct _Instance *parent, int node); // 0x80034EA0

extern void INSTANCE_UnlinkFromParent(struct _Instance *instance); // 0x80034F5C

extern void INSTANCE_UnlinkChildren(struct _Instance *instance); // 0x800350C0

extern void INSTANCE_UpdateFamilyStreamUnitID(struct _Instance *instance); // 0x8003512C

extern struct _Instance * INSTANCE_GetChildLinkedToSegment(struct _Instance *instance, int segment); // 0x80035184

extern int INSTANCE_Linked(struct _Instance *instance1, struct _Instance *instance2); // 0x800351BC

extern int INSTANCE_GetFadeValue(struct _Instance *instance); // 0x8003520C

extern unsigned long INSTANCE_DefaultAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, struct _Instance *instance); // 0x800352F0


#endif
