#ifndef CINEPSX_H
#define CINEPSX_H


extern int CINE_CDIntrQuery(); // 0x800B7434

extern unsigned short CINE_Pad(int pad); // 0x800B745C

extern void CINE_Play(char *strfile, unsigned short mask, int buffers); // 0x800B7480

extern int CINE_Load(); // 0x800B74E4

extern int CINE_Loaded(); // 0x800B7588

extern void CINE_Unload(); // 0x800B7598

extern void CINE_PlayIngame(int number); // 0x800B75E0


#endif
