#ifndef DEBUG_H
#define DEBUG_H


extern void DEBUG_SetGameTime(long *var); // 0x80012D90

extern void DEBUG_KeepGameTime(long *var); // 0x80012DB4

extern void DEBUG_UpdateFog(long *var); // 0x80012DDC

extern void DEBUG_UpdateHealth(long *var); // 0x80012E64

extern void DEBUG_FillUpHealth(long *var); // 0x80012E88

extern void DEBUG_FogLoad(); // 0x80012EB0

extern void DEBUG_FogRestore(); // 0x80012F18

extern void DEBUG_SendCinematicSwitch(); // 0x80012F60

extern void DEBUG_SendMoveTo(); // 0x80012FBC

extern void process_cheat_codes(struct GameTracker *gt, long *ctrl); // 0x80013030

extern void DEBUG_Process(struct GameTracker *gameTracker); // 0x800130D0

extern void DEBUG_Draw(struct GameTracker *gameTracker, unsigned long **ot); // 0x8001327C

extern long DEBUG_MenuCountLength(struct DebugMenuLine *menu); // 0x800132C4

extern void DEBUG_ExitMenus(); // 0x800132F0

extern struct DebugMenuLine * get_last_menu_line(struct DebugMenuLine *line); // 0x80013388

extern int num_menu_items(struct DebugMenuLine *menu); // 0x800133B8

extern void maybe_change_menu_choice(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x800133E8

extern void handle_line_type_long(struct GameTracker *gt, struct DebugMenuLine *line); // 0x800134B0

extern void handle_line_type_bit(struct GameTracker *gt, struct DebugMenuLine *line); // 0x8001359C

extern void handle_line_type_action(struct GameTracker *gt, struct DebugMenuLine *line); // 0x800135F4

extern void handle_line_type_action_with_line(struct GameTracker *gt, struct DebugMenuLine *line); // 0x80013630

extern void handle_line_type_menu(struct GameTracker *gt, struct DebugMenuLine *line); // 0x80013694

extern void process_menu_line(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013714

extern int pre_process_functions(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013778

extern void post_process_functions(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x800137A0

extern void set_debug_leading(); // 0x80013844

extern void set_user_leading(); // 0x8001385C

extern int isdigit(char c); // 0x80013874

extern void adjust_format(char *ctrl, struct debug_format_t *fmt); // 0x80013884

extern char * find_eol(char *text); // 0x80013A2C

extern void draw_menu_item(struct GameTracker *gt, struct debug_format_t *fmt, char *text); // 0x80013A64

extern void draw_menu(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013B64

extern void DEBUG_Menu(struct GameTracker *gt); // 0x80013D70

extern void DEBUG_DisplayStatus(struct GameTracker *gameTracker); // 0x80013E84

extern void DEBUG_DrawShrinkCels(unsigned long **polyAddr); // 0x800140EC

extern void DEBUG_ContinueGame(); // 0x800140F4

extern void DEBUG_ExitGame(); // 0x8001410C

extern void DEBUG_ReloadCurrentLevel(); // 0x80014148

extern void DEBUG_LevelSelectNew(); // 0x800141AC

extern void DEBUG_SetViewVram(); // 0x800142AC

extern void DEBUG_EndViewVram(struct GameTracker *gameTracker); // 0x800142BC

extern void DEBUG_ViewVram(struct GameTracker *gameTracker); // 0x80014314

extern void DEBUG_CaptureScreen(struct GameTracker *gameTracker); // 0x8001443C

extern void DEBUG_PageFlip(); // 0x80014444

extern void DEBUG_FatalError(char *fmt); // 0x80014550

extern void DEBUG_ProcessSecondController(struct GameTracker *gameTracker); // 0x800145A4

extern void DEBUG_ProcessCheat(struct GameTracker *gameTracker); // 0x800145AC


#endif
