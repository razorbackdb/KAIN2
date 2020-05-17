#ifndef DEBUG_H
#define DEBUG_H


extern void DEBUG_SetGameTime(long *var); // 0x80012EB8

extern void DEBUG_KeepGameTime(long *var); // 0x80012EDC

extern void DEBUG_UpdateFog(long *var); // 0x80012F04

extern void DEBUG_UpdateHealth(long *var); // 0x80012F8C

extern void DEBUG_UpdateMana(long *var); // 0x80012FB0

extern void DEBUG_FillUpHealth(long *var); // 0x80012FD4

extern void DEBUG_FogLoad(); // 0x80012FFC

extern void DEBUG_FogRestore(); // 0x80013064

extern void DEBUG_SendCinematicSwitch(); // 0x800130AC

extern void DEBUG_SendMoveTo(); // 0x80013108

extern void process_cheat_codes(struct GameTracker *gt, long *ctrl); // 0x8001317C

extern void DEBUG_Process(struct GameTracker *gameTracker); // 0x80013444

extern void DEBUG_Draw(struct GameTracker *gameTracker, unsigned long **ot); // 0x800135F0

extern long DEBUG_MenuCountLength(struct DebugMenuLine *menu); // 0x80013638

extern void DEBUG_ExitMenus(); // 0x80013664

extern struct DebugMenuLine * get_last_menu_line(struct DebugMenuLine *line); // 0x800136FC

extern int num_menu_items(struct DebugMenuLine *menu); // 0x8001372C

extern void maybe_change_menu_choice(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x8001375C

extern void handle_line_type_long(struct GameTracker *gt, struct DebugMenuLine *line); // 0x80013824

extern void handle_line_type_bit(struct GameTracker *gt, struct DebugMenuLine *line); // 0x80013910

extern void handle_line_type_action(struct GameTracker *gt, struct DebugMenuLine *line); // 0x80013968

extern void handle_line_type_action_with_line(struct GameTracker *gt, struct DebugMenuLine *line); // 0x800139A4

extern void handle_line_type_menu(struct GameTracker *gt, struct DebugMenuLine *line); // 0x80013A08

extern void process_menu_line(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013A88

extern int pre_process_functions(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013AEC

extern void post_process_functions(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013B14

extern void set_debug_leading(); // 0x80013BB8

extern void set_user_leading(); // 0x80013BD0

extern int isdigit(char c); // 0x80013BE8

extern void adjust_format(char *ctrl, struct debug_format_t *fmt); // 0x80013BF8

extern char * find_eol(char *text); // 0x80013DA0

extern void draw_menu_item(struct GameTracker *gt, struct debug_format_t *fmt, char *text); // 0x80013DD8

extern void draw_menu(struct GameTracker *gt, struct DebugMenuLine *menu); // 0x80013ED8

extern void DEBUG_Menu(struct GameTracker *gt); // 0x800140E4

extern void DEBUG_DisplayStatus(struct GameTracker *gameTracker); // 0x800141F8

extern void DEBUG_DrawShrinkCels(unsigned long **polyAddr); // 0x80014460

extern void DEBUG_ContinueGame(); // 0x80014468

extern void DEBUG_ExitGame(); // 0x80014480

extern void DEBUG_ReloadCurrentLevel(); // 0x800144BC

extern void DEBUG_LevelSelectNew(); // 0x80014520

extern void DEBUG_SetViewVram(); // 0x8001461C

extern void DEBUG_EndViewVram(struct GameTracker *gameTracker); // 0x8001462C

extern void DEBUG_ViewVram(struct GameTracker *gameTracker); // 0x8001467C

extern void DEBUG_CaptureScreen(struct GameTracker *gameTracker); // 0x8001479C

extern void DEBUG_PageFlip(); // 0x800147A4

extern void DEBUG_FatalError(char *fmt); // 0x800148AC

extern void DEBUG_ProcessSecondController(struct GameTracker *gameTracker); // 0x80014900

extern void DEBUG_ProcessCheat(struct GameTracker *gameTracker); // 0x80014908

extern void DEBUG_DoAreaProtection(); // 0x80014A7C


#endif
