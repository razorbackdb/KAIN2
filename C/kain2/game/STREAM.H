#ifndef STREAM_H
#define STREAM_H


extern void STREAM_FillOutFileNames(char *baseAreaName, char *dramName, char *vramName, char *sfxName); // 0x80058A00

extern void STREAM_AbortAreaLoad(char *baseAreaName); // 0x80058AC0

extern void STREAM_Init(); // 0x80058B08

extern int FindObjectName(char *name); // 0x80058B34

extern struct _ObjectTracker * FindObjectInTracker(struct Object *object); // 0x80058BA0

extern struct _StreamUnit * FindStreamUnitFromLevel(struct Level *level); // 0x80058BF0

extern void STREAM_LoadObjectReturn(void *loadData, void *data, void *data2); // 0x80058C40

extern void STREAM_DumpMonster(struct _ObjectTracker *dumpee); // 0x80058D30

extern int STREAM_InList(char *name, char **nameList); // 0x80058DF8

extern int STREAM_IsSpecialMonster(char *name); // 0x80058E60

extern void STREAM_DumpSomeMonsters(); // 0x80058E84

extern void STREAM_NoMonsters(); // 0x80058F14

extern void STREAM_YesMonsters(); // 0x80058F44

extern int STREAM_IsMonster(char *name); // 0x80058F60

extern int STREAM_TryAndDumpANonResidentObject(); // 0x80058F84

extern int InsertGlobalObject(char *name, struct GameTracker *gameTracker); // 0x80058FD4

extern struct _ObjectTracker * STREAM_GetObjectTracker(char *name); // 0x80059170

extern void LoadLevelObjects(struct _StreamUnit *stream); // 0x800591BC

extern long STREAM_IsAnInstanceUsingObject(struct Object *object); // 0x800592E0

extern void STREAM_StreamLoadObjectAbort(void *loadData, void *data, void *data2); // 0x80059320

extern void STREAM_DumpLoadingObjects(); // 0x80059350

extern void STREAM_DumpObject(struct _ObjectTracker *objectTracker); // 0x800593B0

extern int STREAM_IsObjectInAnyUnit(struct _ObjectTracker *tracker); // 0x80059498

extern void STREAM_RemoveAllObjectsNotInUse(); // 0x80059558

extern void RemoveAllObjects(struct GameTracker *gameTracker); // 0x80059818

extern struct Level * STREAM_GetLevelWithID(long id); // 0x80059870

extern struct _StreamUnit * STREAM_GetStreamUnitWithID(long id); // 0x800598C8

extern void STREAM_CalculateWaterLevel(struct Level *level); // 0x80059918

extern int STREAM_IsMorphInProgress(); // 0x80059A48

extern long STREAM_GetWaterZLevel(struct Level *level, struct _Instance *instance); // 0x80059A5C

extern void STREAM_SetMainFog(struct _StreamUnit *streamUnit); // 0x80059ADC

extern void STREAM_SetStreamFog(struct _StreamUnit *streamUnit, short fogNear, short fogFar); // 0x80059B30

extern void STREAM_ConnectStream(struct _StreamUnit *streamUnit); // 0x80059BC0

extern void STREAM_StreamLoadLevelAbort(void *loadData, void *data, void *data2); // 0x80059FCC

extern void STREAM_DoObjectLoadAndDump(struct _StreamUnit *streamUnit); // 0x8005A004

extern void STREAM_FinishLoad(struct _StreamUnit *streamUnit); // 0x8005A04C

extern void STREAM_LoadLevelReturn(void *loadData, void *data, void *data2); // 0x8005A198

extern void STREAM_StreamLoadLevelReturn(void *loadData, void *data, void *data2); // 0x8005A1F8

extern void STREAM_UpdateLevelPointer(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel); // 0x8005A2E0

extern struct _StreamUnit * STREAM_WhichUnitPointerIsIn(void *pointer); // 0x8005A5D0

extern void STREAM_UpdateObjectPointer(struct Object *oldObject, struct Object *newObject, long sizeOfObject); // 0x8005A67C

extern void STREAM_UpdateInstanceCollisionInfo(struct _HModel *oldHModel, struct _HModel *newHModel); // 0x8005A91C

extern void STREAM_LoadMainVram(struct GameTracker *gameTracker, char *baseAreaName, struct _StreamUnit *streamUnit); // 0x8005A960

extern void STREAM_MoveIntoNewStreamUnit(); // 0x8005AA08

