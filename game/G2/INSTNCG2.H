#ifndef INSTNCG2_H
#define INSTNCG2_H


extern void G2Instance_BuildTransformsForList(struct _Instance *listHead); // 0x800947A8

extern void G2Instance_BuildTransforms(struct _Instance *instance); // 0x8009496C

extern void G2Instance_RebuildTransforms(struct _Instance *instance); // 0x800949C8

extern struct _G2AnimKeylist_Type * G2Instance_GetKeylist(struct _Instance *instance, int id); // 0x80094A24

extern void _G2Instance_RebuildAnimatedTransforms(struct _Instance *instance); // 0x80094A44

extern void G2Instance_ClearMatrices(struct _Instance *instance); // 0x80094E78

extern void _G2Instance_BuildAnimatedTransforms(struct _Instance *instance); // 0x80094ECC

extern void _G2Instance_RebuildNonAnimatedTransforms(struct _Instance *instance); // 0x80094F88

extern void _G2Instance_BuildDeactivatedTransforms(struct _Instance *instance); // 0x80095214

extern void _G2Instance_BuildNonAnimatedTransforms(struct _Instance *instance); // 0x80095374

extern void _G2Instance_BuildFacadeTransforms(struct _Instance *instance, struct _Segment *segment, struct MATRIX *segMatrix, struct MATRIX *matrixPool, long scale_flag); // 0x80095430


#endif
