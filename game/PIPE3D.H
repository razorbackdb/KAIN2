#ifndef PIPE3D_H
#define PIPE3D_H

extern void PIPE3D_AspectAdjustMatrix(struct MATRIX *matrix);

extern void PIPE3D_CalculateWCTransform(struct _CameraCore_Type *cameraCore);

extern void PIPE3D_InvertTransform(struct MATRIX *target, struct MATRIX *source);

extern long PIPE3D_MatrixColumnLength(struct MATRIX *transform, long column);

extern void PIPE3D_NormalizeMatrix(struct MATRIX *target, struct MATRIX *source);

extern void PIPE3D_TransformVerticesToWorld(struct _Instance *instance, struct _SVector *poolVertex, long *vtxSegment, struct _Vector *Average);

extern void PIPE3D_InstanceTransformAndDraw(struct _Instance *instance, struct _CameraCore_Type *cameraCore, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _Mirror *mirror);

extern void PIPE3D_ExtentsOfPrims(long *firstPrim, long *lastPrim, long *pminx, long *pminy, long *pmaxx, long *pmaxy);

extern void PIPE3D_AddPredatorEffect_Scale(long *firstPrim, long *lastPrim);

extern void PIPE3D_InstanceListTransformAndDrawFunc(struct _StreamUnit *unit, unsigned long **ot, struct _CameraCore_Type *cameraCore, struct _Instance *instance);

extern void PIPE3D_InstanceListTransformAndDraw(struct _StreamUnit *unit, struct GameTracker *gameTracker, unsigned long **ot, struct _CameraCore_Type *cameraCore);

extern void PIPE3D_TransformFromZAxis(struct MATRIX *transform, struct _SVector *normal);

extern void PIPE3D_CalcWorldToSplitPlaneTransform(struct MATRIX *wpTransform, struct _SVector *normal, struct _SVector *translation);

extern long PIPE3D_TransformAnimatedSplitInstanceVertices(struct _MVertex *vertexList, struct _PVertex *poolVertex, struct _Model *model, struct MATRIX *wcTransform, struct MATRIX *matrixPool, struct _Mirror *mirror, struct MATRIX *lm, struct CVECTOR *vertexColor, struct CVECTOR *vertexSrcCol);

extern void PIPE3D_TransformSplitInstanceVertices(struct _MVertex *vertexList, struct _PVertex *pvertex, struct _Model *model, struct MATRIX *wpTransform, struct MATRIX *matrixPool, struct _Mirror *mirror);

extern void PIPE3D_AnimateTextures(struct AniTex *aniTextures, long req_frame);

extern void PIPE3D_AnimateTerrainTextures(struct DrMoveAniTex *aniTextures, long req_frame, struct _PrimPool *primPool, unsigned long **drawot);

extern void PIPE3D_HalvePlaneInstanceTransformAndDraw(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _Mirror *mirror);

extern void PIPE3D_HalvePlaneGetRingPoints(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _FXHalvePlane *ring);

extern void PIPE3D_DoGlow(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _FXGlowEffect *glow);

extern long PIPE3D_Segment2ScreenPt(struct _Instance *instance, struct MATRIX *wcTransform, int segIndex, struct _Position *pos);

#endif