extern struct _StreamUnit * STREAM_LoadLevel(char *baseAreaName, struct StreamUnitPortal *streamPortal, int loadnext); // 0x8005AA9C

extern void RemoveIntroducedLights(struct Level *level); // 0x8005ACC0

extern void STREAM_RemoveInstancesWithIDInInstanceList(struct _InstanceList *list, long id, struct Level *level); // 0x8005ADA4

extern void STREAM_MarkUnitNeeded(long streamID); // 0x8005AE50

extern void STREAM_DumpUnit(struct _StreamUnit *streamUnit, long doSave); // 0x8005AE9C

extern void STREAM_DumpAllUnitsNotNeeded(); // 0x8005B080

extern void STREAM_DumpAllLevels(long IDNoRemove, int DoSave); // 0x8005B0E8

extern void STREAM_LoadCurrentWarpRoom(struct StreamUnitPortal *streamPortal, struct _StreamUnit *mainStreamUnit); // 0x8005B164

extern void WARPGATE_RelocateLoadedWarpRooms(struct _StreamUnit *mainUnit, struct StreamUnitPortal *streamPortal); // 0x8005B220

extern long WARPGATE_GetWarpRoomIndex(char *name); // 0x8005B2C8

extern void WARPGATE_UpdateAddToArray(struct _StreamUnit *streamUnit); // 0x8005B328

extern void WARPGATE_RemoveFromArray(struct _StreamUnit *streamUnit); // 0x8005B374

extern void WARPGATE_Init(); // 0x8005B3A4

extern void WARPGATE_StartUsingWarpgate(); // 0x8005B3EC

extern void WARPGATE_EndUsingWarpgate(); // 0x8005B424

extern int WARPGATE_IsWarpgateInUse(); // 0x8005B45C

extern int WARPGATE_IsWarpgateActive(); // 0x8005B468

extern int WARPGATE_IsWarpgateUsable(); // 0x8005B474

extern int WARPGATE_IsWarpgateReady(); // 0x8005B488

extern int WARPGATE_IsWarpgateSpectral(); // 0x8005B49C

extern int WARPGATE_IsObjectOnWarpSide(struct _Instance *instance); // 0x8005B4D8

extern void WARPGATE_IsItActive(struct _StreamUnit *streamUnit); // 0x8005B53C

extern long WARPGATE_IsUnitWarpRoom(struct _StreamUnit *streamUnit); // 0x8005B604

extern void WARPGATE_FixUnit(struct _StreamUnit *streamUnit); // 0x8005B65C

extern void STREAM_MarkWarpUnitsNeeded(); // 0x8005B690

extern long WARPGATE_IncrementIndex(); // 0x8005B6D0

extern void WARPGATE_CalcWarpFade(int timeInc); // 0x8005B7E8

extern long WARPGATE_DecrementIndex(); // 0x8005B858

extern void PreloadAllConnectedUnits(struct _StreamUnit *streamUnit, struct _SVector *offset); // 0x8005B930

extern void RelocateLevel(struct Level *level, struct _SVector *offset); // 0x8005BAF4

extern void RelocateCameras(struct _CameraKey *cameraList, long numCameras, struct _SVector *offset); // 0x8005BC34

extern void RelocateSavedCameras(struct Camera *camera, struct Level *level, struct _SVector *offset); // 0x8005BCC8

extern void RelocateLevelWithInstances(struct Level *level, struct _SVector *offset); // 0x8005BE00

extern void RelocateTerrain(struct _Terrain *terrain, struct _SVector *offset); // 0x8005BE38

extern void RelocateVMObjects(struct _VMObject *vobjectlist, long numvmobjs, struct _SVector *offset); // 0x8005BF28

extern void RelocateBGObjects(struct _BGObject *BGObjList, long numBGObjs, struct _SVector *offset); // 0x8005BF80

extern void RelocatePlanPool(struct PlanningNode *planPool, struct _SVector *offset); // 0x8005C024

extern void RelocatePlanMarkers(struct _PlanMkr *planMkrList, int numPlanMkrs, struct _SVector *offset); // 0x8005C0D8

extern void RelocateSFXMarkers(struct _SFXMkr *sfxMkrList, int numSFXMkrs, struct _SVector *offset); // 0x8005C12C

extern void STREAM_AdjustMultiSpline(struct MultiSpline *multi, struct _SVector *offset); // 0x8005C178

extern void STREAM_RelocateInstance(struct _Instance *instance, struct _SVector *offset); // 0x8005C228

