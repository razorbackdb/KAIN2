#ifndef ANMCTRLR_H
#define ANMCTRLR_H

extern void G2Anim_AttachControllerToSeg(struct _G2Anim_Type *anim, int segNumber, int type);

extern void G2Anim_DetachControllerFromSeg(struct _G2Anim_Type *anim, int segNumber, int type);

extern void G2Anim_EnableController(struct _G2Anim_Type *anim, int segNumber, int type);

extern void G2Anim_DisableController(struct _G2Anim_Type *anim, int segNumber, int type);

extern void G2Anim_InterpDisableController(struct _G2Anim_Type *anim, int segNumber, int type, short duration);

extern enum _G2Bool_Enum G2Anim_IsControllerActive(struct _G2Anim_Type *anim, int segNumber, int type);

extern enum _G2Bool_Enum G2Anim_IsControllerInterpolating(struct _G2Anim_Type *anim, int segNumber, int type);

extern void G2Anim_GetControllerCurrentInterpVector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector);

extern void G2Anim_SetControllerCallbackData(struct _G2Anim_Type *anim, int segNumber, int type, void *callbackData);

extern void G2Anim_SetControllerAngleOrder(struct _G2Anim_Type *anim, int segNumber, int type, int order);

extern void G2Anim_SetController_Vector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector);

extern void G2Anim_SetInterpController_Vector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector, int duration);

extern void G2Anim_SetInterpController_Quat(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2Quat_Type *quat, int duration);

extern void _G2Anim_ApplyControllersToStoredFrame(struct _G2Anim_Type *anim);

extern void _G2Anim_BuildTransformsWithControllers(struct _G2Anim_Type *anim);

extern void _G2Anim_BuildSegTransformWithControllers(struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix, struct _G2AnimController_Type *controller, enum _G2Bool_Enum bRootTransUpdated, int segIndex);

extern unsigned long _G2AnimController_ApplyToSegValue(struct _G2AnimController_Type *controller, struct _G2AnimSegValue_Type *segValue, struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix);

extern void _G2Anim_UpdateControllers(struct _G2Anim_Type *anim);

extern void _G2Anim_CopyVectorWithOrder(struct _G2SVector3_Type *sourceVector, struct _G2EulerAngles_Type *destVector, int order);

extern void _G2AnimSection_ApplyControllersToStoredFrame(struct _G2AnimSection_Type *section);

extern unsigned long _G2AnimController_ApplyWorldToParentMatrix(struct _G2AnimController_Type *controller, struct _G2Matrix_Type *parentMatrix);

extern void _G2AnimController_GetMatrix(struct _G2AnimController_Type *controller, struct _G2Matrix_Type *matrix);

extern void _G2AnimController_GetVector(struct _G2AnimController_Type *controller, struct _G2SVector3_Type *vector);

extern struct _G2AnimController_Type *_G2Anim_FindController(struct _G2Anim_Type *anim, int segNumber, int type);

extern struct _G2AnimController_Type *_G2AnimController_Create(int segNumber, int type);

extern struct _G2AnimController_Type *_G2AnimController_Destroy(struct _G2AnimController_Type *controller);

extern void _G2AnimController_InsertIntoList(struct _G2AnimController_Type *controller, unsigned short *listPtr);

extern void _G2AnimController_GetCurrentInterpQuat(struct _G2AnimController_Type *controller, struct _G2Anim_Type *anim, struct _G2Quat_Type *quat);

extern void _G2AnimController_GetSimpleWorldRotQuat(struct _G2AnimController_Type *controller, struct _G2Anim_Type *anim, struct _G2Quat_Type *quat);

extern struct _G2AnimController_Type *_G2AnimControllerST_FindInList(int segNumber, int type, unsigned short *listPtr);

extern struct _G2AnimController_Type *_G2AnimControllerST_FindPtrInList(int segNumber, int type, unsigned short **listPtrPtr);

extern struct _G2AnimController_Type *_G2AnimControllerST_RemoveFromList(int segNumber, int type, unsigned short *listPtr);

#endif
