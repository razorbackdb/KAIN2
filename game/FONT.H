#ifndef FONT_H
#define FONT_H


extern void FONT_MakeSpecialFogClut(int x, int y); // 0x8002CE04

extern void FONT_Init(); // 0x8002CE88

extern void FONT_ReloadFont(); // 0x8002CFA8

extern void FONT_DrawChar(struct FontChar *fontChar); // 0x8002D00C

extern long FONT_Get2DImageIndex(unsigned char c); // 0x8002D040

extern void drawChar2DPoly(long fpi, long x, long y); // 0x8002D05C

extern void FONT_DrawChar2D(unsigned char c, long x, long y); // 0x8002D268

extern long FONT_CharSpacing(char c, long fontXSize); // 0x8002D49C

extern void FONT_AddCharToBuffer(char c, long x, long y); // 0x8002D5E0

extern void FONT_Print(char *fmt); // 0x8002D650

extern void FONT_Print2(char *fmt); // 0x8002D6EC

extern int FONT_GetStringWidth(char *str); // 0x8002D744

extern void FONT_CenterString(char *str, int posX, int posY); // 0x8002D7B8

extern void FONT_Flush(); // 0x8002D8AC

extern void FONT_SetCursor(short x, short y); // 0x8002D940

extern void FONT_VaReallyPrint(char *fmt, void *ap); // 0x8002D96C

extern void FONT_FontPrintCentered(char *text, long y); // 0x8002DB04

extern void FONT_SetColorIndex(int color); // 0x8002DB5C


#endif
