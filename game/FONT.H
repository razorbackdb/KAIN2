#ifndef FONT_H
#define FONT_H


extern void FONT_MakeSpecialFogClut(int x, int y); // 0x8002CA94

extern void FONT_Init(); // 0x8002CB18

extern void FONT_ReloadFont(); // 0x8002CC38

extern void FONT_DrawChar(struct FontChar *fontChar); // 0x8002CC9C

extern long FONT_Get2DImageIndex(unsigned char c); // 0x8002CCD0

extern void drawChar2DPoly(long fpi, long x, long y); // 0x8002CCEC

extern void FONT_DrawChar2D(unsigned char c, long x, long y); // 0x8002CEF8

extern long FONT_CharSpacing(char c, long fontXSize); // 0x8002D12C

extern void FONT_AddCharToBuffer(char c, long x, long y); // 0x8002D270

extern void FONT_Print(char *fmt); // 0x8002D2E0

extern void FONT_Print2(char *fmt); // 0x8002D37C

extern int FONT_GetStringWidth(char *str); // 0x8002D3D4

extern void FONT_Flush(); // 0x8002D448

extern void FONT_SetCursor(short x, short y); // 0x8002D4DC

extern void FONT_VaReallyPrint(char *fmt, void *ap); // 0x8002D4FC

extern void FONT_FontPrintCentered(char *text, long y); // 0x8002D694

extern void FONT_SetColorIndex(int color); // 0x8002D6EC


#endif
