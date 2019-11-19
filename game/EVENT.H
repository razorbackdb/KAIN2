#ifndef EVENT_H
#define EVENT_H


extern void EVENT_ResetAllOneTimeVariables(); // 0x800619E4

extern void EVENT_AddSignalToReset(struct _MultiSignal *mSignal); // 0x80061A30

extern void HINT_StartHint(short hintNumber); // 0x80061A64

extern void HINT_StopHint(); // 0x80061AB0

extern void HINT_KillSpecificHint(short hintNumber); // 0x80061B0C

extern long HINT_GetCurrentHint(); // 0x80061B3C

extern void EVENT_ProcessTimers(); // 0x80061B5C

extern struct EventTimer * EVENT_GetNextTimer(); // 0x80061E64

extern void EVENT_RemoveTimer(struct EventTimer *timer); // 0x80061ED4

extern void EVENT_InitTimers(); // 0x80061F04

extern void EVENT_InitTerrainMovement(); // 0x80061F34

extern void EVENT_Init(); // 0x80061F88

extern struct WaterLevelProcess * EVENT_GetNextTerrainMove(); // 0x80061FB0

extern void EVENT_ProcessMovingWater(); // 0x80061FEC

extern void EVENT_DoProcess(); // 0x80062124

extern void EVENT_BSPProcess(struct Level *level); // 0x8006214C

extern void EVENT_Process(struct Event *eventInstance, long startIndex); // 0x8006228C

extern void EVENT_ProcessPuppetShow(struct Event *eventInstance, long startIndex); // 0x80062460

extern void EVENT_ProcessEvents(struct EventPointers *eventPointers, struct Level *level); // 0x8006267C

extern long EVENT_DoAction(struct Event *eventInstance, struct ScriptPCode *actionScript, short *scriptData); // 0x8006271C

extern long EVENT_IsConditionTrue(struct Event *eventInstance, struct ScriptPCode *conditionScript); // 0x80062894

extern long EVENT_WriteEventObject(struct StackType *stackEntry, long areaID, struct Event *event, long number); // 0x80062984

extern struct _MultiSignal * EVENT_ResolveObjectSignal(struct _StreamUnit *stream, long signalNumber); // 0x80062A34

extern struct Intro * EVENT_ResolveObjectIntro(struct EventInstanceObject *instanceObject); // 0x80062ACC

extern struct _SFXMkr * EVENT_ResolveSFXMarker(struct _StreamUnit *stream, struct EventInstanceObject *instanceObject); // 0x80062AF8

extern void EVENT_AddGameObjectToStack(struct _PCodeStack *stack); // 0x80062B58

extern void EVENT_AddPlayerObjectToStack(struct _PCodeStack *stack); // 0x80062BA4

extern void EVENT_AddObjectToStack(struct _PCodeStack *stack, long item); // 0x80062BFC

extern void EVENT_AddShortPointerToStack(struct _PCodeStack *stack, short *pointer); // 0x80062EB4

extern void EVENT_AddNumberToStack(struct _PCodeStack *stack, long item, long flags); // 0x80062EFC

extern void EVENT_ChangeOperandToNumber(struct StackType *operand, long item, long flags); // 0x80062F4C

extern void EVENT_ChangeOperandVector3d(struct StackType *operand, short x, short y, short z); // 0x80062F64

extern void EVENT_Addvector3dToStack(struct _PCodeStack *stack, short x, short y, short z); // 0x80062F8C

extern void EVENT_ChangeOperandRotation3d(struct StackType *operand, struct Rotation3d *rotation); // 0x80062FFC

extern long EVENT_AddSubListObjectToStack(struct _PCodeStack *stack, long listNumber); // 0x80063054

extern void EVENT_StackDuplicate(struct _PCodeStack *stack); // 0x800630E8

extern long EVENT_TransformTGroupAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063180

extern long EVENT_TransformConstrictAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80063210

extern long EVENT_TransformInstanceAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x8006327C

extern long EVENT_TransformSoundObjectAttribute(struct _PCodeStack *stack, struct SoundObject *soundObject, long item, short *codeStream); // 0x800637C4

extern long EVENT_GetGameValue(struct GameObject *gameObject); // 0x800638A4

extern long EVENT_TransformGameAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063940

extern long EVENT_TransformAreaAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063D70

extern long EVENT_TransformEventAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063E4C

extern long EVENT_TransformSavedEventAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063EF0

extern long EVENT_TransformSubListObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80063F7C

extern long EVENT_TransformListObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80063FB0

extern long EVENT_TransformCameraObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063FE4

extern long EVENT_TransformSplineAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80064110

extern long EVENT_TransformIntroAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80064214

extern long EVENT_ParseOperand2(struct StackType *operand2, long *error, long *trueValue); // 0x800642FC

extern long EVENT_DoVMObjectAction(struct EventVmObject *vmobject, struct StackType *operand2); // 0x80064354

extern long EVENT_GetVMObjectValue(struct EventVmObject *vmobject); // 0x80064514

extern long EVENT_DoGameAction(struct GameObject *gameObject, struct StackType *operand2); // 0x800645DC

extern long EVENT_DoSignalAction(struct SignalObject *signalObject, struct StackType *operand2); // 0x80064824

extern long EVENT_TransformSignalAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x800648A0

extern long EVENT_TransformRotation3dAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80064918

extern long EVENT_TransformVector3dAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80064950

extern void EVENT_ModifyObjectToStackWithAttribute(struct _PCodeStack *stack, long item, short *codeStream); // 0x80064A4C

