#ifndef ANMCTRLR_H
#define ANMCTRLR_H


extern void G2Anim_AttachControllerToSeg(struct _G2Anim_Type *anim, int segNumber, int type); // 0x8008FCCC

extern void G2Anim_DetachControllerFromSeg(struct _G2Anim_Type *anim, int segNumber, int type); // 0x8008FD04

extern void G2Anim_EnableController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x8008FDCC

extern void G2Anim_DisableController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x8008FEA8

extern void G2Anim_InterpDisableController(struct _G2Anim_Type *anim, int segNumber, int type, short duration); // 0x8008FEE8

extern enum _G2Bool_Enum G2Anim_IsControllerActive(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80090008

extern enum _G2Bool_Enum G2Anim_IsControllerInterpolating(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80090054

extern void G2Anim_GetControllerCurrentInterpVector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector); // 0x800900A8

extern void G2Anim_SetControllerCallbackData(struct _G2Anim_Type *anim, int segNumber, int type, void *callbackData); // 0x80090208

extern void G2Anim_SetControllerAngleOrder(struct _G2Anim_Type *anim, int segNumber, int type, int order); // 0x80090230

extern void G2Anim_SetController_Vector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector); // 0x80090268

extern void G2Anim_SetInterpController_Vector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector, int duration); // 0x800902B0

extern void G2Anim_SetInterpController_Quat(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2Quat_Type *quat, int duration); // 0x80090414

extern void _G2Anim_ApplyControllersToStoredFrame(struct _G2Anim_Type *anim); // 0x80090490

extern void _G2Anim_BuildTransformsWithControllers(struct _G2Anim_Type *anim); // 0x800904F0

extern void _G2Anim_BuildSegTransformWithControllers(struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix, struct _G2AnimController_Type *controller, enum _G2Bool_Enum bRootTransUpdated, int segIndex); // 0x800906D0

extern unsigned long _G2AnimController_ApplyToSegValue(struct _G2AnimController_Type *controller, struct _G2AnimSegValue_Type *segValue, struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix); // 0x800909E0

extern void _G2Anim_UpdateControllers(struct _G2Anim_Type *anim); // 0x80090D88

extern void _G2Anim_CopyVectorWithOrder(struct _G2SVector3_Type *sourceVector, struct _G2EulerAngles_Type *destVector, int order); // 0x80090F14

extern void _G2AnimSection_ApplyControllersToStoredFrame(struct _G2AnimSection_Type *section); // 0x80090F78

extern unsigned long _G2AnimController_ApplyWorldToParentMatrix(struct _G2AnimController_Type *controller, struct _G2Matrix_Type *parentMatrix); // 0x800911F0

extern void _G2AnimController_GetMatrix(struct _G2AnimController_Type *controller, struct _G2Matrix_Type *matrix); // 0x80091344

extern void _G2AnimController_GetVector(struct _G2AnimController_Type *controller, struct _G2SVector3_Type *vector); // 0x8009141C

extern struct _G2AnimController_Type * _G2Anim_FindController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x800914A4

extern struct _G2AnimController_Type * _G2AnimController_Create(int segNumber, int type); // 0x80091500

extern struct _G2AnimController_Type * _G2AnimController_Destroy(struct _G2AnimController_Type *controller); // 0x8009156C

extern void _G2AnimController_InsertIntoList(struct _G2AnimController_Type *controller, unsigned short *listPtr); // 0x800915D4

extern void _G2AnimController_GetCurrentInterpQuat(struct _G2AnimController_Type *controller, struct _G2Anim_Type *anim, struct _G2Quat_Type *quat); // 0x80091704

extern void _G2AnimController_GetSimpleWorldRotQuat(struct _G2AnimController_Type *controller, struct _G2Anim_Type *anim, struct _G2Quat_Type *quat); // 0x80091840

extern struct _G2AnimController_Type * _G2AnimControllerST_FindInList(int segNumber, int type, unsigned short *listPtr); // 0x800918C4

extern struct _G2AnimController_Type * _G2AnimControllerST_FindPtrInList(int segNumber, int type, unsigned short **listPtrPtr); // 0x80091934

extern struct _G2AnimController_Type * _G2AnimControllerST_RemoveFromList(int segNumber, int type, unsigned short *listPtr); // 0x800919D4


#endif
