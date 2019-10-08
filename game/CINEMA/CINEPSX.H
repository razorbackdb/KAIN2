#ifndef CINEPSX_H
#define CINEPSX_H

extern int CINE_CDIntrQuery();

extern unsigned short CINE_Pad(int pad);

extern void CINE_Play(char *strfile, unsigned short mask, int buffers);

extern int CINE_Load();

extern int CINE_Loaded();

extern void CINE_Unload();

extern void CINE_PlayIngame(int number);

#endif
