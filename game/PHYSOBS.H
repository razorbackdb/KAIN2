#ifndef PHYSOBS_H
#define PHYSOBS_H

extern void PHYSOB_PlayDropSound(struct _Instance *instance);

extern struct _Instance *PHYSOBS_IsAPushBlockAttached(struct _Instance *block);

extern struct _Instance *PHYSOBS_IsAnythingAttached(struct _Instance *block);

extern int CheckPhysOb(struct _Instance *instance);

extern int CheckPhysObAbility(struct _Instance *instance, unsigned short ability);

extern int CheckPhysObFamily(struct _Instance *instance, unsigned short family);

extern int GetPhysicalAbility(struct _Instance *instance);

extern int AnyBlocksInMotion();

extern void ThrowPhysOb(struct _Instance *instance, struct evObjectThrowData *throwData);

extern int PushPhysOb(struct _Instance *instance, short x, short y, short PathNumber, struct _Instance *Force);

extern void ResetSwitchPhysOb(struct _Instance *instance);

extern int SwitchPhysOb(struct _Instance *instance);

extern int InteractPhysOb(struct _Instance *instance, struct _Instance *Force, int LinkNode, int Action);

extern void ResetOrientation(struct _Instance *instance);

extern void FinishPush(struct _Instance *instance);

extern void PhysOb_AlignPush(struct _Instance *instance, int x, int y, int path, struct PhysObData *Data);

extern int FlipPhysOb(struct _Instance *instance, short x, short y, struct _Instance *Force);

extern int CanBePickedUp(struct _Instance *instance, struct _Instance *Force, int LinkNode);

extern int PickUpPhysOb(struct _Instance *instance, short Steps, struct _Instance *Force, int LinkNode);

extern struct _Instance *PHYSOB_BirthCollectible(struct _Instance *parent, int x, int y, int z, int type, int lifeTime);

extern struct evObjectBirthProjectileData *PHYSOB_BirthProjectile(struct _Instance *parent, int joint, int type);

extern struct _Instance *BirthProjectilePhysOb(struct _Instance *instance, int grabJoint, int type);

extern void PHYSOB_SetLightTable(struct _PhysObLight *pLight, struct LightInstance *li, short burnAmplitude);

extern void PHYSOB_EndLighting(struct _Instance *instance, struct _PhysObLight *pLight);

extern void PHYSOB_StartLighting(struct _Instance *instance, struct _PhysObLight *pLight);

extern void PHYSOB_StartBurnFX(struct _Instance *instance);

extern void PHYSOB_StartBurning(struct _Instance *instance, struct _PhysObLight *pLight);

extern void PHYSOB_StopLighting(struct _Instance *instance, struct _PhysObLight *pLight);

extern void PHYSOB_StopBurning(struct _Instance *instance, struct _PhysObLight *pLight);

extern void PHYSOB_EndBurning(struct _Instance *instance, struct _PhysObLight *pLight);

extern void StopPhysOb(struct _Instance *instance);

extern void InitPhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker);

extern void ProcessPhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker);

extern unsigned long PhysicalObjectQuery(struct _Instance *instance, unsigned long Query);

extern void PhysicalObjectPost(struct _Instance *instance, unsigned long Message, unsigned long Data);

extern long PhysobAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data);

extern void CollidePhysicalObject(struct _Instance *instance, struct GameTracker *gameTracker);

extern struct PhysObWeaponAttributes *PhysObGetWeapon(struct _Instance *instance);

extern struct _PhysObLight *PhysObGetLight(struct _Instance *instance);

extern struct PhysObSplinter *PhysObGetSplinter(struct _Instance *instance);

extern void TurnOnCollisionPhysOb(struct _Instance *instance, int coll);

extern void TurnOffCollisionPhysOb(struct _Instance *instance, int coll);

extern int GetPhysObCollisionType(struct _Instance *instance);

extern void ExecuteThrow(struct _Instance *instance);

extern void ExecuteDrag(struct _Instance *instance);

extern void ExecuteSlideToStop(struct _Instance *instance);

extern void ExecuteFlip(struct _Instance *instance);

extern int CheckSlope(int Znormal, int Slope, int Slop);

extern int CheckBlockSlope(struct _Instance *instance, int x, int y, int hOff, int vOff, int dH, int dV);

extern int PHYSOBS_FigureDragForSlope(struct _Instance *instance, int pathNumber, int *result);

extern int PHYSOB_CheckThrownLineCollision(struct _Instance *instance, struct _Instance *parent);

extern int PHYSOB_CheckDroppedLineCollision(struct _Instance *instance, struct _Instance *parent);

extern int PHYSOB_CheckDirectedLineCollision(struct _Instance *instance, int xoffset, int yoffset, int startZOffset);

extern long PHYSOBS_CheckForStackedForwardHits(struct _Instance *block, long xoffset, long yoffset);

extern void PHYSOBS_SetNewAnim(struct _Instance *instance, struct PhysObData *Data, unsigned long modeBits, int path, int resetflg);

extern long PHYSOB_CheckForEnemyInBlkSpot(struct _Instance *instance, int dx, int dy);

extern long PHYSOBS_CheckForValidMove(struct _Instance *instance);

extern void ExecuteGravitate(struct _Instance *instance);

extern void ExecuteFollow(struct _Instance *instance);

extern void PHYSOB_Normalize(struct _SVector *v);

extern int PHYSOB_MoveTowardsAlign(struct _Instance *instance, struct _SVector *orgVec, struct _SVector *endVec);

extern int PHYSOB_ReAlignFalling(struct _Instance *instance, int zEndOff);

extern void DropPhysOb(struct _Instance *instance, int flags);

extern void PhysicalRelocateTune(struct Object *object, long offset);

extern int PHYSOBS_CheckObjectAxisAlignment(struct MATRIX *m0, struct MATRIX *m1, struct _SVector *axis);

extern int PHYSOB_CheckSlide(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data);

extern int PHYSOB_CheckSlide2(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data);

extern int PHYSOB_CheckDropOnSlope(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data);

extern int PHYSOB_CheckSlideNormal(struct _Instance *instance, int x, int y, struct evPhysicsSlideData **data);

extern void PHYSOB_NormalToAxis(short *x, short *y);

#endif
