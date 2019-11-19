#ifndef PHYSICS_H
#define PHYSICS_H


extern void SetNoPtCollideInFamily(struct _Instance *instance); // 0x80073E14

extern void ResetNoPtCollideInFamily(struct _Instance *instance); // 0x80073E5C

extern void PHYSICS_CheckLineInWorld(struct _Instance *instance, struct _PCollideInfo *pcollideInfo); // 0x80073EA8

extern void PHYSICS_CheckLineInWorldMask(struct _Instance *instance, struct _PCollideInfo *pcollideInfo); // 0x80073ECC

extern int PhysicsCheckLinkedMove(struct _Instance *instance, int Data, short Mode); // 0x80073F48

extern void PhysicsDefaultLinkedMoveResponse(struct _Instance *instance, struct evPhysicsLinkedMoveData *Data, int updateTransforms); // 0x80074324

extern int PhysicsCheckGravity(struct _Instance *instance, int Data, short Mode); // 0x800743AC

extern void PhysicsDefaultGravityResponse(struct _Instance *instance, struct evPhysicsGravityData *Data); // 0x80074AD4

extern int PhysicsCheckEdgeGrabbing(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x80074B4C

extern void PhysicsDefaultEdgeGrabResponse(struct _Instance *instance, struct evPhysicsEdgeData *Data, int blockFlag); // 0x800751E0

extern int PhysicsCheckSliding(struct _Instance *instance, int Data, short Mode); // 0x80075480

extern int PhysicsUpdateTface(struct _Instance *instance, int Data); // 0x8007592C

extern int PhysicsCheckBlockers(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x80075A28

extern int PhysicsCheckSwim(struct _Instance *instance, int Data, short Mode); // 0x80075DE0

extern int PhysicsDefaultCheckSwimResponse(struct _Instance *instance, struct evPhysicsSwimData *Data); // 0x80075FD0

extern int PhysicsCheckPullOutOfWater(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x800761C8

extern void PhysicsDefaultPullOutResponse(struct _Instance *instance, struct evPhysicsEdgeData *Data); // 0x80076480

extern void PhysicsForceSetWater(struct _Instance *instance, int *Time, int Depth, int rate, int maxAmplitude); // 0x800766BC

extern int PhysicsCheckLOS(struct _Instance *instance, int Data, int Mode); // 0x80076794

extern int PhysicsCheckDropHeight(struct _Instance *instance, int Data, int Mode); // 0x800767C4

extern int PhysicsCheckDropOff(struct _Instance *instance, int Data, short Mode); // 0x80076A58

extern int PhysicsFollowWall(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x80076C4C

extern void PhysicsMoveLocalZClamp(struct _Instance *instance, long segment, long time, long clamp); // 0x800770B8

extern void PhysicsMove(struct _Instance *instance, struct _Position *position, long time); // 0x80077190

extern void PhysicsSetVelFromZRot(struct _Instance *instance, short angle, long magnitude); // 0x8007732C

extern void PhysicsSetVelFromRot(struct _Instance *instance, struct _Rotation *rot, long magnitude); // 0x8007739C

extern void PHYSICS_SetVAndAFromRot(struct _Instance *instance, struct _Rotation *rot, long v, long a); // 0x8007740C

extern long PHYSICS_FindAFromDAndT(long d, long t); // 0x800774FC

extern long PHYSICS_FindVFromAAndD(long a, long d); // 0x80077538

extern void PHYSICS_StopIfCloseToTarget(struct _Instance *instance, int x, int y, int z); // 0x80077570

extern int PHYSICS_CheckForTerrainCollide(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment); // 0x80077650

extern int PHYSICS_CheckForValidMove(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment); // 0x8007769C

extern int PHYSICS_CheckFaceStick(struct _PCollideInfo *CInfo); // 0x8007770C

extern int PHYSICS_CheckDontGrabEdge(struct _PCollideInfo *CInfo); // 0x80077770

extern void PHYSICS_GenericLineCheckSetup(short x, short y, short z, struct SVECTOR *inVec); // 0x800777FC

extern void PHYSICS_GenericLineCheck(struct _Instance *instance, struct MATRIX *transMat, struct MATRIX *rotMat, struct _PCollideInfo *cInfo); // 0x8007780C

extern void PHYSICS_GenericLineCheckMask(struct _Instance *instance, struct MATRIX *transMat, struct MATRIX *rotMat, struct _PCollideInfo *cInfo); // 0x80077830


#endif
