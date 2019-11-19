#ifndef DRAWS_H
#define DRAWS_H


extern void depthQPTable() ; // 0x800CE3AC

extern void depthQBlendStart() ; // 0x800CE3B0

extern void depthQFogStart() ; // 0x800CE3B4

extern void depthQFogFar() ; // 0x800CE3B8

extern void depthQBackColor() ; // 0x800CE3BC

extern void gameTimer() ; // 0x800CE3C0

extern void modelFadeValue() ; // 0x800CE3C4

extern void lowerSplitPush() ; // 0x800CE3C8

extern void overlayAddress() ; // 0x800CE3CC

extern void forceDrawInFront() ; // 0x800CE3D0

extern void ClearBss() ; // 0x80025104

extern void clearloop() ; // 0x80025114

extern void TimerTick() ; // 0x80025130

extern void CheckVolatile() ; // 0x80025168

extern void DRAW_AnimatedModel_S() ; // 0x80025174

extern void anim_loop_top() ; // 0x80025258

extern void anim_dont_flip_backface() ; // 0x800252C0

extern void sort_max_z2() ; // 0x80025338

extern void mm2L1() ; // 0x80025354

extern void mm2L2() ; // 0x80025364

extern void sort_avz_continue2() ; // 0x8002536C

extern void anim_no_pushsort() ; // 0x80025388

extern void not_colored_fog() ; // 0x800253B4

extern void anim_ft3() ; // 0x800253BC

extern void always_ft3() ; // 0x800253CC

extern void nofade_ft3_a() ; // 0x80025408

extern void nofade_ft3_b() ; // 0x80025440

extern void nofade_ft3_c() ; // 0x800254B8

extern void anim_gt3() ; // 0x800254E0

extern void nofade_gt3_a() ; // 0x80025550

extern void nofade_gt3_b2() ; // 0x800255C8

extern void nofade_gt3_b() ; // 0x800255E0

extern void anim_nontext() ; // 0x8002563C

extern void anim_g3() ; // 0x80025644

extern void anim_g3_from_t() ; // 0x8002567C

extern void anim_g3_overface() ; // 0x8002573C

extern void anim_f3() ; // 0x80025794

extern void anim_next_mface() ; // 0x800257E8

extern void exit_AnimDraw() ; // 0x80025800

extern void fogged_face() ; // 0x80025834

extern void always_fogged_ft3() ; // 0x8002585C

extern void fanim_gt3() ; // 0x800258E8

extern void fog_backface() ; // 0x8002598C

extern void fog_backface2() ; // 0x800259F4

extern void fanim_nontext() ; // 0x80025A74

extern void fanim_g3() ; // 0x80025A7C

extern void fanim_f3() ; // 0x80025B7C

extern void faded_backpoly() ; // 0x80025C28

extern void faded_t5_smaller() ; // 0x80025C94

extern void faded_t6_min() ; // 0x80025CA8

extern void faded_tpage_calc() ; // 0x80025CAC

extern void do_super_subdiv() ; // 0x80025D10

extern void super_clip() ; // 0x80025D7C

extern void DRAW_DisplayTFace_S() ; // 0x80025D84

extern void rLL2() ; // 0x80025F50

extern void rLL2A() ; // 0x80025F58

extern void subdiv_begin() ; // 0x80025F60

extern void not_liquid_26() ; // 0x80026044

extern void next_tface_subdiv() ; // 0x8002653C

extern void DRAW_DisplaySubdivPolytope_S() ; // 0x80026554

extern void do_poly() ; // 0x800266E8

extern void positive() ; // 0x80026918

extern void not_quad() ; // 0x800269D8

extern void no_subdiv() ; // 0x800269EC

extern void maxL1() ; // 0x80026A28

extern void maxL2() ; // 0x80026A3C

extern void minL1() ; // 0x80026A4C

extern void not_liquid_54() ; // 0x80026B84

extern void depthQface() ; // 0x80026BC8

extern void no_depthQ() ; // 0x80026D0C

extern void skip_tface() ; // 0x80026D24

extern void no_blend2() ; // 0x80026D3C

extern void end_of_polytope() ; // 0x80026D58

extern void draw_trans_fog() ; // 0x80026D88

extern void OK() ; // 0x80026DBC

extern void no_depthQ2() ; // 0x80026E74

extern void DRAW_DisplayPolytopeList_S() ; // 0x80026E8C

extern void PIPE3D_TransformAnimatedInstanceVertices_S() ; // 0x800270C8

extern void DRAW_MFace3_S() ; // 0x80027F00

extern void DRAW_MFace3_MAXZ0() ; // 0x80027F40

