#ifndef FX_H
#define FX_H


extern void FX_Init(struct _FXTracker *fxTracker); // 0x80042560

extern void FX_Die(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80042640

extern struct _FX_MATRIX * FX_GetMatrix(struct _FXTracker *fxTracker); // 0x800426B0

extern struct _FX_PRIM * FX_GetPrim(struct _FXTracker *fxTracker); // 0x80042700

extern struct _FXParticle * FX_GetParticle(struct _Instance *instance, short startSegment); // 0x80042770

extern void FX_AniTexSetup(struct _FX_PRIM *fxPrim, struct _MFace *mface, struct _Model *model, struct _FXTracker *fxTracker); // 0x8004280C

extern void FX_StandardProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80042888

extern void FX_ShatterProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x800428A8

extern void FX_DFacadeProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80042B50

extern struct _FX_PRIM * _FX_BuildSingleFaceWithModel(struct _Model *model, struct _MFace *mface, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup fxSetup, TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess fxProcess, struct _FX_MATRIX *fxMatrix, int timeToLive); // 0x80042D24

extern struct _FX_PRIM * FX_BuildSingleFaceWithModel(struct _Model *model, struct _MFace *mface, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, TDRFuncPtr_FX_BuildSingleFaceWithModel6fxSetup fxSetup, TDRFuncPtr_FX_BuildSingleFaceWithModel7fxProcess fxProcess, int timeToLive); // 0x80042E20

extern void _FX_SetupLighting(struct _Instance *instance); // 0x80042E70

extern long _FX_DoLighting(struct _MFace *mface); // 0x80042EC0

extern void _FX_BuildSegmentedSplinters(struct _Instance *instance, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct FXSplinter *splintDef, struct _FXTracker *fxTracker, TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup fxSetup, TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess fxProcess, int shardFlags); // 0x80042FD8

extern void _FX_BuildNonSegmentedSplinters(struct _Instance *instance, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct FXSplinter *splintDef, struct _FXTracker *fxTracker, TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup fxSetup, TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess fxProcess, int shardFlags); // 0x80043A5C

extern void _FX_BuildSplinters(struct _Instance *instance, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct FXSplinter *splintDef, struct _FXTracker *fxTracker, TDRFuncPtr__FX_BuildSplinters6fxSetup fxSetup, TDRFuncPtr__FX_BuildSplinters7fxProcess fxProcess, int shardFlags); // 0x80044648

extern void _FX_Build(struct _Instance *instance, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, TDRFuncPtr__FX_Build5fxSetup fxSetup, TDRFuncPtr__FX_Build6fxProcess fxProcess, int shardFlags); // 0x8004479C

extern void FX_Build(struct _Instance *instance, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, TDRFuncPtr_FX_Build5fxSetup fxSetup, TDRFuncPtr_FX_Build6fxProcess fxProcess); // 0x800448B0

extern void FX_UpdatePos(struct _FX_PRIM *fxPrim, struct _SVector *offset, int spriteflag); // 0x800448E8

extern void FX_Relocate(struct _SVector *offset); // 0x80044A3C

extern void FX_UpdateTexturePointers(struct _FX_PRIM *fxPrim, struct Object *oldObject, long sizeOfObject, long offset); // 0x80044BEC

extern void FX_RelocateFXPointers(struct Object *oldObject, struct Object *newObject, long sizeOfObject); // 0x80044C4C

extern void FX_ProcessList(struct _FXTracker *fxTracker); // 0x80044D1C

extern void FX_DrawReaver(struct _PrimPool *primPool, unsigned long **ot, struct MATRIX *wcTransform); // 0x80044F18

extern void FX_DrawList(struct _FXTracker *fxTracker, struct GameTracker *gameTracker, unsigned long **ot, struct MATRIX *wcTransform); // 0x80044F64

extern void FX_SimpleQuadSetup(struct _FX_PRIM *fxPrim, TDRFuncPtr_FX_SimpleQuadSetup1fxProcess fxProcess, struct _FX_MATRIX *fxMatrix, struct _Instance *instance, struct _MFace *mface, struct _MVertex *vertexList, struct SVECTOR *center, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, int timeToLive); // 0x8004616C

extern void FX_WaterRingProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x800463A8

extern void FX_WaterBubbleProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80046424

extern void FX_Sprite_Insert(struct NodeType *list, struct _FX_PRIM *fxPrim); // 0x8004663C

extern struct TextureMT3 * FX_GetTextureObject(struct Object *object, int modelnum, int texnum); // 0x80046674

extern void FX_MakeWaterBubble(struct _SVector *position, struct _SVector *vel, struct _SVector *accl, long splashZ, struct __BubbleParams *BP); // 0x800466B0

extern void FX_DrawScreenPoly(int transtype, unsigned long color, int zdepth); // 0x80046860

extern struct POLY_GT4 * FX_SetupPolyGT4(int x1, int y1, int x2, int y2, int otz, struct TextureMT3 *texture, long color0, long color1, long color2, long color3); // 0x8004690C

extern void FX_MakeWarpArrow(int x, int y, int xsize, int ysize, int fade); // 0x80046A10

extern void FX_MakeMannaIcon(int x, int y, int xsize, int ysize); // 0x80046AF0

extern void FX_MakeGlyphIcon(struct _Position *position, struct Object *glyphObject, int size, int glyphnum, int enabled); // 0x80046C9C

extern void FX_SoulDustProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80046E60

extern void FX_MakeSoulDust(struct _Instance *instance, short segment); // 0x80047014

extern void FX_WaterTrailProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80047254

extern void FX_MakeWaterTrail(struct _Instance *instance, int depth); // 0x8004736C

extern struct _FXRibbon * FX_StartRibbon(struct _Instance *instance, short startSegment, short endSegment, short type, int ribbonLifeTime, int faceLifeTime, int startFadeValue, long startColor, long endColor); // 0x800475A0

extern void FX_RibbonProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80047870

extern void FX_ConstrictProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80047964

extern void FX_StartConstrict(struct _Instance *instance, struct _SVector *constrict_point, short startSegment, short endSegment); // 0x80047C08

extern void FX_EndConstrict(int ConstrictEnemyFlag, struct _Instance *instance); // 0x80047C98

extern void FX_SubDividePrim(struct _FX_PRIM *fxPrim1, struct _FX_PRIM *fxPrim2); // 0x80047D04

extern void FX_ContinueRibbon(struct _FXRibbon *ribbon, struct _FXTracker *fxTracker); // 0x80047DC8

extern void FX_StandardFXPrimProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80048398

extern void FX_AttachedParticlePrimProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x80048708

extern void FX_FlamePrimProcess(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x8004879C

extern void FX_DFacadeParticleSetup(struct _FX_PRIM *fxPrim, struct SVECTOR *center, short halveWidth, short halveHeight, long color, struct SVECTOR *vel, struct SVECTOR *accl, struct _FXTracker *fxTracker, int timeToLive); // 0x80048970

extern struct _FX_PRIM * FX_Dot(struct _SVector *location, struct _SVector *vel, struct _SVector *accel, int scale_speed, long color, long size, int lifetime, int texture_num); // 0x80048A58

extern void FX_Blood(struct _SVector *location, struct _SVector *input_vel, struct _SVector *accel, int amount, long color, long size); // 0x80048BC4

extern void FX_Blood2(struct _SVector *location, struct _SVector *input_vel, struct _SVector *accel, int amount, long color, long dummyCrapShouldRemove); // 0x80048D00

extern void FX_Blood_Impale(struct _Instance *locinst, short locseg, struct _Instance *instance, short segment); // 0x80048D2C

extern struct _FXParticle * FX_BloodCone(struct _Instance *instance, short startSegment, long time); // 0x80048EF8

extern struct _FXParticle * FX_GetTorchParticle(struct _Instance *instance, short startSegment, int tex, int birthRadius, int num); // 0x80048FC4

extern struct _FXParticle * FX_TorchFlame(struct _Instance *instance, short startSegment); // 0x800490A8

extern int FX_GetMorphFadeVal(); // 0x80049204

extern void FX_ConvertCamPersToWorld(struct SVECTOR *campos, struct SVECTOR *worldpos); // 0x80049244

extern void FX_GetRandomScreenPt(struct SVECTOR *point); // 0x8004935C

extern void FX_ProcessSnow(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x800493E8

extern void FX_ContinueSnow(struct _FXTracker *fxTracker); // 0x8004951C

extern void FX_UpdateWind(struct _FXTracker *fxTracker); // 0x80049674

extern void FX_ProcessRain(struct _FX_PRIM *fxPrim, struct _FXTracker *fxTracker); // 0x800497EC

extern void FX_ContinueRain(struct _FXTracker *fxTracker); // 0x800498BC

extern void FX_MakeSpark(struct _Instance *instance, struct _Model *model, int segment); // 0x80049BF4

extern void FX_ContinueParticle(struct _FXParticle *currentParticle, struct _FXTracker *fxTracker); // 0x80049CB0

extern void FX_UpdraftPrimModify(struct _FX_PRIM *fxPrim, struct _Instance *instance, struct _FXParticle *particle, struct _FXTracker *fxTracker); // 0x8004A4F0

extern void FX_MakeParticleTexFX(struct _FX_PRIM *fxPrim, struct _SVector *position, struct Object *object, int modelnum, int texnum, struct _SVector *vel, struct _SVector *accl, long color, int size, int life); // 0x8004A634

extern void FX_MakeHitFX(struct _SVector *position); // 0x8004A73C

extern void FX_ContinueLightning(struct _FXLightning *zap, struct _FXTracker *fxTracker); // 0x8004A7D0

extern void FX_SetReaverInstance(struct _Instance *instance); // 0x8004A830

extern void FX_SoulReaverBlade(struct _Instance *instance, unsigned long **drawot); // 0x8004A83C

extern void FX_ReaverBladeInit(); // 0x8004AC2C

extern void FX_SoulReaverWinding(struct _Instance *instance, struct _PrimPool *primPool, unsigned long **ot, struct MATRIX *wcTransform); // 0x8004AC34

extern void FX_UpdateInstanceWaterSplit(struct _Instance *instance); // 0x8004AE84

extern void FX_GetPlaneEquation(struct _SVector *normal, struct _SVector *poPlane, struct _PlaneConstants *plane); // 0x8004AF34

extern void FX_DoInstancePowerRing(struct _Instance *instance, long atuTime, long *color, long numColors, int follow_halveplane); // 0x8004AFA8

extern void FX_UpdatePowerRing(struct _FXHalvePlane *ring); // 0x8004B128

extern void FX_UpdateInstanceSplitRing(struct _FXHalvePlane *ring, struct _FXTracker *fxTracker); // 0x8004B3AC

extern void FX_UpdateGlowEffect(struct _FXGlowEffect *effect, struct _FXTracker *fxTracker); // 0x8004B43C

extern void FX_InsertGeneralEffect(void *ptr); // 0x8004B46C

extern void FX_DeleteGeneralEffect(struct _FXGeneralEffect *effect); // 0x8004B47C

extern struct _FXGlowEffect * FX_DoInstanceOneSegmentGlow(struct _Instance *instance, long segment, long *color, long numColors, long atuColorCycleRate, long width, long height); // 0x8004B518

extern void FX_SetGlowFades(struct _FXGlowEffect *glowEffect, int fadein, int fadeout); // 0x8004B678

extern struct _FXGlowEffect * FX_DoInstanceTwoSegmentGlow(struct _Instance *instance, long segment, long segmentEnd, long *color, long numColors, long atuColorCycleRate, long height); // 0x8004B694

extern struct _FXGlowEffect * FX_DoInstanceManySegmentGlow(struct _Instance *instance, long segment, long numSegments, long *color, long numColors, long atuColorCycleRate, long height); // 0x8004B6EC

extern struct _FXGlowEffect * FX_DoInstanceOneSegmentGlowWithTime(struct _Instance *instance, long segment, long *color, long numColors, long atuColorCycleRate, long width, long height, long ATULifeTime); // 0x8004B734

extern void FX_StopAllGlowEffects(struct _Instance *instance, int fadeout_time); // 0x8004B77C

extern void FX_StopGlowEffect(struct _FXGlowEffect *glowEffect, int fadeout_time); // 0x8004B810

extern void FX_DrawLightning(struct _FXLightning *zap, struct MATRIX *wcTransform, unsigned long **ot); // 0x8004B898

extern void FX_DrawAllGeneralEffects(struct MATRIX *wcTransform, struct _VertexPool *vertexPool, struct _PrimPool *primPool, unsigned long **ot); // 0x8004BB4C

extern void FX_ContinueBlastRing(struct _FXBlastringEffect *blast, struct _FXTracker *fxTracker); // 0x8004BD24

extern struct _FXBlastringEffect * FX_DoBlastRing(struct _Instance *instance, struct _SVector *position, struct MATRIX *mat, int segment, int radius, int endRadius, int colorChangeRadius, int size1, int size2, int vel, int accl, int height1, int height2, int height3, long startColor, long endColor, int pred_offset, int lifeTime, int sortInWorld); // 0x8004BF38

extern void FX_DrawBlastring(struct MATRIX *wcTransform, struct _FXBlastringEffect *blast); // 0x8004C10C

extern void FX_ContinueFlash(struct _FXFlash *flash, struct _FXTracker *fxTracker); // 0x8004C2D8

extern void FX_DrawFlash(struct _FXFlash *flash); // 0x8004C328

extern void FX_RelocateGeneric(struct Object *object, long offset); // 0x8004C43C

extern struct _FXParticle * FX_StartGenericParticle(struct _Instance *instance, int num, int segOverride, int lifeOverride, int InitFlag); // 0x8004C4D8

extern void FX_StartGenericRibbon(struct _Instance *instance, int num, int segOverride, int endOverride, int InitFlag); // 0x8004C828

extern void FX_StartGenericGlow(struct _Instance *instance, int num, int segOverride, int seg2Override, int InitFlag); // 0x8004C8E4

extern struct _FXLightning * FX_CreateLightning(struct _Instance *instance, int lifeTime, int deg, int deg_inc, int width, int small_width, int segs, int sine_size, int variation, unsigned long color, unsigned long glow_color); // 0x8004CA8C

extern void FX_SetLightingPos(struct _FXLightning *zap, struct _Instance *startInstance, int startSeg, struct _Position *startOffset, struct _Instance *endInstance, int endSeg, struct _Position *endOffset, int matrixSeg); // 0x8004CB94

extern struct _FXLightning * FX_StartGenericLightning(struct _Instance *instance, int num, int segOverride, int endSegOverride); // 0x8004CC44

extern struct _FXBlastringEffect * FX_StartGenericBlastring(struct _Instance *instance, int num, int segOverride, int matrixSegOverride); // 0x8004CDE8

extern struct _FXFlash * FX_StartGenericFlash(struct _Instance *instance, int num); // 0x8004CFF0

extern long FX_GetHealthColor(int currentHealth); // 0x8004D0D0

extern void FX_Start_Snow(int percent); // 0x8004D124

extern void FX_Start_Rain(int percent); // 0x8004D158

extern void FX_StartLightbeam(struct _Instance *instance, int startSeg, int endSeg, int color_num); // 0x8004D194

extern void FX_StartInstanceEffect(struct _Instance *instance, struct ObjectEffect *effect, int InitFlag); // 0x8004D238

extern void FX_EndInstanceEffects(struct _Instance *instance); // 0x8004D658

extern void FX_EndInstanceParticleEffects(struct _Instance *instance); // 0x8004D6AC

extern void FX_GetSpiralPoint(int radius, int deg, int *x, int *y); // 0x8004D71C

extern void FX_GetLinePoint(int radius, int next_radius, int deg, int next_deg, int *pntx, int *pnty, int part); // 0x8004D7F0

extern void FX_CalcSpiral(int degchange); // 0x8004D8BC

extern void FX_Spiral(struct _PrimPool *primPool, unsigned long **ot); // 0x8004DBB4

extern void FX_Health_Spiral(int number, int current_health, int max_health); // 0x8004DFD4

extern void FX_Spiral_Init(); // 0x8004E120

extern void FX_DrawModel(struct Object *object, int model_num, struct _SVector *rotation, struct _SVector *position, struct _SVector *offset, int transflag); // 0x8004E160

extern void fx_calc_points(struct _SVector *points, int degrees, int radius, int radius2, int radius3); // 0x8004E3D8

extern long fx_get_startz(struct _SVector *position); // 0x8004E4E8

extern void FX_DrawRing(struct MATRIX *wcTransform, struct _SVector *position, struct MATRIX *matrix, int radius, int radius2, int radius3, int z1, int z2, int z3, long color, int sortInWorld); // 0x8004E540

extern void fx_setTex(struct DVECTOR *x, unsigned char *uv, int tx, int offset); // 0x8004E7EC

extern void FX_DrawRing2(struct MATRIX *wcTransform, struct _SVector *position, struct MATRIX *matrix, int radius, int radius2, int radius3, int z1, int z2, int z3, long offset, int sortInWorld); // 0x8004E830

extern void FX_DrawFField(struct MATRIX *wcTransform, struct _FXForceFieldEffect *field); // 0x8004EC08

extern struct _FXForceFieldEffect * FX_StartFField(struct _Instance *instance, int size, struct _Position *offset, int size_diff, int size_change, int deg_change, long color); // 0x8004EDFC

extern void FX_EndFField(struct _Instance *instance); // 0x8004EED0

extern void FX_Draw_Glowing_Line(unsigned long **ot, long otz, struct DVECTOR *sxy0, struct DVECTOR *sxy1, struct DVECTOR *xy0, struct DVECTOR *xy1, long color, long color2); // 0x8004EF50

extern void FX_Lightning(struct MATRIX *wcTransform, unsigned long **ot, struct MATRIX *mat, short deg, struct _SVector *start, struct _SVector *end, int width, int small_width, int segs, int sine_size, int variation, long color, long glow_color); // 0x8004F0EC

extern void FX_LightHouse(struct MATRIX *wcTransform, unsigned long **ot, struct _Instance *instance, int startSeg, int endSeg, int segs, long beam_color); // 0x8004F5DC

extern void FX_StartPassthruFX(struct _Instance *instance, struct _SVector *normal, struct _SVector *point); // 0x8004FA58

extern void FX_EndPassthruFX(struct _Instance *instance); // 0x8004FB34


typedef void (*TDRFuncPtr__FX_Build5fxSetup)();

typedef void (*TDRFuncPtr__FX_Build6fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildSplinters6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildSplinters7fxProcess)();

typedef void (*TDRFuncPtr_FX_Build5fxSetup)();

typedef void (*TDRFuncPtr_FX_Build6fxProcess)();

typedef void (*TDRFuncPtr_FX_BuildSingleFaceWithModel6fxSetup)();

typedef void (*TDRFuncPtr_FX_BuildSingleFaceWithModel7fxProcess)();

typedef void (*TDRFuncPtr_FX_SimpleQuadSetup1fxProcess)();




#endif
