#ifndef EVENT_H
#define EVENT_H

extern void EVENT_UpdateResetSignalArray(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel);

extern void EVENT_ResetAllOneTimeVariables();

extern void EVENT_AddSignalToReset(struct _MultiSignal *mSignal);

extern void HINT_ResetHint();

extern void HINT_StartHint(short hintNumber);

extern void HINT_StopHint();

extern void HINT_KillSpecificHint(short hintNumber);

extern long HINT_GetCurrentHint();

extern void EVENT_ProcessTimers();

extern void EVENT_ProcessHints();

extern struct EventTimer *EVENT_GetNextTimer();

extern void EVENT_RemoveTimer(struct EventTimer *timer);

extern void EVENT_InitTimers();

extern void EVENT_InitTerrainMovement();

extern void EVENT_Init();

extern struct WaterLevelProcess *EVENT_GetNextTerrainMove();

extern void EVENT_ProcessMovingWater();

extern void EVENT_DoProcess();

extern void EVENT_BSPProcess(struct _StreamUnit *streamUnit);

extern void EVENT_Process(struct Event *eventInstance, long startIndex);

extern void EVENT_ProcessPuppetShow(struct Event *eventInstance, long startIndex);

extern void EVENT_ProcessEvents(struct EventPointers *eventPointers, struct Level *level);

extern long EVENT_DoAction(struct Event *eventInstance, struct ScriptPCode *actionScript, short *scriptData);

extern long EVENT_IsConditionTrue(struct Event *eventInstance, struct ScriptPCode *conditionScript);

extern long EVENT_WriteEventObject(struct StackType *stackEntry, long areaID, struct Event *event, long number);

extern struct _MultiSignal *EVENT_ResolveObjectSignal(struct _StreamUnit *stream, long signalNumber);

extern struct Intro *EVENT_ResolveObjectIntro(struct EventInstanceObject *instanceObject);

extern struct _SFXMkr *EVENT_ResolveSFXMarker(struct _StreamUnit *stream, struct EventInstanceObject *instanceObject);

extern void EVENT_AddGameObjectToStack(struct _PCodeStack *stack);

extern void EVENT_AddPlayerObjectToStack(struct _PCodeStack *stack);

extern void EVENT_AddObjectToStack(struct _PCodeStack *stack, long item);

extern void EVENT_AddCharPointerToStack(struct _PCodeStack *stack, char *pointer);

extern void EVENT_AddShortPointerToStack(struct _PCodeStack *stack, short *pointer);

extern void EVENT_AddNumberToStack(struct _PCodeStack *stack, long item, long flags);

extern void EVENT_ChangeOperandToNumber(struct StackType *operand, long item, long flags);

extern void EVENT_ChangeOperandVector3d(struct StackType *operand, short x, short y, short z, long streamUnitID);

extern void EVENT_Addvector3dToStack(struct _PCodeStack *stack, short x, short y, short z, long streamUnitID);

extern void EVENT_ChangeOperandRotation3d(struct StackType *operand, struct Rotation3d *rotation);

extern long EVENT_AddSubListObjectToStack(struct _PCodeStack *stack, long listNumber);

extern void EVENT_StackDuplicate(struct _PCodeStack *stack);

extern long EVENT_TransformTGroupAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream);

extern long EVENT_TransformConstrictAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item);

extern long EVENT_TransformInstanceAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream);

extern long EVENT_TransformSoundObjectAttribute(struct _PCodeStack *stack, struct SoundObject *soundObject, long item, short *codeStream);

extern long EVENT_GetGameValue(struct GameObject *gameObject);

extern long EVENT_TransformGameAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream);

extern long EVENT_TransformAreaAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream);

extern long EVENT_TransformEventAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream);

extern long EVENT_TransformSavedEventAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream);

extern long EVENT_TransformSubListObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item);

extern long EVENT_TransformListObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item);

extern long EVENT_TransformCameraObjectAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream);

extern long EVENT_TransformSplineAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream);

extern long EVENT_TransformIntroAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item);

extern long EVENT_ParseOperand2(struct StackType *operand2, long *error, long *trueValue);

extern long EVENT_DoVMObjectAction(struct EventVmObject *vmobject, struct StackType *operand2);

extern long EVENT_GetVMObjectValue(struct EventVmObject *vmobject);

extern long EVENT_DoGameAction(struct GameObject *gameObject, struct StackType *operand2);

extern long EVENT_DoSignalAction(struct SignalObject *signalObject, struct StackType *operand2);

extern long EVENT_TransformSignalAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item);

extern long EVENT_TransformRotation3dAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream);

extern long EVENT_TransformVector3dAttribute(struct _PCodeStack *stack, struct StackType *stackObject, long item, short *codeStream);

extern void EVENT_ModifyObjectToStackWithAttribute(struct _PCodeStack *stack, long item, short *codeStream);

