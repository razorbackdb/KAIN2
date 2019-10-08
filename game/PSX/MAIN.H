#ifndef MAIN_H
#define MAIN_H

extern void ClearDisplay();

extern void show_screen(char *name);

extern void play_movie(char *name);

extern void InitMainTracker(struct MainTracker *mainTracker);

extern char *FindTextInLine(char *search_match, char *search_str);

extern void ExtractWorldName(char *worldName, char *levelName);

extern void ExtractLevelNum(char *levelNum, char *levelName);

extern void ProcessArgs(char *baseAreaName, struct GameTracker *gameTracker);

extern void InitDisplay();

extern void StartTimer();

extern void VblTick();

extern void DrawCallback();

extern void FadeOutSayingLoading(struct GameTracker *gameTracker);

extern void CheckForDevStation();

extern void MAIN_ShowLoadingScreen();

extern long *MAIN_LoadTim(char *name);

extern void init_menus(struct GameTracker *gt);

extern void MAIN_DoMainInit();

extern void MAIN_ShowPalWarningScreen(struct GameTracker *gameTracker);

extern void MAIN_InitVolume();

extern void MAIN_ResetGame();

extern void MAIN_MainMenuInit();

extern void MAIN_FreeMainMenuStuff();

extern void MAIN_StartGame();

extern long MAIN_DoMainMenu(struct GameTracker *gameTracker, struct MainTracker *mainTracker, long menuPos);

extern int MainG2(void *appData);

#endif
