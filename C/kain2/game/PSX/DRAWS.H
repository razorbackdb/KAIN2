#ifndef DRAWS_H
#define DRAWS_H


extern void depthQPTable() ; // 0x800D05DC

extern void depthQBlendStart() ; // 0x800D05E0

extern void depthQFogStart() ; // 0x800D05E4

extern void depthQFogFar() ; // 0x800D05E8

extern void depthQBackColor() ; // 0x800D05EC

extern void gameTimer() ; // 0x800D05F0

extern void modelFadeValue() ; // 0x800D05F4

extern void lowerSplitPush() ; // 0x800D05F8

extern void overlayAddress() ; // 0x800D05FC

extern void forceDrawInFront() ; // 0x800D0600

extern void ClearBss() ; // 0x800251AC

extern void clearloop() ; // 0x800251BC

extern void TimerTick() ; // 0x800251D8

extern void CheckVolatile() ; // 0x80025210

extern void DRAW_AnimatedModel_S() ; // 0x8002521C

extern void anim_loop_top() ; // 0x80025300

extern void anim_dont_flip_backface() ; // 0x80025368

extern void sort_max_z2() ; // 0x800253E0

extern void mm2L1() ; // 0x800253FC

extern void mm2L2() ; // 0x8002540C

extern void sort_avz_continue2() ; // 0x80025414

extern void anim_no_pushsort() ; // 0x80025430

extern void not_colored_fog() ; // 0x8002545C

extern void anim_ft3() ; // 0x80025464

extern void always_ft3() ; // 0x80025474

extern void nofade_ft3_a() ; // 0x800254B0

extern void nofade_ft3_b() ; // 0x800254E8

extern void nofade_ft3_c() ; // 0x80025560

extern void anim_gt3() ; // 0x80025588

extern void nofade_gt3_a() ; // 0x800255F8

extern void nofade_gt3_b2() ; // 0x80025670

extern void nofade_gt3_b() ; // 0x80025688

extern void anim_nontext() ; // 0x800256E4

extern void anim_g3() ; // 0x800256EC

extern void anim_g3_from_t() ; // 0x80025724

extern void anim_g3_overface() ; // 0x800257E4

extern void anim_f3() ; // 0x8002583C

extern void anim_next_mface() ; // 0x80025890

extern void exit_AnimDraw() ; // 0x800258A8

extern void fogged_face() ; // 0x800258DC

extern void always_fogged_ft3() ; // 0x80025904

extern void fanim_gt3() ; // 0x80025990

extern void fog_backface() ; // 0x80025A34

extern void fog_backface2() ; // 0x80025A9C

extern void fanim_nontext() ; // 0x80025B1C

extern void fanim_g3() ; // 0x80025B24

extern void fanim_f3() ; // 0x80025C24

extern void faded_backpoly() ; // 0x80025CD0

extern void faded_t5_smaller() ; // 0x80025D3C

extern void faded_t6_min() ; // 0x80025D50

extern void faded_tpage_calc() ; // 0x80025D54

extern void do_super_subdiv() ; // 0x80025DB8

extern void super_clip() ; // 0x80025E24

extern void DRAW_DisplayTFace_S() ; // 0x80025E2C

extern void rLL2() ; // 0x80025FF8

extern void rLL2A() ; // 0x80026000

extern void subdiv_begin() ; // 0x80026008

extern void not_liquid_26() ; // 0x800260EC

extern void next_tface_subdiv() ; // 0x800265E4

extern void DRAW_DisplaySubdivPolytope_S() ; // 0x800265FC

extern void do_poly() ; // 0x80026790

extern void positive() ; // 0x800269C0

extern void not_quad() ; // 0x80026A80

extern void no_subdiv() ; // 0x80026A94

extern void maxL1() ; // 0x80026AD0

extern void maxL2() ; // 0x80026AE4

extern void minL1() ; // 0x80026AF4

extern void not_liquid_54() ; // 0x80026C2C

extern void depthQface() ; // 0x80026C70

extern void no_depthQ() ; // 0x80026DB4

extern void skip_tface() ; // 0x80026DCC

extern void no_blend2() ; // 0x80026DE4

extern void end_of_polytope() ; // 0x80026E00

extern void draw_trans_fog() ; // 0x80026E30

extern void OK() ; // 0x80026E64

extern void no_depthQ2() ; // 0x80026F1C

extern void DRAW_DisplayPolytopeList_S() ; // 0x80026F34

extern void PIPE3D_TransformAnimatedInstanceVertices_S() ; // 0x80027170

extern void DRAW_MFace3_S() ; // 0x80027FA8

