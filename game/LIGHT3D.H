#ifndef LIGHT3D_H
#define LIGHT3D_H

struct LightGroup
{
	struct MATRIX lightMatrix;
	struct MATRIX colorMatrix;
};

struct LightList
{
	struct CVECTOR ambient;
	long numLightGroups;
	struct LightGroup *lightGroupList;
};

extern void LIGHT_GetLightMatrix(struct _Instance *instance, struct Level *level, struct MATRIX *lightM, struct MATRIX *colorM);

extern void LIGHT_PresetInstanceLight(struct _Instance *instance, short attenuate, struct MATRIX *lm);

extern void LIGHT_GetAmbient(struct _ColorType *color, struct _Instance *instance);

extern void LIGHT_CalcLightValue(struct _TFace *tface, struct _Instance *instance, struct _Terrain *terrain);

extern void LIGHT_SetAmbientInstance(struct _Instance *instance, struct Level *level);

extern void LIGHT_SetMatrixForLightGroupInstance(struct _Instance *instance, struct Level *level);

extern void LIGHT_DrawShadow(struct MATRIX *wcTransform, struct _Instance *instance, struct _PrimPool *primPool, unsigned long **ot);

extern void LIGHT_CalcShadowPositions(struct GameTracker *gameTracker);

extern void LIGHT_InitSources(struct LightInfo *lightInfo);

extern void LIGHT_Restore(struct LightInfo *lightInfo);

extern void LIGHT_SourcesAndTerrain(struct LightInfo *lightInfo, struct _Terrain *terrain);

extern void LIGHT_ActivateSources(struct _CameraCore_Type *cameraCore, struct Level *level, struct NodeType *activeLightList, struct NodeType *usedLightList);

extern void LIGHT_RelocatePointerInList(struct Level *oldLevel, long sizeOfLevel, long offset, struct NodeType *currentLightList);

extern void LIGHT_RelocateLights(struct LightInfo *lightInfo, struct Level *oldLevel, long sizeOfLevel, long offset);

extern void LIGHT_ClassifySources(struct _CameraCore_Type *cameraCore, struct Level *level, struct LightInfo *lightInfo);

extern long LIGHT_CollideInstanceAndSphere(struct _Instance *instance, struct _Sphere *sphere);

extern void LIGHT_SourcesAndInstances(struct LightInfo *lightInfo, struct _InstanceList *instanceList);

extern void LIGHT_CalcDQPTable(struct Level *level);

#endif
