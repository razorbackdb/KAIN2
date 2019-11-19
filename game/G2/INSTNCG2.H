#ifndef INSTNCG2_H
#define INSTNCG2_H


extern void G2Instance_BuildTransformsForList(struct _Instance *listHead); // 0x80092C20

extern void G2Instance_BuildTransforms(struct _Instance *instance); // 0x80092DE4

extern void G2Instance_RebuildTransforms(struct _Instance *instance); // 0x80092E40

extern struct _G2AnimKeylist_Type * G2Instance_GetKeylist(struct _Instance *instance, int id); // 0x80092E9C

extern void _G2Instance_RebuildAnimatedTransforms(struct _Instance *instance); // 0x80092EBC

extern void _G2Instance_BuildAnimatedTransforms(struct _Instance *instance); // 0x800932F0

extern void _G2Instance_RebuildNonAnimatedTransforms(struct _Instance *instance); // 0x800933AC

extern void _G2Instance_BuildDeactivatedTransforms(struct _Instance *instance); // 0x80093638

extern void _G2Instance_BuildNonAnimatedTransforms(struct _Instance *instance); // 0x80093798

extern void _G2Instance_BuildFacadeTransforms(struct _Instance *instance, struct _Segment *segment, struct MATRIX *segMatrix, struct MATRIX *matrixPool, long scale_flag); // 0x80093854


#endif
