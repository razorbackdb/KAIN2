#ifndef MENU_H
#define MENU_H

extern int menu_data_size();

extern void menu_initialize(struct menu_t *menu, void *opaque);

extern void menu_format(struct menu_t *menu, int center, int xpos, int ypos, int width, int lineskip, int itemskip, int border);

extern void menu_set(struct menu_t *menu, TDRFuncPtr_menu_set1fn fn);

extern void menu_push(struct menu_t *menu, TDRFuncPtr_menu_push1fn fn);

extern void menu_pop(struct menu_t *menu);

extern void menu_item_flags(struct menu_t *menu, TDRFuncPtr_menu_item_flags1fn fn, long parameter, long flags, char *format);

extern void menu_item(struct menu_t *menu, TDRFuncPtr_menu_item1fn fn, long parameter, char *format);

extern void menu_build(struct menu_t *menu);

extern void DisplayHintBox(int len, int y);

extern void DisplayMenuBox(int x0, int x1, int y0, int y1);

extern int menu_draw_item(struct menu_t *menu, int ypos, int xadj, int yadj, char *text, int color, long flags, struct Extents2d *e);

extern void menu_draw(struct menu_t *menu);

extern void menu_run(struct menu_t *menu);

extern void menu_process(struct menu_t *menu);

typedef int (*TDRFuncPtr_menu_item_flags1fn)();

typedef int (*TDRFuncPtr_menu_item1fn)();

typedef int (*TDRFuncPtr_menu_push1fn)();

typedef int (*TDRFuncPtr_menu_set1fn)();

#endif
