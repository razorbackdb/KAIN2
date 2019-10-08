#ifndef DEBUG_H
#define DEBUG_H

extern void DEBUG_SetGameTime(long *var);

extern void DEBUG_KeepGameTime(long *var);

extern void DEBUG_UpdateFog(long *var);

extern void DEBUG_UpdateHealth(long *var);

extern void DEBUG_FillUpHealth(long *var);

extern void DEBUG_FogLoad();

extern void DEBUG_FogRestore();

extern void DEBUG_SendCinematicSwitch();

extern void DEBUG_SendMoveTo();

extern void process_cheat_codes(struct GameTracker *gt, long *ctrl);

extern void DEBUG_Process(struct GameTracker *gameTracker);

extern void DEBUG_Draw(struct GameTracker *gameTracker, unsigned long **ot);

extern long DEBUG_MenuCountLength(struct DebugMenuLine *menu);

extern void DEBUG_ExitMenus();

extern struct DebugMenuLine *get_last_menu_line(struct DebugMenuLine *line);

extern int num_menu_items(struct DebugMenuLine *menu);

extern void maybe_change_menu_choice(struct GameTracker *gt, struct DebugMenuLine *menu);

extern void handle_line_type_long(struct GameTracker *gt, struct DebugMenuLine *line);

extern void handle_line_type_bit(struct GameTracker *gt, struct DebugMenuLine *line);

extern void handle_line_type_action(struct GameTracker *gt, struct DebugMenuLine *line);

extern void handle_line_type_action_with_line(struct GameTracker *gt, struct DebugMenuLine *line);

extern void handle_line_type_menu(struct GameTracker *gt, struct DebugMenuLine *line);

extern void process_menu_line(struct GameTracker *gt, struct DebugMenuLine *menu);

extern int pre_process_functions(struct GameTracker *gt, struct DebugMenuLine *menu);

extern void post_process_functions(struct GameTracker *gt, struct DebugMenuLine *menu);

extern void set_debug_leading();

extern void set_user_leading();

extern int isdigit(char c);

extern void adjust_format(char *ctrl, struct debug_format_t *fmt);

extern char *find_eol(char *text);

extern void draw_menu_item(struct GameTracker *gt, struct debug_format_t *fmt, char *text);

extern void draw_menu(struct GameTracker *gt, struct DebugMenuLine *menu);

extern void DEBUG_Menu(struct GameTracker *gt);

extern void DEBUG_DisplayStatus(struct GameTracker *gameTracker);

extern void DEBUG_DrawShrinkCels(unsigned long **polyAddr);

extern void DEBUG_ContinueGame();

extern void DEBUG_ExitGame();

extern void DEBUG_ReloadCurrentLevel();

extern void DEBUG_LevelSelectNew();

extern void DEBUG_SetViewVram();

extern void DEBUG_EndViewVram(struct GameTracker *gameTracker);

extern void DEBUG_ViewVram(struct GameTracker *gameTracker);

extern void DEBUG_CaptureScreen(struct GameTracker *gameTracker);

extern void DEBUG_PageFlip();

extern void DEBUG_FatalError(char *fmt);

extern void DEBUG_ProcessSecondController(struct GameTracker *gameTracker);

extern void DEBUG_ProcessCheat(struct GameTracker *gameTracker);

#endif
