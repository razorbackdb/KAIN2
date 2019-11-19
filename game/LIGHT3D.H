#ifndef LIGHT3D_H
#define LIGHT3D_H


extern void LIGHT_GetLightMatrix(struct _Instance *instance, struct Level *level, struct MATRIX *lightM, struct MATRIX *colorM); // 0x80035D80

extern void LIGHT_PresetInstanceLight(struct _Instance *instance, short attenuate, struct MATRIX *lm); // 0x800360FC

extern void LIGHT_GetAmbient(struct _ColorType *color, struct _Instance *instance); // 0x8003630C

extern void LIGHT_CalcLightValue(struct _TFace *tface, struct _Instance *instance, struct _Terrain *terrain); // 0x800363EC

extern void LIGHT_SetAmbientInstance(struct _Instance *instance, struct Level *level); // 0x80036B08

extern void LIGHT_SetMatrixForLightGroupInstance(struct _Instance *instance, struct Level *level); // 0x80036B38

extern void LIGHT_DrawShadow(struct MATRIX *wcTransform, struct _Instance *instance, struct _PrimPool *primPool, unsigned long **ot); // 0x80036F04

extern void LIGHT_CalcShadowPositions(struct GameTracker *gameTracker); // 0x800371E8

extern void LIGHT_InitSources(struct LightInfo *lightInfo); // 0x800374F8

extern void LIGHT_Restore(struct LightInfo *lightInfo); // 0x800375B4

extern void LIGHT_SourcesAndTerrain(struct LightInfo *lightInfo, struct _Terrain *terrain); // 0x800375BC

extern void LIGHT_ActivateSources(struct _CameraCore_Type *cameraCore, struct Level *level, struct NodeType *activeLightList, struct NodeType *usedLightList); // 0x800375C4

extern void LIGHT_RelocatePointerInList(struct Level *oldLevel, long sizeOfLevel, long offset, struct NodeType *currentLightList); // 0x800376E4

extern void LIGHT_RelocateLights(struct LightInfo *lightInfo, struct Level *oldLevel, long sizeOfLevel, long offset); // 0x80037794

extern void LIGHT_ClassifySources(struct _CameraCore_Type *cameraCore, struct Level *level, struct LightInfo *lightInfo); // 0x80037828

extern long LIGHT_CollideInstanceAndSphere(struct _Instance *instance, struct _Sphere *sphere); // 0x80037880

extern void LIGHT_SourcesAndInstances(struct LightInfo *lightInfo, struct _InstanceList *instanceList); // 0x80037934

extern void LIGHT_CalcDQPTable(struct Level *level); // 0x80037B50


#endif
