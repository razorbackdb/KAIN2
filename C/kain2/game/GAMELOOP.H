#ifndef GAMELOOP_H
#define GAMELOOP_H


extern void GAMELOOP_AllocStaticMemory(); // 0x8002DB28

extern void GAMELOOP_InitGameTracker(); // 0x8002DC18

extern void GAMELOOP_SystemInit(struct GameTracker *gameTracker); // 0x8002DD18

extern void GAMELOOP_ResetGameStates(); // 0x8002DD50

extern void GAMELOOP_ClearGameTracker(); // 0x8002DD70

extern void GAMELOOP_CalcGameTime(); // 0x8002DDB8

extern void GAMELOOP_SetGameTime(long timeOfDay); // 0x8002DE64

extern int GAMELOOP_GetTimeOfDay(); // 0x8002DEF8

extern int GAMELOOP_GetTimeOfDayIdx(int timeOfDay); // 0x8002DF44

extern int GAMELOOP_WaitForLoad(); // 0x8002DF88

extern struct _StreamUnit * LoadLevels(char *baseAreaName, struct GameTracker *gameTracker); // 0x8002DFC0

extern void GAMELOOP_InitStandardObjects(); // 0x8002E1C0

extern void GAMELOOP_LevelLoadAndInit(char *baseAreaName, struct GameTracker *gameTracker); // 0x8002E214

extern void GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName, struct GameTracker *gameTracker, int toSignalNum, int fromSignalNum); // 0x8002E524

extern void GAMELOOP_SetScreenWipe(int time, int maxTime, int type); // 0x8002E544

extern void GAMELOOP_HandleScreenWipes(unsigned long **drawot); // 0x8002E558

extern void UpdateFogSettings(struct _StreamUnit *currentUnit, struct Level *level); // 0x8002E9B8

extern int CheckForNoBlend(struct _ColorType *Color); // 0x8002EAE0

extern void BlendToColor(struct _ColorType *target, struct _ColorType *current, struct _ColorType *dest); // 0x8002EB28

extern void MainRenderLevel(struct _StreamUnit *currentUnit, unsigned long **drawot); // 0x8002EC1C

extern void StreamIntroInstancesForUnit(struct _StreamUnit *currentUnit); // 0x8002F11C

extern long StreamRenderLevel(struct _StreamUnit *currentUnit, struct Level *mainLevel, unsigned long **drawot, long portalFogColor); // 0x8002F15C

extern void GAMELOOP_FlipScreenAndDraw(struct GameTracker *gameTracker, unsigned long **drawot); // 0x8002F4A4

extern void GAMELOOP_AddClearPrim(unsigned long **drawot, int override); // 0x8002F558

extern void GAMELOOP_SwitchTheDrawBuffer(unsigned long **drawot); // 0x8002F600

extern void GAMELOOP_SetupRenderFunction(struct GameTracker *gameTracker); // 0x8002F680

extern struct _StreamUnit * GAMELOOP_GetMainRenderUnit(); // 0x8002F69C

extern void GAMELOOP_DisplayFrame(struct GameTracker *gameTracker); // 0x8002F75C

extern void GAMELOOP_DrawSavedOT(unsigned long **newOT); // 0x8002FF18

extern void ResetPrimPool(); // 0x80030090

extern void Switch_For_Redraw(); // 0x8003013C

extern void GAMELOOP_Set_Pause_Redraw(); // 0x800301B8

extern void SaveOT(); // 0x800301C8

extern void ResetDrawPage(); // 0x80030368

extern void GAMELOOP_Set24FPS(); // 0x800303A8

extern void GAMELOOP_Reset24FPS(); // 0x800303B8

extern void GAMELOOP_DoTimeProcess(); // 0x800303C4

extern void GAMELOOP_Process(struct GameTracker *gameTracker); // 0x800305C8

extern void GAMELOOP_ModeStartRunning(); // 0x80030BFC

extern void GAMELOOP_ModeStartPause(); // 0x80030CD4

extern void GAMELOOP_ChangeMode(); // 0x80030DAC

extern void GAMELOOP_RequestLevelChange(char *name, short number, struct GameTracker *gameTracker); // 0x80031158

extern void PSX_GameLoop(struct GameTracker *gameTracker); // 0x800311D8

extern struct MATRIX * GAMELOOP_GetMatrices(int numMatrices); // 0x80031204

extern struct GameTracker * GAMELOOP_GetGT(); // 0x80031238


#endif
