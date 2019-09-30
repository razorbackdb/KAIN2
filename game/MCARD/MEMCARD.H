#ifndef MEMCARD_H
#define MEMCARD_H


extern int MEMCARD_IsWrongVersion(struct memcard_t *memcard); // 0x800B81CC

extern void load(struct memcard_t *memcard); // 0x800B81E0

extern void unload(struct memcard_t *memcard); // 0x800B82AC

extern int memcard_data_size(); // 0x800B8300

extern int memcard_initialize(struct memcard_t *memcard, void *gt, int nblocks, void *buffer, int nbytes); // 0x800B8308

extern void memcard_end(struct memcard_t *memcard); // 0x800B83C8

extern int maybe_start(struct memcard_t *memcard); // 0x800B840C

extern int memcard_main_menu(void *gt, int index); // 0x800B8478

extern int memcard_pause_menu(void *gt, int index); // 0x800B84CC

extern void * gt2mcmenu(void *gt); // 0x800B8520

extern void memcard_pop(void *opaque); // 0x800B8534

extern void memcard_start(void *opaque); // 0x800B8570

extern void memcard_load(void *opaque); // 0x800B85B4

extern void memcard_save(void *opaque); // 0x800B8600

extern void memcard_item(void *opaque, TDRFuncPtr_memcard_item1fn fn, long parameter, long flags, char *text); // 0x800B8620


typedef int (*TDRFuncPtr_memcard_item1fn)();




#endif