extern long EVENT_DoInstanceAnimateTextureAction(struct InstanceAnimateTexture *instanceAniTexture, struct StackType *operand2); // 0x80064A7C

extern void EVENT_ResetAllSplineFlags(struct MultiSpline *spline); // 0x80064B84

extern void EVENT_SetSplineLoop(struct MultiSpline *spline); // 0x80064C0C

extern long EVENT_DoSplineAction(struct InstanceSpline *instanceSpline, struct StackType *operand2); // 0x80064C94

extern long EVENT_DoAnimateAction(struct InstanceAnimate *instanceAnimate, struct StackType *operand2); // 0x80065060

extern long EVENT_DoInstanceAction(struct InstanceObject *instanceObject, struct StackType *operand2, short *codeStream); // 0x80065334

extern long EVENT_GetTGroupValue(struct TGroupObject *terrainGroup); // 0x80065D28

extern long EVENT_DoTGroupAction(struct TGroupObject *terrainGroup, struct StackType *operand2); // 0x80065EA0

extern long EVENT_DoCameraAction(struct CameraObject *cameraObject, struct StackType *operand2, short *codeStream); // 0x800661A4

extern long EVENT_DoObjectSoundAction(struct SoundObject *soundObject, struct StackType *operand2); // 0x80066524

extern long EVENT_DoSoundMarkerAction(struct SoundObject *soundObject, struct StackType *operand2); // 0x80066658

extern long EVENT_GetSoundValue(struct SoundObject *soundObject); // 0x8006678C

extern long EVENT_DoAreaAction(struct AreaObject *areaObject, struct StackType *operand2); // 0x80066794

extern long EVENT_DoIntroAction(struct IntroObject *introObject, struct StackType *operand2); // 0x80066830

extern void EVENT_DoStackOperationEquals(struct _PCodeStack *stack, short *codeStream); // 0x80066A08

extern long EVENT_CompareVector3d(struct Vector3d *vector1, struct Vector3d *vector2); // 0x80066AF4

extern long EVENT_CompareRotationVectors(struct Rotation3d *rot1, struct Rotation3d *rot2, long trueValue); // 0x80066C9C

extern long EVENT_CompareListWithOperation(struct _PCodeStack *stack, struct ListObject *listObject, struct StackType *operand2, long operation); // 0x80066E94

extern long EVENT_CompareSubListWithOperation(struct _PCodeStack *stack, struct SubListObject *subListObject, struct StackType *operand2, long operation); // 0x80067094

extern long EVENT_CompareOperandsWithOperation(struct _PCodeStack *stack, struct StackType *operand1, struct StackType *operand2, long operation); // 0x8006723C

extern void EVENT_DoStackMathOperation(struct _PCodeStack *stack, long operation); // 0x8006756C

extern short * EVENT_ParseOpcode(struct _PCodeStack *stack, short *codeStream, long *operateOnStack); // 0x80067754

extern long EVENT_GetIntroValue(struct IntroObject *introObject); // 0x800679D0

extern void EVENT_DoSubListAction(struct SubListObject *subListObject, struct StackType *operand2, struct _PCodeStack *stack, short *codeStream); // 0x80067A64

extern long EVENT_GetInstanceValue(struct InstanceObject *instanceObject); // 0x80067B5C

extern long EVENT_GetSplineFrameNumber(struct InstanceSpline *instanceSpline); // 0x80067CD4

extern long EVENT_GetSplineValue(struct InstanceSpline *instanceSpline); // 0x80067D18

extern long EVENT_GetAnimateTextureValue(struct InstanceAnimateTexture *instanceAniTexture); // 0x80067E14

extern long EVENT_GetAnimateValue(struct InstanceAnimate *instanceAnimate); // 0x80067EC4

extern long EVENT_TransformObjectOnStack(struct _PCodeStack *stack, long item, short *codeStream); // 0x80067F3C

extern void EVENT_UpdatePuzzlePointers(struct EventPointers *events, long offset); // 0x80067F90

extern void EVENT_SaveEventsFromLevel(long levelID, struct Level *level); // 0x8006816C

extern void EVENT_LoadEventsForLevel(long levelID, struct Level *level); // 0x800682A0

extern struct SavedEvent * EVENT_CreateSaveEvent(long levelID, long eventNumber); // 0x80068370

extern void EVENT_RemoveInstanceFromInstanceList(struct _Instance *instance); // 0x800683DC

extern void EVENT_UpdatePuzzleWithInstance(struct EventPointers *puzzle, struct _Instance *instance); // 0x800684C8

extern void EVENT_AddInstanceToInstanceList(struct _Instance *instance); // 0x8006856C

extern struct _VMObject * EVENT_FindVMObject(struct _StreamUnit *stream, char *vmoName); // 0x8006865C

extern void EVENT_FixPuzzlesForStream(struct _StreamUnit *stream); // 0x800686FC

extern void EVENT_AddStreamToInstanceList(struct _StreamUnit *stream); // 0x800689E0

extern void EVENT_RemoveStreamToInstanceList(struct _StreamUnit *stream); // 0x80068CCC

extern void EVENT_RelocateInstanceList(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel); // 0x80068E98

extern void EVENT_PrintVars(); // 0x800690A4

extern void EVENT_ExecuteActionCommand(struct StackType *operand1, struct StackType *operand2, struct _PCodeStack *stack, short *codeStream); // 0x800691D8

extern long EVENT_GetScalerValueFromOperand(struct StackType *operand, long *error, short *flags); // 0x80069374

extern long EVENT_TransformOperand(struct StackType *stackObject, struct _PCodeStack *stack, long item, short *codeStream); // 0x800694D0


#endif
