#ifndef GLYPH_H
#define GLYPH_H


extern void GlyphInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007A22C

extern void GlyphCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007A348

extern void GlyphProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007A350

extern unsigned long GlyphQuery(struct _Instance *instance, unsigned long query); // 0x8007A3D8

extern void GlyphPost(struct _Instance *instance, unsigned long message, unsigned long messageData); // 0x8007A3F8

extern void _GlyphSwitchProcess(struct _Instance *instance, TDRFuncPtr__GlyphSwitchProcess1process process); // 0x8007A42C

extern int GlyphIsGlyphOpen(struct _Instance *instance); // 0x8007A4CC

extern int _GlyphIsGlyphSet(int glyph); // 0x8007A4E0

extern int _GlyphIsGlyphUsable(int glyph); // 0x8007A51C

extern int _GlyphIsAnyGlyphSet(); // 0x8007A558

extern int _GlyphCost(struct _GlyphTuneData *glyphtunedata, int glyphNum); // 0x8007A580

extern void _GlyphDefaultProcess(struct _Instance *instance, int data1, int data2); // 0x8007A590

extern void HUD_GetPlayerScreenPt(struct DVECTOR *center); // 0x8007A628

extern void GlyphDrawMenu(struct _Instance *instance); // 0x8007A6B8

extern long GlyphTime(int time); // 0x8007AA1C

extern void ShrinkGlyphMenu(struct _Instance *instance); // 0x8007AA38

extern void EnlargeGlyphMenu(struct _Instance *instance); // 0x8007AB64

extern void _GlyphOffProcess(struct _Instance *instance, int data1, int data2); // 0x8007AC68

extern void _GlyphSelectProcess(struct _Instance *instance, int data1, int data2); // 0x8007AD60

extern void Glyph_StartSpell(struct _Instance *instance, int glyphnum); // 0x8007B228

extern void Glyph_Broadcast(struct _Instance *sender, int glyphnum); // 0x8007B2D0

extern void Glyph_DoSpell(struct _Instance *instance, int glyphnum); // 0x8007B4A4

extern void Glyph_EndFX(); // 0x8007B74C

extern void Glyph_DoFX(struct _Instance *instance); // 0x8007B760

extern void _GlyphGenericProcess(struct _Instance *instance, int data1, int data2); // 0x8007B810

extern void GlyphTrigger(); // 0x8007B948

extern void MANNA_Pickup(); // 0x8007B964

extern void HEALTHU_Pickup(struct _Instance *instance); // 0x8007B980

extern void HUD_Damp(short *val, short target, short *vel, short max); // 0x8007BA10

extern void HUD_Init(); // 0x8007BA58

extern void HUD_Setup_Chit_Count(int chits); // 0x8007BA8C

extern void HUD_Update(); // 0x8007BAC0

extern void HUD_Draw(); // 0x8007BD08


typedef void (*TDRFuncPtr__GlyphSwitchProcess1process)();




#endif
