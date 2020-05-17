#ifndef MENUDEFS_H
#define MENUDEFS_H


extern void do_check_controller(void *gt); // 0x800B85F0

extern int do_push_menu(void *gt, long menuparam, enum menu_ctrl_t ctrl); // 0x800B8624

extern int do_pop_menu(void *gt, long param, enum menu_ctrl_t ctrl); // 0x800B865C

extern int do_function(void *gt, long fnparam, enum menu_ctrl_t ctrl); // 0x800B8694

extern int do_start_game(void *gt, long parameter, enum menu_ctrl_t ctrl); // 0x800B86C8

extern int do_save_menu(void *gt, long parameter, enum menu_ctrl_t ctrl); // 0x800B872C

extern void womp_background(char *tim_path); // 0x800B8768

extern void play_movie(char *name); // 0x800B87A0

extern void menudefs_reset_hack_attract_mode(); // 0x800B87E8

extern void check_hack_attract(); // 0x800B880C

extern int get_volume(void *gt, enum sfx_t sfx); // 0x800B887C

extern void set_volume(enum sfx_t sfx, int cooked); // 0x800B88E8

extern int do_sound_adjust(void *gt, long sfxparam, enum menu_ctrl_t ctrl); // 0x800B8974

extern void sound_item(void *gt, char *text, enum sfx_t sfx); // 0x800B89F0

extern int menudefs_toggle_dualshock(void *gt, long param, enum menu_ctrl_t ctrl); // 0x800B8A54

extern int options_menu(void *gt, int index); // 0x800B8AB8

extern int main_menu(void *gt, int index); // 0x800B8C00

extern int do_main_menu(void *gt, long param, enum menu_ctrl_t ctrl); // 0x800B8CC4

extern char * flashStart(); // 0x800B8D18

extern int menudefs_main_menu(void *gt, int index); // 0x800B8F1C

extern int menudefs_confirmexit_menu(void *gt, int index); // 0x800B8FC4

extern int menudefs_pause_menu(void *gt, int index); // 0x800B906C


#endif
