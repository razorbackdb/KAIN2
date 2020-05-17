#ifndef RELMOD_H
#define RELMOD_H


extern void RELMOD_InitModulePointers(int baseaddr, int *relocs); // 0x8007CBA4

extern void RELMOD_RelocModulePointers(int baseaddr, int offset, int *relocs); // 0x8007CC88


#endif
