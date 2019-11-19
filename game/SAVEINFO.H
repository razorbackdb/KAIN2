#ifndef SAVEINFO_H
#define SAVEINFO_H


extern void SAVE_ClearMemory(struct GameTracker *gameTracker); // 0x800AFBC4

extern void SAVE_Init(struct GameTracker *gt); // 0x800AFC3C

extern void * SAVE_GetSavedBlock(long saveType, long extraSize); // 0x800AFCD0

extern long SAVE_SaveableInstance(struct _Instance *instance); // 0x800AFD90

extern struct _SavedIntro * SAVE_GetSavedIntro(struct _Instance *instance); // 0x800AFE28

extern struct _SavedIntro * SAVE_UpdateSavedIntro(struct _Instance *instance, struct Level *level, struct _SavedIntro *savedIntro, struct evControlSaveDataData *extraData); // 0x800AFE90

extern struct SavedEvent * SAVE_GetSavedEvent(long areaID, long eventNumber); // 0x800B0060

extern struct SavedEvent * SAVE_GetSavedNextEvent(long areaID, struct SavedBasic *curSave); // 0x800B00D0

extern void SAVE_BufferIntro(struct _SavedIntro *savedIntro); // 0x800B014C

extern void SAVE_IntroduceBufferIntros(); // 0x800B0200

extern void SAVE_IntroForStreamID(long streamID, struct Level *level); // 0x800B0294

extern long SAVE_HasSavedIntro(struct Intro *intro, long currentStreamID); // 0x800B0324

extern struct SavedLevel * SAVE_HasSavedLevel(long areaID); // 0x800B0390

extern void SAVE_UpdateLevelWithSave(struct _StreamUnit *streamUnit); // 0x800B03F0

extern struct SavedLevel * SAVE_CreatedSavedLevel(long areaID, struct Level *level); // 0x800B0534

extern void SAVE_DeleteBlock(struct SavedBasic *savedBlock); // 0x800B06D4

extern void SAVE_Instance(struct _Instance *instance, struct Level *level); // 0x800B0744

extern void SAVE_DeleteInstance(struct _Instance *instance); // 0x800B08B0

extern void SAVE_SetDeadDeadBit(struct _Instance *instance, long set); // 0x800B092C

extern void SAVE_RestoreGlobalSavePointer(); // 0x800B0A20

extern long SAVE_IsIntroDeadDead(struct Intro *intro); // 0x800B0A74

extern void SAVE_DoInstanceDeadDead(struct _Instance *instance); // 0x800B0B58

extern void SAVE_MarkDeadDead(struct _Instance *instance); // 0x800B0B88

extern void SAVE_UndestroyInstance(struct _Instance *instance); // 0x800B0B9C

extern struct SavedIntroSmall * SAVE_GetSavedSmallIntro(struct _Instance *instance); // 0x800B0BBC

extern void SAVE_UpdateGlobalSaveTracker(); // 0x800B0C4C

extern void SAVE_RestoreGlobalSaveTracker(); // 0x800B0C94

extern void SAVE_SaveEverythingInMemory(); // 0x800B0CE0

extern void SAVE_SaveGame(); // 0x800B0D98

extern void SAVE_RestoreGame(); // 0x800B0DD4

extern void SAVE_DebugSaveGame(); // 0x800B0E38

extern void SAVE_LoadSaveGame(); // 0x800B0E40

extern long SAVE_SizeOfFreeSpace(); // 0x800B0E8C


#endif
