#ifndef DEBUG_H
#define DEBUG_H


extern void DEBUG_SetGameTime(long *var); // 0x80012C2C

extern void DEBUG_KeepGameTime(long *var); // 0x80012C50

extern void DEBUG_UpdateFog(long *var); // 0x80012C78

extern void DEBUG_UpdateHealth(long *var); // 0x80012D00

extern void DEBUG_FillUpHealth(long *var); // 0x80012D24

extern void DEBUG_FogLoad(); // 0x80012D44

extern void DEBUG_FogRestore(); // 0x80012DAC

extern void DEBUG_SendCinematicSwitch(); // 0x80012DF4

extern void DEBUG_SendMoveTo(); // 0x80012E50

extern void process_cheat_codes(struct GameTracker *gt, long *ctrl); // 0x80012EC4

extern void DEBUG_Process(struct GameTracker *gameTracker); // 0x80012F50

extern void DEBUG_VoiceTest(); // 0x800130FC

extern void DEBUG_Draw(struct GameTracker *gameTracker, unsigned long **ot); // 0x80013120

extern long DEBUG_MenuCountLength(struct DebugMenuLine *menu); // 0x80013168

extern void DEBUG_ExitMenus(); // 0x80013194

extern struct DebugMenuLine * get_last_menu_line(struct DebugMenuLine *line); // 0x80013224

extern int num_menu_items(struct DebugMenuLine *menu); // 0x80013254

extern void maybe_change_menu_choice(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013284

extern void handle_line_type_long(struct GameTracker *gt, struct DebugMenuLine *line); // 0x8001334C

extern void handle_line_type_bit(struct GameTracker *gt, struct DebugMenuLine *line); // 0x80013438

extern void handle_line_type_action(struct GameTracker *gt, struct DebugMenuLine *line); // 0x80013490

extern void handle_line_type_action_with_line(struct GameTracker *gt, struct DebugMenuLine *line); // 0x800134CC

extern void handle_line_type_menu(struct GameTracker *gt, struct DebugMenuLine *line); // 0x80013530

extern void process_menu_line(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x800135B0

extern int pre_process_functions(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013614

extern void post_process_functions(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x8001363C

extern void set_debug_leading(); // 0x800136E0

extern void set_user_leading(); // 0x800136F8

extern int isdigit(char c); // 0x80013710

extern void adjust_format(char *ctrl, struct debug_format_t *fmt); // 0x80013720

extern char * find_eol(char *text); // 0x800138C8

extern void draw_menu_item(struct GameTracker *gt, struct debug_format_t *fmt, char *text); // 0x80013900

extern void draw_menu(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013A00

extern void DEBUG_Menu(struct GameTracker *gt); // 0x80013C0C

extern void DEBUG_DisplayStatus(struct GameTracker *gameTracker); // 0x80013D20

extern void DEBUG_DrawShrinkCels(unsigned long **polyAddr); // 0x800144F0

extern void DEBUG_ContinueGame(); // 0x800144F8

extern void DEBUG_ExitGame(); // 0x80014518

extern void DEBUG_ReloadCurrentLevel(); // 0x80014550

extern void DEBUG_LevelSelectNew(); // 0x800145B0

extern void DEBUG_MusicSelect(); // 0x800146A8

extern void DEBUG_PrintSramStatus(); // 0x80014790

extern void DEBUG_SetViewVram(); // 0x800148CC

extern void DEBUG_EndViewVram(struct GameTracker *gameTracker); // 0x800148DC

extern void DEBUG_ViewVram(struct GameTracker *gameTracker); // 0x80014934

extern void DEBUG_CaptureScreen(struct GameTracker *gameTracker); // 0x80014A5C

extern void DEBUG_PageFlip(); // 0x80014A64

extern void DEBUG_FatalError(char *fmt); // 0x80014B70

extern void DEBUG_ProcessSecondController(struct GameTracker *gameTracker); // 0x80014BCC

extern void DEBUG_ProcessCheat(struct GameTracker *gameTracker); // 0x80014BD4


#endif