extern long EVENT_DoInstanceAnimateTextureAction(struct InstanceAnimateTexture *instanceAniTexture, struct StackType *operand2);

extern void EVENT_ResetAllSplineFlags(struct MultiSpline *spline);

extern void EVENT_SetSplineLoop(struct MultiSpline *spline);

extern long EVENT_DoSplineAction(struct InstanceSpline *instanceSpline, struct StackType *operand2);

extern long EVENT_DoAnimateAction(struct InstanceAnimate *instanceAnimate, struct StackType *operand2);

extern long EVENT_DoInstanceAction(struct InstanceObject *instanceObject, struct StackType *operand2, short *codeStream);

extern long EVENT_GetTGroupValue(struct TGroupObject *terrainGroup);

extern long EVENT_DoTGroupAction(struct TGroupObject *terrainGroup, struct StackType *operand2);

extern long EVENT_DoCameraAction(struct CameraObject *cameraObject, struct StackType *operand2, short *codeStream);

extern long EVENT_DoObjectSoundAction(struct SoundObject *soundObject, struct StackType *operand2);

extern long EVENT_DoSoundMarkerAction(struct SoundObject *soundObject, struct StackType *operand2);

extern long EVENT_GetSoundValue(struct SoundObject *soundObject);

extern long EVENT_DoAreaAction(struct AreaObject *areaObject, struct StackType *operand2);

extern long EVENT_DoIntroAction(struct IntroObject *introObject, struct StackType *operand2);

extern void EVENT_DoStackOperationEquals(struct _PCodeStack *stack, short *codeStream);

extern long EVENT_CompareVector3d(struct Vector3d *vector1, struct Vector3d *vector2);

extern long EVENT_CompareRotationVectors(struct Rotation3d *rot1, struct Rotation3d *rot2, long trueValue);

extern long EVENT_CompareListWithOperation(struct _PCodeStack *stack, struct ListObject *listObject, struct StackType *operand2, long operation);

extern long EVENT_CompareSubListWithOperation(struct _PCodeStack *stack, struct SubListObject *subListObject, struct StackType *operand2, long operation);

extern long EVENT_CompareOperandsWithOperation(struct _PCodeStack *stack, struct StackType *operand1, struct StackType *operand2, long operation);

extern void EVENT_DoStackMathOperation(struct _PCodeStack *stack, long operation);

extern short *EVENT_ParseOpcode(struct _PCodeStack *stack, short *codeStream, long *operateOnStack);

extern long EVENT_GetIntroValue(struct IntroObject *introObject);

extern void EVENT_DoSubListAction(struct SubListObject *subListObject, struct StackType *operand2, struct _PCodeStack *stack, short *codeStream);

extern long EVENT_GetInstanceValue(struct InstanceObject *instanceObject);

extern long EVENT_GetSplineFrameNumber(struct InstanceSpline *instanceSpline);

extern long EVENT_GetSplineValue(struct InstanceSpline *instanceSpline);

extern long EVENT_GetAnimateTextureValue(struct InstanceAnimateTexture *instanceAniTexture);

extern long EVENT_GetAnimateValue(struct InstanceAnimate *instanceAnimate);

extern long EVENT_TransformObjectOnStack(struct _PCodeStack *stack, long item, short *codeStream);

extern void EVENT_UpdatePuzzlePointers(struct EventPointers *events, long offset);

extern void EVENT_SaveEventsFromLevel(long levelID, struct Level *level);

extern void EVENT_LoadEventsForLevel(long levelID, struct Level *level);

extern struct SavedBasic *EVENT_CreateSaveEvent(long levelID, long eventNumber);

extern void EVENT_RemoveInstanceFromInstanceList(struct _Instance *instance);

extern void EVENT_UpdatePuzzleWithInstance(struct EventPointers *puzzle, struct _Instance *instance);

extern void EVENT_AddInstanceToInstanceList(struct _Instance *instance);

extern struct _VMObject *EVENT_FindVMObject(struct _StreamUnit *stream, char *vmoName);

extern void EVENT_FixPuzzlesForStream(struct _StreamUnit *stream);

extern void EVENT_AddStreamToInstanceList(struct _StreamUnit *stream);

extern void EVENT_RemoveStreamToInstanceList(struct _StreamUnit *stream);

extern void EVENT_RelocateInstanceList(struct Level *oldLevel, struct Level *newLevel, long sizeOfLevel);

extern void EVENT_PrintVars();

extern void EVENT_ExecuteActionCommand(struct StackType *operand1, struct StackType *operand2, struct _PCodeStack *stack, short *codeStream);

extern long EVENT_GetScalerValueFromOperand(struct StackType *operand, long *error, short *flags);

extern long EVENT_TransformOperand(struct StackType *stackObject, struct _PCodeStack *stack, long item, short *codeStream);

#endif
