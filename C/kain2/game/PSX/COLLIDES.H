#ifndef COLLIDES_H
#define COLLIDES_H


extern void COLLIDE_NearestPointOnLine_S() ; // 0x800781E4

extern void COLLIDE_IntersectLineAndPlane_S() ; // 0x800782F4

extern void COLLIDE_NearestPointOnPlane_S() ; // 0x800783CC

extern void VM_ProcessVMObjectSetColor_S() ; // 0x80078950

extern void VM_ProcessVMObjectList_S() ; // 0x800789C4

extern void BSP_SphereIntersectsViewVolume_S() ; // 0x80078A88

extern void RotMatrixZYX() ; // 0x80078B60

extern void rmzyx_1() ; // 0x80078B9C

extern void rmzyx_2() ; // 0x80078BD0

extern void rmzyx_3() ; // 0x80078BF8

extern void rmzyx_onlyz() ; // 0x80078CC8

extern void RotMatrix() ; // 0x80078CF4

extern void rm_1() ; // 0x80078D30

extern void rm_2() ; // 0x80078D64

extern void rm_3() ; // 0x80078D8C

extern void RotMatrixX() ; // 0x80078E60

extern void RMX_0() ; // 0x80078E90

extern void RotMatrixY() ; // 0x80078F94

extern void RMY_0() ; // 0x80078FC4

extern void RotMatrixZ() ; // 0x800790C8

extern void RMZ_0() ; // 0x800790F8

extern void ApplyMatrix_S() ; // 0x80079208

extern void ScaleMatrix() ; // 0x80079258

extern void rsin() ; // 0x80079340

extern void rsin_exit() ; // 0x80079368

extern void rcos() ; // 0x80079370

extern void rcos_exit() ; // 0x80079398

extern void MATH3D_racos_S() ; // 0x800793A0

extern void SetGp() ; // 0x80079400

extern void memcpy() ; // 0x80079408

extern void BSP_MarkVisibleLeaves_S() ; // 0x800794C0

extern void G2Quat_FromMatrix_S() ; // 0x80079A90

extern void G2Quat_ToMatrix_S() ; // 0x80079C9C

extern void G2Quat_FromEuler_S() ; // 0x80079D8C

extern void eul_1() ; // 0x80079DF8

extern void eul_2() ; // 0x80079E20

extern void eul_3() ; // 0x80079E48


#endif
