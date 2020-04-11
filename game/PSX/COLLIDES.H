#ifndef COLLIDES_H
#define COLLIDES_H


extern void COLLIDE_NearestPointOnLine_S() ; // 0x80077924

extern void COLLIDE_IntersectLineAndPlane_S() ; // 0x80077A34

extern void COLLIDE_NearestPointOnPlane_S() ; // 0x80077B0C

extern void VM_ProcessVMObjectSetColor_S() ; // 0x80078090

extern void VM_ProcessVMObjectList_S() ; // 0x80078104

extern void BSP_SphereIntersectsViewVolume_S() ; // 0x800781C8

extern void RotMatrixZYX() ; // 0x800782A0

extern void rmzyx_1() ; // 0x800782DC

extern void rmzyx_2() ; // 0x80078310

extern void rmzyx_3() ; // 0x80078338

extern void rmzyx_onlyz() ; // 0x80078408

extern void RotMatrix() ; // 0x80078434

extern void rm_1() ; // 0x80078470

extern void rm_2() ; // 0x800784A4

extern void rm_3() ; // 0x800784CC

extern void RotMatrixX() ; // 0x800785A0

extern void RMX_0() ; // 0x800785D0

extern void RotMatrixY() ; // 0x800786D4

extern void RMY_0() ; // 0x80078704

extern void RotMatrixZ() ; // 0x80078808

extern void RMZ_0() ; // 0x80078838

extern void ApplyMatrix_S() ; // 0x80078948

extern void ScaleMatrix() ; // 0x80078998

extern void rsin() ; // 0x80078A80

extern void rsin_exit() ; // 0x80078AA8

extern void rcos() ; // 0x80078AB0

extern void rcos_exit() ; // 0x80078AD8

extern void MATH3D_racos_S() ; // 0x80078AE0

extern void SetGp() ; // 0x80078B40

extern void memcpy() ; // 0x80078B48

extern void BSP_MarkVisibleLeaves_S() ; // 0x80078C00

extern void G2Quat_FromMatrix_S() ; // 0x800791D0

extern void G2Quat_ToMatrix_S() ; // 0x800793DC

extern void G2Quat_FromEuler_S() ; // 0x800794CC

extern void eul_1() ; // 0x80079538

extern void eul_2() ; // 0x80079560

extern void eul_3() ; // 0x80079588


#endif
