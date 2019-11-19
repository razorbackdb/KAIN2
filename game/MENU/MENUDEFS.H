#ifndef MENUDEFS_H
#define MENUDEFS_H


extern int do_push_menu(void *gt, long menuparam, enum menu_ctrl_t ctrl); // 0x800B2980

extern int do_pop_menu(void *gt, long param, enum menu_ctrl_t ctrl); // 0x800B29B8

extern int do_function(void *gt, long fnparam, enum menu_ctrl_t ctrl); // 0x800B29F0

extern int do_start_game(void *gt, long parameter, enum menu_ctrl_t ctrl); // 0x800B2A24

extern int do_save_menu(void *gt, long parameter, enum menu_ctrl_t ctrl); // 0x800B2A88

extern void womp_background(char *tim_path); // 0x800B2AC4

extern void play_movie(char *name); // 0x800B2AFC

extern void menudefs_reset_hack_attract_mode(); // 0x800B2B3C

extern void check_hack_attract(); // 0x800B2B60

extern int get_volume(void *gt, enum sfx_t sfx); // 0x800B2BE8

extern void set_volume(enum sfx_t sfx, int cooked); // 0x800B2C54

extern int do_sound_adjust(void *gt, long sfxparam, enum menu_ctrl_t ctrl); // 0x800B2CE0

extern void sound_item(void *gt, char *text, enum sfx_t sfx); // 0x800B2D5C

extern int maybe_update_flags(long *flagsptr, long mask, enum menu_ctrl_t ctrl); // 0x800B2DC0

extern int do_flags(void *gt, long mask, enum menu_ctrl_t ctrl); // 0x800B2E34

extern int do_debug(void *gt, long mask, enum menu_ctrl_t ctrl); // 0x800B2E54

extern void flags_item(void *gt, char *text, long mask); // 0x800B2E74

extern void debug_item(void *gt, char *text, long mask); // 0x800B2ED0

extern int cheats_menu(void *gt, int index); // 0x800B2F2C

extern int menudefs_toggle_dualshock(void *gt, int index); // 0x800B3048

extern int options_menu(void *gt, int index); // 0x800B30CC

extern int main_menu(void *gt, int index); // 0x800B31D0

extern int do_main_menu(void *gt, long param, enum menu_ctrl_t ctrl); // 0x800B32B4

extern char * flashStart(); // 0x800B331C

extern int menudefs_main_menu(void *gt, int index); // 0x800B3394

extern int menudefs_confirmexit_menu(void *gt, int index); // 0x800B343C

extern int menudefs_pause_menu(void *gt, int index); // 0x800B34DC


#endif
