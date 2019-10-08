#ifndef DRAWS_H
#define DRAWS_H

extern void depthQPTable();

extern void depthQBlendStart();

extern void depthQFogStart();

extern void depthQFogFar();

extern void depthQBackColor();

extern void gameTimer();

extern void modelFadeValue();

extern void lowerSplitPush();

extern void overlayAddress();

extern void forceDrawInFront();

extern void ClearBss();

extern void clearloop();

extern void TimerTick();

extern void CheckVolatile();

extern void DRAW_AnimatedModel_S();

extern void anim_loop_top();

extern void anim_dont_flip_backface();

extern void sort_max_z2();

extern void mm2L1();

extern void mm2L2();

extern void sort_avz_continue2();

extern void anim_no_pushsort();

extern void not_colored_fog();

extern void anim_ft3();

extern void always_ft3();

extern void nofade_ft3_a();

extern void nofade_ft3_b();

extern void nofade_ft3_c();

extern void anim_gt3();

extern void nofade_gt3_a();

extern void nofade_gt3_b2();

extern void nofade_gt3_b();

extern void anim_nontext();

extern void anim_g3();

extern void anim_g3_from_t();

extern void anim_g3_overface();

extern void anim_f3();

extern void anim_next_mface();

extern void exit_AnimDraw();

extern void fogged_face();

extern void always_fogged_ft3();

extern void fanim_gt3();

extern void fog_backface();

extern void fog_backface2();

extern void fanim_nontext();

extern void fanim_g3();

extern void fanim_f3();

extern void faded_backpoly();

extern void faded_t5_smaller();

extern void faded_t6_min();

extern void faded_tpage_calc();

extern void do_super_subdiv();

extern void super_clip();

extern void DRAW_DisplayTFace_S();

extern void rLL2();

extern void rLL2A();

extern void subdiv_begin();

extern void not_liquid_26();

extern void next_tface_subdiv();

extern void DRAW_DisplaySubdivPolytope_S();

extern void do_poly();

extern void positive();

extern void not_quad();

extern void no_subdiv();

extern void maxL1();

extern void maxL2();

extern void minL1();

extern void not_liquid_54();

extern void depthQface();

extern void no_depthQ();

extern void skip_tface();

extern void no_blend2();

extern void end_of_polytope();

extern void draw_trans_fog();

extern void OK();

extern void no_depthQ2();

extern void DRAW_DisplayPolytopeList_S();

extern void PIPE3D_TransformAnimatedInstanceVertices_S();

extern void DRAW_MFace3_S();

extern void DRAW_MFace3_MAXZ0();

extern void DRAW_MFace3_MAXZ1();

extern void DRAW_MFace3_MT();

extern void DRAW_MFace3_OTZ();

extern void DRAW_MFace3_F3();

extern void DRAW_MFace3_F3_NCDPQ();

extern void DRAW_MFace3_F3_AddPrim();

extern void DRAW_MFace3_FT3();

extern void DRAW_MFace3_FT3_NCDPQ();

extern void DRAW_MFace3_FT3_AddPrim();

extern void DRAW_MFace3_Gouraud();

extern void DRAW_MFace3_G3();

extern void DRAW_MFace3_GT3();

extern void DRAW_MFace3_GT_nofade();

extern void DRAW_MFace3_Return();

extern void DRAW_MFace3_FadeBackpoly();

extern void DMF_faded_t2_smaller();

extern void DMF_faded_t3_min();

extern void DMF_faded_tpage_calc();

extern void DRAW_MFace3_fog_g3();

extern void DRAW_MFace3_fog_ft3();

extern void DRAW_MFace3_fog_gt3();

extern void DRAW_MFace3_fog_backface();

extern void DRAW_SplitModel_S();

extern void DSM_noFade();

extern void DSM_SetOutcode0();

extern void DSM_SetOutcode1();

extern void DSM_IncrementMFace();

extern void DSM_BeginLoop();

extern void DSM_Outcode0();

extern void DSM_Outcode7();

extern void DSM_Outcode7_LDV3();

extern void DSM_Outcode7_MG();

extern void DSM_Outcode7_G();

extern void DSM_Outcode7_Flat();

extern void DSM_Outcode7_Draw();

extern void DSM_Outcode1();

extern void DSM_Outcode1_MG();

extern void DSM_Outcode1_G();

extern void DSM_Outcode1_Flat();

extern void DSM_Outcode1_Draw();

extern void DSM_Outcode2();

extern void DSM_Outcode2_MG();

extern void DSM_Outcode2_G();

extern void DSM_Outcode2_Flat();

extern void DSM_Outcode2_Draw();

extern void DSM_Outcode4();

extern void DSM_Outcode4_MG();

extern void DSM_Outcode4_G();

extern void DSM_Outcode4_Flat();

extern void DSM_Outcode4_Draw();

extern void DSM_Outcode3();

extern void DSM_Outcode3_MG();

extern void DSM_Outcode3_G();

extern void DSM_Outcode3_Flat();

extern void DSM_Outcode3_Draw();

extern void DSM_Outcode5();

extern void DSM_Outcode5_MG();

extern void DSM_Outcode5_G();

extern void DSM_Outcode5_Flat();

extern void DSM_Outcode5_Draw();

extern void DSM_Outcode6();

extern void DSM_Outcode6_MG();

extern void DSM_Outcode6_G();

extern void DSM_Outcode6_Flat();

extern void DSM_Outcode6_Draw();

extern void DSM_CleanUp();

#endif
