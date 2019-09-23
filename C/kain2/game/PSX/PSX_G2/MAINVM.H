#ifndef MAINVM_H
#define MAINVM_H

struct _G2AppDataVM_Type // hashcode: 0xC1BF7B11 (dec: -1044415727)
{
	int argc;  // size=0, offset=0 //  hashcode: 0x719EC553 (dec: 1906230611), parent name: '_G2AppDataVM_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int *argv; // size=0, offset=4 //  hashcode: 0x1B38EC1B (dec: 456715291), parent name: '_G2AppDataVM_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

typedef struct _G2AppDataVM_Type G2AppDataVM;

static struct _G2AppDataVM_Type _appDataVM; // offset 0x800D517C

extern int main(); // 0x800962C0

extern void __main();

extern int __initialised;

#endif
