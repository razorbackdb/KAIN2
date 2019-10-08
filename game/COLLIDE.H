#ifndef COLLIDE_H
#define COLLIDE_H

extern int COLLIDE_PointInTriangle(struct _SVector *v0, struct _SVector *v1, struct _SVector *v2, struct _SVector *point, struct _SVector *normal);

extern int COLLIDE_PointInTriangle2DPub(short *v0, short *v1, short *v2, short *point);

extern long COLLIDE_GetNormal(short nNum, short *nrmlArray, struct _SVector *nrml);

extern void COLLIDE_MakeNormal(struct _Terrain *terrain, struct _TFace *tface, struct _SVector *normal);

extern void COLLIDE_UpdateAllTransforms(struct _Instance *instance, struct SVECTOR *offset);

extern void COLLIDE_MoveAllTransforms(struct _Instance *instance, struct _Position *offset);

extern long COLLIDE_WithinYZBounds(struct _SVector *point, struct _HBox *hbox);

extern long COLLIDE_WithinXZBounds(struct _SVector *point, struct _HBox *hbox);

extern long COLLIDE_WithinXYBounds(struct _SVector *point, struct _HBox *hbox);

extern void COLLIDE_LineWithBoxFace(short startDist, long lineDist, short planeDist, struct _SVector *start, struct _Vector *line, struct _HBox *hbox, TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc collideBoundFunc, struct _SVector *normal);

extern long COLLIDE_IntersectLineAndBox(struct _SVector *point0, struct _SVector *normal0, struct _SVector *point1, struct _SVector *normal1, struct _SVector *end, struct _SVector *start, struct _HBox *hbox);

extern struct _TFace *COLLIDE_PointAndTerrain(struct _Terrain *terrain, struct _PCollideInfo *pcollideInfo, struct _LCollideInfo *lcol);

extern struct _TFace *COLLIDE_PointAndTerrainFunc(struct _Terrain *terrain, struct _PCollideInfo *pCollideInfo, int Flags, short *Backface_Flag, long ignoreAttr, long acceptAttr, struct _LCollideInfo *lcolinfo);

extern int COLLIDE_PointAndHFace(struct _SVector *newPos, struct _SVector *oldPos, struct _HFace *hface, struct _Model *model, struct _SVector *hfNormal);

extern void COLLIDE_PointAndInstance(struct _PCollideInfo *pcollideInfo, struct _Instance *instance);

extern void COLLIDE_PointAndInstanceTrivialReject(struct _PCollideInfo *pcollideInfo, struct _Instance *instance);

extern void COLLIDE_PointAndWorld(struct _PCollideInfo *pcollideInfo, struct Level *level);

extern long COLLIDE_ClosestPointInBoxToPoint(struct _Position *boxPoint, struct _HBox *hbox, struct _SVector *point);

extern long COLLIDE_SphereAndPoint(struct _Sphere *sphere, struct _SVector *point, struct _SVector *normal);

extern long COLLIDE_SphereAndHBox(struct _HBox *hbox, struct _Sphere *sphere, struct _Position *oldPos, struct _SVector *normal);

extern void COLLIDE_Instance1SpheresToInstance2(struct _Instance *instance1, struct _Instance *instance2, long sphereToSphere);

extern void COLLIDE_Instances(struct _Instance *instance1, struct _Instance *instance2);

extern void COLLIDE_InstanceList(struct _InstanceList *instanceList);

extern long COLLIDE_SphereAndHFace(struct _Sphere *sphere, struct _Position *oldPos, struct _HFaceInfo *hfaceInfo, struct _SVector *intersect, long *edge);

extern long COLLIDE_SAndT(struct SCollideInfo *scollideInfo, struct Level *level);

extern long COLLIDE_SphereAndTerrain(struct SCollideInfo *scollideInfo, struct Level *level);

extern void COLLIDE_InstanceTerrain(struct _Instance *instance, struct Level *level);

extern long COLLIDE_LineWithSignals(struct _SVector *startPoint, struct _SVector *endPoint, struct _MultiSignal **signalList, long maxSignals, struct Level *level);

extern void COLLIDE_InstanceTerrainSignal(struct _Instance *instance, struct Level *level);

extern struct _StreamUnit *COLLIDE_CameraWithStreamSignals(struct Camera *camera);

extern void COLLIDE_InstanceListWithSignals(struct _InstanceList *instanceList);

extern void COLLIDE_InstanceListTerrain(struct _InstanceList *instanceList);

extern void COLLIDE_SegmentCollisionOn(struct _Instance *instance, int segment);

extern void COLLIDE_SegmentCollisionOff(struct _Instance *instance, int segment);

extern long COLLIDE_FindCollisionFaceNormal(struct _CollideInfo *collideInfo, struct _Normal *normal);

extern short *COLLIDE_GetBSPTreeFlag(struct _CollideInfo *collideInfo);

extern void COLLIDE_SetBSPTreeFlag(struct _CollideInfo *collideInfo, short flag);

extern int COLLIDE_PointAndTfaceFunc(struct _Terrain *terrain, struct BSPTree *bsp, struct _SVector *orgNewPos, struct _SVector *orgOldPos, struct _TFace *tface, long ignoreAttr, long flags);

typedef long (*TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc)();

#endif
