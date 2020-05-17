#ifndef SAVEINFO_H
#define SAVEINFO_H


extern void SAVE_GetInstanceRotation(struct _Instance *instance, struct _SmallRotation *vector); // 0x800B51F8

extern void SAVE_ClearMemory(struct GameTracker *gameTracker); // 0x800B5280

extern void SAVE_Init(struct GameTracker *gt); // 0x800B5300

extern void * SAVE_GetSavedBlock(long saveType, long extraSize); // 0x800B5384

extern long SAVE_PurgeAMemoryBlock(); // 0x800B54A0

extern long SAVE_SaveableInstance(struct _Instance *instance); // 0x800B5540

extern struct _SavedIntro * SAVE_UpdateSavedIntro(struct _Instance *instance, struct Level *level, struct _SavedIntro *savedIntro, struct evControlSaveDataData *extraData); // 0x800B562C

extern struct _SavedIntroWithIntro * SAVE_UpdateSavedIntroWithIntro(struct _Instance *instance, struct Level *level, struct _SavedIntroWithIntro *savedIntro, struct evControlSaveDataData *extraData); // 0x800B5738

extern struct SavedBasic * SAVE_GetSavedEvent(long areaID, long eventNumber); // 0x800B5870

extern void SAVE_DeleteSavedEvent(long areaID, long eventNumber); // 0x800B5918

extern struct SavedBasic * SAVE_GetSavedNextEvent(long areaID, struct SavedBasic *curSave); // 0x800B5948

extern void SAVE_BufferIntro(struct SavedBasic *savedIntro); // 0x800B59EC

extern void SAVE_IntroduceBufferIntros(); // 0x800B5A6C

extern void SAVE_IntroForStreamID(struct _StreamUnit *streamUnit); // 0x800B5B48

extern long SAVE_HasSavedIntro(struct Intro *intro, long currentStreamID); // 0x800B5C24

extern struct SavedLevel * SAVE_HasSavedLevel(long areaID); // 0x800B5CB4

extern void SAVE_UpdateLevelWithSave(struct _StreamUnit *streamUnit); // 0x800B5D18

extern struct SavedLevel * SAVE_CreatedSavedLevel(long areaID, struct Level *level); // 0x800B5E64

extern void SAVE_DeleteBlock(struct SavedBasic *savedBlock); // 0x800B6020

extern void SAVE_Instance(struct _Instance *instance, struct Level *level); // 0x800B60AC

extern void SAVE_DeleteInstance(struct _Instance *instance); // 0x800B62E0

extern void SAVE_SetDeadDeadBit(int uniqueID, long set); // 0x800B63B0

extern void SAVE_RestoreGlobalSavePointer(); // 0x800B6474

extern long SAVE_IsUniqueIDDeadDead(long uniqueID); // 0x800B64CC

extern long SAVE_IsIntroDeadDead(struct Intro *intro); // 0x800B6578

extern void SAVE_DoInstanceDeadDead(struct _Instance *instance); // 0x800B659C

extern void SAVE_MarkDeadDead(struct _Instance *instance); // 0x800B65CC

extern void SAVE_UndestroyInstance(struct _Instance *instance); // 0x800B65E0

extern struct SavedIntroSmall * SAVE_GetSavedSmallIntro(struct _Instance *instance); // 0x800B6604

extern struct SavedIntroSpline * SAVE_GetIntroSpline(struct _Instance *instance); // 0x800B6670

extern void SAVE_UpdateGlobalSaveTracker(); // 0x800B66DC

extern void SAVE_RestoreGlobalSaveTracker(); // 0x800B6770

extern void SAVE_SaveEverythingInMemory(); // 0x800B6840

extern void SAVE_SaveGame(); // 0x800B68F4

extern void SAVE_RestoreGame(); // 0x800B6940

extern void SAVE_DebugSaveGame(); // 0x800B69A4

extern void SAVE_LoadSaveGame(); // 0x800B69AC

extern long SAVE_SizeOfFreeSpace(); // 0x800B69E8


#endif
