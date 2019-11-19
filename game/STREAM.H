#ifndef STREAM_H
#define STREAM_H


extern void STREAM_FillOutFileNames(char *baseAreaName, char *dramName, char *vramName, char *sfxName); // 0x80059AD0

extern void STREAM_AbortAreaLoad(char *baseAreaName); // 0x80059B90

extern void STREAM_Init(); // 0x80059BC8

extern int FindObjectName(char *name); // 0x80059BEC

extern struct _ObjectTracker * FindObjectInTracker(struct Object *object); // 0x80059C58

extern struct _StreamUnit * FindStreamUnitFromLevel(struct Level *level); // 0x80059CA8

extern void STREAM_LoadObjectReturn(void *loadData, void *data, void *data2); // 0x80059CFC

extern void STREAM_DumpMonster(struct _ObjectTracker *dumpee); // 0x80059DF4

extern int STREAM_InList(char *name, char **nameList); // 0x80059EC0

extern int STREAM_IsSpecialMonster(char *name); // 0x80059F28

extern void STREAM_DumpSomeMonsters(); // 0x80059F4C

extern void STREAM_NoMonsters(); // 0x80059FF4

extern void STREAM_YesMonsters(); // 0x8005A024

extern int STREAM_IsMonster(char *name); // 0x8005A040

extern void STREAM_DumpAMonster(int needed); // 0x8005A064

extern int InsertGlobalObject(char *name, struct GameTracker *gameTracker); // 0x8005A178

extern struct _ObjectTracker * STREAM_GetObjectTracker(char *name); // 0x8005A300

extern void LoadLevelObjects(struct Level *level, struct GameTracker *gameTracker); // 0x8005A350

extern long STREAM_IsAnInstanceUsingObject(struct Object *object); // 0x8005A440

extern void STREAM_StreamLoadObjectAbort(void *loadData, void *data, void *data2); // 0x8005A480

extern void STREAM_DumpObject(struct _ObjectTracker *objectTracker); // 0x8005A4B0

extern int STREAM_IsObjectInAnyUnit(struct _ObjectTracker *tracker); // 0x8005A59C

extern void STREAM_RemoveAllObjectsNotInUse(struct GameTracker *gameTracker); // 0x8005A660

extern void RemoveAllObjects(struct GameTracker *gameTracker); // 0x8005A910

extern struct Level * STREAM_GetLevelWithID(long id); // 0x8005A968

extern struct _StreamUnit * STREAM_GetStreamUnitWithID(long id); // 0x8005A9C4

extern void STREAM_CalculateWaterLevel(struct Level *level); // 0x8005AA18

extern int STREAM_IsMorphInProgress(); // 0x8005AB48

extern long STREAM_GetWaterZLevel(struct Level *level, struct _Instance *instance); // 0x8005AB5C

extern void STREAM_SetMainFog(struct _StreamUnit *streamUnit); // 0x8005ABDC

extern void STREAM_SetStreamFog(struct _StreamUnit *streamUnit, short fogNear, short fogFar); // 0x8005AC30

extern void STREAM_ConnectStream(struct _StreamUnit *streamUnit); // 0x8005ACC0

extern void STREAM_StreamLoadLevelAbort(void *loadData, void *data, void *data2); // 0x8005AF24

extern void STREAM_FinishLoad(struct _StreamUnit *streamUnit); // 0x8005AF58

extern void STREAM_LoadLevelReturn(void *loadData, void *data, void *data2); // 0x8005B094

extern void STREAM_StreamLoadLevelReturn(void *loadData, void *data, void *data2); // 0x8005B124

extern void STREAM_UpdateLevelPointer(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel); // 0x8005B234

extern struct _StreamUnit * STREAM_WhichUnitPointerIsIn(void *pointer); // 0x8005B4EC

extern void STREAM_UpdateObjectPointer(struct Object *oldObject, struct Object *newObject, long sizeOfObject); // 0x8005B59C

extern void STREAM_UpdateInstanceCollisionInfo(struct _HModel *oldHModel, struct _HModel *newHModel); // 0x8005B840

extern void STREAM_LoadMainVram(struct GameTracker *gameTracker, char *baseAreaName, struct _StreamUnit *streamUnit); // 0x8005B884

extern void STREAM_MoveIntoNewStreamUnit(); // 0x8005B938

