#ifndef STREAM_H
#define STREAM_H

#include "LIBGPU.H"

extern void STREAM_FillOutFileNames(char *baseAreaName, char *dramName, char *vramName, char *sfxName); // 0x80058BD8

extern void STREAM_AbortAreaLoad(char *baseAreaName); // 0x80058C98

extern void STREAM_Init(); // 0x80058CD0

extern int FindObjectName(char *name); // 0x80058CF4

extern struct _ObjectTracker * FindObjectInTracker(struct Object *object); // 0x80058D60

extern struct _StreamUnit * FindStreamUnitFromLevel(struct Level *level); // 0x80058DB0

extern void STREAM_LoadObjectReturn(void *loadData, void *data, void *data2); // 0x80058E04

extern void STREAM_DumpMonster(struct _ObjectTracker *dumpee); // 0x80058EE4

extern int STREAM_InList(char *name, char **nameList); // 0x80058FAC

extern int STREAM_IsSpecialMonster(char *name); // 0x80059014

extern void STREAM_DumpSomeMonsters(); // 0x80059038

extern void STREAM_NoMonsters(); // 0x800590E0

extern void STREAM_YesMonsters(); // 0x80059110

extern int STREAM_IsMonster(char *name); // 0x8005912C

extern int InsertGlobalObject(char *name, struct GameTracker *gameTracker); // 0x80059150

extern struct _ObjectTracker * STREAM_GetObjectTracker(char *name); // 0x8005930C

extern void LoadLevelObjects(struct Level *level, struct GameTracker *gameTracker); // 0x8005935C

extern long STREAM_IsAnInstanceUsingObject(struct Object *object); // 0x8005944C

extern void STREAM_StreamLoadObjectAbort(void *loadData, void *data, void *data2); // 0x8005948C

extern void STREAM_DumpObject(struct _ObjectTracker *objectTracker); // 0x800594BC

extern int STREAM_IsObjectInAnyUnit(struct _ObjectTracker *tracker); // 0x800595A4

extern void STREAM_RemoveAllObjectsNotInUse(struct GameTracker *gameTracker); // 0x80059668

extern void RemoveAllObjects(struct GameTracker *gameTracker); // 0x80059918

extern struct Level * STREAM_GetLevelWithID(long id); // 0x80059970

extern struct _StreamUnit * STREAM_GetStreamUnitWithID(long id); // 0x800599CC

extern void STREAM_CalculateWaterLevel(struct Level *level); // 0x80059A20

extern int STREAM_IsMorphInProgress(); // 0x80059B50

extern long STREAM_GetWaterZLevel(struct Level *level, struct _Instance *instance); // 0x80059B64

extern void STREAM_SetMainFog(struct _StreamUnit *streamUnit); // 0x80059BE4

extern void STREAM_SetStreamFog(struct _StreamUnit *streamUnit, short fogNear, short fogFar); // 0x80059C38

extern void STREAM_ConnectStream(struct _StreamUnit *streamUnit); // 0x80059CC8

extern void STREAM_StreamLoadLevelAbort(void *loadData, void *data, void *data2); // 0x8005A0DC

extern void STREAM_FinishLoad(struct _StreamUnit *streamUnit); // 0x8005A110

extern void STREAM_LoadLevelReturn(void *loadData, void *data, void *data2); // 0x8005A25C

extern void STREAM_StreamLoadLevelReturn(void *loadData, void *data, void *data2); // 0x8005A2BC

extern void STREAM_UpdateLevelPointer(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel); // 0x8005A3A4

extern struct _StreamUnit * STREAM_WhichUnitPointerIsIn(void *pointer); // 0x8005A674

extern void STREAM_UpdateObjectPointer(struct Object *oldObject, struct Object *newObject, long sizeOfObject); // 0x8005A724

extern void STREAM_UpdateInstanceCollisionInfo(struct _HModel *oldHModel, struct _HModel *newHModel); // 0x8005A9C8

extern void STREAM_LoadMainVram(struct GameTracker *gameTracker, char *baseAreaName, struct _StreamUnit *streamUnit); // 0x8005AA0C

extern void STREAM_MoveIntoNewStreamUnit(); // 0x8005AAC0

extern struct _StreamUnit * STREAM_LoadLevel(struct GameTracker *gameTracker, char *baseAreaName, struct StreamUnitPortal *streamPortal, int loadnext); // 0x8005AB40

extern void RemoveIntroducedLights(struct Level *level); // 0x8005AD60

extern void STREAM_RemoveInstancesWithIDInInstanceList(struct _InstanceList *list, long id, struct Level *level); // 0x8005AE44

