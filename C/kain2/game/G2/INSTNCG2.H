#ifndef INSTNCG2_H
#define INSTNCG2_H


extern void G2Instance_BuildTransformsForList(struct _Instance *listHead); // 0x80094ED0

extern void G2Instance_BuildTransforms(struct _Instance *instance); // 0x8009504C

extern void G2Instance_RebuildTransforms(struct _Instance *instance); // 0x800950A8

extern struct _G2AnimKeylist_Type * G2Instance_GetKeylist(struct _Instance *instance, int id); // 0x80095104

extern void _G2Instance_RebuildAnimatedTransforms(struct _Instance *instance); // 0x80095124

extern void G2Instance_ClearMatrices(struct _Instance *instance); // 0x80095558

extern void _G2Instance_BuildAnimatedTransforms(struct _Instance *instance); // 0x800955AC

extern void _G2Instance_RebuildNonAnimatedTransforms(struct _Instance *instance); // 0x80095668

extern void _G2Instance_BuildDeactivatedTransforms(struct _Instance *instance); // 0x800958F4

extern void _G2Instance_BuildNonAnimatedTransforms(struct _Instance *instance); // 0x80095A74

extern void _G2Instance_BuildFacadeTransforms(struct _Instance *instance, struct _Segment *segment, struct MATRIX *segMatrix, struct MATRIX *matrixPool, long scale_flag); // 0x80095B30


#endif
