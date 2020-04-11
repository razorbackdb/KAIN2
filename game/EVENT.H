#ifndef EVENT_H
#define EVENT_H


extern void EVENT_UpdateResetSignalArray(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel); // 0x80060C74

extern void EVENT_ResetAllOneTimeVariables(); // 0x80060CE8

extern void EVENT_AddSignalToReset(struct _MultiSignal *mSignal); // 0x80060D54

extern void HINT_ResetHint(); // 0x80060DB4

extern void HINT_StartHint(short hintNumber); // 0x80060DE0

extern void HINT_StopHint(); // 0x80060E2C

extern void HINT_KillSpecificHint(short hintNumber); // 0x80060E94

extern long HINT_GetCurrentHint(); // 0x80060EC4

extern void EVENT_ProcessTimers(); // 0x80060EE4

extern void EVENT_ProcessHints(); // 0x80061004

extern struct EventTimer * EVENT_GetNextTimer(); // 0x800611C8

extern void EVENT_RemoveTimer(struct EventTimer *timer); // 0x80061238

extern void EVENT_InitTimers(); // 0x80061268

extern void EVENT_InitTerrainMovement(); // 0x80061298

extern void EVENT_Init(); // 0x800612EC

extern struct WaterLevelProcess * EVENT_GetNextTerrainMove(); // 0x8006132C

extern void EVENT_ProcessMovingWater(); // 0x80061368

extern void EVENT_DoProcess(); // 0x800614A0

extern void EVENT_BSPProcess(struct _StreamUnit *streamUnit); // 0x800614C8

extern void EVENT_Process(struct Event *eventInstance, long startIndex); // 0x800616F8

extern void EVENT_ProcessPuppetShow(struct Event *eventInstance, long startIndex); // 0x80061858

extern void EVENT_ProcessEvents(struct EventPointers *eventPointers, struct Level *level); // 0x80061A30

extern long EVENT_DoAction(struct Event *eventInstance, struct ScriptPCode *actionScript, short *scriptData); // 0x80061AD0

extern long EVENT_IsConditionTrue(struct Event *eventInstance, struct ScriptPCode *conditionScript); // 0x80061C48

extern long EVENT_WriteEventObject(struct StackType *stackEntry, long areaID, struct Event *event, long number); // 0x80061D38

extern struct _MultiSignal * EVENT_ResolveObjectSignal(struct _StreamUnit *stream, long signalNumber); // 0x80061DE8

extern struct Intro * EVENT_ResolveObjectIntro(struct EventInstanceObject *instanceObject); // 0x80061E80

extern struct _SFXMkr * EVENT_ResolveSFXMarker(struct _StreamUnit *stream, struct EventInstanceObject *instanceObject); // 0x80061EAC

extern void EVENT_AddGameObjectToStack(struct _PCodeStack *stack); // 0x80061F0C

extern void EVENT_AddPlayerObjectToStack(struct _PCodeStack *stack); // 0x80061F58

extern void EVENT_AddObjectToStack(struct _PCodeStack *stack, long item); // 0x80061FB0

extern void EVENT_AddCharPointerToStack(struct _PCodeStack *stack, char *pointer); // 0x800621E4

extern void EVENT_AddShortPointerToStack(struct _PCodeStack *stack, short *pointer); // 0x8006222C

extern void EVENT_AddNumberToStack(struct _PCodeStack *stack, long item, long flags); // 0x80062274

extern void EVENT_ChangeOperandToNumber(struct StackType *operand, long item, long flags); // 0x800622C4

extern void EVENT_ChangeOperandVector3d(struct StackType *operand, short x, short y, short z, long streamUnitID); // 0x800622DC

extern void EVENT_Addvector3dToStack(struct _PCodeStack *stack, short x, short y, short z, long streamUnitID); // 0x8006230C

extern void EVENT_ChangeOperandRotation3d(struct StackType *operand, struct Rotation3d *rotation); // 0x80062384

extern long EVENT_AddSubListObjectToStack(struct _PCodeStack *stack, long listNumber); // 0x800623DC

extern void EVENT_StackDuplicate(struct _PCodeStack *stack); // 0x80062470

extern long EVENT_TransformTGroupAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80062508

extern long EVENT_TransformConstrictAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80062598

extern long EVENT_TransformInstanceAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80062604

extern long EVENT_TransformSoundObjectAttribute(struct _PCodeStack *stack, struct SoundObject *soundObject, long item, short *codeStream); // 0x80062C68

extern long EVENT_GetGameValue(struct GameObject *gameObject); // 0x80062D48

extern long EVENT_TransformGameAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80062DE4

extern long EVENT_TransformAreaAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063288

extern long EVENT_TransformEventAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063364

extern long EVENT_TransformSavedEventAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x800633F4

extern long EVENT_TransformSubListObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x800634B0

extern long EVENT_TransformListObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x800634E4

extern long EVENT_TransformCameraObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063518

extern long EVENT_TransformSplineAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063644

extern long EVENT_TransformIntroAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80063748

extern long EVENT_ParseOperand2(struct StackType *operand2, long *error, long *trueValue); // 0x80063864

extern long EVENT_DoVMObjectAction(struct EventVmObject *vmobject, struct StackType *operand2); // 0x800638BC

extern long EVENT_GetVMObjectValue(struct EventVmObject *vmobject); // 0x80063A7C

extern long EVENT_DoGameAction(struct GameObject *gameObject, struct StackType *operand2); // 0x80063B44

extern long EVENT_DoSignalAction(struct SignalObject *signalObject, struct StackType *operand2); // 0x80063E20

extern long EVENT_TransformSignalAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item); // 0x80063E9C

extern long EVENT_TransformRotation3dAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063EF4

extern long EVENT_TransformVector3dAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream); // 0x80063F2C