extern void DRAW_MFace3_MAXZ0() ; // 0x80027FE8

extern void DRAW_MFace3_MAXZ1() ; // 0x80028004

extern void DRAW_MFace3_MT() ; // 0x80028014

extern void DRAW_MFace3_OTZ() ; // 0x80028030

extern void DRAW_MFace3_F3() ; // 0x8002805C

extern void DRAW_MFace3_F3_NCDPQ() ; // 0x80028080

extern void DRAW_MFace3_F3_AddPrim() ; // 0x800280E0

extern void DRAW_MFace3_FT3() ; // 0x8002811C

extern void DRAW_MFace3_FT3_NCDPQ() ; // 0x80028154

extern void DRAW_MFace3_FT3_AddPrim() ; // 0x800281D4

extern void DRAW_MFace3_Gouraud() ; // 0x80028228

extern void DRAW_MFace3_G3() ; // 0x800282D4

extern void DRAW_MFace3_GT3() ; // 0x8002835C

extern void DRAW_MFace3_GT_nofade() ; // 0x800283DC

extern void DRAW_MFace3_Return() ; // 0x8002842C

extern void DRAW_MFace3_FadeBackpoly() ; // 0x80028434

extern void DMF_faded_t2_smaller() ; // 0x800284A4

extern void DMF_faded_t3_min() ; // 0x800284B8

extern void DMF_faded_tpage_calc() ; // 0x800284BC

extern void DRAW_MFace3_fog_g3() ; // 0x80028524

extern void DRAW_MFace3_fog_ft3() ; // 0x800285F4

extern void DRAW_MFace3_fog_gt3() ; // 0x8002868C

extern void DRAW_MFace3_fog_backface() ; // 0x8002871C

extern void DRAW_SplitModel_S() ; // 0x8002878C

extern void DSM_noFade() ; // 0x80028820

extern void DSM_SetOutcode0() ; // 0x80028868

extern void DSM_SetOutcode1() ; // 0x80028874

extern void DSM_IncrementMFace() ; // 0x80028928

extern void DSM_BeginLoop() ; // 0x8002892C

extern void DSM_Outcode0() ; // 0x800289D4

extern void DSM_Outcode7() ; // 0x800289E4

extern void DSM_Outcode7_LDV3() ; // 0x800289E8

extern void DSM_Outcode7_MG() ; // 0x80028A3C

extern void DSM_Outcode7_G() ; // 0x80028AF4

extern void DSM_Outcode7_Flat() ; // 0x80028B08

extern void DSM_Outcode7_Draw() ; // 0x80028B1C

extern void DSM_Outcode1() ; // 0x80028B2C

extern void DSM_Outcode1_MG() ; // 0x80028E78

extern void DSM_Outcode1_G() ; // 0x80028F30

extern void DSM_Outcode1_Flat() ; // 0x80028F44

extern void DSM_Outcode1_Draw() ; // 0x80028F60

extern void DSM_Outcode2() ; // 0x80029010

extern void DSM_Outcode2_MG() ; // 0x80029364

extern void DSM_Outcode2_G() ; // 0x8002941C

extern void DSM_Outcode2_Flat() ; // 0x80029430

extern void DSM_Outcode2_Draw() ; // 0x8002944C

extern void DSM_Outcode4() ; // 0x80029510

extern void DSM_Outcode4_MG() ; // 0x80029864

extern void DSM_Outcode4_G() ; // 0x80029920

extern void DSM_Outcode4_Flat() ; // 0x80029934

extern void DSM_Outcode4_Draw() ; // 0x80029950

extern void DSM_Outcode3() ; // 0x80029A10

extern void DSM_Outcode3_MG() ; // 0x80029D54

extern void DSM_Outcode3_G() ; // 0x80029E0C

extern void DSM_Outcode3_Flat() ; // 0x80029E20

extern void DSM_Outcode3_Draw() ; // 0x80029E3C

extern void DSM_Outcode5() ; // 0x80029EEC

extern void DSM_Outcode5_MG() ; // 0x8002A240

extern void DSM_Outcode5_G() ; // 0x8002A2FC

extern void DSM_Outcode5_Flat() ; // 0x8002A310

extern void DSM_Outcode5_Draw() ; // 0x8002A32C

extern void DSM_Outcode6() ; // 0x8002A3E4

extern void DSM_Outcode6_MG() ; // 0x8002A738

extern void DSM_Outcode6_G() ; // 0x8002A7F0

extern void DSM_Outcode6_Flat() ; // 0x8002A804

extern void DSM_Outcode6_Draw() ; // 0x8002A820

extern void DSM_CleanUp() ; // 0x8002A8D8


#endif
