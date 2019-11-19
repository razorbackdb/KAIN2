#ifndef COLLIDE_H
#define COLLIDE_H


extern int COLLIDE_PointInTriangle(struct _SVector *v0, struct _SVector *v1, struct _SVector *v2, struct _SVector *point, struct _SVector *normal); // 0x8001E8DC

extern int COLLIDE_PointInTriangle2DPub(short *v0, short *v1, short *v2, short *point); // 0x8001EB68

extern long COLLIDE_GetNormal(short nNum, short *nrmlArray, struct _SVector *nrml); // 0x8001EBB4

extern void COLLIDE_MakeNormal(struct _Terrain *terrain, struct _TFace *tface, struct _SVector *normal); // 0x8001EC4C

extern void COLLIDE_UpdateAllTransforms(struct _Instance *instance, struct SVECTOR *offset); // 0x8001EE24

extern void COLLIDE_MoveAllTransforms(struct _Instance *instance, struct _Position *offset); // 0x8001EEF4

extern long COLLIDE_WithinYZBounds(struct _SVector *point, struct _HBox *hbox); // 0x8001EFC4

extern long COLLIDE_WithinXZBounds(struct _SVector *point, struct _HBox *hbox); // 0x8001F020

extern long COLLIDE_WithinXYBounds(struct _SVector *point, struct _HBox *hbox); // 0x8001F07C

extern void COLLIDE_LineWithBoxFace(short startDist, long lineDist, short planeDist, struct _SVector *start, struct _Vector *line, struct _HBox *hbox, TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc collideBoundFunc, struct _SVector *normal); // 0x8001F0D8

extern long COLLIDE_IntersectLineAndBox(struct _SVector *point0, struct _SVector *normal0, struct _SVector *point1, struct _SVector *normal1, struct _SVector *end, struct _SVector *start, struct _HBox *hbox); // 0x8001F284

extern struct _TFace * COLLIDE_PointAndTerrain(struct _Terrain *terrain, struct _SVector *newPos, struct _SVector *oldPos, struct _Instance *instance, struct _LCollideInfo *lcol); // 0x8001F500

extern struct _TFace * COLLIDE_PointAndTerrainFunc(struct _Terrain *terrain, struct _SVector *NewPos, struct _SVector *OldPos, int Flags, short *Backface_Flag, struct _Instance *instance, long ignoreAttr, long acceptAttr, struct _LCollideInfo *lcolinfo); // 0x8001F538

extern int COLLIDE_PointAndHFace(struct _SVector *newPos, struct _SVector *oldPos, struct _HFace *hface, struct _Model *model, struct _SVector *hfNormal); // 0x80020088

extern void COLLIDE_PointAndInstance(struct _PCollideInfo *pcollideInfo, struct _Instance *instance); // 0x800202D0

extern void COLLIDE_PointAndInstanceTrivialReject(struct _PCollideInfo *pcollideInfo, struct _Instance *instance); // 0x80020B04

extern void COLLIDE_PointAndWorld(struct _PCollideInfo *pcollideInfo, struct GameTracker *gameTracker, struct Level *level); // 0x80020C88

extern long COLLIDE_ClosestPointInBoxToPoint(struct _Position *boxPoint, struct _HBox *hbox, struct _SVector *point); // 0x8002105C

extern long COLLIDE_SphereAndPoint(struct _Sphere *sphere, struct _SVector *point, struct _SVector *normal); // 0x80021130

extern long COLLIDE_SphereAndHBox(struct _HBox *hbox, struct _Sphere *sphere, struct _Position *oldPos, struct _SVector *normal); // 0x80021374

extern void COLLIDE_Instance1SpheresToInstance2(struct _Instance *instance1, struct _Instance *instance2, long sphereToSphere); // 0x800217F8

extern void COLLIDE_Instances(struct _Instance *instance1, struct _Instance *instance2); // 0x80022560

extern void COLLIDE_InstanceList(struct _InstanceList *instanceList); // 0x800226A8

extern long COLLIDE_SphereAndHFace(struct _Sphere *sphere, struct _Position *oldPos, struct _HFaceInfo *hfaceInfo, struct _SVector *intersect, long *edge); // 0x8002295C

extern long COLLIDE_SAndT(struct SCollideInfo *scollideInfo, struct Level *level); // 0x80023038

extern long COLLIDE_SphereAndTerrain(struct SCollideInfo *scollideInfo, struct Level *level); // 0x80023B10

extern void COLLIDE_InstanceTerrain(struct _Instance *instance, struct Level *level); // 0x80023BFC

extern long COLLIDE_LineWithSignals(struct _SVector *startPoint, struct _SVector *endPoint, struct _MultiSignal **signalList, long maxSignals, struct Level *level); // 0x80023E24

extern void COLLIDE_InstanceTerrainSignal(struct _Instance *instance, struct Level *level); // 0x800245E8

extern struct _StreamUnit * COLLIDE_CameraWithStreamSignals(struct Camera *camera); // 0x80024788

extern void COLLIDE_InstanceListWithSignals(struct _InstanceList *instanceList); // 0x800249F8

extern void COLLIDE_InstanceListTerrain(struct _InstanceList *instanceList); // 0x80024A6C

extern void COLLIDE_SegmentCollisionOn(struct _Instance *instance, int segment); // 0x80024B1C

extern void COLLIDE_SegmentCollisionOff(struct _Instance *instance, int segment); // 0x80024B94

extern long COLLIDE_FindCollisionFaceNormal(struct _CollideInfo *collideInfo, struct _Normal *normal); // 0x80024C30

extern short * COLLIDE_GetBSPTreeFlag(struct _CollideInfo *collideInfo); // 0x80024D6C

extern void COLLIDE_SetBSPTreeFlag(struct _CollideInfo *collideInfo, short flag); // 0x80024D94

extern int COLLIDE_PointAndTfaceFunc(struct _Terrain *terrain, struct BSPTree *bsp, struct _SVector *orgNewPos, struct _SVector *orgOldPos, struct _TFace *tface, long ignoreAttr, long flags); // 0x80024DC8


typedef long (*TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc)();




#endif
