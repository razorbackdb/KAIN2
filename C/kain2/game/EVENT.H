#ifndef EVENT_H
#define EVENT_H


extern void EVENT_UpdateResetSignalArrayAndWaterMovement(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel); // 0x80060B8C

extern void EVENT_ResetAllOneTimeVariables(); // 0x80060C68

extern void EVENT_AddSignalToReset(struct _MultiSignal *mSignal); // 0x80060CD0

extern void HINT_ResetHint(); // 0x80060D2C

extern void HINT_StartHint(short hintNumber); // 0x80060D54

extern void HINT_StopHint(); // 0x80060DA0

extern void HINT_KillSpecificHint(short hintNumber); // 0x80060E04

extern long HINT_GetCurrentHint(); // 0x80060E34

extern void EVENT_ProcessTimers(); // 0x80060E54

extern void EVENT_ProcessHints(); // 0x80060F70

extern struct EventTimer * EVENT_GetNextTimer(); // 0x80061130

extern void EVENT_RemoveTimer(struct EventTimer *timer); // 0x8006119C

extern void EVENT_InitTimers(); // 0x800611CC

extern void EVENT_InitTerrainMovement(); // 0x800611F8

extern void EVENT_Init(); // 0x80061248

extern struct WaterLevelProcess * EVENT_GetNextTerrainMove(); // 0x80061294

extern void EVENT_ProcessMovingWater(); // 0x800612CC

extern void EVENT_DoProcess(); // 0x800613FC

extern void EVENT_BSPProcess(struct _StreamUnit *streamUnit); // 0x80061424

extern void EVENT_Process(struct Event *eventInstance, long startIndex); // 0x80061664

extern void EVENT_ProcessPuppetShow(struct Event *eventInstance, long startIndex); // 0x800617C4

extern void EVENT_ProcessEvents(struct EventPointers *eventPointers, struct Level *level); // 0x8006199C

extern long EVENT_DoAction(struct Event *eventInstance, struct ScriptPCode *actionScript, short *scriptData); // 0x80061A60

extern long EVENT_IsConditionTrue(struct Event *eventInstance, struct ScriptPCode *conditionScript); // 0x80061BD8

extern long EVENT_WriteEventObject(struct StackType *stackEntry, long areaID, struct Event *event, long number); // 0x80061CC8

extern struct _MultiSignal * EVENT_ResolveObjectSignal(struct _StreamUnit *stream, long signalNumber); // 0x80061D78

extern struct Intro * EVENT_ResolveObjectIntro(struct EventInstanceObject *instanceObject); // 0x80061E10

extern struct _SFXMkr * EVENT_ResolveSFXMarker(struct _StreamUnit *stream, struct EventInstanceObject *instanceObject); // 0x80061E3C

extern void EVENT_AddGameObjectToStack(struct _PCodeStack *stack); // 0x80061E9C

extern void EVENT_AddPlayerObjectToStack(struct _PCodeStack *stack); // 0x80061EE8

extern void EVENT_AddObjectToStack(struct _PCodeStack *stack, long item); // 0x80061F40

extern void EVENT_AddCharPointerToStack(struct _PCodeStack *stack, char *pointer); // 0x80062174

extern void EVENT_AddShortPointerToStack(struct _PCodeStack *stack, short *pointer); // 0x800621BC

extern void EVENT_AddNumberToStack(struct _PCodeStack *stack, long item, long flags); // 0x80062204

extern void EVENT_ChangeOperandToNumber(struct StackType *operand, long item, long flags); // 0x80062254

extern void EVENT_ChangeOperandVector3d(struct StackType *operand, short x, short y, short z, long streamUnitID); // 0x8006226C

extern void EVENT_Addvector3dToStack(struct _PCodeStack *stack, short x, short y, short z, long streamUnitID); // 0x8006229C

extern void EVENT_ChangeOperandRotation3d(struct StackType *operand, struct Rotation3d *rotation); // 0x80062314