extern void STREAM_MarkUnitNeeded(long streamID); // 0x8005AEF0

extern void STREAM_DumpUnit(struct _StreamUnit *streamUnit, long doSave); // 0x8005AF40

extern void STREAM_DumpAllUnitsNotNeeded(struct GameTracker *gameTracker); // 0x8005B130

extern void STREAM_DumpAllLevels(long IDNoRemove, int DoSave); // 0x8005B1A8

extern void STREAM_LoadCurrentWarpRoom(struct StreamUnitPortal *streamPortal, struct _StreamUnit *mainStreamUnit); // 0x8005B228

extern void WARPGATE_RelocateLoadedWarpRooms(struct _StreamUnit *mainUnit, struct StreamUnitPortal *streamPortal); // 0x8005B2F0

extern long WARPGATE_GetWarpRoomIndex(char *name); // 0x8005B38C

extern void WARPGATE_UpdateAddToArray(struct _StreamUnit *streamUnit); // 0x8005B3F0

extern void WARPGATE_RemoveFromArray(struct _StreamUnit *streamUnit); // 0x8005B440

extern void WARPGATE_Init(); // 0x8005B470

extern void WARPGATE_StartUsingWarpgate(); // 0x8005B4A0

extern void WARPGATE_EndUsingWarpgate(); // 0x8005B4D8

extern int WARPGATE_IsWarpgateInUse(); // 0x8005B510

extern int WARPGATE_IsWarpgateActive(); // 0x8005B51C

extern int WARPGATE_IsWarpgateUsable(); // 0x8005B528

extern int WARPGATE_IsWarpgateSpectral(); // 0x8005B53C

extern void WARPGATE_IsItActive(struct _StreamUnit *streamUnit); // 0x8005B57C

extern long WARPGATE_IsUnitWarpRoom(struct _StreamUnit *streamUnit); // 0x8005B644

extern void WARPGATE_FixUnit(struct _StreamUnit *streamUnit); // 0x8005B69C

extern void STREAM_MarkWarpUnitsNeeded(); // 0x8005B6D0

extern long WARPGATE_IncrementIndex(); // 0x8005B714

extern void WARPGATE_CalcWarpFade(int timeInc); // 0x8005B834

extern long WARPGATE_DecrementIndex(); // 0x8005B8A4

extern void PreloadAllConnectedUnits(struct GameTracker *gameTracker, struct _StreamUnit *streamUnit, struct _SVector *offset); // 0x8005B984

extern void RelocateLevel(struct Level *level, struct _SVector *offset); // 0x8005BB4C

extern void RelocateCameras(struct _CameraKey *cameraList, long numCameras, struct _SVector *offset); // 0x8005BCB0

extern void RelocateSavedCameras(struct Camera *camera, struct Level *level, struct _SVector *offset); // 0x8005BD44

extern void RelocateLevelWithInstances(struct Level *level, struct _SVector *offset); // 0x8005BE7C

extern void RelocateTerrain(struct _Terrain *terrain, struct _SVector *offset); // 0x8005BEC0

extern void RelocateVMObjects(struct _VMObject *vobjectlist, long numvmobjs, struct _SVector *offset); // 0x8005BFB0

extern void RelocateSpotLights(struct SpotLight *spotLightList, long numSpotLights, struct _SVector *offset); // 0x8005C008

extern void RelocatePointLights(struct PointLight *PLightList, long numPLights, struct _SVector *offset); // 0x8005C09C

extern void RelocateBGObjects(struct _BGObject *BGObjList, long numBGObjs, struct _SVector *offset); // 0x8005C0F4

extern void RelocatePlanPool(struct PlanningNode *planPool, struct _SVector *offset); // 0x8005C198

extern void RelocatePlanMarkers(struct _PlanMkr *planMkrList, int numPlanMkrs, struct _SVector *offset); // 0x8005C24C

extern void RelocateSFXMarkers(struct _SFXMkr *sfxMkrList, int numSFXMkrs, struct _SVector *offset); // 0x8005C2A0

extern void STREAM_AdjustMultiSpline(struct MultiSpline *multi, struct _SVector *offset); // 0x8005C2EC

extern void STREAM_RelocateInstance(struct GameTracker *gameTracker, struct _Instance *instance, struct _SVector *offset); // 0x8005C39C

extern void STREAM_OffsetInstancePosition(struct GameTracker *gameTracker, struct _Instance *instance, struct _SVector *offset, int streamSignalFlag); // 0x8005C3E4

extern void STREAM_SetInstancePosition(struct GameTracker *gameTracker, struct _Instance *instance, struct evPositionData *data); // 0x8005C500

