#ifndef LOCALSTR_H
#define LOCALSTR_H


extern enum language_t localstr_get_language(); // 0x800B62C4

extern void localstr_set_language(enum language_t lang); // 0x800B62D0

extern char * localstr_get(enum localstr_t id); // 0x800B6360


#endif
