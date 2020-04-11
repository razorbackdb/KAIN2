#ifndef DRAWS_H
#define DRAWS_H


extern void depthQPTable() ; // 0x800CF350

extern void depthQBlendStart() ; // 0x800CF354

extern void depthQFogStart() ; // 0x800CF358

extern void depthQFogFar() ; // 0x800CF35C

extern void depthQBackColor() ; // 0x800CF360

extern void gameTimer() ; // 0x800CF364

extern void modelFadeValue() ; // 0x800CF368

extern void lowerSplitPush() ; // 0x800CF36C

extern void overlayAddress() ; // 0x800CF370

extern void forceDrawInFront() ; // 0x800CF374

extern void ClearBss() ; // 0x80024D14

extern void clearloop() ; // 0x80024D24

extern void TimerTick() ; // 0x80024D40

extern void CheckVolatile() ; // 0x80024D78

extern void DRAW_AnimatedModel_S() ; // 0x80024D84

extern void anim_loop_top() ; // 0x80024E68

extern void anim_dont_flip_backface() ; // 0x80024ED0

extern void sort_max_z2() ; // 0x80024F48

extern void mm2L1() ; // 0x80024F64

extern void mm2L2() ; // 0x80024F74

extern void sort_avz_continue2() ; // 0x80024F7C

extern void anim_no_pushsort() ; // 0x80024F98

extern void not_colored_fog() ; // 0x80024FC4

extern void anim_ft3() ; // 0x80024FCC

extern void always_ft3() ; // 0x80024FDC

extern void nofade_ft3_a() ; // 0x80025018

extern void nofade_ft3_b() ; // 0x80025050

extern void nofade_ft3_c() ; // 0x800250C8

extern void anim_gt3() ; // 0x800250F0

extern void nofade_gt3_a() ; // 0x80025160

extern void nofade_gt3_b2() ; // 0x800251D8

extern void nofade_gt3_b() ; // 0x800251F0

extern void anim_nontext() ; // 0x8002524C

extern void anim_g3() ; // 0x80025254

extern void anim_g3_from_t() ; // 0x8002528C

extern void anim_g3_overface() ; // 0x8002534C

extern void anim_f3() ; // 0x800253A4

extern void anim_next_mface() ; // 0x800253F8

extern void exit_AnimDraw() ; // 0x80025410

extern void fogged_face() ; // 0x80025444

extern void always_fogged_ft3() ; // 0x8002546C

extern void fanim_gt3() ; // 0x800254F8

extern void fog_backface() ; // 0x8002559C

extern void fog_backface2() ; // 0x80025604

extern void fanim_nontext() ; // 0x80025684

extern void fanim_g3() ; // 0x8002568C

extern void fanim_f3() ; // 0x8002578C

extern void faded_backpoly() ; // 0x80025838

extern void faded_t5_smaller() ; // 0x800258A4

extern void faded_t6_min() ; // 0x800258B8

extern void faded_tpage_calc() ; // 0x800258BC

extern void do_super_subdiv() ; // 0x80025920

extern void super_clip() ; // 0x8002598C

extern void DRAW_DisplayTFace_S() ; // 0x80025994

extern void rLL2() ; // 0x80025B60

extern void rLL2A() ; // 0x80025B68

extern void subdiv_begin() ; // 0x80025B70

extern void not_liquid_26() ; // 0x80025C54

extern void next_tface_subdiv() ; // 0x8002614C

extern void DRAW_DisplaySubdivPolytope_S() ; // 0x80026164

extern void do_poly() ; // 0x800262F8

extern void positive() ; // 0x80026528

extern void not_quad() ; // 0x800265E8

extern void no_subdiv() ; // 0x800265FC

extern void maxL1() ; // 0x80026638

extern void maxL2() ; // 0x8002664C

extern void minL1() ; // 0x8002665C

extern void not_liquid_54() ; // 0x80026794

extern void depthQface() ; // 0x800267D8

extern void no_depthQ() ; // 0x8002691C

extern void skip_tface() ; // 0x80026934

extern void no_blend2() ; // 0x8002694C

extern void end_of_polytope() ; // 0x80026968

extern void draw_trans_fog() ; // 0x80026998

extern void OK() ; // 0x800269CC

extern void no_depthQ2() ; // 0x80026A84

extern void DRAW_DisplayPolytopeList_S() ; // 0x80026A9C

extern void PIPE3D_TransformAnimatedInstanceVertices_S() ; // 0x80026CD8

extern void DRAW_MFace3_S() ; // 0x80027B10

extern void DRAW_MFace3_MAXZ0() ; // 0x80027B50

