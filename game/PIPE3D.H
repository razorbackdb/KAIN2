#ifndef PIPE3D_H
#define PIPE3D_H


extern void PIPE3D_AspectAdjustMatrix(struct MATRIX *matrix); // 0x8003A740

extern void PIPE3D_CalculateWCTransform(struct _CameraCore_Type *cameraCore); // 0x8003A7C8

extern void PIPE3D_InvertTransform(struct MATRIX *target, struct MATRIX *source); // 0x8003AB44

extern long PIPE3D_MatrixColumnLength(struct MATRIX *transform, long column); // 0x8003ABD8

extern void PIPE3D_NormalizeMatrix(struct MATRIX *target, struct MATRIX *source); // 0x8003AC14

extern void PIPE3D_TransformVerticesToWorld(struct _Instance *instance, struct _SVector *poolVertex, long *vtxSegment, struct _Vector *Average); // 0x8003AD00

extern void PIPE3D_InstanceTransformAndDraw(struct _Instance *instance, struct _CameraCore_Type *cameraCore, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _Mirror *mirror); // 0x8003B02C

extern void PIPE3D_ExtentsOfPrims(long *firstPrim, long *lastPrim, long *pminx, long *pminy, long *pmaxx, long *pmaxy); // 0x8003B324

extern void PIPE3D_AddPredatorEffect_Scale(long *firstPrim, long *lastPrim); // 0x8003B534

extern void PIPE3D_InstanceListTransformAndDrawFunc(struct _StreamUnit *unit, unsigned long **ot, struct _CameraCore_Type *cameraCore, struct _Instance *instance); // 0x8003B924

extern void PIPE3D_InstanceListTransformAndDraw(struct _StreamUnit *unit, struct GameTracker *gameTracker, unsigned long **ot, struct _CameraCore_Type *cameraCore); // 0x8003BC80

extern void PIPE3D_TransformFromZAxis(struct MATRIX *transform, struct _SVector *normal); // 0x8003BD78

extern void PIPE3D_CalcWorldToSplitPlaneTransform(struct MATRIX *wpTransform, struct _SVector *normal, struct _SVector *translation); // 0x8003BF68

extern long PIPE3D_TransformAnimatedSplitInstanceVertices(struct _MVertex *vertexList, struct _PVertex *poolVertex, struct _Model *model, struct MATRIX *wcTransform, struct MATRIX *matrixPool, struct _Mirror *mirror, struct MATRIX *lm, struct CVECTOR *vertexColor, struct CVECTOR *vertexSrcCol); // 0x8003C03C

extern void PIPE3D_TransformSplitInstanceVertices(struct _MVertex *vertexList, struct _PVertex *pvertex, struct _Model *model, struct MATRIX *wpTransform, struct MATRIX *matrixPool, struct _Mirror *mirror); // 0x8003C60C

extern void PIPE3D_AnimateTextures(struct AniTex *aniTextures, long req_frame); // 0x8003C780

extern void PIPE3D_AnimateTerrainTextures(struct DrMoveAniTex *aniTextures, long req_frame, struct _PrimPool *primPool, unsigned long **drawot); // 0x8003C820

extern void PIPE3D_HalvePlaneInstanceTransformAndDraw(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _Mirror *mirror); // 0x8003C9B8

extern void PIPE3D_HalvePlaneGetRingPoints(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _FXHalvePlane *ring); // 0x8003CBAC

extern void PIPE3D_DoGlow(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _FXGlowEffect *glow); // 0x8003CD7C

extern long PIPE3D_Segment2ScreenPt(struct _Instance *instance, struct MATRIX *wcTransform, int segIndex, struct _Position *pos); // 0x8003D158


#endif
