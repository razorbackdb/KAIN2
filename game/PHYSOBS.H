#ifndef PHYSOBS_H
#define PHYSOBS_H


extern void PHYSOB_PlayDropSound(struct _Instance *instance); // 0x80068D0C

extern struct _Instance * PHYSOBS_IsAPushBlockAttached(struct _Instance *block); // 0x80068E2C

extern struct _Instance * PHYSOBS_IsAnythingAttached(struct _Instance *block); // 0x80068EB4

extern int CheckPhysOb(struct _Instance *instance); // 0x80068EFC

extern int CheckPhysObAbility(struct _Instance *instance, unsigned short ability); // 0x80068F28

extern int CheckPhysObFamily(struct _Instance *instance, unsigned short family); // 0x80068FA4

extern int GetPhysicalAbility(struct _Instance *instance); // 0x80068FE8

extern int AnyBlocksInMotion(); // 0x80069040

extern void ThrowPhysOb(struct _Instance *instance, struct evObjectThrowData *throwData); // 0x800690E0

extern int PushPhysOb(struct _Instance *instance, short x, short y, short PathNumber, struct _Instance *Force); // 0x8006972C

extern void ResetSwitchPhysOb(struct _Instance *instance); // 0x80069888

extern int SwitchPhysOb(struct _Instance *instance); // 0x80069920

extern int InteractPhysOb(struct _Instance *instance, struct _Instance *Force, int LinkNode, int Action); // 0x80069AFC

extern void ResetOrientation(struct _Instance *instance); // 0x80069E4C

extern void FinishPush(struct _Instance *instance); // 0x8006A368

extern void PhysOb_AlignPush(struct _Instance *instance, int x, int y, int path, struct PhysObData *Data); // 0x8006A388

extern int FlipPhysOb(struct _Instance *instance, short x, short y, struct _Instance *Force); // 0x8006A4F8

extern int CanBePickedUp(struct _Instance *instance, struct _Instance *Force, int LinkNode); // 0x8006A63C

extern int PickUpPhysOb(struct _Instance *instance, short Steps, struct _Instance *Force, int LinkNode); // 0x8006A7D4

extern struct _Instance * PHYSOB_BirthCollectible(struct _Instance *parent, int x, int y, int z, int type, int lifeTime); // 0x8006A8D4

extern struct evObjectBirthProjectileData * PHYSOB_BirthProjectile(struct _Instance *parent, int joint, int type); // 0x8006A984

extern struct _Instance * BirthProjectilePhysOb(struct _Instance *instance, int grabJoint, int type); // 0x8006A9DC

extern void PHYSOB_SetLightTable(struct _PhysObLight *pLight, struct LightInstance *li, short burnAmplitude); // 0x8006AB70

extern void PHYSOB_EndLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006ACD8

extern void PHYSOB_StartLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006ACFC

extern void PHYSOB_StartBurnFX(struct _Instance *instance); // 0x8006AD6C

extern void PHYSOB_StartBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006ADF8

extern void PHYSOB_StopLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006AE34

extern void PHYSOB_StopBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006AE54

extern void PHYSOB_EndBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006AE78

extern void StopPhysOb(struct _Instance *instance); // 0x8006AED8

extern void InitPhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006AF14

extern void ProcessPhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006B748

extern unsigned long PhysicalObjectQuery(struct _Instance *instance, unsigned long Query); // 0x8006C33C

extern void PhysicalObjectPost(struct _Instance *instance, unsigned long Message, unsigned long Data); // 0x8006C7D4

extern long PhysobAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x8006CF68

extern void CollidePhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006D00C

extern struct PhysObWeaponAttributes * PhysObGetWeapon(struct _Instance *instance); // 0x8006DA0C

extern struct _PhysObLight * PhysObGetLight(struct _Instance *instance); // 0x8006DAB0

extern struct PhysObSplinter * PhysObGetSplinter(struct _Instance *instance); // 0x8006DAE8

extern void TurnOnCollisionPhysOb(struct _Instance *instance, int coll); // 0x8006DB1C

extern void TurnOffCollisionPhysOb(struct _Instance *instance, int coll); // 0x8006DBC0

extern int GetPhysObCollisionType(struct _Instance *instance); // 0x8006DC48

extern void ExecuteThrow(struct _Instance *instance); // 0x8006DEF4

extern void ExecuteDrag(struct _Instance *instance); // 0x8006E004

extern void ExecuteSlideToStop(struct _Instance *instance); // 0x8006E0AC

extern void ExecuteFlip(struct _Instance *instance); // 0x8006E138

extern int CheckSlope(int Znormal, int Slope, int Slop); // 0x8006E1F8

extern int CheckBlockSlope(struct _Instance *instance, int x, int y, int hOff, int vOff, int dH, int dV); // 0x8006E218

extern int PHYSOBS_FigureDragForSlope(struct _Instance *instance, int pathNumber, int *result); // 0x8006E2D8

extern int PHYSOB_CheckThrownLineCollision(struct _Instance *instance, struct _Instance *parent); // 0x8006E358

extern int PHYSOB_CheckDroppedLineCollision(struct _Instance *instance, struct _Instance *parent); // 0x8006E628

extern int PHYSOB_CheckDirectedLineCollision(struct _Instance *instance, int xoffset, int yoffset, int startZOffset); // 0x8006EA24

extern long PHYSOBS_CheckForStackedForwardHits(struct _Instance *block, long xoffset, long yoffset); // 0x8006EA98

extern void PHYSOBS_SetNewAnim(struct _Instance *instance, struct PhysObData *Data, unsigned long modeBits, int path, int resetflg); // 0x8006EB14

extern long PHYSOB_CheckForEnemyInBlkSpot(struct _Instance *instance, int dx, int dy); // 0x8006EB8C

extern long PHYSOBS_CheckForValidMove(struct _Instance *instance); // 0x8006ECC0

extern void ExecuteGravitate(struct _Instance *instance); // 0x8006F20C

extern void ExecuteFollow(struct _Instance *instance); // 0x8006F580

extern void PHYSOB_Normalize(struct _SVector *v); // 0x8006F5D8

extern int PHYSOB_MoveTowardsAlign(struct _Instance *instance, struct _SVector *orgVec, struct _SVector *endVec); // 0x8006F674

extern int PHYSOB_ReAlignFalling(struct _Instance *instance, int zEndOff); // 0x8006F94C

extern void DropPhysOb(struct _Instance *instance, int flags); // 0x8006FEE0

extern void PhysicalRelocateTune(struct Object *object, long offset); // 0x8006FFDC

extern int PHYSOBS_CheckObjectAxisAlignment(struct MATRIX *m0, struct MATRIX *m1, struct _SVector *axis); // 0x80070174

extern int PHYSOB_CheckSlide(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x80070244

extern int PHYSOB_CheckSlide2(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x800702D4

extern int PHYSOB_CheckDropOnSlope(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x80070364

extern int PHYSOB_CheckSlideNormal(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x800703F8

extern void PHYSOB_NormalToAxis(short *x, short *y); // 0x8007044C


#endif