extern void STREAM_OffsetInstancePosition(struct _Instance *instance, struct _SVector *offset, int streamSignalFlag); // 0x8005C270

extern void STREAM_SetInstancePosition(struct _Instance *instance, struct evPositionData *data); // 0x8005C388

extern void RelocateInstances(struct _SVector *offset); // 0x8005C3E0

extern void RelocateStreamPortals(struct StreamUnitPortal *StreamUnitList, int NumStreamUnits, struct _SVector *offset); // 0x8005C43C

extern void STREAM_PackVRAMObject(struct _ObjectTracker *objectTracker); // 0x8005C56C

extern void MORPH_SetupInstanceFlags(struct _Instance *instance); // 0x8005C66C

extern void MORPH_SetupInstanceListFlags(); // 0x8005C794

extern void MORPH_InMorphInstanceListFlags(); // 0x8005C7DC

extern void MORPH_InMorphDoFadeValues(); // 0x8005C844

extern void MORPH_UpdateTimeMult(); // 0x8005C89C

extern void MORPH_UpdateNormals(struct Level *BaseLevel); // 0x8005CA10

extern void MORPH_BringBackNormals(struct Level *BaseLevel); // 0x8005CEC4

extern void MORPH_AddOffsets(struct Level *BaseLevel, int time); // 0x8005D334

extern void MORPH_SubtractOffsets(struct Level *BaseLevel, int time); // 0x8005D700

extern void MORPH_GetComponentsForTrackingPoint(struct _TFace *face, struct Level *level); // 0x8005DAD4

extern void MORPH_AveragePoint(struct _SVector *start, struct _SVector *end, int interp, struct _SVector *out); // 0x8005DDB4

extern void MORPH_UpdateTrackingPoint(struct _TFace *face, struct Level *level); // 0x8005DE2C

extern void MORPH_ToggleMorph(); // 0x8005DFD0

extern void MORPH_DoStep(struct _StreamUnit *streamUnit, char *baseAreaName); // 0x8005E11C

extern void MORPH_SetFog(struct _StreamUnit *streamUnit, int mainUnitFlag); // 0x8005E1F8

extern void MORPH_UpdateTextures(); // 0x8005E2CC

extern void MORPH_Continue(); // 0x8005E324

extern void STREAM_MORPH_Relocate(); // 0x8005E498

extern int AddVertex(struct VECTOR *v0, struct RECT *rect); // 0x8005E4A8

extern int GetPlaneDist(int k, int j, int i, struct VECTOR *v); // 0x8005E634

extern void CalcVert(struct VECTOR *v, struct VECTOR *v1, struct VECTOR *v2, int dist1, int dist2, int k, int j); // 0x8005E6C0

extern int AddClippedTri(struct SVECTOR *iv, struct RECT *cliprect, int *minz); // 0x8005E748

extern int STREAM_GetClipRect(struct StreamUnitPortal *portal, struct RECT *rect); // 0x8005E9F0

extern long GetFogColor(struct StreamUnitPortal *portal, struct _StreamUnit *mainStreamUnit, struct Level *mainLevel); // 0x8005EFB8

extern void DrawFogRectangle(struct RECT *cliprect, struct _PrimPool *primPool, int otzpos, unsigned long **drawot, long color); // 0x8005F2DC

extern void STREAM_RenderAdjacantUnit(unsigned long **curOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *toStreamUnit, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect); // 0x8005F3C8

extern struct BSPTree * STREAM_GetBspTree(struct _StreamUnit *streamUnit, long bspNumber); // 0x8005F474

extern void WARPGATE_BlockWarpGateEntrance(struct _StreamUnit *streamUnit, long collideOn); // 0x8005F4D4

extern void WARPGATE_DrawWarpGateRim(struct _StreamUnit *streamUnit, long drawOn); // 0x8005F544

extern void WARPGATE_HideAllCloudCovers(); // 0x8005F59C

extern struct _Instance * WARPGATE_UnHideCloudCoverInUnit(long streamUnitID); // 0x8005F5FC

extern void STREAM_RenderWarpGate(unsigned long **mainOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect); // 0x8005F674

extern void WARPGATE_RenderWarpUnit(unsigned long **mainOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *mainStreamUnit, struct RECT *cliprect); // 0x8005F9AC

extern void STREAM_DumpNonResidentObjects(); // 0x8005FD84

extern int STREAM_TryAndDumpNonResident(struct _ObjectTracker *otr); // 0x8005FE34


#endif
