#ifndef MAIN_H
#define MAIN_H


extern void ClearDisplay(); // 0x800384F8

extern void screen_to_vram(long *screen, int buffer); // 0x800385B4

extern void show_screen(char *name); // 0x800385E4

extern void play_movie(char *name); // 0x80038628

extern void InitMainTracker(struct MainTracker *mainTracker); // 0x80038670

extern char * FindTextInLine(char *search_match, char *search_str); // 0x80038680

extern void ExtractWorldName(char *worldName, char *levelName); // 0x80038708

extern void ExtractLevelNum(char *levelNum, char *levelName); // 0x80038754

extern void ProcessArgs(char *baseAreaName, struct GameTracker *gameTracker); // 0x800387C0

extern void InitDisplay(); // 0x800389D8

extern void StartTimer(); // 0x80038B54

extern void VblTick(); // 0x80038BC0

extern void DrawCallback(); // 0x80038C2C

extern void FadeOutSayingLoading(struct GameTracker *gameTracker); // 0x80038C84

extern void CheckForDevStation(); // 0x80038DD4

extern void MAIN_ShowLoadingScreen(); // 0x80038E34

extern long * MAIN_LoadTim(char *name); // 0x80038EE4

extern void init_menus(struct GameTracker *gt); // 0x80038F04

extern void MAIN_DoMainInit(); // 0x80038F50

extern void MAIN_InitVolume(); // 0x80039044

extern void MAIN_ResetGame(); // 0x80039084

extern void MAIN_MainMenuInit(); // 0x800390D4

extern void MAIN_FreeMainMenuStuff(); // 0x8003924C

extern void MAIN_StartGame(); // 0x800392BC

extern long MAIN_DoMainMenu(struct GameTracker *gameTracker, struct MainTracker *mainTracker, long menuPos); // 0x80039328

extern int MainG2(void *appData); // 0x800393FC


#endif
