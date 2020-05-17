#ifndef LOCALSTR_H
#define LOCALSTR_H


extern enum language_t localstr_get_language(); // 0x800B7630

extern void localstr_set_language(enum language_t lang); // 0x800B763C

extern char * localstr_get(enum localstr_t id); // 0x800B76CC


#endif
