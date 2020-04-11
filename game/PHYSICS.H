#ifndef PHYSICS_H
#define PHYSICS_H


extern void SetNoPtCollideInFamily(struct _Instance *instance); // 0x80074100

extern void ResetNoPtCollideInFamily(struct _Instance *instance); // 0x80074148

extern void PHYSICS_CheckLineInWorld(struct _Instance *instance, struct _PCollideInfo *pcollideInfo); // 0x80074194

extern void PHYSICS_CheckLineInWorldMask(struct _Instance *instance, struct _PCollideInfo *pcollideInfo); // 0x800741B8

extern int PhysicsCheckLinkedMove(struct _Instance *instance, int Data, short Mode); // 0x8007422C

extern void PhysicsDefaultLinkedMoveResponse(struct _Instance *instance, struct evPhysicsLinkedMoveData *Data, int updateTransforms); // 0x80074688

extern int PhysicsCheckGravity(struct _Instance *instance, int Data, short Mode); // 0x80074710

extern void PhysicsDefaultGravityResponse(struct _Instance *instance, struct evPhysicsGravityData *Data); // 0x80074E90

extern int PhysicsCheckEdgeGrabbing(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x80074F08

extern void PhysicsDefaultEdgeGrabResponse(struct _Instance *instance, struct evPhysicsEdgeData *Data, int blockFlag); // 0x8007559C

extern int PhysicsCheckSliding(struct _Instance *instance, int Data, short Mode); // 0x80075840

extern int PhysicsUpdateTface(struct _Instance *instance, int Data); // 0x80075CEC

extern int PhysicsCheckBlockers(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x80075DE8

extern int PhysicsCheckSwim(struct _Instance *instance, int Data, short Mode); // 0x80076188

extern int PhysicsDefaultCheckSwimResponse(struct _Instance *instance, struct evPhysicsSwimData *Data); // 0x80076378

extern void PhysicsForceSetWater(struct _Instance *instance, int *Time, int Depth, int rate, int maxAmplitude); // 0x80076570

extern int PhysicsCheckLOS(struct _Instance *instance, int Data, int Mode); // 0x80076648

extern int PhysicsCheckDropHeight(struct _Instance *instance, int Data, int Mode); // 0x80076678

extern int PhysicsCheckDropOff(struct _Instance *instance, int Data, short Mode); // 0x8007690C

extern int PhysicsFollowWall(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x80076B30

extern void PhysicsMoveLocalZClamp(struct _Instance *instance, long segment, long time, long clamp); // 0x80076FA4

extern void PhysicsMove(struct _Instance *instance, struct _Position *position, long time); // 0x8007707C

extern void PhysicsSetVelFromZRot(struct _Instance *instance, short angle, long magnitude); // 0x80077218

extern void PhysicsSetVelFromRot(struct _Instance *instance, struct _Rotation *rot, long magnitude); // 0x80077288

extern void PHYSICS_SetVAndAFromRot(struct _Instance *instance, struct _Rotation *rot, long v, long a); // 0x800772F8

extern long PHYSICS_FindAFromDAndT(long d, long t); // 0x800773E8

extern long PHYSICS_FindVFromAAndD(long a, long d); // 0x80077424

extern void PHYSICS_StopIfCloseToTarget(struct _Instance *instance, int x, int y, int z); // 0x8007745C

extern int PHYSICS_CheckForTerrainCollide(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment); // 0x8007753C

extern int PHYSICS_CheckForObjectCollide(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment); // 0x80077584

extern int PHYSICS_CheckForValidMove(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment); // 0x800775C8

extern int PHYSICS_CheckFaceStick(struct _PCollideInfo *CInfo); // 0x80077634

extern int PHYSICS_CheckDontGrabEdge(struct _PCollideInfo *CInfo); // 0x80077698

extern void PHYSICS_GenericLineCheckSetup(short x, short y, short z, struct SVECTOR *inVec); // 0x800777C0

extern void PHYSICS_GenericLineCheck(struct _Instance *instance, struct MATRIX *transMat, struct MATRIX *rotMat, struct _PCollideInfo *cInfo); // 0x800777D0

extern void PHYSICS_GenericLineCheckMask(struct _Instance *instance, struct MATRIX *transMat, struct MATRIX *rotMat, struct _PCollideInfo *cInfo); // 0x800777F4


#endif
