#ifndef MENUFACE_H
#define MENUFACE_H


extern char * NextTimAddr(char *addr, int w, int h, enum bdepth bpp); // 0x800B91B0

extern void menuface_initialize(); // 0x800B91F8

extern void menuface_terminate(); // 0x800B9324

extern void MENUFACE_ChangeStateRandomly(int index); // 0x800B93D0

extern void MENUFACE_RefreshFaces(); // 0x800B94F4


#endif
