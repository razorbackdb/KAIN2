#ifndef MEMCARD_H
#define MEMCARD_H


extern int MEMCARD_IsWrongVersion(struct memcard_t *memcard); // 0x800B3BC8

extern void load(struct memcard_t *memcard); // 0x800B3BDC

extern void unload(struct memcard_t *memcard); // 0x800B3CB8

extern int memcard_data_size(); // 0x800B3D0C

extern int memcard_initialize(struct memcard_t *memcard, void *gt, int nblocks, void *buffer, int nbytes); // 0x800B3D14

extern void memcard_end(struct memcard_t *memcard); // 0x800B3DF8

extern int maybe_start(struct memcard_t *memcard); // 0x800B3E3C

extern int memcard_main_menu(void *gt, int index); // 0x800B3EA8

extern int memcard_pause_menu(void *gt, int index); // 0x800B3EFC

extern void * gt2mcmenu(void *gt); // 0x800B3F50

extern void memcard_pop(void *opaque); // 0x800B3F64

extern void memcard_start(void *opaque); // 0x800B3FAC

extern void memcard_load(void *opaque); // 0x800B3FFC

extern void memcard_save(void *opaque); // 0x800B4054

extern void memcard_item(void *opaque, TDRFuncPtr_memcard_item1fn fn, long parameter, char *text); // 0x800B4074


typedef int (*TDRFuncPtr_memcard_item1fn)();




#endif