extern void DRAW_MFace3_MAXZ1() ; // 0x80027B6C

extern void DRAW_MFace3_MT() ; // 0x80027B7C

extern void DRAW_MFace3_OTZ() ; // 0x80027B98

extern void DRAW_MFace3_F3() ; // 0x80027BC4

extern void DRAW_MFace3_F3_NCDPQ() ; // 0x80027BE8

extern void DRAW_MFace3_F3_AddPrim() ; // 0x80027C48

extern void DRAW_MFace3_FT3() ; // 0x80027C84

extern void DRAW_MFace3_FT3_NCDPQ() ; // 0x80027CBC

extern void DRAW_MFace3_FT3_AddPrim() ; // 0x80027D3C

extern void DRAW_MFace3_Gouraud() ; // 0x80027D90

extern void DRAW_MFace3_G3() ; // 0x80027E3C

extern void DRAW_MFace3_GT3() ; // 0x80027EC4

extern void DRAW_MFace3_GT_nofade() ; // 0x80027F44

extern void DRAW_MFace3_Return() ; // 0x80027F94

extern void DRAW_MFace3_FadeBackpoly() ; // 0x80027F9C

extern void DMF_faded_t2_smaller() ; // 0x8002800C

extern void DMF_faded_t3_min() ; // 0x80028020

extern void DMF_faded_tpage_calc() ; // 0x80028024

extern void DRAW_MFace3_fog_g3() ; // 0x8002808C

extern void DRAW_MFace3_fog_ft3() ; // 0x8002815C

extern void DRAW_MFace3_fog_gt3() ; // 0x800281F4

extern void DRAW_MFace3_fog_backface() ; // 0x80028284

extern void DRAW_SplitModel_S() ; // 0x800282F4

extern void DSM_noFade() ; // 0x80028388

extern void DSM_SetOutcode0() ; // 0x800283D0

extern void DSM_SetOutcode1() ; // 0x800283DC

extern void DSM_IncrementMFace() ; // 0x80028490

extern void DSM_BeginLoop() ; // 0x80028494

extern void DSM_Outcode0() ; // 0x8002853C

extern void DSM_Outcode7() ; // 0x8002854C

extern void DSM_Outcode7_LDV3() ; // 0x80028550

extern void DSM_Outcode7_MG() ; // 0x800285A4

extern void DSM_Outcode7_G() ; // 0x8002865C

extern void DSM_Outcode7_Flat() ; // 0x80028670

extern void DSM_Outcode7_Draw() ; // 0x80028684

extern void DSM_Outcode1() ; // 0x80028694

extern void DSM_Outcode1_MG() ; // 0x800289E0

extern void DSM_Outcode1_G() ; // 0x80028A98

extern void DSM_Outcode1_Flat() ; // 0x80028AAC

extern void DSM_Outcode1_Draw() ; // 0x80028AC8

extern void DSM_Outcode2() ; // 0x80028B78

extern void DSM_Outcode2_MG() ; // 0x80028ECC

extern void DSM_Outcode2_G() ; // 0x80028F84

extern void DSM_Outcode2_Flat() ; // 0x80028F98

extern void DSM_Outcode2_Draw() ; // 0x80028FB4

extern void DSM_Outcode4() ; // 0x80029078

extern void DSM_Outcode4_MG() ; // 0x800293CC

extern void DSM_Outcode4_G() ; // 0x80029488

extern void DSM_Outcode4_Flat() ; // 0x8002949C

extern void DSM_Outcode4_Draw() ; // 0x800294B8

extern void DSM_Outcode3() ; // 0x80029578

extern void DSM_Outcode3_MG() ; // 0x800298BC

extern void DSM_Outcode3_G() ; // 0x80029974

extern void DSM_Outcode3_Flat() ; // 0x80029988

extern void DSM_Outcode3_Draw() ; // 0x800299A4

extern void DSM_Outcode5() ; // 0x80029A54

extern void DSM_Outcode5_MG() ; // 0x80029DA8

extern void DSM_Outcode5_G() ; // 0x80029E64

extern void DSM_Outcode5_Flat() ; // 0x80029E78

extern void DSM_Outcode5_Draw() ; // 0x80029E94

extern void DSM_Outcode6() ; // 0x80029F4C

extern void DSM_Outcode6_MG() ; // 0x8002A2A0

extern void DSM_Outcode6_G() ; // 0x8002A358

extern void DSM_Outcode6_Flat() ; // 0x8002A36C

extern void DSM_Outcode6_Draw() ; // 0x8002A388

extern void DSM_CleanUp() ; // 0x8002A440


#endif
