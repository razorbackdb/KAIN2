#ifndef LOCALSTR_H
#define LOCALSTR_H


extern void localstr_set_language(enum language_t lang); // 0x800B1ABC

extern char * localstr_get(enum localstr_t id); // 0x800B1B4C


#endif
