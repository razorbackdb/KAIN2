#ifndef FONT_H
#define FONT_H

extern void FONT_MakeSpecialFogClut(int x, int y);

extern void FONT_Init();

extern void FONT_ReloadFont();

extern void FONT_DrawChar(struct FontChar *fontChar);

extern long FONT_Get2DImageIndex(unsigned char c);

extern void drawChar2DPoly(long fpi, long x, long y);

extern void FONT_DrawChar2D(unsigned char c, long x, long y);

extern long FONT_CharSpacing(char c, long fontXSize);

extern void FONT_AddCharToBuffer(char c, long x, long y);

extern void FONT_Print(char *fmt);

extern void FONT_Print2(char *fmt);

extern int FONT_GetStringWidth(char *str);

extern void FONT_Flush();

extern void FONT_SetCursor(short x, short y);

extern void FONT_VaReallyPrint(char *fmt, void *ap);

extern void FONT_FontPrintCentered(char *text, long y);

extern void FONT_SetColorIndex(int color);

#endif
