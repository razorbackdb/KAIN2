#ifndef ANMCTRLR_H
#define ANMCTRLR_H


extern void G2Anim_AttachControllerToSeg(struct _G2Anim_Type *anim, int segNumber, int type); // 0x8008E190

extern void G2Anim_DetachControllerFromSeg(struct _G2Anim_Type *anim, int segNumber, int type); // 0x8008E1C8

extern void G2Anim_EnableController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x8008E288

extern void G2Anim_DisableController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x8008E364

extern void G2Anim_InterpDisableController(struct _G2Anim_Type *anim, int segNumber, int type, short duration); // 0x8008E3A4

extern enum _G2Bool_Enum G2Anim_IsControllerActive(struct _G2Anim_Type *anim, int segNumber, int type); // 0x8008E4C4

extern enum _G2Bool_Enum G2Anim_IsControllerInterpolating(struct _G2Anim_Type *anim, int segNumber, int type); // 0x8008E510

extern void G2Anim_GetControllerCurrentInterpVector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector); // 0x8008E564

extern void G2Anim_SetControllerCallbackData(struct _G2Anim_Type *anim, int segNumber, int type, void *callbackData); // 0x8008E6C4

extern void G2Anim_SetControllerAngleOrder(struct _G2Anim_Type *anim, int segNumber, int type, int order); // 0x8008E6EC

extern void G2Anim_SetController_Vector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector); // 0x8008E724

extern void G2Anim_SetInterpController_Vector(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2SVector3_Type *vector, int duration); // 0x8008E76C

extern void G2Anim_SetInterpController_Quat(struct _G2Anim_Type *anim, int segNumber, int type, struct _G2Quat_Type *quat, int duration); // 0x8008E8D0

extern void _G2Anim_ApplyControllersToStoredFrame(struct _G2Anim_Type *anim); // 0x8008E94C

extern void _G2Anim_BuildTransformsWithControllers(struct _G2Anim_Type *anim); // 0x8008E9AC

extern void _G2Anim_BuildSegTransformWithControllers(struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix, struct _G2AnimController_Type *controller, enum _G2Bool_Enum bRootTransUpdated, int segIndex); // 0x8008EB8C

extern unsigned long _G2AnimController_ApplyToSegValue(struct _G2AnimController_Type *controller, struct _G2AnimSegValue_Type *segValue, struct _G2Matrix_Type *segMatrix, struct _G2Matrix_Type *parentMatrix); // 0x8008EE9C

extern void _G2Anim_UpdateControllers(struct _G2Anim_Type *anim); // 0x8008F244

extern void _G2Anim_CopyVectorWithOrder(struct _G2SVector3_Type *sourceVector, struct _G2EulerAngles_Type *destVector, int order); // 0x8008F3D0

extern void _G2AnimSection_ApplyControllersToStoredFrame(struct _G2AnimSection_Type *section); // 0x8008F434

extern unsigned long _G2AnimController_ApplyWorldToParentMatrix(struct _G2AnimController_Type *controller, struct _G2Matrix_Type *parentMatrix); // 0x8008F6AC

extern void _G2AnimController_GetMatrix(struct _G2AnimController_Type *controller, struct _G2Matrix_Type *matrix); // 0x8008F800

extern void _G2AnimController_GetVector(struct _G2AnimController_Type *controller, struct _G2SVector3_Type *vector); // 0x8008F8D8

extern struct _G2AnimController_Type * _G2Anim_FindController(struct _G2Anim_Type *anim, int segNumber, int type); // 0x8008F960

extern struct _G2AnimController_Type * _G2AnimController_Create(int segNumber, int type); // 0x8008F9BC

extern struct _G2AnimController_Type * _G2AnimController_Destroy(struct _G2AnimController_Type *controller); // 0x8008FA28

extern void _G2AnimController_InsertIntoList(struct _G2AnimController_Type *controller, unsigned short *listPtr); // 0x8008FA90

extern void _G2AnimController_GetCurrentInterpQuat(struct _G2AnimController_Type *controller, struct _G2Anim_Type *anim, struct _G2Quat_Type *quat); // 0x8008FBC0

extern void _G2AnimController_GetSimpleWorldRotQuat(struct _G2AnimController_Type *controller, struct _G2Anim_Type *anim, struct _G2Quat_Type *quat); // 0x8008FCFC

extern struct _G2AnimController_Type * _G2AnimControllerST_FindInList(int segNumber, int type, unsigned short *listPtr); // 0x8008FD80

extern struct _G2AnimController_Type * _G2AnimControllerST_FindPtrInList(int segNumber, int type, unsigned short **listPtrPtr); // 0x8008FDF0

extern struct _G2AnimController_Type * _G2AnimControllerST_RemoveFromList(int segNumber, int type, unsigned short *listPtr); // 0x8008FE90


#endif