extern struct _StreamUnit * STREAM_LoadLevel(struct GameTracker *gameTracker, char *baseAreaName, struct StreamUnitPortal *streamPortal, int loadnext); // 0x8005B9A0

extern void RemoveIntroducedLights(struct Level *level); // 0x8005BBC0

extern void STREAM_RemoveInstancesWithIDInInstanceList(struct _InstanceList *list, long id, struct Level *level); // 0x8005BCA4

extern void STREAM_MarkUnitNeeded(long streamID); // 0x8005BD50

extern void STREAM_DumpUnit(struct _StreamUnit *streamUnit, long doSave); // 0x8005BDA0

extern void STREAM_DumpAllUnitsNotNeeded(struct GameTracker *gameTracker); // 0x8005BF94

extern void STREAM_DumpAllLevels(long IDNoRemove); // 0x8005C00C

extern void STREAM_LoadCurrentWarpRoom(struct StreamUnitPortal *streamPortal, struct _StreamUnit *mainStreamUnit); // 0x8005C080

extern void WARPGATE_RelocateLoadedWarpRooms(struct _StreamUnit *mainUnit, struct StreamUnitPortal *streamPortal); // 0x8005C174

extern long WARPGATE_GetWarpRoomIndex(char *name); // 0x8005C210

extern void WARPGATE_UpdateAddToArray(struct _StreamUnit *streamUnit); // 0x8005C274

extern void WARPGATE_RemoveFromArray(struct _StreamUnit *streamUnit); // 0x8005C2C4

extern void WARPGATE_IsItActive(struct _StreamUnit *streamUnit); // 0x8005C2F4

extern long WARPGATE_IsUnitWarpRoom(struct _StreamUnit *streamUnit); // 0x8005C3BC

extern void WARPGATE_FixUnit(struct _StreamUnit *streamUnit); // 0x8005C414

extern void STREAM_MarkWarpUnitsNeeded(); // 0x8005C448

extern long WARPGATE_IncrementIndex(); // 0x8005C48C

extern void WARPGATE_CalcWarpFade(int timeInc); // 0x8005C594

extern long WARPGATE_DecrementIndex(); // 0x8005C604

extern void PreloadAllConnectedUnits(struct GameTracker *gameTracker, struct _StreamUnit *streamUnit, struct _SVector *offset); // 0x8005C6CC

extern void RelocateLevel(struct Level *level, struct _SVector *offset); // 0x8005C8B0

extern void RelocateCameras(struct _CameraKey *cameraList, long numCameras, struct _SVector *offset); // 0x8005CA14

extern void RelocateSavedCameras(struct Camera *camera, struct Level *level, struct _SVector *offset); // 0x8005CAA8

extern void RelocateLevelWithInstances(struct Level *level, struct _SVector *offset); // 0x8005CBE0

extern void RelocateTerrain(struct _Terrain *terrain, struct _SVector *offset); // 0x8005CC24

extern void RelocateVMObjects(struct _VMObject *vobjectlist, long numvmobjs, struct _SVector *offset); // 0x8005CE3C

extern void RelocateSpotLights(struct SpotLight *spotLightList, long numSpotLights, struct _SVector *offset); // 0x8005CE94

extern void RelocatePointLights(struct PointLight *PLightList, long numPLights, struct _SVector *offset); // 0x8005CF28

extern void RelocateBGObjects(struct _BGObject *BGObjList, long numBGObjs, struct _SVector *offset); // 0x8005CF80

extern void RelocatePlanPool(struct PlanningNode *planPool, struct _SVector *offset); // 0x8005D024

extern void RelocatePlanMarkers(struct _PlanMkr *planMkrList, int numPlanMkrs, struct _SVector *offset); // 0x8005D0D8

extern void RelocateSFXMarkers(struct _SFXMkr *sfxMkrList, int numSFXMkrs, struct _SVector *offset); // 0x8005D12C

extern void STREAM_AdjustMultiSpline(struct MultiSpline *multi, struct _SVector *offset); // 0x8005D178

extern void STREAM_RelocateInstance(struct GameTracker *gameTracker, struct _Instance *instance, struct _SVector *offset); // 0x8005D228

