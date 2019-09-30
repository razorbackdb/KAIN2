#ifndef MENUDEFS_H
#define MENUDEFS_H


extern void do_check_controller(void *gt); // 0x800B7274

extern int do_push_menu(void *gt, long menuparam, enum menu_ctrl_t ctrl); // 0x800B72A8

extern int do_pop_menu(void *gt, long param, enum menu_ctrl_t ctrl); // 0x800B72E0

extern int do_function(void *gt, long fnparam, enum menu_ctrl_t ctrl); // 0x800B7318

extern int do_start_game(void *gt, long parameter, enum menu_ctrl_t ctrl); // 0x800B734C

extern int do_save_menu(void *gt, long parameter, enum menu_ctrl_t ctrl); // 0x800B73B0

extern void womp_background(char *tim_path); // 0x800B73EC

extern void play_movie(char *name); // 0x800B7424

extern void menudefs_reset_hack_attract_mode(); // 0x800B746C

extern void check_hack_attract(); // 0x800B7490

extern int get_volume(void *gt, enum sfx_t sfx); // 0x800B7518

extern void set_volume(enum sfx_t sfx, int cooked); // 0x800B7584

extern int do_sound_adjust(void *gt, long sfxparam, enum menu_ctrl_t ctrl); // 0x800B7610

extern void sound_item(void *gt, char *text, enum sfx_t sfx); // 0x800B768C

extern int menudefs_toggle_dualshock(void *gt, long param, enum menu_ctrl_t ctrl); // 0x800B76F0

extern int options_menu(void *gt, int index); // 0x800B7774

extern int main_menu(void *gt, int index); // 0x800B78BC

extern int do_main_menu(void *gt, long param, enum menu_ctrl_t ctrl); // 0x800B7980

extern char * flashStart(); // 0x800B79D4

extern int menudefs_main_menu(void *gt, int index); // 0x800B7AC0

extern int menudefs_confirmexit_menu(void *gt, int index); // 0x800B7B68

extern int menudefs_pause_menu(void *gt, int index); // 0x800B7C10


#endif
