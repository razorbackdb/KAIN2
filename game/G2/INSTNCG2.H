#ifndef INSTNCG2_H
#define INSTNCG2_H

extern void G2Instance_BuildTransformsForList(struct _Instance *listHead);

extern void G2Instance_BuildTransforms(struct _Instance *instance);

extern void G2Instance_RebuildTransforms(struct _Instance *instance);

extern struct _G2AnimKeylist_Type *G2Instance_GetKeylist(struct _Instance *instance, int id);

extern void _G2Instance_RebuildAnimatedTransforms(struct _Instance *instance);

extern void G2Instance_ClearMatrices(struct _Instance *instance);

extern void _G2Instance_BuildAnimatedTransforms(struct _Instance *instance);

extern void _G2Instance_RebuildNonAnimatedTransforms(struct _Instance *instance);

extern void _G2Instance_BuildDeactivatedTransforms(struct _Instance *instance);

extern void _G2Instance_BuildNonAnimatedTransforms(struct _Instance *instance);

extern void _G2Instance_BuildFacadeTransforms(struct _Instance *instance, struct _Segment *segment, struct MATRIX *segMatrix, struct MATRIX *matrixPool, long scale_flag);

#endif