extern void STREAM_OffsetInstancePosition(struct GameTracker *gameTracker, struct _Instance *instance, struct _SVector *offset, int streamSignalFlag); // 0x8005D270

extern void STREAM_SetInstancePosition(struct GameTracker *gameTracker, struct _Instance *instance, struct evPositionData *data); // 0x8005D38C

extern void RelocateInstances(struct GameTracker *gameTracker, struct _SVector *offset, long StreamUnitID); // 0x8005D3E4

extern void RelocateStreamPortals(struct StreamUnitPortal *StreamUnitList, int NumStreamUnits, struct _SVector *offset); // 0x8005D454

extern void STREAM_PackVRAMObject(struct _ObjectTracker *objectTracker); // 0x8005D584

extern void MORPH_SetupInstanceFlags(struct GameTracker *gameTracker, struct _Instance *instance); // 0x8005D684

extern void MORPH_SetupInstanceListFlags(struct GameTracker *gameTracker); // 0x8005D79C

extern void MORPH_InMorphInstanceListFlags(struct GameTracker *gameTracker); // 0x8005D7F4

extern void MORPH_InMorphDoFadeValues(struct GameTracker *gameTracker); // 0x8005D85C

extern void MORPH_UpdateTimeMult(); // 0x8005D8AC

extern void MORPH_UpdateNormals(struct Level *BaseLevel); // 0x8005DA20

extern void MORPH_BringBackNormals(struct Level *BaseLevel); // 0x8005DEFC

extern void MORPH_AddOffsets(struct Level *BaseLevel, int time); // 0x8005E420

extern void MORPH_SubtractOffsets(struct Level *BaseLevel, int time); // 0x8005E840

extern void MORPH_GetComponentsForTrackingPoint(struct _TFace *face); // 0x8005EC68

extern void MORPH_UpdateTrackingPoint(struct _Vector *point, struct _TFace *face); // 0x8005EF34

extern void MORPH_ToggleMorph(); // 0x8005F144

extern void MORPH_DoStep(struct _StreamUnit *streamUnit, char *baseAreaName); // 0x8005F264

extern void MORPH_SetFog(struct _StreamUnit *streamUnit, int mainUnitFlag); // 0x8005F498

extern void MORPH_UpdateTextures(); // 0x8005F56C

extern void MORPH_Continue(); // 0x8005F5C4

extern void STREAM_MORPH_Relocate(); // 0x8005F6E8

extern int AddVertex(struct VECTOR *v0, struct RECT *rect); // 0x8005F6F4

extern int GetPlaneDist(int k, int j, int i, struct VECTOR *v); // 0x8005F880

extern void CalcVert(struct VECTOR *v, struct VECTOR *v1, struct VECTOR *v2, int dist1, int dist2, int k, int j); // 0x8005F910

extern int AddClippedTri(struct SVECTOR *iv, struct RECT *cliprect, int *minz); // 0x8005F998

extern int STREAM_GetClipRect(struct StreamUnitPortal *portal, struct RECT *rect); // 0x8005FC40

extern long GetFogColor(struct StreamUnitPortal *portal, struct _StreamUnit *mainStreamUnit, struct Level *mainLevel); // 0x8006020C

extern void DrawFogRectangle(struct RECT *cliprect, struct _PrimPool *primPool, int otzpos, unsigned long **drawot, long color); // 0x80060530

extern void STREAM_RenderAdjacantUnit(unsigned long **curOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *toStreamUnit, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect); // 0x8006060C

extern struct BSPTree * STREAM_GetBspTree(struct _StreamUnit *streamUnit, long bspNumber); // 0x800606B8

extern void WARPGATE_BlockWarpGateEntrance(struct _StreamUnit *streamUnit, long collideOn); // 0x80060718

extern void WARPGATE_DrawWarpGateRim(struct _StreamUnit *streamUnit, long drawOn); // 0x80060770

extern void WARPGATE_HideAllCloudCovers(); // 0x800607DC

extern struct _Instance * WARPGATE_UnHideCloudCoverInUnit(long streamUnitID); // 0x8006083C

extern void STREAM_RenderWarpGate(unsigned long **mainOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect); // 0x800608B4

extern void WARPGATE_RenderWarpUnit(unsigned long **mainOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect); // 0x80060A60

extern void STREAM_DumpNonResidentObjects(); // 0x80060DB4


#endif