extern void RelocateInstances(struct GameTracker *gameTracker, struct _SVector *offset, long StreamUnitID); // 0x8005C558

extern void RelocateStreamPortals(struct StreamUnitPortal *StreamUnitList, int NumStreamUnits, struct _SVector *offset); // 0x8005C5C8

extern void STREAM_PackVRAMObject(struct _ObjectTracker *objectTracker); // 0x8005C6F8

extern void MORPH_SetupInstanceFlags(struct GameTracker *gameTracker, struct _Instance *instance); // 0x8005C7F8

extern void MORPH_SetupInstanceListFlags(struct GameTracker *gameTracker); // 0x8005C910

extern void MORPH_InMorphInstanceListFlags(struct GameTracker *gameTracker); // 0x8005C968

extern void MORPH_InMorphDoFadeValues(struct GameTracker *gameTracker); // 0x8005C9D0

extern void MORPH_UpdateTimeMult(); // 0x8005CA20

extern void MORPH_UpdateNormals(struct Level *BaseLevel); // 0x8005CB94

extern void MORPH_BringBackNormals(struct Level *BaseLevel); // 0x8005D084

extern void MORPH_AddOffsets(struct Level *BaseLevel, int time); // 0x8005D538

extern void MORPH_SubtractOffsets(struct Level *BaseLevel, int time); // 0x8005D904

extern void MORPH_GetComponentsForTrackingPoint(struct _TFace *face, struct Level *level); // 0x8005DCD8

extern void MORPH_AveragePoint(struct _SVector *start, struct _SVector *end, int interp, struct _SVector *out); // 0x8005DFC0

extern void MORPH_UpdateTrackingPoint(struct _TFace *face, struct Level *level); // 0x8005E014

extern void MORPH_ToggleMorph(); // 0x8005E1AC

extern void MORPH_DoStep(struct _StreamUnit *streamUnit, char *baseAreaName); // 0x8005E2FC

extern void MORPH_SetFog(struct _StreamUnit *streamUnit, int mainUnitFlag); // 0x8005E3D8

extern void MORPH_UpdateTextures(); // 0x8005E4AC

extern void MORPH_Continue(); // 0x8005E504

extern void STREAM_MORPH_Relocate(); // 0x8005E694

extern int AddVertex(VECTOR *v0, RECT *rect); // 0x8005E6A4

extern int GetPlaneDist(int k, int j, int i, struct VECTOR *v); // 0x8005E830

extern void CalcVert(struct VECTOR *v, struct VECTOR *v1, struct VECTOR *v2, int dist1, int dist2, int k, int j); // 0x8005E8C0

extern int AddClippedTri(SVECTOR *iv, RECT *cliprect, int *minz); // 0x8005E948

extern int STREAM_GetClipRect(StreamUnitPortal *portal, RECT *rect); // 0x8005EBF0

extern long GetFogColor(struct StreamUnitPortal *portal, struct _StreamUnit *mainStreamUnit, struct Level *mainLevel); // 0x8005F1BC

extern void DrawFogRectangle(RECT *cliprect, struct _PrimPool *primPool, int otzpos, unsigned long **drawot, long color); // 0x8005F4E0

extern void STREAM_RenderAdjacantUnit(unsigned long **curOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *toStreamUnit, struct _StreamUnit *mainStreamUnit, RECT *cliprect); // 0x8005F5CC

extern struct BSPTree * STREAM_GetBspTree(struct _StreamUnit *streamUnit, long bspNumber); // 0x8005F678

extern void WARPGATE_BlockWarpGateEntrance(struct _StreamUnit *streamUnit, long collideOn); // 0x8005F6D8

extern void WARPGATE_DrawWarpGateRim(struct _StreamUnit *streamUnit, long drawOn); // 0x8005F748

extern void WARPGATE_HideAllCloudCovers(); // 0x8005F7A0

extern struct _Instance * WARPGATE_UnHideCloudCoverInUnit(long streamUnitID); // 0x8005F800

extern void STREAM_RenderWarpGate(unsigned long **mainOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *mainStreamUnit, RECT *cliprect); // 0x8005F878

extern void WARPGATE_RenderWarpUnit(unsigned long **mainOT, struct StreamUnitPortal *curStreamPortal, struct _StreamUnit *mainStreamUnit, RECT *cliprect); // 0x8005FBC4

extern void STREAM_DumpNonResidentObjects(); // 0x8005FFA0

extern int STREAM_TryAndDumpNonResident(struct _ObjectTracker *otr); // 0x80060058


#endif
