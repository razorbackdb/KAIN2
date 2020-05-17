#ifndef PIPE3D_H
#define PIPE3D_H


extern void PIPE3D_AspectAdjustMatrix(struct MATRIX *matrix); // 0x8003A7D0

extern void PIPE3D_CalculateWCTransform(struct _CameraCore_Type *cameraCore); // 0x8003A858

extern void PIPE3D_InvertTransform(struct MATRIX *target, struct MATRIX *source); // 0x8003ABD4

extern long PIPE3D_MatrixColumnLength(struct MATRIX *transform, long column); // 0x8003AC68

extern void PIPE3D_NormalizeMatrix(struct MATRIX *target, struct MATRIX *source); // 0x8003ACA4

extern void PIPE3D_TransformVerticesToWorld(struct _Instance *instance, struct _SVector *poolVertex, long *vtxSegment, struct _Vector *Average); // 0x8003AD90

extern void PIPE3D_InstanceTransformAndDraw(struct _Instance *instance, struct _CameraCore_Type *cameraCore, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _Mirror *mirror); // 0x8003B0BC

extern void PIPE3D_InstanceListTransformAndDrawFunc(struct _StreamUnit *unit, unsigned long **ot, struct _CameraCore_Type *cameraCore, struct _Instance *instance); // 0x8003B3B0

extern void PIPE3D_InstanceListTransformAndDraw(struct _StreamUnit *unit, struct GameTracker *gameTracker, unsigned long **ot, struct _CameraCore_Type *cameraCore); // 0x8003B72C

extern void PIPE3D_TransformFromZAxis(struct MATRIX *transform, struct _SVector *normal); // 0x8003B824

extern void PIPE3D_CalcWorldToSplitPlaneTransform(struct MATRIX *wpTransform, struct _SVector *normal, struct _SVector *translation); // 0x8003BA14

extern long PIPE3D_TransformAnimatedSplitInstanceVertices(struct _MVertex *vertexList, struct _PVertex *poolVertex, struct _Model *model, struct MATRIX *wcTransform, struct MATRIX *matrixPool, struct _Mirror *mirror, struct MATRIX *lm, struct CVECTOR *vertexColor, struct CVECTOR *vertexSrcCol); // 0x8003BAE8

extern void PIPE3D_TransformSplitInstanceVertices(struct _MVertex *vertexList, struct _PVertex *pvertex, struct _Model *model, struct MATRIX *wpTransform, struct MATRIX *matrixPool, struct _Mirror *mirror); // 0x8003C0B4

extern void PIPE3D_AnimateTextures(struct AniTex *aniTextures, long req_frame); // 0x8003C228

extern void PIPE3D_AnimateTerrainTextures(struct DrMoveAniTex *aniTextures, long req_frame, struct _PrimPool *primPool, unsigned long **drawot); // 0x8003C2C8

extern void PIPE3D_HalvePlaneInstanceTransformAndDraw(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _Mirror *mirror); // 0x8003C460

extern void PIPE3D_HalvePlaneGetRingPoints(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _FXHalvePlane *ring); // 0x8003C654

extern void PIPE3D_DoGlow(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _FXGlowEffect *glow); // 0x8003C824

extern long PIPE3D_Segment2ScreenPt(struct _Instance *instance, struct MATRIX *wcTransform, int segIndex, struct _Position *pos); // 0x8003CC00


#endif
