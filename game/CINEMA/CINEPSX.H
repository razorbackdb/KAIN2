#ifndef CINEPSX_H
#define CINEPSX_H


extern int CINE_CDIntrQuery(); // 0x800B60C8

extern unsigned short CINE_Pad(int pad); // 0x800B60F0

extern void CINE_Play(char *strfile, unsigned short mask, int buffers); // 0x800B6114

extern int CINE_Load(); // 0x800B6178

extern int CINE_Loaded(); // 0x800B621C

extern void CINE_Unload(); // 0x800B622C

extern void CINE_PlayIngame(int number); // 0x800B6274


#endif
