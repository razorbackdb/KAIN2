#ifndef LOCALSTR_H
#define LOCALSTR_H

extern enum language_t localstr_get_language();

extern void localstr_set_language(enum language_t lang);

extern char *localstr_get(enum localstr_t id);

#endif
