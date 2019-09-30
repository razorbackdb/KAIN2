#ifndef MENU_H
#define MENU_H


extern int menu_data_size(); // 0x800B6390

extern void menu_initialize(struct menu_t *menu, void *opaque); // 0x800B6398

extern void menu_format(struct menu_t *menu, int center, int xpos, int ypos, int width, int lineskip, int itemskip, int border); // 0x800B63DC

extern void menu_set(struct menu_t *menu, TDRFuncPtr_menu_set1fn fn); // 0x800B642C

extern void menu_push(struct menu_t *menu, TDRFuncPtr_menu_push1fn fn); // 0x800B6450

extern void menu_pop(struct menu_t *menu); // 0x800B64C0

extern void menu_item_flags(struct menu_t *menu, TDRFuncPtr_menu_item_flags1fn fn, long parameter, long flags, char *format); // 0x800B64D4

extern void menu_item(struct menu_t *menu, TDRFuncPtr_menu_item1fn fn, long parameter, char *format); // 0x800B6564

extern void menu_build(struct menu_t *menu); // 0x800B6608

extern void DisplayHintBox(int len, int y); // 0x800B6660

extern void DisplayMenuBox(int x0, int x1, int y0, int y1); // 0x800B678C

extern int menu_draw_item(struct menu_t *menu, int ypos, int xadj, int yadj, char *text, int color, long flags, struct Extents2d *e); // 0x800B69CC

extern void menu_draw(struct menu_t *menu); // 0x800B6DD0

extern void menu_run(struct menu_t *menu); // 0x800B6F18

extern void menu_process(struct menu_t *menu); // 0x800B7108


typedef int (*TDRFuncPtr_menu_item_flags1fn)();

typedef int (*TDRFuncPtr_menu_item1fn)();

typedef int (*TDRFuncPtr_menu_push1fn)();

typedef int (*TDRFuncPtr_menu_set1fn)();




#endif
