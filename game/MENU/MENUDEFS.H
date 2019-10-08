#ifndef MENUDEFS_H
#define MENUDEFS_H

extern void do_check_controller(void *gt);

extern int do_push_menu(void *gt, long menuparam, enum menu_ctrl_t ctrl);

extern int do_pop_menu(void *gt, long param, enum menu_ctrl_t ctrl);

extern int do_function(void *gt, long fnparam, enum menu_ctrl_t ctrl);

extern int do_start_game(void *gt, long parameter, enum menu_ctrl_t ctrl);

extern int do_save_menu(void *gt, long parameter, enum menu_ctrl_t ctrl);

extern void womp_background(char *tim_path);

extern void play_movie(char *name);

extern void menudefs_reset_hack_attract_mode();

extern void check_hack_attract();

extern int get_volume(void *gt, enum sfx_t sfx);

extern void set_volume(enum sfx_t sfx, int cooked);

extern int do_sound_adjust(void *gt, long sfxparam, enum menu_ctrl_t ctrl);

extern void sound_item(void *gt, char *text, enum sfx_t sfx);

extern int menudefs_toggle_dualshock(void *gt, long param, enum menu_ctrl_t ctrl);

extern int options_menu(void *gt, int index);

extern int main_menu(void *gt, int index);

extern int do_main_menu(void *gt, long param, enum menu_ctrl_t ctrl);

extern char *flashStart();

extern int menudefs_main_menu(void *gt, int index);

extern int menudefs_confirmexit_menu(void *gt, int index);

extern int menudefs_pause_menu(void *gt, int index);

#endif
