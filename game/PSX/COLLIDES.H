#ifndef COLLIDES_H
#define COLLIDES_H


extern void COLLIDE_NearestPointOnLine_S() ; // 0x80077960

extern void COLLIDE_IntersectLineAndPlane_S() ; // 0x80077A70

extern void COLLIDE_NearestPointOnPlane_S() ; // 0x80077B48

extern void VM_ProcessVMObjectSetColor_S() ; // 0x800780CC

extern void VM_ProcessVMObjectList_S() ; // 0x80078140

extern void BSP_SphereIntersectsViewVolume_S() ; // 0x80078204

extern void RotMatrixZYX() ; // 0x800782DC

extern void rmzyx_onlyz() ; // 0x80078420

extern void RotMatrix() ; // 0x80078450

extern void ApplyMatrix_S() ; // 0x80078598

extern void ScaleMatrix() ; // 0x800785E8

extern void rsin() ; // 0x800786D0

extern void rcos() ; // 0x800786F0

extern void MATH3D_racos_S() ; // 0x80078710

extern void SetGp() ; // 0x80078770

extern void memcpy() ; // 0x80078778

extern void BSP_MarkVisibleLeaves_S() ; // 0x80078830

extern void G2Quat_FromMatrix_S() ; // 0x80078E00

extern void G2Quat_ToMatrix_S() ; // 0x8007900C

extern void G2Quat_FromEuler_S() ; // 0x800790FC


#endif