extern long EVENT_AddSubListObjectToStack(struct _PCodeStack *stack, long listNumber); // 0x8006236C

extern void EVENT_StackDuplicate(struct _PCodeStack *stack); // 0x800623F8

extern long EVENT_TransformTGroupAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80062490

extern long EVENT_TransformConstrictAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80062520

extern long EVENT_TransformInstanceAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x8006258C

extern long EVENT_TransformSoundObjectAttribute(struct _PCodeStack *stack, struct SoundObject *soundObject, long item, short *codeStream); // 0x80062BF0

extern long EVENT_GetGameValue(struct GameObject *gameObject); // 0x80062D08

extern long EVENT_TransformGameAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80062DA4

extern long EVENT_TransformAreaAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063224

extern long EVENT_TransformEventAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063300

extern long EVENT_TransformSavedEventAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063390

extern long EVENT_TransformSubListObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x8006344C

extern long EVENT_TransformListObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80063480

extern long EVENT_TransformCameraObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x800634B4

extern long EVENT_TransformSplineAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x800635E0

extern long EVENT_TransformIntroAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x800636E4

extern long EVENT_ParseOperand2(struct StackType *operand2, long *error, long *trueValue); // 0x80063800

extern long EVENT_DoVMObjectAction(struct EventVmObject *vmobject, struct StackType *operand2); // 0x80063858

extern long EVENT_GetVMObjectValue(struct EventVmObject *vmobject); // 0x80063A18

extern long EVENT_DoGameAction(struct GameObject *gameObject, struct StackType *operand2); // 0x80063AE0

extern long EVENT_DoSignalAction(struct SignalObject *signalObject, struct StackType *operand2); // 0x80063DD4

extern long EVENT_TransformSignalAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80063E50

extern long EVENT_TransformRotation3dAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063EA8

extern long EVENT_TransformVector3dAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063EE0

extern void EVENT_ModifyObjectToStackWithAttribute(struct _PCodeStack *stack, long item, short *codeStream); // 0x80063FDC

extern long EVENT_DoInstanceAnimateTextureAction(struct InstanceAnimateTexture *instanceAniTexture, struct StackType *operand2); // 0x8006400C

extern void EVENT_ResetAllSplineFlags(struct MultiSpline *spline); // 0x80064114

extern void EVENT_SetSplineLoop(struct MultiSpline *spline); // 0x8006419C

extern long EVENT_DoSplineAction(struct InstanceSpline *instanceSpline, struct StackType *operand2); // 0x80064224

extern long EVENT_DoAnimateAction(struct InstanceAnimate *instanceAnimate, struct StackType *operand2); // 0x800645F0

extern long EVENT_DoInstanceAction(struct InstanceObject *instanceObject, struct StackType *operand2, short *codeStream); // 0x800648C4

extern long EVENT_GetTGroupValue(struct TGroupObject *terrainGroup); // 0x80065368

extern long EVENT_DoTGroupAction(struct TGroupObject *terrainGroup, struct StackType *operand2); // 0x800654D4

extern long EVENT_DoCameraAction(struct CameraObject *cameraObject, struct StackType *operand2, short *codeStream); // 0x800657DC

extern long EVENT_DoObjectSoundAction(struct SoundObject *soundObject, struct StackType *operand2); // 0x80065B5C

extern long EVENT_DoSoundMarkerAction(struct SoundObject *soundObject, struct StackType *operand2); // 0x80065C90

extern long EVENT_GetSoundValue(struct SoundObject *soundObject); // 0x80065DC4

extern long EVENT_DoAreaAction(struct AreaObject *areaObject, struct StackType *operand2); // 0x80065DCC

extern long EVENT_DoIntroAction(struct IntroObject *introObject, struct StackType *operand2); // 0x80065E78

