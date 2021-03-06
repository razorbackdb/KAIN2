#ifndef MENUUTIL_H
#define MENUUTIL_H


extern enum menu_ctrl_t menu_get_ctrl(void *gt); // 0x800B84B4

extern void menu_print(int xpos, int ypos, char *text, int color); // 0x800B8534

extern int menu_text_width(char *text); // 0x800B859C

extern void menu_sound(enum menu_sound_t sound); // 0x800B85BC


#endif
