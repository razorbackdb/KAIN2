#ifndef LIGHT3D_H
#define LIGHT3D_H


extern void LIGHT_GetLightMatrix(struct _Instance *instance, struct Level *level, struct MATRIX *lightM, struct MATRIX *colorM); // 0x80035ACC

extern void LIGHT_PresetInstanceLight(struct _Instance *instance, short attenuate, struct MATRIX *lm); // 0x80035E40

extern void LIGHT_GetAmbient(struct _ColorType *color, struct _Instance *instance); // 0x80036050

extern void LIGHT_CalcLightValue(struct _TFace *tface, struct _Instance *instance, struct _Terrain *terrain); // 0x80036080

extern void LIGHT_SetAmbientInstance(struct _Instance *instance, struct Level *level); // 0x800367D0

extern void LIGHT_SetMatrixForLightGroupInstance(struct _Instance *instance, struct Level *level); // 0x80036800

extern void LIGHT_DrawShadow(struct MATRIX *wcTransform, struct _Instance *instance, struct _PrimPool *primPool, unsigned long **ot); // 0x80036BC8

extern void LIGHT_CalcShadowPositions(struct GameTracker *gameTracker); // 0x80036EAC

extern void LIGHT_Restore(struct LightInfo *lightInfo); // 0x800371AC

extern void LIGHT_CalcDQPTable(struct Level *level); // 0x800371B4


#endif
