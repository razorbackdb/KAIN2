#ifndef RELMOD_H
#define RELMOD_H

extern void RELMOD_InitModulePointers(int baseaddr, int *relocs);

extern void RELMOD_RelocModulePointers(int baseaddr, int offset, int *relocs);

#endif
