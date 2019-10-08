#ifndef COLLIDES_H
#define COLLIDES_H

extern void COLLIDE_NearestPointOnLine_S();

extern void COLLIDE_IntersectLineAndPlane_S();

extern void COLLIDE_NearestPointOnPlane_S();

extern void VM_ProcessVMObjectSetColor_S();

extern void VM_ProcessVMObjectList_S();

extern void BSP_SphereIntersectsViewVolume_S();

extern void RotMatrixZYX();

extern void rmzyx_1();

extern void rmzyx_2();

extern void rmzyx_3();

extern void rmzyx_onlyz();

extern void RotMatrix();

extern void rm_1();

extern void rm_2();

extern void rm_3();

extern void RotMatrixX();

extern void RMX_0();

extern void RotMatrixY();

extern void RMY_0();

extern void RotMatrixZ();

extern void RMZ_0();

extern void ApplyMatrix_S();

extern void ScaleMatrix();

extern void rsin();

extern void rsin_exit();

extern void rcos();

extern void rcos_exit();

extern void MATH3D_racos_S();

extern void SetGp();

extern void memcpy();

extern void BSP_MarkVisibleLeaves_S();

extern void G2Quat_FromMatrix_S();

extern void G2Quat_ToMatrix_S();

extern void G2Quat_FromEuler_S();

extern void eul_1();

extern void eul_2();

extern void eul_3();

#endif
