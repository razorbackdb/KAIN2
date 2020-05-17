#ifndef SUPPORT_H
#define SUPPORT_H


extern int printf(char *fmt); // 0x80074418

extern int sprintf(char *string, char *fmt); // 0x80074468

extern int vsprintf(char *str, char *fmtstr, void *argptr); // 0x80074498

extern char * my_itoa(unsigned long value, char *str, int radix); // 0x80074714

extern int atoi(char *str); // 0x800747E4

extern int mytolower(int c); // 0x80074854

extern int strcmpi(char *s1, char *s2); // 0x80074870


#endif
