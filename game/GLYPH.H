#ifndef GLYPH_H
#define GLYPH_H


extern void GlyphInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80079B64

extern void GlyphCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80079C78

extern void GlyphProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x80079C80

extern unsigned long GlyphQuery(struct _Instance *instance, unsigned long query); // 0x80079CF0

extern void GlyphPost(struct _Instance *instance, unsigned long message, unsigned long messageData); // 0x80079D40

extern void _GlyphSwitchProcess(struct _Instance *instance, TDRFuncPtr__GlyphSwitchProcess1process process); // 0x80079D98

extern int _GlyphIsGlyphSet(int glyph); // 0x80079E38

extern int _GlyphIsGlyphUsable(int glyph); // 0x80079E74

extern int _GlyphIsAnyGlyphSet(); // 0x80079EB0

extern int _GlyphCost(struct _GlyphTuneData *glyphtunedata, int glyphNum); // 0x80079ED8

extern void _GlyphDefaultProcess(struct _Instance *instance, int data1, int data2); // 0x80079EE8

extern void HUD_GetPlayerScreenPt(struct DVECTOR *center); // 0x80079F6C

extern void GlyphDrawMenu(struct _Instance *instance); // 0x80079FFC

extern long GlyphTime(int time); // 0x8007A358

extern void ShrinkGlyphMenu(struct _Instance *instance); // 0x8007A374

extern void EnlargeGlyphMenu(struct _Instance *instance); // 0x8007A478

extern void _GlyphOffProcess(struct _Instance *instance, int data1, int data2); // 0x8007A570

extern void _GlyphSelectProcess(struct _Instance *instance, int data1, int data2); // 0x8007A668

extern void Glyph_StartSpell(struct _Instance *instance, int glyphnum); // 0x8007AB44

extern void Glyph_Broadcast(struct _Instance *sender, int glyphnum); // 0x8007ABEC

extern void Glyph_DoSpell(struct _Instance *instance, int glyphnum); // 0x8007ADC0

extern void Glyph_EndFX(); // 0x8007B068

extern void Glyph_DoFX(struct _Instance *instance); // 0x8007B07C

extern void _GlyphGenericProcess(struct _Instance *instance, int data1, int data2); // 0x8007B12C

extern void GlyphTrigger(); // 0x8007B240

extern void MANNA_Pickup(struct _Instance *instance, int amount); // 0x8007B25C

extern void HEALTHU_Pickup(struct _Instance *instance); // 0x8007B288

extern void HUD_Damp(short *val, short target, short *vel, short max); // 0x8007B318

extern void HUD_Init(); // 0x8007B360

extern void HUD_Update(); // 0x8007B398

extern void HUD_Draw(); // 0x8007B5B0


typedef void (*TDRFuncPtr__GlyphSwitchProcess1process)();




#endif
