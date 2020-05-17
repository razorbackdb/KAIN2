#ifndef UNDRWRLD_H
#define UNDRWRLD_H


extern void UNDERWORLD_StartProcess(); // 0x800B4838

extern long UNDERWORLD_RotateScreenStep(long time); // 0x800B48AC

extern void UNDERWORLD_DoUV(unsigned char *uv, struct UW_ScreenXY *p0, int tx); // 0x800B4A18

extern struct POLY_GT3 * UNDERWORLD_Poly(struct POLY_GT3 *last, struct UW_ScreenXY *p0, struct UW_ScreenXY *p1, struct UW_ScreenXY *p2, int drawY); // 0x800B4A64

extern void UNDERWORLD_DisplayFrame(long *primStart, long drawY); // 0x800B4BDC

extern void UNDERWORLD_SetupSource(); // 0x800B4D34

extern void UNDERWORLD_InitDisplayProcess(); // 0x800B4DE0

extern struct _StreamUnit * UNDERWORLD_LoadLevel(char *baseAreaName, struct GameTracker *gameTracker); // 0x800B4EA0

extern void UNDERWORLD_UpdatePlayer(struct Intro *playerIntro, struct _Instance *instance); // 0x800B5198


#endif