extern void EVENT_ModifyObjectToStackWithAttribute(struct _PCodeStack *stack, long item, short *codeStream); // 0x80064028

extern long EVENT_DoInstanceAnimateTextureAction(struct InstanceAnimateTexture *instanceAniTexture, struct StackType *operand2); // 0x80064058

extern void EVENT_ResetAllSplineFlags(struct MultiSpline *spline); // 0x80064160

extern void EVENT_SetSplineLoop(struct MultiSpline *spline); // 0x800641E8

extern long EVENT_DoSplineAction(struct InstanceSpline *instanceSpline, struct StackType *operand2); // 0x80064270

extern long EVENT_DoAnimateAction(struct InstanceAnimate *instanceAnimate, struct StackType *operand2); // 0x8006463C

extern long EVENT_DoInstanceAction(struct InstanceObject *instanceObject, struct StackType *operand2, short *codeStream); // 0x80064910

extern long EVENT_GetTGroupValue(struct TGroupObject *terrainGroup); // 0x800653B4

extern long EVENT_DoTGroupAction(struct TGroupObject *terrainGroup, struct StackType *operand2); // 0x80065540

extern long EVENT_DoCameraAction(struct CameraObject *cameraObject, struct StackType *operand2, short *codeStream); // 0x80065844

extern long EVENT_DoObjectSoundAction(struct SoundObject *soundObject, struct StackType *operand2); // 0x80065BC4

extern long EVENT_DoSoundMarkerAction(struct SoundObject *soundObject, struct StackType *operand2); // 0x80065CF8

extern long EVENT_GetSoundValue(struct SoundObject *soundObject); // 0x80065E2C

extern long EVENT_DoAreaAction(struct AreaObject *areaObject, struct StackType *operand2); // 0x80065E34

extern long EVENT_DoIntroAction(struct IntroObject *introObject, struct StackType *operand2); // 0x80065EE0

extern void EVENT_DoStackOperationEquals(struct _PCodeStack *stack, short *codeStream); // 0x800660B8

extern long EVENT_CompareVector3d(struct Vector3d *vector1, struct Vector3d *vector2); // 0x800661A4

extern long EVENT_CompareRotationVectors(struct Rotation3d *rot1, struct Rotation3d *rot2, long trueValue); // 0x80066360

extern long EVENT_CompareListWithOperation(struct _PCodeStack *stack, struct ListObject *listObject, struct StackType *operand2, long operation); // 0x80066558

extern long EVENT_CompareSubListWithOperation(struct _PCodeStack *stack, struct SubListObject *subListObject, struct StackType *operand2, long operation); // 0x80066758

extern long EVENT_CompareOperandsWithOperation(struct _PCodeStack *stack, struct StackType *operand1, struct StackType *operand2, long operation); // 0x80066900

extern void EVENT_DoStackMathOperation(struct _PCodeStack *stack, long operation); // 0x80066C38

extern short * EVENT_ParseOpcode(struct _PCodeStack *stack, short *codeStream, long *operateOnStack); // 0x80066E20

extern long EVENT_GetIntroValue(struct IntroObject *introObject); // 0x8006709C

extern void EVENT_DoSubListAction(struct SubListObject *subListObject, struct StackType *operand2, struct _PCodeStack *stack, short *codeStream); // 0x80067130

extern long EVENT_GetInstanceValue(struct InstanceObject *instanceObject); // 0x80067228

extern long EVENT_GetSplineFrameNumber(struct InstanceSpline *instanceSpline); // 0x800673A0

extern long EVENT_GetSplineValue(struct InstanceSpline *instanceSpline); // 0x800673E4

extern long EVENT_GetAnimateTextureValue(struct InstanceAnimateTexture *instanceAniTexture); // 0x800674E0

extern long EVENT_GetAnimateValue(struct InstanceAnimate *instanceAnimate); // 0x80067590

extern long EVENT_TransformObjectOnStack(struct _PCodeStack *stack, long item, short *codeStream); // 0x80067608

extern void EVENT_UpdatePuzzlePointers(struct EventPointers *events, long offset); // 0x8006765C

extern void EVENT_SaveEventsFromLevel(long levelID, struct Level *level); // 0x80067838

extern void EVENT_LoadEventsForLevel(long levelID, struct Level *level); // 0x800679B4

extern struct SavedBasic * EVENT_CreateSaveEvent(long levelID, long eventNumber); // 0x80067AF0

extern void EVENT_RemoveInstanceFromInstanceList(struct _Instance *instance); // 0x80067B5C

extern void EVENT_UpdatePuzzleWithInstance(struct EventPointers *puzzle, struct _Instance *instance); // 0x80067C48

extern void EVENT_AddInstanceToInstanceList(struct _Instance *instance); // 0x80067CEC

extern struct _VMObject * EVENT_FindVMObject(struct _StreamUnit *stream, char *vmoName); // 0x80067DDC

extern void EVENT_FixPuzzlesForStream(struct _StreamUnit *stream); // 0x80067E7C

extern void EVENT_AddStreamToInstanceList(struct _StreamUnit *stream); // 0x80068160

extern void EVENT_RemoveStreamToInstanceList(struct _StreamUnit *stream); // 0x8006844C

extern void EVENT_RelocateInstanceList(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel); // 0x80068618

extern void EVENT_PrintVars(); // 0x80068824

extern void EVENT_ExecuteActionCommand(struct StackType *operand1, struct StackType *operand2, struct _PCodeStack *stack, short *codeStream); // 0x8006882C

extern long EVENT_GetScalerValueFromOperand(struct StackType *operand, long *error, short *flags); // 0x800689F4

extern long EVENT_TransformOperand(struct StackType *stackObject, struct _PCodeStack *stack, long item, short *codeStream); // 0x80068B64


#endif
