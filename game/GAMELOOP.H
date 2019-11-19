#ifndef GAMELOOP_H
#define GAMELOOP_H


extern void GAMELOOP_AllocStaticMemory(); // 0x8002DB68

extern void GAMELOOP_InitGameTracker(); // 0x8002DC64

extern void GAMELOOP_SystemInit(struct GameTracker *gameTracker); // 0x8002DD64

extern void GAMELOOP_ResetGameStates(); // 0x8002DD9C

extern void GAMELOOP_ClearGameTracker(); // 0x8002DDBC

extern void GAMELOOP_CalcGameTime(); // 0x8002DDEC

extern void GAMELOOP_SetGameTime(long timeOfDay); // 0x8002DE98

extern int GAMELOOP_GetTimeOfDay(); // 0x8002DF2C

extern int GAMELOOP_GetTimeOfDayIdx(int timeOfDay); // 0x8002DF78

extern void GAMELOOP_InterpTODLighting(struct Level *level, short ratio, int startidx, short *r, short *g, short *b); // 0x8002DFBC

extern void GAMELOOP_InterpTODFogging(struct Level *level, short ratio, int startidx, unsigned char *color, unsigned short *near_dist, unsigned short *far_dist); // 0x8002E08C

extern void GAMELOOP_GetTimeOfDayLighting(struct Level *level, short *r, short *g, short *b, unsigned char *backColor, unsigned short *nearFog, unsigned short *farFog); // 0x8002E1A4

extern void GAMELOOP_SetLevelVmTimeOfDay(struct Level *level, short r, short g, short b); // 0x8002E520

extern void GAMELOOP_SetLevelTimeOfDay(struct Level *level, short r, short g, short b); // 0x8002E528

extern void GAMELOOP_UpdateInstanceListTimeOfDay(short ratio); // 0x8002E634

extern void GAMELOOP_SetTODVtxColor(struct _Terrain *terrain, int vidx, int ratio); // 0x8002E6D8

extern void GAMELOOP_UpdateBspListTimeOfDay(short ratio); // 0x8002E878

extern void GAMELOOP_UpdateWorldInstTimeOfDay(int timeOfDay); // 0x8002EA10

extern int GAMELOOP_TimeOfDayRatio(int timeOfDay); // 0x8002EB60

extern void GAMELOOP_InitLevelTimeOfDay(struct Level *level); // 0x8002EC60

extern void GAMELOOP_UpdateWorldTimeOfDay(); // 0x8002ED00

extern struct _StreamUnit * LoadLevels(char *baseAreaName, struct GameTracker *gameTracker); // 0x8002EEB4

extern void GAMELOOP_LevelLoadAndInit(char *baseAreaName, struct GameTracker *gameTracker); // 0x8002F070

extern void GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName, struct GameTracker *gameTracker, int toSignalNum, int fromSignalNum); // 0x8002F414

extern void GAMELOOP_HandleScreenWipes(unsigned long **drawot); // 0x8002F434

extern void UpdateFogSettings(struct _StreamUnit *currentUnit, struct Level *level); // 0x8002F8A0

extern int CheckForNoBlend(struct _ColorType *Color); // 0x8002F9C8

extern void BlendToColor(struct _ColorType *target, struct _ColorType *current, struct _ColorType *dest); // 0x8002FA10

extern void MainRenderLevel(struct _StreamUnit *currentUnit, unsigned long **drawot); // 0x8002FB04

extern void StreamIntroInstancesForUnit(struct _StreamUnit *currentUnit); // 0x80030054

extern long StreamRenderLevel(struct _StreamUnit *currentUnit, struct Level *mainLevel, unsigned long **drawot, long portalFogColor); // 0x80030094

extern void GAMELOOP_FlipScreenAndDraw(struct GameTracker *gameTracker, unsigned long **drawot); // 0x800303DC

extern void GAMELOOP_SwitchTheDrawBuffer(unsigned long **drawot); // 0x800304A0

extern void GAMELOOP_SetupRenderFunction(struct GameTracker *gameTracker); // 0x800305CC

extern struct _StreamUnit * GAMELOOP_GetMainRenderUnit(); // 0x800305E8

extern void GAMELOOP_DisplayFrame(struct GameTracker *gameTracker); // 0x800306AC

extern void ResetPrimPool(); // 0x80030CF4

extern void SaveOT(); // 0x80030DA0

extern void ResetDrawPage(); // 0x80030F40

extern void GAMELOOP_Set24FPS(); // 0x80030F80

extern void GAMELOOP_Reset24FPS(); // 0x80030F90

extern void GAMELOOP_DoTimeProcess(); // 0x80030F9C

extern void GAMELOOP_Process(struct GameTracker *gameTracker); // 0x80031190

extern void GAMELOOP_ModeStartRunning(); // 0x80031848

extern void GAMELOOP_ModeStartPause(); // 0x80031924

extern void GAMELOOP_DemoSetup(); // 0x800319EC

extern void GAMELOOP_ChangeMode(); // 0x80031A04

extern void GAMELOOP_RequestLevelChange(char *name, short number, struct GameTracker *gameTracker); // 0x80031D6C

extern void PSX_GameLoop(struct GameTracker *gameTracker); // 0x80031DEC

extern struct MATRIX * GAMELOOP_GetMatrices(int numMatrices); // 0x80031E18

extern struct GameTracker * GAMELOOP_GetGT(); // 0x80031E4C


#endif