extern void EVENT_DoStackOperationEquals(struct _PCodeStack *stack, short *codeStream); // 0x80066088

extern long EVENT_CompareVector3d(struct Vector3d *vector1, struct Vector3d *vector2); // 0x80066174

extern long EVENT_CompareRotationVectors(struct Rotation3d *rot1, struct Rotation3d *rot2, long trueValue); // 0x80066330

extern long EVENT_CompareListWithOperation(struct _PCodeStack *stack, struct ListObject *listObject, struct StackType *operand2, long operation); // 0x80066528

extern long EVENT_CompareSubListWithOperation(struct _PCodeStack *stack, struct SubListObject *subListObject, struct StackType *operand2, long operation); // 0x8006671C

extern long EVENT_CompareOperandsWithOperation(struct _PCodeStack *stack, struct StackType *operand1, struct StackType *operand2, long operation); // 0x800668B8

extern void EVENT_DoStackMathOperation(struct _PCodeStack *stack, long operation); // 0x80066BF0

extern short * EVENT_ParseOpcode(struct _PCodeStack *stack, short *codeStream, long *operateOnStack); // 0x80066DD8

extern long EVENT_GetIntroValue(struct IntroObject *introObject); // 0x80067054

extern void EVENT_DoSubListAction(struct SubListObject *subListObject, struct StackType *operand2, struct _PCodeStack *stack, short *codeStream); // 0x800670E8

extern long EVENT_GetInstanceValue(struct InstanceObject *instanceObject); // 0x800671E0

extern long EVENT_GetSplineFrameNumber(struct InstanceSpline *instanceSpline); // 0x80067358

extern long EVENT_GetSplineValue(struct InstanceSpline *instanceSpline); // 0x8006739C

extern long EVENT_GetAnimateTextureValue(struct InstanceAnimateTexture *instanceAniTexture); // 0x80067498

extern long EVENT_GetAnimateValue(struct InstanceAnimate *instanceAnimate); // 0x80067548

extern long EVENT_TransformObjectOnStack(struct _PCodeStack *stack, long item, short *codeStream); // 0x800675C0

extern void EVENT_UpdatePuzzlePointers(struct EventPointers *events, long offset); // 0x80067614

extern void EVENT_SaveEventsFromLevel(long levelID, struct Level *level); // 0x800677F0

extern void EVENT_LoadEventsForLevel(long levelID, struct Level *level); // 0x8006796C

extern struct SavedBasic * EVENT_CreateSaveEvent(long levelID, long eventNumber); // 0x80067AA8

extern void EVENT_RemoveInstanceFromInstanceList(struct _Instance *instance); // 0x80067B14

extern void EVENT_UpdatePuzzleWithInstance(struct EventPointers *puzzle, struct _Instance *instance); // 0x80067BFC

extern void EVENT_AddInstanceToInstanceList(struct _Instance *instance); // 0x80067CA0

extern struct _VMObject * EVENT_FindVMObject(struct _StreamUnit *stream, char *vmoName); // 0x80067D8C

extern void EVENT_FixPuzzlesForStream(struct _StreamUnit *stream); // 0x80067E2C

extern void EVENT_AddStreamToInstanceList(struct _StreamUnit *stream); // 0x80068110

extern void EVENT_RemoveStreamToInstanceList(struct _StreamUnit *stream); // 0x800683F8

extern void EVENT_RelocateInstanceList(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel); // 0x800685BC

extern void EVENT_PrintVars(); // 0x800687BC

extern void EVENT_ExecuteActionCommand(struct StackType *operand1, struct StackType *operand2, struct _PCodeStack *stack, short *codeStream); // 0x800687C4

extern long EVENT_GetScalerValueFromOperand(struct StackType *operand, long *error, short *flags); // 0x8006898C

extern long EVENT_TransformOperand(struct StackType *stackObject, struct _PCodeStack *stack, long item, short *codeStream); // 0x80068AFC


#endif
