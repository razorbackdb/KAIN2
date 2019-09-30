#ifndef GAMELOOP_H
#define GAMELOOP_H


extern void GAMELOOP_AllocStaticMemory(); // 0x8002D6F8

extern void GAMELOOP_InitGameTracker(); // 0x8002D7E8

extern void GAMELOOP_SystemInit(struct GameTracker *gameTracker); // 0x8002D8E8

extern void GAMELOOP_ResetGameStates(); // 0x8002D920

extern void GAMELOOP_ClearGameTracker(); // 0x8002D940

extern void GAMELOOP_CalcGameTime(); // 0x8002D970

extern void GAMELOOP_SetGameTime(long timeOfDay); // 0x8002DA1C

extern int GAMELOOP_GetTimeOfDay(); // 0x8002DAB0

extern int GAMELOOP_GetTimeOfDayIdx(int timeOfDay); // 0x8002DAFC

extern int GAMELOOP_WaitForLoad(); // 0x8002DB40

extern struct _StreamUnit * LoadLevels(char *baseAreaName, struct GameTracker *gameTracker); // 0x8002DB78

extern void GAMELOOP_InitStandardObjects(); // 0x8002DD74

extern void GAMELOOP_LevelLoadAndInit(char *baseAreaName, struct GameTracker *gameTracker); // 0x8002DDCC

extern void GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName, struct GameTracker *gameTracker, int toSignalNum, int fromSignalNum); // 0x8002E0F0

extern void GAMELOOP_SetScreenWipe(int time, int maxTime, int type); // 0x8002E110

extern void GAMELOOP_HandleScreenWipes(unsigned long **drawot); // 0x8002E124

extern void UpdateFogSettings(struct _StreamUnit *currentUnit, struct Level *level); // 0x8002E590

extern int CheckForNoBlend(struct _ColorType *Color); // 0x8002E6B8

extern void BlendToColor(struct _ColorType *target, struct _ColorType *current, struct _ColorType *dest); // 0x8002E700

extern void MainRenderLevel(struct _StreamUnit *currentUnit, unsigned long **drawot); // 0x8002E7F4

extern void StreamIntroInstancesForUnit(struct _StreamUnit *currentUnit); // 0x8002ED64

extern long StreamRenderLevel(struct _StreamUnit *currentUnit, struct Level *mainLevel, unsigned long **drawot, long portalFogColor); // 0x8002EDA4

extern void GAMELOOP_FlipScreenAndDraw(struct GameTracker *gameTracker, unsigned long **drawot); // 0x8002F130

extern void GAMELOOP_AddClearPrim(unsigned long **drawot); // 0x8002F1E8

extern void GAMELOOP_SwitchTheDrawBuffer(unsigned long **drawot); // 0x8002F290

extern void GAMELOOP_SetupRenderFunction(struct GameTracker *gameTracker); // 0x8002F314

extern struct _StreamUnit * GAMELOOP_GetMainRenderUnit(); // 0x8002F330

extern void GAMELOOP_DisplayFrame(struct GameTracker *gameTracker); // 0x8002F3F4

extern void GAMELOOP_DrawSavedOT(unsigned long **newOT); // 0x8002FA1C

extern void ResetPrimPool(); // 0x8002FB98

extern void SaveOT(); // 0x8002FC44

extern void ResetDrawPage(); // 0x8002FDE4

extern void GAMELOOP_Set24FPS(); // 0x8002FE24

extern void GAMELOOP_Reset24FPS(); // 0x8002FE34

extern void GAMELOOP_DoTimeProcess(); // 0x8002FE40

extern void GAMELOOP_Process(struct GameTracker *gameTracker); // 0x80030044

extern void GAMELOOP_ModeStartRunning(); // 0x80030708

extern void GAMELOOP_ModeStartPause(); // 0x800307E0

extern void GAMELOOP_DemoSetup(); // 0x800308B4

extern void GAMELOOP_ChangeMode(); // 0x800308CC

extern void GAMELOOP_RequestLevelChange(char *name, short number, struct GameTracker *gameTracker); // 0x80030C80

extern void PSX_GameLoop(struct GameTracker *gameTracker); // 0x80030D00

//extern struct MATRIX * GAMELOOP_GetMatrices(int numMatrices); // 0x80030D2C

extern struct GameTracker * GAMELOOP_GetGT(); // 0x80030D60


#endif
