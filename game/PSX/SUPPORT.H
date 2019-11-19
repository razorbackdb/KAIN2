#ifndef SUPPORT_H
#define SUPPORT_H


extern int printf(char *fmt); // 0x8007395C

extern int sprintf(char *string, char *fmt); // 0x800739AC

extern int vsprintf(char *str, char *fmtstr, void *argptr); // 0x800739DC

extern char * my_itoa(unsigned long value, char *str, int radix); // 0x80073C58

extern int atoi(char *str); // 0x80073D28

extern int mytolower(int c); // 0x80073D98

extern int strcmpi(char *s1, char *s2); // 0x80073DB4


#endif
