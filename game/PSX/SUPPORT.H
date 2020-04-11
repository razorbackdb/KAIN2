#ifndef SUPPORT_H
#define SUPPORT_H


extern int printf(char *fmt); // 0x80073C48

extern int sprintf(char *string, char *fmt); // 0x80073C98

extern int vsprintf(char *str, char *fmtstr, void *argptr); // 0x80073CC8

extern char * my_itoa(unsigned long value, char *str, int radix); // 0x80073F44

extern int atoi(char *str); // 0x80074014

extern int mytolower(int c); // 0x80074084

extern int strcmpi(char *s1, char *s2); // 0x800740A0


#endif
