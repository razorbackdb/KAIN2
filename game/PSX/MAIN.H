#ifndef MAIN_H
#define MAIN_H


extern void ClearDisplay(); // 0x80038EF0

extern void show_screen(char *name); // 0x80038F88

extern void DoCinematicStuff(struct GameTracker *gameTracker, struct MainTracker *mainTracker); // 0x80038FDC

extern void play_intro_movie(); // 0x80039040

extern void InitMainTracker(struct MainTracker *mainTracker); // 0x80039088

extern char * FindTextInLine(char *search_match, char *search_str); // 0x80039098

extern void ExtractWorldName(char *worldName, char *levelName); // 0x80039120

extern void ExtractLevelNum(char *levelNum, char *levelName); // 0x8003916C

extern void ProcessArgs(char *argFileName, char *baseAreaName, struct GameTracker *gameTracker); // 0x800391D8

extern void InitDisplay(); // 0x8003941C

extern void StartTimer(); // 0x800395B0

extern void VblTick(); // 0x8003961C

extern void DrawCallback(); // 0x80039688

extern void FadeOutSayingLoading(struct GameTracker *gameTracker); // 0x800396E0

extern void CheckForDevStation(); // 0x80039824

extern void MAIN_ShowLoadingScreen(); // 0x800398A4

extern long * MAIN_LoadTim(char *name); // 0x80039908

extern void init_menus(struct GameTracker *gt); // 0x80039928

extern void MAIN_DoMainInit(); // 0x80039974

extern void MAIN_ShowPalWarningScreen(struct GameTracker *gameTracker); // 0x80039A58

extern void MAIN_MainMenuInit(); // 0x80039ABC

extern void MAIN_FreeMainMenuStuff(); // 0x80039B18

extern void MAIN_StartGame(); // 0x80039B54

extern long MAIN_DoMainMenu(struct GameTracker *gameTracker, struct MainTracker *mainTracker, long menuPos); // 0x80039B8C

extern void MAIN_ShowFeaturesInit(); // 0x80039C38

extern int MainG2(void *appData); // 0x80039C70


#endif
