#ifndef ANMCTRLR_H
#define ANMCTRLR_H


extern void G2Anim_AttachControllerToSeg(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80090458

extern void G2Anim_DetachControllerFromSeg(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80090490

extern void G2Anim_EnableController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80090558

extern void G2Anim_DisableController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80090634

extern void G2Anim_InterpDisableController(struct _G2Anim_Type *anim, int segNumber, int type, short duration); // 0x80090674

extern enum _G2Bool_Enum G2Anim_IsControllerActive(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80090794

extern enum _G2Bool_Enum G2Anim_IsControllerInterpolating(struct _G2Anim_Type *anim, int segNumber, int type); // 0x800907E0

extern void G2Anim_GetControllerCurrentInterpVector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector); // 0x80090834

extern void G2Anim_SetControllerCallbackData(struct _G2Anim_Type *anim, int segNumber, int type, void *callbackData); // 0x80090994

extern void G2Anim_SetControllerAngleOrder(struct _G2Anim_Type *anim, int segNumber, int type, int order); // 0x800909BC

extern void G2Anim_SetController_Vector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector); // 0x800909F4

extern void G2Anim_SetInterpController_Vector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector, int duration); // 0x80090A3C

extern void G2Anim_SetInterpController_Quat(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2Quat_Type *quat, int duration); // 0x80090BA0

extern void _G2Anim_ApplyControllersToStoredFrame(struct _G2Anim_Type *anim); // 0x80090C1C

extern void _G2Anim_BuildTransformsWithControllers(struct _G2Anim_Type *anim); // 0x80090C7C

extern void _G2Anim_BuildSegTransformWithControllers(struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix, struct _G2AnimController_Type *controller, enum _G2Bool_Enum bRootTransUpdated, int segIndex); // 0x80090E5C

extern unsigned long _G2AnimController_ApplyToSegValue(struct _G2AnimController_Type *controller, struct _G2AnimSegValue_Type *segValue, struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix); // 0x80091168

extern void _G2Anim_UpdateControllers(struct _G2Anim_Type *anim); // 0x80091510

extern void _G2Anim_CopyVectorWithOrder(struct _G2SVector3_Type *sourceVector, struct _G2EulerAngles_Type *destVector, int order); // 0x8009169C

extern void _G2AnimSection_ApplyControllersToStoredFrame(struct _G2AnimSection_Type *section); // 0x80091700

extern unsigned long _G2AnimController_ApplyWorldToParentMatrix(struct _G2AnimController_Type *controller, struct _G2Matrix_Type *parentMatrix); // 0x80091974

extern void _G2AnimController_GetMatrix(struct _G2AnimController_Type *controller, struct _G2Matrix_Type *matrix); // 0x80091AC8

extern void _G2AnimController_GetVector(struct _G2AnimController_Type *controller, struct _G2SVector3_Type *vector); // 0x80091BA0

extern struct _G2AnimController_Type * _G2Anim_FindController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x80091C28

extern struct _G2AnimController_Type * _G2AnimController_Create(int segNumber, int type); // 0x80091C84

extern struct _G2AnimController_Type * _G2AnimController_Destroy(struct _G2AnimController_Type *controller); // 0x80091CEC

extern void _G2AnimController_InsertIntoList(struct _G2AnimController_Type *controller, unsigned short *listPtr); // 0x80091D50

extern void _G2AnimController_GetCurrentInterpQuat(struct _G2AnimController_Type *controller, struct _G2Anim_Type *anim, struct _G2Quat_Type *quat); // 0x80091E80

extern void _G2AnimController_GetSimpleWorldRotQuat(struct _G2AnimController_Type *controller, struct _G2Anim_Type *anim, struct _G2Quat_Type *quat); // 0x80091FBC

extern struct _G2AnimController_Type * _G2AnimControllerST_FindInList(int segNumber, int type, unsigned short *listPtr); // 0x8009203C

extern struct _G2AnimController_Type * _G2AnimControllerST_FindPtrInList(int segNumber, int type, unsigned short **listPtrPtr); // 0x800920AC

extern struct _G2AnimController_Type * _G2AnimControllerST_RemoveFromList(int segNumber, int type, unsigned short *listPtr); // 0x8009214C


#endif
