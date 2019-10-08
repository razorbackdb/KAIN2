#ifndef UNDRWRLD_H
#define UNDRWRLD_H

extern void UNDERWORLD_StartProcess();

extern long UNDERWORLD_RotateScreenStep(long time);

extern void UNDERWORLD_DoUV(unsigned char *uv, struct UW_ScreenXY *p0, int tx);

extern struct POLY_GT3 *UNDERWORLD_Poly(struct POLY_GT3 *last, struct UW_ScreenXY *p0, struct UW_ScreenXY *p1, struct UW_ScreenXY *p2, int drawY);

extern void UNDERWORLD_DisplayFrame(long *primStart, long drawY);

extern void UNDERWORLD_SetupSource();

extern void UNDERWORLD_InitDisplayProcess();

extern struct _StreamUnit *UNDERWORLD_LoadLevel(char *baseAreaName, struct GameTracker *gameTracker);

extern void UNDERWORLD_UpdatePlayer(struct Intro *playerIntro, struct _Instance *instance);

#endif
