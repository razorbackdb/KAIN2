#ifndef PHYSICS_H
#define PHYSICS_H

extern void SetNoPtCollideInFamily(struct _Instance *instance);

extern void ResetNoPtCollideInFamily(struct _Instance *instance);

extern void PHYSICS_CheckLineInWorld(struct _Instance *instance, struct _PCollideInfo *pcollideInfo);

extern void PHYSICS_CheckLineInWorldMask(struct _Instance *instance, struct _PCollideInfo *pcollideInfo);

extern int PhysicsCheckLinkedMove(struct _Instance *instance, int Data, short Mode);

extern void PhysicsDefaultLinkedMoveResponse(struct _Instance *instance, struct evPhysicsLinkedMoveData *Data, int updateTransforms);

extern int PhysicsCheckGravity(struct _Instance *instance, int Data, short Mode);

extern void PhysicsDefaultGravityResponse(struct _Instance *instance, struct evPhysicsGravityData *Data);

extern int PhysicsCheckEdgeGrabbing(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode);

extern void PhysicsDefaultEdgeGrabResponse(struct _Instance *instance, struct evPhysicsEdgeData *Data, int blockFlag);

extern int PhysicsCheckSliding(struct _Instance *instance, int Data, short Mode);

extern int PhysicsUpdateTface(struct _Instance *instance, int Data);

extern int PhysicsCheckBlockers(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode);

extern int PhysicsCheckSwim(struct _Instance *instance, int Data, short Mode);

extern int PhysicsDefaultCheckSwimResponse(struct _Instance *instance, struct evPhysicsSwimData *Data);

extern void PhysicsForceSetWater(struct _Instance *instance, int *Time, int Depth, int rate, int maxAmplitude);

extern int PhysicsCheckLOS(struct _Instance *instance, int Data, int Mode);

extern int PhysicsCheckDropHeight(struct _Instance *instance, int Data, int Mode);

extern int PhysicsCheckDropOff(struct _Instance *instance, int Data, short Mode);

extern int PhysicsFollowWall(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode);

extern void PhysicsMoveLocalZClamp(struct _Instance *instance, long segment, long time, long clamp);

extern void PhysicsMove(struct _Instance *instance, struct _Position *position, long time);

extern void PhysicsSetVelFromZRot(struct _Instance *instance, short angle, long magnitude);

extern void PhysicsSetVelFromRot(struct _Instance *instance, struct _Rotation *rot, long magnitude);

extern void PHYSICS_SetVAndAFromRot(struct _Instance *instance, struct _Rotation *rot, long v, long a);

extern long PHYSICS_FindAFromDAndT(long d, long t);

extern long PHYSICS_FindVFromAAndD(long a, long d);

extern void PHYSICS_StopIfCloseToTarget(struct _Instance *instance, int x, int y, int z);

extern int PHYSICS_CheckForTerrainCollide(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment);

extern int PHYSICS_CheckForObjectCollide(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment);

extern int PHYSICS_CheckForValidMove(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment);

extern int PHYSICS_CheckFaceStick(struct _PCollideInfo *CInfo);

extern int PHYSICS_CheckDontGrabEdge(struct _PCollideInfo *CInfo);

extern void PHYSICS_GenericLineCheckSetup(short x, short y, short z, struct SVECTOR *inVec);

extern void PHYSICS_GenericLineCheck(struct _Instance *instance, struct MATRIX *transMat, struct MATRIX *rotMat, struct _PCollideInfo *cInfo);

extern void PHYSICS_GenericLineCheckMask(struct _Instance *instance, struct MATRIX *transMat, struct MATRIX *rotMat, struct _PCollideInfo *cInfo);

#endif
