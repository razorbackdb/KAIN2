#ifndef PHYSICS_H
#define PHYSICS_H


extern void SetNoPtCollideInFamily(struct _Instance *instance); // 0x800748D0

extern void ResetNoPtCollideInFamily(struct _Instance *instance); // 0x80074918

extern void PHYSICS_CheckLineInWorld(struct _Instance *instance, struct _PCollideInfo *pcollideInfo); // 0x80074964

extern void PHYSICS_CheckLineInWorldMask(struct _Instance *instance, struct _PCollideInfo *pcollideInfo); // 0x80074988

extern int PhysicsCheckLinkedMove(struct _Instance *instance, int Data, short Mode); // 0x800749FC

extern void PhysicsDefaultLinkedMoveResponse(struct _Instance *instance, struct evPhysicsLinkedMoveData *Data, int updateTransforms); // 0x80074E58

extern int PhysicsCheckGravity(struct _Instance *instance, int Data, short Mode); // 0x80074EE0

extern void PhysicsDefaultGravityResponse(struct _Instance *instance, struct evPhysicsGravityData *Data); // 0x80075698

extern int PhysicsCheckEdgeGrabbing(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x80075710

extern void PhysicsDefaultEdgeGrabResponse(struct _Instance *instance, struct evPhysicsEdgeData *Data, int blockFlag); // 0x80075DC8

extern int PhysicsCheckSliding(struct _Instance *instance, int Data, short Mode); // 0x8007606C

extern int PhysicsUpdateTface(struct _Instance *instance, int Data); // 0x80076518

extern int PhysicsCheckBlockers(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x80076614

extern int PhysicsCheckSwim(struct _Instance *instance, int Data, short Mode); // 0x800769B4

extern int PhysicsDefaultCheckSwimResponse(struct _Instance *instance, struct evPhysicsSwimData *Data); // 0x80076BA4

extern void PhysicsForceSetWater(struct _Instance *instance, int *Time, int Depth, int rate, int maxAmplitude); // 0x80076D9C

extern int PhysicsCheckLOS(struct _Instance *instance, int Data, int Mode); // 0x80076E74

extern int PhysicsCheckDropHeight(struct _Instance *instance, int Data, int Mode); // 0x80076EA4

extern int PhysicsCheckDropOff(struct _Instance *instance, int Data, short Mode); // 0x80077134

extern int PhysicsFollowWall(struct _Instance *instance, struct GameTracker *gameTracker, int Data, short Mode); // 0x80077354

extern void PhysicsMoveLocalZClamp(struct _Instance *instance, long segment, long time, long clamp); // 0x80077864

extern void PhysicsMove(struct _Instance *instance, struct _Position *position, long time); // 0x8007793C

extern void PhysicsSetVelFromZRot(struct _Instance *instance, short angle, long magnitude); // 0x80077AD8

extern void PhysicsSetVelFromRot(struct _Instance *instance, struct _Rotation *rot, long magnitude); // 0x80077B48

extern void PHYSICS_SetVAndAFromRot(struct _Instance *instance, struct _Rotation *rot, long v, long a); // 0x80077BB8

extern long PHYSICS_FindAFromDAndT(long d, long t); // 0x80077CA8

extern long PHYSICS_FindVFromAAndD(long a, long d); // 0x80077CE4

extern void PHYSICS_StopIfCloseToTarget(struct _Instance *instance, int x, int y, int z); // 0x80077D1C

extern int PHYSICS_CheckForTerrainCollide(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment); // 0x80077DFC

extern int PHYSICS_CheckForObjectCollide(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment); // 0x80077E44

extern int PHYSICS_CheckForValidMove(struct _Instance *instance, struct SVECTOR *startVec, struct SVECTOR *endVec, int segment); // 0x80077E88

extern int PHYSICS_CheckFaceStick(struct _PCollideInfo *CInfo); // 0x80077EF4

extern int PHYSICS_CheckDontGrabEdge(struct _PCollideInfo *CInfo); // 0x80077F58

extern void PHYSICS_GenericLineCheckSetup(short x, short y, short z, struct SVECTOR *inVec); // 0x80078080

extern void PHYSICS_GenericLineCheck(struct _Instance *instance, struct MATRIX *transMat, struct MATRIX *rotMat, struct _PCollideInfo *cInfo); // 0x80078090

extern void PHYSICS_GenericLineCheckMask(struct _Instance *instance, struct MATRIX *transMat, struct MATRIX *rotMat, struct _PCollideInfo *cInfo); // 0x800780B4


#endif