extern void DRAW_MFace3_MAXZ1() ; // 0x80027F5C

extern void DRAW_MFace3_MT() ; // 0x80027F6C

extern void DRAW_MFace3_OTZ() ; // 0x80027F88

extern void DRAW_MFace3_F3() ; // 0x80027FB4

extern void DRAW_MFace3_F3_NCDPQ() ; // 0x80027FD8

extern void DRAW_MFace3_F3_AddPrim() ; // 0x80028038

extern void DRAW_MFace3_FT3() ; // 0x80028074

extern void DRAW_MFace3_FT3_NCDPQ() ; // 0x800280AC

extern void DRAW_MFace3_FT3_AddPrim() ; // 0x8002812C

extern void DRAW_MFace3_Gouraud() ; // 0x80028180

extern void DRAW_MFace3_G3() ; // 0x8002822C

extern void DRAW_MFace3_GT3() ; // 0x800282B4

extern void DRAW_MFace3_GT_nofade() ; // 0x80028334

extern void DRAW_MFace3_Return() ; // 0x80028384

extern void DRAW_MFace3_FadeBackpoly() ; // 0x8002838C

extern void DMF_faded_t2_smaller() ; // 0x800283FC

extern void DMF_faded_t3_min() ; // 0x80028410

extern void DMF_faded_tpage_calc() ; // 0x80028414

extern void DRAW_MFace3_fog_g3() ; // 0x8002847C

extern void DRAW_MFace3_fog_ft3() ; // 0x80028558

extern void DRAW_MFace3_fog_gt3() ; // 0x800285F0

extern void DRAW_MFace3_fog_backface() ; // 0x80028680

extern void DRAW_SplitModel_S() ; // 0x800286F0

extern void DSM_noFade() ; // 0x80028784

extern void DSM_SetOutcode0() ; // 0x800287CC

extern void DSM_SetOutcode1() ; // 0x800287D8

extern void DSM_IncrementMFace() ; // 0x8002888C

extern void DSM_BeginLoop() ; // 0x80028890

extern void DSM_Outcode0() ; // 0x80028938

extern void DSM_Outcode7() ; // 0x80028948

extern void DSM_Outcode7_LDV3() ; // 0x8002894C

extern void DSM_Outcode7_MG() ; // 0x800289A0

extern void DSM_Outcode7_G() ; // 0x80028A58

extern void DSM_Outcode7_Flat() ; // 0x80028A6C

extern void DSM_Outcode7_Draw() ; // 0x80028A80

extern void DSM_Outcode1() ; // 0x80028A90

extern void DSM_Outcode1_MG() ; // 0x80028DDC

extern void DSM_Outcode1_G() ; // 0x80028E94

extern void DSM_Outcode1_Flat() ; // 0x80028EA8

extern void DSM_Outcode1_Draw() ; // 0x80028EC4

extern void DSM_Outcode2() ; // 0x80028F74

extern void DSM_Outcode2_MG() ; // 0x800292C8

extern void DSM_Outcode2_G() ; // 0x80029380

extern void DSM_Outcode2_Flat() ; // 0x80029394

extern void DSM_Outcode2_Draw() ; // 0x800293B0

extern void DSM_Outcode4() ; // 0x80029474

extern void DSM_Outcode4_MG() ; // 0x800297C8

extern void DSM_Outcode4_G() ; // 0x80029884

extern void DSM_Outcode4_Flat() ; // 0x80029898

extern void DSM_Outcode4_Draw() ; // 0x800298B4

extern void DSM_Outcode3() ; // 0x80029974

extern void DSM_Outcode3_MG() ; // 0x80029CB8

extern void DSM_Outcode3_G() ; // 0x80029D70

extern void DSM_Outcode3_Flat() ; // 0x80029D84

extern void DSM_Outcode3_Draw() ; // 0x80029DA0

extern void DSM_Outcode5() ; // 0x80029E50

extern void DSM_Outcode5_MG() ; // 0x8002A1A4

extern void DSM_Outcode5_G() ; // 0x8002A260

extern void DSM_Outcode5_Flat() ; // 0x8002A274

extern void DSM_Outcode5_Draw() ; // 0x8002A290

extern void DSM_Outcode6() ; // 0x8002A348

extern void DSM_Outcode6_MG() ; // 0x8002A69C

extern void DSM_Outcode6_G() ; // 0x8002A754

extern void DSM_Outcode6_Flat() ; // 0x8002A768

extern void DSM_Outcode6_Draw() ; // 0x8002A784

extern void DSM_CleanUp() ; // 0x8002A83C


#endif
