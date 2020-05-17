#ifndef PHYSOBS_H
#define PHYSOBS_H


extern void PHYSOB_PlayDropSound(struct _Instance *instance); // 0x80068CA4

extern struct _Instance * PHYSOBS_IsAPushBlockAttached(struct _Instance *block); // 0x80068DC4

extern struct _Instance * PHYSOBS_IsAnythingAttached(struct _Instance *block); // 0x80068E4C

extern int CheckPhysOb(struct _Instance *instance); // 0x80068E94

extern int CheckPhysObAbility(struct _Instance *instance, unsigned short ability); // 0x80068EC0

extern int CheckPhysObFamily(struct _Instance *instance, unsigned short family); // 0x80068F3C

extern int GetPhysicalAbility(struct _Instance *instance); // 0x80068F80

extern int AnyBlocksInMotion(); // 0x80068FD8

extern void SetThrowDirection(struct _Instance *instance, struct _Instance *parent, struct evObjectThrowData *throwData, struct PhysObData *Data); // 0x80069078

extern void ThrowPhysOb(struct _Instance *instance, struct evObjectThrowData *throwData); // 0x80069394

extern int PushPhysOb(struct _Instance *instance, short x, short y, short PathNumber, struct _Instance *Force); // 0x80069774

extern void ResetSwitchPhysOb(struct _Instance *instance); // 0x800698D0

extern int SwitchPhysOb(struct _Instance *instance); // 0x80069968

extern int InteractPhysOb(struct _Instance *instance, struct _Instance *Force, int LinkNode, int Action); // 0x80069B44

extern void ResetOrientation(struct _Instance *instance); // 0x80069EA4

extern void FinishPush(struct _Instance *instance); // 0x8006A3C0

extern void PhysOb_AlignPush(struct _Instance *instance, int x, int y, int path, struct PhysObData *Data); // 0x8006A3E0

extern int FlipPhysOb(struct _Instance *instance, short x, short y, struct _Instance *Force); // 0x8006A550

extern int CanBePickedUp(struct _Instance *instance, struct _Instance *Force, int LinkNode); // 0x8006A694

extern int PickUpPhysOb(struct _Instance *instance, short Steps, struct _Instance *Force, int LinkNode); // 0x8006A82C

extern struct _Instance * PHYSOB_BirthCollectible(struct _Instance *parent, int x, int y, int z, int type, int lifeTime); // 0x8006A92C

extern struct evObjectBirthProjectileData * PHYSOB_BirthProjectile(struct _Instance *parent, int joint, int type); // 0x8006A9DC

extern struct _Instance * BirthProjectilePhysOb(struct _Instance *instance, int grabJoint, int type); // 0x8006AA34

extern void PHYSOB_SetLightTable(struct _PhysObLight *pLight, struct LightInstance *li, short burnAmplitude); // 0x8006AC08

extern void PHYSOB_EndLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006AD70

extern void PHYSOB_StartLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006AD94

extern void PHYSOB_StartBurnFX(struct _Instance *instance); // 0x8006AE00

extern void PHYSOB_StartBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006AE8C

extern void PHYSOB_StopLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006AEC8

extern void PHYSOB_StopBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006AEE8

extern void PHYSOB_EndBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006AF0C

extern void StopPhysOb(struct _Instance *instance); // 0x8006AF6C

extern void InitPhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006AFA8

extern void ProcessPhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006B824

extern unsigned long PhysicalObjectQuery(struct _Instance *instance, unsigned long Query); // 0x8006C458

extern void PhysicalObjectPost(struct _Instance *instance, unsigned long Message, unsigned long Data); // 0x8006C948

extern long PhysobAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x8006D238

extern void CheckForceCollision(struct _Instance *instance, struct _Instance *hitinst, struct _TFace *tface, struct _CollideInfo *collideInfo, struct _SVector *dir, int obliqueFlg); // 0x8006D2DC

extern int GetObliqueDirection(struct _Instance *instance, struct _SVector *dir); // 0x8006D548

extern void CollidePhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006D624

extern struct PhysObWeaponAttributes * PhysObGetWeapon(struct _Instance *instance); // 0x8006DDF8

extern struct _PhysObLight * PhysObGetLight(struct _Instance *instance); // 0x8006DE9C

extern struct PhysObSplinter * PhysObGetSplinter(struct _Instance *instance); // 0x8006DED4

extern void TurnOnCollisionPhysOb(struct _Instance *instance, int coll); // 0x8006DF08

extern void TurnOffCollisionPhysOb(struct _Instance *instance, int coll); // 0x8006DFAC

extern int GetPhysObCollisionType(struct _Instance *instance); // 0x8006E034

extern void ExecuteThrow(struct _Instance *instance); // 0x8006E370

extern void ExecuteDrag(struct _Instance *instance); // 0x8006E480

extern void ExecuteSlideToStop(struct _Instance *instance); // 0x8006E528

extern void ExecuteFlip(struct _Instance *instance); // 0x8006E5E8

extern int CheckSlope(int Znormal, int Slope, int Slop); // 0x8006E6D8

extern int CheckBlockSlope(struct _Instance *instance, int x, int y, int hOff, int vOff, int dH, int dV); // 0x8006E6F8

extern int PHYSOBS_FigureDragForSlope(struct _Instance *instance, int pathNumber, int *result); // 0x8006E7B8

extern int PHYSOB_CheckThrownLineCollision(struct _Instance *instance, struct _Instance *parent); // 0x8006E838

extern int PHYSOB_CheckDroppedLineCollision(struct _Instance *instance, struct _Instance *parent); // 0x8006ED30

extern int PHYSOB_CheckDirectedLineCollision(struct _Instance *instance, int xoffset, int yoffset, int startZOffset); // 0x8006F1EC

extern long PHYSOBS_CheckForStackedForwardHits(struct _Instance *block, long xoffset, long yoffset); // 0x8006F260

extern void PHYSOBS_SetNewAnim(struct _Instance *instance, struct PhysObData *Data, unsigned long modeBits, int path, int resetflg); // 0x8006F2DC

extern long PHYSOB_CheckForEnemyInBlkSpot(struct _Instance *instance, int dx, int dy); // 0x8006F354

extern long PHYSOBS_CheckForValidMove(struct _Instance *instance); // 0x8006F488

extern void ExecuteGravitate(struct _Instance *instance); // 0x8006F9D4

extern void ExecuteFollow(struct _Instance *instance); // 0x8006FD48

extern void PHYSOB_Normalize(struct _SVector *v); // 0x8006FDA0

extern int PHYSOB_MoveTowardsAlign(struct _Instance *instance, struct _SVector *orgVec, struct _SVector *endVec); // 0x8006FE3C

extern int PHYSOB_ReAlignFalling(struct _Instance *instance, int zEndOff); // 0x80070114

extern void DropPhysOb(struct _Instance *instance, int flags); // 0x80070638

extern void PhysicalRelocateTune(struct Object *object, long offset); // 0x80070734

extern int PHYSOBS_CheckObjectAxisAlignment(struct MATRIX *m0, struct MATRIX *m1, struct _SVector *axis); // 0x800708CC

extern int PHYSOB_CheckSlide(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x8007099C

extern int PHYSOB_CheckSlide2(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x80070A2C

extern int PHYSOB_CheckDropOnSlope(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x80070ABC

extern int PHYSOB_CheckSlideNormal(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x80070B50

extern void PHYSOB_NormalToAxis(short *x, short *y); // 0x80070BA4


#endif
