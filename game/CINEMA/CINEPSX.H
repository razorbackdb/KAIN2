#ifndef CINEPSX_H
#define CINEPSX_H


extern int CINE_CDIntrQuery(); // 0x800B18D0

extern unsigned short CINE_Pad(int pad); // 0x800B18F8

extern void CINE_Play(char *strfile, unsigned short mask, int buffers); // 0x800B191C

extern int CINE_Load(); // 0x800B1980

extern void CINE_Unload(); // 0x800B1A30

extern void CINE_PlayIngame(int number); // 0x800B1A78


#endif
