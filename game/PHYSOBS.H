#ifndef PHYSOBS_H
#define PHYSOBS_H


extern void PHYSOB_PlayDropSound(struct _Instance *instance); // 0x80069678

extern struct _Instance * PHYSOBS_IsAPushBlockAttached(struct _Instance *block); // 0x80069798

extern struct _Instance * PHYSOBS_IsAnythingAttached(struct _Instance *block); // 0x80069820

extern int CheckPhysOb(struct _Instance *instance); // 0x80069868

extern int CheckPhysObAbility(struct _Instance *instance, unsigned short ability); // 0x80069894

extern int CheckPhysObFamily(struct _Instance *instance, unsigned short family); // 0x80069910

extern int GetPhysicalAbility(struct _Instance *instance); // 0x80069954

extern void ThrowPhysOb(struct _Instance *instance, struct evObjectThrowData *throwData); // 0x800699AC

extern int PushPhysOb(struct _Instance *instance, short x, short y, short PathNumber, struct _Instance *Force); // 0x80069F28

extern void ResetSwitchPhysOb(struct _Instance *instance); // 0x8006A05C

extern int SwitchPhysOb(struct _Instance *instance); // 0x8006A0F4

extern int InteractPhysOb(struct _Instance *instance, struct _Instance *Force, int LinkNode, int Action); // 0x8006A2D0

extern void ResetOrientation(struct _Instance *instance); // 0x8006A620

extern void FinishPush(struct _Instance *instance); // 0x8006AA1C

extern void PhysOb_AlignPush(struct _Instance *instance, int x, int y, int path, struct PhysObData *Data); // 0x8006AA3C

extern int FlipPhysOb(struct _Instance *instance, short x, short y, struct _Instance *Force); // 0x8006ABAC

extern int PickUpPhysOb(struct _Instance *instance, short Steps, struct _Instance *Force, int LinkNode); // 0x8006ACD0

extern struct _Instance * PHYSOB_BirthCollectible(struct _Instance *parent, int x, int y, int z, int type, int lifeTime); // 0x8006ADD8

extern struct evObjectBirthProjectileData * PHYSOB_BirthProjectile(struct _Instance *parent, int joint, int type); // 0x8006AE88

extern struct _Instance * BirthProjectilePhysOb(struct _Instance *instance, int grabJoint, int type); // 0x8006AEE0

extern void PHYSOB_SetLightTable(struct _PhysObLight *pLight, struct LightInstance *li, short burnAmplitude); // 0x8006B074

extern void PHYSOB_EndLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006B1DC

extern void PHYSOB_StartLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006B200

extern void PHYSOB_StartBurnFX(struct _Instance *instance); // 0x8006B270

extern void PHYSOB_StartBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006B2FC

extern void PHYSOB_StopLighting(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006B338

extern void PHYSOB_StopBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006B358

extern void PHYSOB_EndBurning(struct _Instance *instance, struct _PhysObLight *pLight); // 0x8006B37C

extern void StopPhysOb(struct _Instance *instance); // 0x8006B3DC

extern void InitPhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006B418

extern void ProcessPhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006BAE0

extern unsigned long PhysicalObjectQuery(struct _Instance *instance, unsigned long Query); // 0x8006C528

extern void PhysicalObjectPost(struct _Instance *instance, unsigned long Message, unsigned long Data); // 0x8006C8E8

extern long PhysobAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x8006CF8C

extern void CollidePhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8006D030

extern struct PhysObWeaponAttributes * PhysObGetWeapon(struct _Instance *instance); // 0x8006D9B4

extern struct _PhysObLight * PhysObGetLight(struct _Instance *instance); // 0x8006DA58

extern struct PhysObSplinter * PhysObGetSplinter(struct _Instance *instance); // 0x8006DA90

extern void TurnOnCollisionPhysOb(struct _Instance *instance, int coll); // 0x8006DAC4

extern void TurnOffCollisionPhysOb(struct _Instance *instance, int coll); // 0x8006DB68

extern int GetPhysObCollisionType(struct _Instance *instance); // 0x8006DBF0

extern void ExecuteThrow(struct _Instance *instance); // 0x8006DE94

extern void ExecuteDrag(struct _Instance *instance); // 0x8006DFA4

extern void ExecuteSlideToStop(struct _Instance *instance); // 0x8006E048

extern void ExecuteFlip(struct _Instance *instance); // 0x8006E0D4

extern void ExecuteSlopeSlideToStop(struct _Instance *instance); // 0x8006E190

extern int CheckSlope(int Znormal, int Slope, int Slop); // 0x8006E2A0

extern int CheckBlockSlope(struct _Instance *instance, int x, int y, int hOff, int vOff, int dH, int dV); // 0x8006E2C0

extern int PHYSOBS_FigureDragForSlope(struct _Instance *instance, int pathNumber, int *result); // 0x8006E380

extern int PHYSOB_CheckThrownLineCollision(struct _Instance *instance); // 0x8006E400

extern int PHYSOB_CheckDroppedLineCollision(struct _Instance *instance, struct _Instance *parent); // 0x8006E54C

extern int PHYSOB_CheckDirectedLineCollision(struct _Instance *instance, int xoffset, int yoffset, int startZOffset); // 0x8006E704

extern long PHYSOBS_CheckForStackedForwardHits(struct _Instance *block, long xoffset, long yoffset); // 0x8006E778

extern void PHYSOBS_SetNewAnim(struct _Instance *instance, struct PhysObData *Data, unsigned long modeBits, int path, int resetflg); // 0x8006E7F4

extern long PHYSOB_CheckForEnemyInBlkSpot(struct _Instance *instance, int dx, int dy); // 0x8006E86C

extern long PHYSOBS_CheckForValidMove(struct _Instance *instance); // 0x8006E938

extern void ExecuteGravitate(struct _Instance *instance); // 0x8006EF5C

extern void ExecuteFollow(struct _Instance *instance); // 0x8006F2D0

extern void PHYSOB_Normalize(struct _SVector *v); // 0x8006F328

extern int PHYSOB_MoveTowardsAlign(struct _Instance *instance, struct _SVector *orgVec, struct _SVector *endVec); // 0x8006F3C4

extern int PHYSOB_ReAlignFalling(struct _Instance *instance, int zEndOff); // 0x8006F69C

extern void DropPhysOb(struct _Instance *instance); // 0x8006FACC

extern void PhysicalRelocateTune(struct Object *object, long offset); // 0x8006FB8C

extern int PHYSOBS_CheckObjectAxisAlignment(struct MATRIX *m0, struct MATRIX *m1, struct _SVector *axis); // 0x8006FCF4

extern int PHYSOB_CheckSlide(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x8006FDC4

extern int PHYSOB_CheckSlide2(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x8006FE54

extern int PHYSOB_CheckSlideNormal(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data); // 0x8006FEE4

extern void PHYSOB_NormalToAxis(short *x, short *y); // 0x8006FF38


#endif
