#ifndef COLLIDE_H
#define COLLIDE_H


extern int COLLIDE_PointInTriangle(struct _SVector *v0, struct _SVector *v1, struct _SVector *v2, struct _SVector *point, struct _SVector *normal); // 0x8001E48C

extern int COLLIDE_PointInTriangle2DPub(short *v0, short *v1, short *v2, short *point); // 0x8001E718

extern long COLLIDE_GetNormal(short nNum, short *nrmlArray, struct _SVector *nrml); // 0x8001E764

extern void COLLIDE_MakeNormal(struct _Terrain *terrain, struct _TFace *tface, struct _SVector *normal); // 0x8001E7FC

extern void COLLIDE_UpdateAllTransforms(struct _Instance *instance, struct SVECTOR *offset); // 0x8001E9D4

extern void COLLIDE_MoveAllTransforms(struct _Instance *instance, struct _Position *offset); // 0x8001EAA4

extern long COLLIDE_WithinYZBounds(struct _SVector *point, struct _HBox *hbox); // 0x8001EB74

extern long COLLIDE_WithinXZBounds(struct _SVector *point, struct _HBox *hbox); // 0x8001EBD0

extern long COLLIDE_WithinXYBounds(struct _SVector *point, struct _HBox *hbox); // 0x8001EC2C

extern void COLLIDE_LineWithBoxFace(short startDist, long lineDist, short planeDist, struct _SVector *start, struct _Vector *line, struct _HBox *hbox, TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc collideBoundFunc, struct _SVector *normal); // 0x8001EC88

extern long COLLIDE_IntersectLineAndBox(struct _SVector *point0, struct _SVector *normal0, struct _SVector *point1, struct _SVector *normal1, struct _SVector *end, struct _SVector *start, struct _HBox *hbox); // 0x8001EE34

extern struct _TFace * COLLIDE_PointAndTerrain(struct _Terrain *terrain, struct _PCollideInfo *pcollideInfo, struct _LCollideInfo *lcol); // 0x8001F0B0

extern struct _TFace * COLLIDE_PointAndTerrainFunc(struct _Terrain *terrain, struct _PCollideInfo *pCollideInfo, int Flags, short *Backface_Flag, long ignoreAttr, long acceptAttr, struct _LCollideInfo *lcolinfo); // 0x8001F0E0

extern int COLLIDE_PointAndHFace(struct _SVector *newPos, struct _SVector *oldPos, struct _HFace *hface, struct _Model *model, struct _SVector *hfNormal); // 0x8001FC60

extern void COLLIDE_PointAndInstance(struct _PCollideInfo *pcollideInfo, struct _Instance *instance); // 0x8001FEA8

extern void COLLIDE_PointAndInstanceTrivialReject(struct _PCollideInfo *pcollideInfo, struct _Instance *instance); // 0x800206DC

extern void COLLIDE_PointAndWorld(struct _PCollideInfo *pcollideInfo, struct Level *level); // 0x80020860

extern long COLLIDE_ClosestPointInBoxToPoint(struct _Position *boxPoint, struct _HBox *hbox, struct _SVector *point); // 0x80020C58

extern long COLLIDE_SphereAndPoint(struct _Sphere *sphere, struct _SVector *point, struct _SVector *normal); // 0x80020D2C

extern long COLLIDE_SphereAndHBox(struct _HBox *hbox, struct _Sphere *sphere, struct _Position *oldPos, struct _SVector *normal); // 0x80020F70

extern void COLLIDE_Instance1SpheresToInstance2(struct _Instance *instance1, struct _Instance *instance2, long sphereToSphere); // 0x800213F4

extern void COLLIDE_Instances(struct _Instance *instance1, struct _Instance *instance2); // 0x8002215C

extern void COLLIDE_InstanceList(struct _InstanceList *instanceList); // 0x800222A4

extern long COLLIDE_SphereAndHFace(struct _Sphere *sphere, struct _Position *oldPos, struct _HFaceInfo *hfaceInfo, struct _SVector *intersect, long *edge); // 0x80022558

extern long COLLIDE_SAndT(struct SCollideInfo *scollideInfo, struct Level *level); // 0x80022C34

extern long COLLIDE_SphereAndTerrain(struct SCollideInfo *scollideInfo, struct Level *level); // 0x8002370C

extern void COLLIDE_InstanceTerrain(struct _Instance *instance, struct Level *level); // 0x800237F8

extern long COLLIDE_LineWithSignals(struct _SVector *startPoint, struct _SVector *endPoint, struct _MultiSignal **signalList, long maxSignals, struct Level *level); // 0x80023A20

extern void COLLIDE_InstanceTerrainSignal(struct _Instance *instance, struct Level *level); // 0x800241E4

extern struct _StreamUnit * COLLIDE_CameraWithStreamSignals(struct Camera *camera); // 0x80024398

extern void COLLIDE_InstanceListWithSignals(struct _InstanceList *instanceList); // 0x80024608

extern void COLLIDE_InstanceListTerrain(struct _InstanceList *instanceList); // 0x8002467C

extern void COLLIDE_SegmentCollisionOn(struct _Instance *instance, int segment); // 0x8002472C

extern void COLLIDE_SegmentCollisionOff(struct _Instance *instance, int segment); // 0x800247A4

extern long COLLIDE_FindCollisionFaceNormal(struct _CollideInfo *collideInfo, struct _Normal *normal); // 0x80024840

extern short * COLLIDE_GetBSPTreeFlag(struct _CollideInfo *collideInfo); // 0x8002497C

extern void COLLIDE_SetBSPTreeFlag(struct _CollideInfo *collideInfo, short flag); // 0x800249A4

extern int COLLIDE_PointAndTfaceFunc(struct _Terrain *terrain, struct BSPTree *bsp, struct _SVector *orgNewPos, struct _SVector *orgOldPos, struct _TFace *tface, long ignoreAttr, long flags); // 0x800249D8


typedef long (*TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc)();




#endif
