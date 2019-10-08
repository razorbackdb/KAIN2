#ifndef STREAM_H
#define STREAM_H

extern void STREAM_FillOutFileNames(char *baseAreaName, char *dramName, char *vramName, char *sfxName);

extern void STREAM_AbortAreaLoad(char *baseAreaName);

extern void STREAM_Init();

extern int FindObjectName(char *name);

extern struct _ObjectTracker *FindObjectInTracker(struct Object *object);

extern struct _StreamUnit *FindStreamUnitFromLevel(struct Level *level);

extern void STREAM_LoadObjectReturn(void *loadData, void *data, void *data2);

extern void STREAM_DumpMonster(struct _ObjectTracker *dumpee);

extern int STREAM_InList(char *name, char **nameList);

extern int STREAM_IsSpecialMonster(char *name);

extern void STREAM_DumpSomeMonsters();

extern void STREAM_NoMonsters();

extern void STREAM_YesMonsters();

extern int STREAM_IsMonster(char *name);

extern int InsertGlobalObject(char *name, struct GameTracker *gameTracker);

extern struct _ObjectTracker *STREAM_GetObjectTracker(char *name);

extern void LoadLevelObjects(struct Level *level, struct GameTracker *gameTracker);

extern long STREAM_IsAnInstanceUsingObject(struct Object *object);

extern void STREAM_StreamLoadObjectAbort(void *loadData, void *data, void *data2);

extern void STREAM_DumpObject(struct _ObjectTracker *objectTracker);

extern int STREAM_IsObjectInAnyUnit(struct _ObjectTracker *tracker);

extern void STREAM_RemoveAllObjectsNotInUse(struct GameTracker *gameTracker);

extern void RemoveAllObjects(struct GameTracker *gameTracker);

extern struct Level *STREAM_GetLevelWithID(long id);

extern struct _StreamUnit *STREAM_GetStreamUnitWithID(long id);

extern void STREAM_CalculateWaterLevel(struct Level *level);

extern int STREAM_IsMorphInProgress();

extern long STREAM_GetWaterZLevel(struct Level *level, struct _Instance *instance);

extern void STREAM_SetMainFog(struct _StreamUnit *streamUnit);

extern void STREAM_SetStreamFog(struct _StreamUnit *streamUnit, short fogNear, short fogFar);

extern void STREAM_ConnectStream(struct _StreamUnit *streamUnit);

extern void STREAM_StreamLoadLevelAbort(void *loadData, void *data, void *data2);

extern void STREAM_FinishLoad(struct _StreamUnit *streamUnit);

extern void STREAM_LoadLevelReturn(void *loadData, void *data, void *data2);

extern void STREAM_StreamLoadLevelReturn(void *loadData, void *data, void *data2);

extern void STREAM_UpdateLevelPointer(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel);

extern struct _StreamUnit *STREAM_WhichUnitPointerIsIn(void *pointer);

extern void STREAM_UpdateObjectPointer(struct Object *oldObject, struct Object *newObject, long sizeOfObject);

extern void STREAM_UpdateInstanceCollisionInfo(struct _HModel *oldHModel, struct _HModel *newHModel);

extern void STREAM_LoadMainVram(struct GameTracker *gameTracker, char *baseAreaName, struct _StreamUnit *streamUnit);

extern void STREAM_MoveIntoNewStreamUnit();

extern struct _StreamUnit *STREAM_LoadLevel(struct GameTracker *gameTracker, char *baseAreaName, struct StreamUnitPortal *streamPortal, int loadnext);

extern void RemoveIntroducedLights(struct Level *level);

extern void STREAM_RemoveInstancesWithIDInInstanceList(struct _InstanceList *list, long id, struct Level *level);

extern void STREAM_MarkUnitNeeded(long streamID);

extern void STREAM_DumpUnit(struct _StreamUnit *streamUnit, long doSave);

extern void STREAM_DumpAllUnitsNotNeeded(struct GameTracker *gameTracker);

extern void STREAM_DumpAllLevels(long IDNoRemove, int DoSave);

extern void STREAM_LoadCurrentWarpRoom(struct StreamUnitPortal *streamPortal, struct _StreamUnit *mainStreamUnit);

extern void WARPGATE_RelocateLoadedWarpRooms(struct _StreamUnit *mainUnit, struct StreamUnitPortal *streamPortal);

extern long WARPGATE_GetWarpRoomIndex(char *name);

extern void WARPGATE_UpdateAddToArray(struct _StreamUnit *streamUnit);

extern void WARPGATE_RemoveFromArray(struct _StreamUnit *streamUnit);

extern void WARPGATE_Init();

extern void WARPGATE_StartUsingWarpgate();

extern void WARPGATE_EndUsingWarpgate();

extern int WARPGATE_IsWarpgateInUse();

extern int WARPGATE_IsWarpgateActive();

extern int WARPGATE_IsWarpgateUsable();

extern int WARPGATE_IsWarpgateSpectral();

extern void WARPGATE_IsItActive(struct _StreamUnit *streamUnit);

extern long WARPGATE_IsUnitWarpRoom(struct _StreamUnit *streamUnit);

extern void WARPGATE_FixUnit(struct _StreamUnit *streamUnit);

extern void STREAM_MarkWarpUnitsNeeded();

extern long WARPGATE_IncrementIndex();

extern void WARPGATE_CalcWarpFade(int timeInc);

extern long WARPGATE_DecrementIndex();

