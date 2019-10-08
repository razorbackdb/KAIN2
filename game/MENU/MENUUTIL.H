#ifndef MENUUTIL_H
#define MENUUTIL_H

extern enum menu_ctrl_t menu_get_ctrl(void *gt);

extern void menu_print(int xpos, int ypos, char *text, int color);

extern int menu_text_width(char *text);

extern void menu_sound(enum menu_sound_t sound);

#endif
