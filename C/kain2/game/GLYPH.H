#ifndef GLYPH_H
#define GLYPH_H


extern void GlyphInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007AB64

extern void GlyphCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007AC80

extern void GlyphProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007AC88

extern unsigned long GlyphQuery(struct _Instance *instance, unsigned long query); // 0x8007AD10

extern void GlyphPost(struct _Instance *instance, unsigned long message, unsigned long messageData); // 0x8007AD30

extern void _GlyphSwitchProcess(struct _Instance *instance, TDRFuncPtr__GlyphSwitchProcess1process process); // 0x8007AD64

extern int GlyphIsGlyphOpen(struct _Instance *instance); // 0x8007AE04

extern int _GlyphIsGlyphSet(int glyph); // 0x8007AE18

extern int _GlyphIsGlyphUsable(int glyph); // 0x8007AE5C

extern int _GlyphIsAnyGlyphSet(); // 0x8007AE98

extern int _GlyphCost(struct _GlyphTuneData *glyphtunedata, int glyphNum); // 0x8007AEC8

extern void _GlyphDefaultProcess(struct _Instance *instance, int data1, int data2); // 0x8007AED8

extern void HUD_GetPlayerScreenPt(struct DVECTOR *center); // 0x8007AF70

extern void GlyphDrawMenu(struct _Instance *instance); // 0x8007B000

extern long GlyphTime(int time); // 0x8007B364

extern void ShrinkGlyphMenu(struct _Instance *instance); // 0x8007B380

extern void EnlargeGlyphMenu(struct _Instance *instance); // 0x8007B4A4

extern void _GlyphOffProcess(struct _Instance *instance, int data1, int data2); // 0x8007B5A0

extern void _GlyphSelectProcess(struct _Instance *instance, int data1, int data2); // 0x8007B6D8

extern void Glyph_StartSpell(struct _Instance *instance, int glyphnum); // 0x8007BBA0

extern void Glyph_Broadcast(struct _Instance *sender, int glyphnum); // 0x8007BC48

extern void Glyph_DoSpell(struct _Instance *instance, int glyphnum); // 0x8007BEA0

extern void Glyph_EndFX(); // 0x8007C144

extern void Glyph_DoFX(struct _Instance *instance); // 0x8007C158

extern void _GlyphGenericProcess(struct _Instance *instance, int data1, int data2); // 0x8007C208

extern void GlyphTrigger(); // 0x8007C340

extern void MANNA_Pickup(); // 0x8007C35C

extern void HEALTHU_Pickup(struct _Instance *instance); // 0x8007C378

extern void HUD_Damp(short *val, short target, short *vel, short max); // 0x8007C404

extern void HUD_Init(); // 0x8007C44C

extern void HUD_Setup_Chit_Count(int chits); // 0x8007C484

extern void HUD_Update(); // 0x8007C4BC

extern void HUD_Draw(); // 0x8007C6F0


typedef void (*TDRFuncPtr__GlyphSwitchProcess1process)();




#endif
