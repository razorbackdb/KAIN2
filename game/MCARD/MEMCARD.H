#ifndef MEMCARD_H
#define MEMCARD_H

extern int MEMCARD_IsWrongVersion(struct memcard_t *memcard);

extern void load(struct memcard_t *memcard);

extern void unload(struct memcard_t *memcard);

extern int memcard_data_size();

extern int memcard_initialize(struct memcard_t *memcard, void *gt, int nblocks, void *buffer, int nbytes);

extern void memcard_end(struct memcard_t *memcard);

extern int maybe_start(struct memcard_t *memcard);

extern int memcard_main_menu(void *gt, int index);

extern int memcard_pause_menu(void *gt, int index);

extern void *gt2mcmenu(void *gt);

extern void memcard_pop(void *opaque);

extern void memcard_start(void *opaque);

extern void memcard_load(void *opaque);

extern void memcard_save(void *opaque);

extern void memcard_item(void *opaque, TDRFuncPtr_memcard_item1fn fn, long parameter, long flags, char *text);

typedef int (*TDRFuncPtr_memcard_item1fn)();

#endif
