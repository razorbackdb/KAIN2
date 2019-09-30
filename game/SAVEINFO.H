#ifndef SAVEINFO_H
#define SAVEINFO_H


extern void SAVE_GetInstanceRotation(struct _Instance *instance, struct _SmallRotation *vector); // 0x800B3EA8

extern void SAVE_ClearMemory(struct GameTracker *gameTracker); // 0x800B3F30

extern void SAVE_Init(struct GameTracker *gt); // 0x800B3FB8

extern void * SAVE_GetSavedBlock(long saveType, long extraSize); // 0x800B403C

extern long SAVE_PurgeAMemoryBlock(); // 0x800B4120

extern long SAVE_SaveableInstance(struct _Instance *instance); // 0x800B41C0

extern struct _SavedIntro * SAVE_UpdateSavedIntro(struct _Instance *instance, struct Level *level, struct _SavedIntro *savedIntro, struct evControlSaveDataData *extraData); // 0x800B42AC

extern struct _SavedIntroWithIntro * SAVE_UpdateSavedIntroWithIntro(struct _Instance *instance, struct Level *level, struct _SavedIntroWithIntro *savedIntro, struct evControlSaveDataData *extraData); // 0x800B43B8

extern struct SavedBasic * SAVE_GetSavedEvent(long areaID, long eventNumber); // 0x800B44F0

extern void SAVE_DeleteSavedEvent(long areaID, long eventNumber); // 0x800B4598

extern struct SavedBasic * SAVE_GetSavedNextEvent(long areaID, struct SavedBasic *curSave); // 0x800B45C8

extern void SAVE_BufferIntro(struct SavedBasic *savedIntro); // 0x800B466C

extern void SAVE_IntroduceBufferIntros(); // 0x800B46F4

extern void SAVE_IntroForStreamID(struct _StreamUnit *streamUnit); // 0x800B47C8

extern long SAVE_HasSavedIntro(struct Intro *intro, long currentStreamID); // 0x800B488C

extern struct SavedLevel * SAVE_HasSavedLevel(long areaID); // 0x800B491C

extern void SAVE_UpdateLevelWithSave(struct _StreamUnit *streamUnit); // 0x800B4980

extern struct SavedLevel * SAVE_CreatedSavedLevel(long areaID, struct Level *level); // 0x800B4ACC

extern void SAVE_DeleteBlock(struct SavedBasic *savedBlock); // 0x800B4C88

extern void SAVE_Instance(struct _Instance *instance, struct Level *level); // 0x800B4D20

extern void SAVE_DeleteInstance(struct _Instance *instance); // 0x800B4F54

extern void SAVE_SetDeadDeadBit(struct _Instance *instance, long set); // 0x800B5024

extern void SAVE_RestoreGlobalSavePointer(); // 0x800B50F8

extern long SAVE_IsIntroDeadDead(struct Intro *intro); // 0x800B5150

extern void SAVE_DoInstanceDeadDead(struct _Instance *instance); // 0x800B520C

extern void SAVE_MarkDeadDead(struct _Instance *instance); // 0x800B523C

extern void SAVE_UndestroyInstance(struct _Instance *instance); // 0x800B5250

extern struct SavedIntroSmall * SAVE_GetSavedSmallIntro(struct _Instance *instance); // 0x800B5270

extern struct SavedIntroSpline * SAVE_GetIntroSpline(struct _Instance *instance); // 0x800B52DC

extern void SAVE_UpdateGlobalSaveTracker(); // 0x800B5348

extern void SAVE_RestoreGlobalSaveTracker(); // 0x800B53E0

extern void SAVE_SaveEverythingInMemory(); // 0x800B54B8

extern void SAVE_SaveGame(); // 0x800B5570

extern void SAVE_RestoreGame(); // 0x800B55AC

extern void SAVE_DebugSaveGame(); // 0x800B5614

extern void SAVE_LoadSaveGame(); // 0x800B561C

extern long SAVE_SizeOfFreeSpace(); // 0x800B565C


#endif
