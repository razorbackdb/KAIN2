#ifndef GLYPH_H
#define GLYPH_H

extern void GlyphInit(struct _Instance *instance, struct GameTracker *gameTracker);

extern void GlyphCollide(struct _Instance *instance, struct GameTracker *gameTracker);

extern void GlyphProcess(struct _Instance *instance, struct GameTracker *gameTracker);

extern unsigned long GlyphQuery(struct _Instance *instance, unsigned long query);

extern void GlyphPost(struct _Instance *instance, unsigned long message, unsigned long messageData);

extern void _GlyphSwitchProcess(struct _Instance *instance, TDRFuncPtr__GlyphSwitchProcess1process process);

extern int GlyphIsGlyphOpen(struct _Instance *instance);

extern int _GlyphIsGlyphSet(int glyph);

extern int _GlyphIsGlyphUsable(int glyph);

extern int _GlyphIsAnyGlyphSet();

extern int _GlyphCost(struct _GlyphTuneData *glyphtunedata, int glyphNum);

extern void _GlyphDefaultProcess(struct _Instance *instance, int data1, int data2);

extern void HUD_GetPlayerScreenPt(struct DVECTOR *center);

extern void GlyphDrawMenu(struct _Instance *instance);

extern long GlyphTime(int time);

extern void ShrinkGlyphMenu(struct _Instance *instance);

extern void EnlargeGlyphMenu(struct _Instance *instance);

extern void _GlyphOffProcess(struct _Instance *instance, int data1, int data2);

extern void _GlyphSelectProcess(struct _Instance *instance, int data1, int data2);

extern void Glyph_StartSpell(struct _Instance *instance, int glyphnum);

extern void Glyph_Broadcast(struct _Instance *sender, int glyphnum);

extern void Glyph_DoSpell(struct _Instance *instance, int glyphnum);

extern void Glyph_EndFX();

extern void Glyph_DoFX(struct _Instance *instance);

extern void _GlyphGenericProcess(struct _Instance *instance, int data1, int data2);

extern void GlyphTrigger();

extern void MANNA_Pickup();

extern void HEALTHU_Pickup(struct _Instance *instance);

extern void HUD_Damp(short *val, short target, short *vel, short max);

extern void HUD_Init();

extern void HUD_Setup_Chit_Count(int chits);

extern void HUD_Update();

extern void HUD_Draw();

typedef void (*TDRFuncPtr__GlyphSwitchProcess1process)();

#endif