extern void PreloadAllConnectedUnits(struct GameTracker *gameTracker, struct _StreamUnit *streamUnit, struct _SVector *offset);

extern void RelocateLevel(struct Level *level, struct _SVector *offset);

extern void RelocateCameras(struct _CameraKey *cameraList, long numCameras, struct _SVector *offset);

extern void RelocateSavedCameras(struct Camera *camera, struct Level *level, struct _SVector *offset);

extern void RelocateLevelWithInstances(struct Level *level, struct _SVector *offset);

extern void RelocateTerrain(struct _Terrain *terrain, struct _SVector *offset);

extern void RelocateVMObjects(struct _VMObject *vobjectlist, long numvmobjs, struct _SVector *offset);

extern void RelocateSpotLights(struct SpotLight *spotLightList, long numSpotLights, struct _SVector *offset);

extern void RelocatePointLights(struct PointLight *PLightList, long numPLights, struct _SVector *offset);

extern void RelocateBGObjects(struct _BGObject *BGObjList, long numBGObjs, struct _SVector *offset);

extern void RelocatePlanPool(struct PlanningNode *planPool, struct _SVector *offset);

extern void RelocatePlanMarkers(struct _PlanMkr *planMkrList, int numPlanMkrs, struct _SVector *offset);

extern void RelocateSFXMarkers(struct _SFXMkr *sfxMkrList, int numSFXMkrs, struct _SVector *offset);

extern void STREAM_AdjustMultiSpline(struct MultiSpline *multi, struct _SVector *offset);

extern void STREAM_RelocateInstance(struct GameTracker *gameTracker, struct _Instance *instance, struct _SVector *offset);

extern void STREAM_OffsetInstancePosition(struct GameTracker *gameTracker, struct _Instance *instance, struct _SVector *offset, int streamSignalFlag);

extern void STREAM_SetInstancePosition(struct GameTracker *gameTracker, struct _Instance *instance, struct evPositionData *data);

extern void RelocateInstances(struct GameTracker *gameTracker, struct _SVector *offset, long StreamUnitID);

extern void RelocateStreamPortals(struct StreamUnitPortal *StreamUnitList, int NumStreamUnits, struct _SVector *offset);

extern void STREAM_PackVRAMObject(struct _ObjectTracker *objectTracker);

extern void MORPH_SetupInstanceFlags(struct GameTracker *gameTracker, struct _Instance *instance);

extern void MORPH_SetupInstanceListFlags(struct GameTracker *gameTracker);

extern void MORPH_InMorphInstanceListFlags(struct GameTracker *gameTracker);

extern void MORPH_InMorphDoFadeValues(struct GameTracker *gameTracker);

extern void MORPH_UpdateTimeMult();

extern void MORPH_UpdateNormals(struct Level *BaseLevel);

extern void MORPH_BringBackNormals(struct Level *BaseLevel);

extern void MORPH_AddOffsets(struct Level *BaseLevel, int time);

extern void MORPH_SubtractOffsets(struct Level *BaseLevel, int time);

extern void MORPH_GetComponentsForTrackingPoint(struct _TFace *face, struct Level *level);

extern void MORPH_AveragePoint(struct _SVector *start, struct _SVector *end, int interp, struct _SVector *out);

extern void MORPH_UpdateTrackingPoint(struct _TFace *face, struct Level *level);

extern void MORPH_ToggleMorph();

extern void MORPH_DoStep(struct _StreamUnit *streamUnit, char *baseAreaName);

extern void MORPH_SetFog(struct _StreamUnit *streamUnit, int mainUnitFlag);

extern void MORPH_UpdateTextures();

extern void MORPH_Continue();

extern void STREAM_MORPH_Relocate();

extern int AddVertex(struct VECTOR *v0, struct RECT *rect);

extern int GetPlaneDist(int k, int j, int i, struct VECTOR *v);

extern void CalcVert(struct VECTOR *v, struct VECTOR *v1, struct VECTOR *v2, int dist1, int dist2, int k, int j);

extern int AddClippedTri(struct SVECTOR *iv, struct RECT *cliprect, int *minz);

extern int STREAM_GetClipRect(struct StreamUnitPortal *portal, struct RECT *rect);

extern long GetFogColor(struct StreamUnitPortal *portal, struct _StreamUnit *mainStreamUnit, struct Level *mainLevel);

extern void DrawFogRectangle(struct RECT *cliprect, struct _PrimPool *primPool, int otzpos, unsigned long **drawot, long color);

extern void STREAM_RenderAdjacantUnit(unsigned long **curOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *toStreamUnit, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect);

extern struct BSPTree *STREAM_GetBspTree(struct _StreamUnit *streamUnit, long bspNumber);

extern void WARPGATE_BlockWarpGateEntrance(struct _StreamUnit *streamUnit, long collideOn);

extern void WARPGATE_DrawWarpGateRim(struct _StreamUnit *streamUnit, long drawOn);

extern void WARPGATE_HideAllCloudCovers();

extern struct _Instance *WARPGATE_UnHideCloudCoverInUnit(long streamUnitID);

extern void STREAM_RenderWarpGate(unsigned long **mainOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect);

extern void WARPGATE_RenderWarpUnit(unsigned long **mainOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect);

extern void STREAM_DumpNonResidentObjects();

extern int STREAM_TryAndDumpNonResident(struct _ObjectTracker *otr);

#endif
