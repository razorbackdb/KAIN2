#ifndef MENU_H
#define MENU_H


extern int menu_data_size(); // 0x800B1B7C

extern void menu_initialize(struct menu_t *menu, void *opaque); // 0x800B1B84

extern void menu_format(struct menu_t *menu, int center, int xpos, int ypos, int width, int lineskip, int itemskip, int border); // 0x800B1BC8

extern void menu_set(struct menu_t *menu, TDRFuncPtr_menu_set1fn fn); // 0x800B1C18

extern void menu_push(struct menu_t *menu, TDRFuncPtr_menu_push1fn fn); // 0x800B1C3C

extern void menu_pop(struct menu_t *menu); // 0x800B1CAC

extern void menu_item(struct menu_t *menu, TDRFuncPtr_menu_item1fn fn, long parameter, char *format); // 0x800B1CC0

extern void menu_build(struct menu_t *menu); // 0x800B1D64

extern void DisplayHintBox(int len, int y); // 0x800B1DBC

extern void DisplayMenuBox(int x0, int x1, int y0, int y1); // 0x800B1EC4

extern int menu_draw_item(struct menu_t *menu, int ypos, int xadj, int yadj, char *text, int color, long flags, struct Extents2d *e); // 0x800B210C

extern void menu_draw(struct menu_t *menu); // 0x800B24DC

extern void menu_run(struct menu_t *menu); // 0x800B2624

extern void menu_process(struct menu_t *menu); // 0x800B2814


typedef int (*TDRFuncPtr_menu_item1fn)();

typedef int (*TDRFuncPtr_menu_push1fn)();

typedef int (*TDRFuncPtr_menu_set1fn)();




#endif
