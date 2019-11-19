#ifndef PIPE3D_H
#define PIPE3D_H


extern void PIPE3D_AspectAdjustMatrix(struct MATRIX *matrix); // 0x8003AF40

extern void PIPE3D_CalculateWCTransform(struct _CameraCore_Type *cameraCore); // 0x8003AFC8

extern void PIPE3D_InvertTransform(struct MATRIX *target, struct MATRIX *source); // 0x8003B344

extern long PIPE3D_MatrixColumnLength(struct MATRIX *transform, long column); // 0x8003B3D8

extern void PIPE3D_NormalizeMatrix(struct MATRIX *target, struct MATRIX *source); // 0x8003B414

extern void PIPE3D_TransformVerticesToWorld(struct _Instance *instance, struct _SVector *poolVertex, long *vtxSegment, struct _Vector *Average); // 0x8003B500

extern void PIPE3D_InstanceTransformAndDraw(struct _Instance *instance, struct _CameraCore_Type *cameraCore, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _Mirror *mirror); // 0x8003B82C

extern void PIPE3D_ExtentsOfPrims(long *firstPrim, long *lastPrim, long *pminx, long *pminy, long *pmaxx, long *pmaxy); // 0x8003BAC8

extern void PIPE3D_AddPredatorEffect_Scale(long *firstPrim, long *lastPrim); // 0x8003BCD8

extern void PIPE3D_InstanceListTransformAndDraw(struct Level *level, struct GameTracker *gameTracker, unsigned long **ot, struct _CameraCore_Type *cameraCore); // 0x8003C0C8

extern void PIPE3D_TransformFromZAxis(struct MATRIX *transform, struct _SVector *normal); // 0x8003C4A0

extern void PIPE3D_CalcWorldToSplitPlaneTransform(struct MATRIX *wpTransform, struct _SVector *normal, struct _SVector *translation); // 0x8003C690

extern long PIPE3D_TransformAnimatedSplitInstanceVertices(struct _MVertex *vertexList, struct _PVertex *poolVertex, struct _Model *model, struct MATRIX *wcTransform, struct MATRIX *matrixPool, struct _Mirror *mirror, struct MATRIX *lm, struct CVECTOR *vertexColor, struct CVECTOR *vertexSrcCol); // 0x8003C764

extern void PIPE3D_TransformSplitInstanceVertices(struct _MVertex *vertexList, struct _PVertex *pvertex, struct _Model *model, struct MATRIX *wpTransform, struct MATRIX *matrixPool, struct _Mirror *mirror); // 0x8003CD34

extern void PIPE3D_AnimateTextures(struct AniTex *aniTextures, long req_frame); // 0x8003CEA8

extern void PIPE3D_AnimateTerrainTextures(struct DrMoveAniTex *aniTextures, long req_frame, struct _PrimPool *primPool, unsigned long **drawot); // 0x8003CF48

extern void PIPE3D_HalvePlaneInstanceTransformAndDraw(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _Mirror *mirror); // 0x8003D0E0

extern void PIPE3D_HalvePlaneGetRingPoints(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _FXHalvePlane *ring); // 0x8003D2D4

extern void PIPE3D_DoGlow(struct _Instance *instance, struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot, struct _FXGlowEffect *glow); // 0x8003D4A4

extern long PIPE3D_Segment2ScreenPt(struct _Instance *instance, struct MATRIX *wcTransform, int segIndex, struct _Position *pos); // 0x8003D880


#endif
