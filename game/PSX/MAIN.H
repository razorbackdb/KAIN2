#ifndef MAIN_H
#define MAIN_H

struct MainTracker // hashcode: 0x17FC94E6 (dec: 402429158)
{
	long mainState; // size=0, offset=0
	long previousState; // size=0, offset=4
	long movieNum; // size=0, offset=8
	long done; // size=0, offset=12
};

typedef struct MainTracker MainTracker;

extern void ClearDisplay(); // 0x8003840C

extern void show_screen(char *name); // 0x80038498

extern void play_movie(char *name); // 0x800384EC

extern void InitMainTracker(struct MainTracker *mainTracker); // 0x80038534

extern char * FindTextInLine(char *search_match, char *search_str); // 0x80038544

extern void ExtractWorldName(char *worldName, char *levelName); // 0x800385CC

extern void ExtractLevelNum(char *levelNum, char *levelName); // 0x80038618

extern void ProcessArgs(char *baseAreaName, struct GameTracker *gameTracker); // 0x80038684

extern void InitDisplay(); // 0x800388D0

extern void StartTimer(); // 0x80038A64

extern void VblTick(); // 0x80038AD0

extern void DrawCallback(); // 0x80038B3C

extern void FadeOutSayingLoading(struct GameTracker *gameTracker); // 0x80038B94

extern void CheckForDevStation(); // 0x80038CE8

extern void MAIN_ShowLoadingScreen(); // 0x80038D48

extern long * MAIN_LoadTim(char *name); // 0x80038E08

extern void init_menus(struct GameTracker *gt); // 0x80038E28

extern void MAIN_DoMainInit(); // 0x80038E74

extern void MAIN_ShowPalWarningScreen(struct GameTracker *gameTracker); // 0x80038F70

extern void MAIN_InitVolume(); // 0x80038FD4

extern void MAIN_ResetGame(); // 0x80039014

extern void MAIN_MainMenuInit(); // 0x80039064

extern void MAIN_FreeMainMenuStuff(); // 0x800391DC

extern void MAIN_StartGame(); // 0x8003924C

extern long MAIN_DoMainMenu(struct GameTracker *gameTracker, struct MainTracker *mainTracker, long menuPos); // 0x800392B8

extern int MainG2(void *appData); // 0x80039394


#endif
