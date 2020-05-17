#ifndef MEMCARD_H
#define MEMCARD_H


extern int MEMCARD_IsWrongVersion(struct memcard_t *memcard); // 0x800B959C

extern void load(struct memcard_t *memcard); // 0x800B95B0

extern void unload(struct memcard_t *memcard); // 0x800B967C

extern int memcard_data_size(); // 0x800B96D0

extern int memcard_initialize(struct memcard_t *memcard, void *gt, int nblocks, void *buffer, int nbytes); // 0x800B96D8

extern void memcard_end(struct memcard_t *memcard); // 0x800B9798

extern int maybe_start(struct memcard_t *memcard); // 0x800B97DC

extern int memcard_main_menu(void *gt, int index); // 0x800B9848

extern int memcard_pause_menu(void *gt, int index); // 0x800B989C

extern void * gt2mcmenu(void *gt); // 0x800B98F0

extern void memcard_pop(void *opaque); // 0x800B9904

extern void memcard_start(void *opaque); // 0x800B9940

extern void memcard_load(void *opaque); // 0x800B9984

extern void memcard_save(void *opaque); // 0x800B99D0

extern void memcard_item(void *opaque, TDRFuncPtr_memcard_item1fn fn, long parameter, long flags, char *text); // 0x800B99F0


typedef int (*TDRFuncPtr_memcard_item1fn)();




#endif
