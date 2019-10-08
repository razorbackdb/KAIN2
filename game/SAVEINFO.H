#ifndef SAVEINFO_H
#define SAVEINFO_H

extern void SAVE_GetInstanceRotation(struct _Instance *instance, struct _SmallRotation *vector);

extern void SAVE_ClearMemory(struct GameTracker *gameTracker);

extern void SAVE_Init(struct GameTracker *gt);

extern void *SAVE_GetSavedBlock(long saveType, long extraSize);

extern long SAVE_PurgeAMemoryBlock();

extern long SAVE_SaveableInstance(struct _Instance *instance);

extern struct _SavedIntro *SAVE_UpdateSavedIntro(struct _Instance *instance, struct Level *level, struct _SavedIntro *savedIntro, struct evControlSaveDataData *extraData);

extern struct _SavedIntroWithIntro *SAVE_UpdateSavedIntroWithIntro(struct _Instance *instance, struct Level *level, struct _SavedIntroWithIntro *savedIntro, struct evControlSaveDataData *extraData);

extern struct SavedBasic *SAVE_GetSavedEvent(long areaID, long eventNumber);

extern void SAVE_DeleteSavedEvent(long areaID, long eventNumber);

extern struct SavedBasic *SAVE_GetSavedNextEvent(long areaID, struct SavedBasic *curSave);

extern void SAVE_BufferIntro(struct SavedBasic *savedIntro);

extern void SAVE_IntroduceBufferIntros();

extern void SAVE_IntroForStreamID(struct _StreamUnit *streamUnit);

extern long SAVE_HasSavedIntro(struct Intro *intro, long currentStreamID);

extern struct SavedLevel *SAVE_HasSavedLevel(long areaID);

extern void SAVE_UpdateLevelWithSave(struct _StreamUnit *streamUnit);

extern struct SavedLevel *SAVE_CreatedSavedLevel(long areaID, struct Level *level);

extern void SAVE_DeleteBlock(struct SavedBasic *savedBlock);

extern void SAVE_Instance(struct _Instance *instance, struct Level *level);

extern void SAVE_DeleteInstance(struct _Instance *instance);

extern void SAVE_SetDeadDeadBit(struct _Instance *instance, long set);

extern void SAVE_RestoreGlobalSavePointer();

extern long SAVE_IsIntroDeadDead(struct Intro *intro);

extern void SAVE_DoInstanceDeadDead(struct _Instance *instance);

extern void SAVE_MarkDeadDead(struct _Instance *instance);

extern void SAVE_UndestroyInstance(struct _Instance *instance);

extern struct SavedIntroSmall *SAVE_GetSavedSmallIntro(struct _Instance *instance);

extern struct SavedIntroSpline *SAVE_GetIntroSpline(struct _Instance *instance);

extern void SAVE_UpdateGlobalSaveTracker();

extern void SAVE_RestoreGlobalSaveTracker();

extern void SAVE_SaveEverythingInMemory();

extern void SAVE_SaveGame();

extern void SAVE_RestoreGame();

extern void SAVE_DebugSaveGame();

extern void SAVE_LoadSaveGame();

extern long SAVE_SizeOfFreeSpace();

#endif
