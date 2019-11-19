#ifndef CAMERA_H
#define CAMERA_H


extern void CAMERA_CalculateViewVolumeNormals(struct Camera *camera); // 0x80014D48

extern void CAMERA_CalcVVClipInfo(struct Camera *camera); // 0x80015084

extern void CAMERA_SetViewVolume(struct Camera *camera); // 0x800151A4

extern void CAMERA_SetProjDistance(struct Camera *camera, long distance); // 0x800151D0

extern void CAMERA_CreateNewFocuspoint(struct Camera *camera); // 0x80015278

extern void CAMERA_SaveMode(struct Camera *camera, long mode); // 0x8001531C

extern void CAMERA_RestoreMode(struct Camera *camera); // 0x80015654

extern void CAMERA_Save(struct Camera *camera, long save); // 0x80015AB0

extern void CAMERA_Restore(struct Camera *camera, long restore); // 0x80015B80

extern struct _SVector * SplineGetNextPointDC(struct Spline *spline, struct SplineDef *def); // 0x80015C3C

extern void CAMERA_SetMode(struct Camera *camera, long mode); // 0x80015CA0

extern void CAMERA_Initialize(struct Camera *camera); // 0x800161BC

extern void CAMERA_SetInstanceFocus(struct Camera *camera, struct _Instance *instance); // 0x800164AC

extern void CAMERA_SetZRotation(struct Camera *camera, short zrot); // 0x800164F4

extern long CAMERA_LengthSVector(struct _SVector *sv); // 0x80016518

extern void CAMERA_SetValue(struct Camera *camera, long index, long value); // 0x8001656C

extern short CAMERA_AngleDifference(short angle0, short angle1); // 0x80016998

extern short CAMERA_SignedAngleDifference(short angle0, short angle1); // 0x80016A10

extern unsigned long CAMERA_QueryMode(struct Camera *camera); // 0x80016A40

extern void CAMERA_SetMaxVel(struct Camera *camera); // 0x80016A64

extern void CAMERA_SetTarget(struct Camera *camera, struct _Position *pos); // 0x80016B70

extern void CAMERA_CalcPosition(struct _Position *position, struct _Position *base, struct _Rotation *rotation, short distance); // 0x80016BEC

extern void CAMERA_SetFocus(struct Camera *camera, struct _Position *targetfocusPoint); // 0x80016D14

extern void CAMERA_Lock(struct Camera *camera, long lock); // 0x80016F90

extern void CAMERA_Unlock(struct Camera *camera, long unlock); // 0x80016FA4

extern void CAMERA_SetSmoothValue(struct Camera *camera, long smooth); // 0x80016FB8

extern void CAMERA_SetTimer(struct Camera *camera, long time); // 0x80017008

extern void CAMERA_Adjust_tilt(struct Camera *camera, long tilt); // 0x80017028

extern void CAMERA_Adjust_distance(struct Camera *camera, long dist); // 0x80017064

extern void CAMERA_Adjust_rotation(struct Camera *camera, long rotation); // 0x800170E0

extern void CAMERA_Adjust_roll(long roll_degrees, int frames); // 0x80017164

extern void CAMERA_Adjust(struct Camera *camera, long adjust); // 0x800171E8

extern void CAMERA_ChangeTo(struct Camera *camera, struct _CameraKey *cameraKey); // 0x800172A8

extern void CAMERA_SetShake(struct Camera *camera, long shake, long scale); // 0x800172B0

extern void Decouple_AngleMoveToward(short *current_ptr, short destination, short step); // 0x80017350

extern void CriticalDampValue(long dampMode, short *sourceVal, short targetVal, short *vel, short *accl, int smooth); // 0x800173A0

extern void CriticalDampPosition(long dampMode, struct _Position *position, struct _Position *targetPos, struct _SVector *vel, struct _SVector *accl, int smooth); // 0x80017554

extern void CriticalDampAngle(long dampMode, short *currentVal, short target, short *vel, short *accl, int smooth); // 0x80017C18

extern short CAMERA_CalcZRotation(struct _Position *target, struct _Position *position); // 0x80017CB8

extern void CAMERA_CalcRotation(struct _Rotation *rotation, struct _Position *target, struct _Position *position); // 0x80017D30

extern void CAMERA_CalcFSRotation(struct Camera *camera, struct _Rotation *rotation, struct _Position *target, struct _Position *position); // 0x80017DCC

extern void CAMERA_Relocate(struct Camera *camera, struct _SVector *offset, int streamSignalFlag); // 0x80017E78

extern struct _TFace * CAMERA_SphereToSphereWithLines(struct Camera *camera, struct CameraCollisionInfo *colInfo, int secondcheck_flag); // 0x80017F88

extern long CAMERA_CalcTilt(struct _Normal *normal, short zRot); // 0x80018AFC

extern void CAMERA_SetLookFocusAndBase(struct _Instance *focusInstance, struct _Position *focusPoint); // 0x80018B70

extern void CAMERA_SetLookFocusAndDistance(struct Camera *camera, struct VECTOR *focuspoint, int distance); // 0x80018BB8

extern void CAMERA_LookProcess(struct Camera *camera); // 0x80018BE0

extern void CAMERA_Normalize(struct _SVector *svector); // 0x80018E14

extern void CAMERA_HandleTransitions(struct Camera *camera); // 0x80018E8C

extern void CAMERA_CalcFocusOffset(struct _SVector *offset, struct Camera *camera); // 0x80019040

extern void CAMERA_CalcFocusOffsetForSwim(struct _SVector *offset, struct Camera *camera); // 0x800190F4

extern short CAMERA_CalcIntersectAngle(struct _SVector *linept, struct _SVector *vertex0, struct _SVector *vertex1, short *high, short *low); // 0x80019160

extern short CAMERA_GetLineAngle(struct Camera *camera, struct CameraCollisionInfo *colInfo, struct _SVector *linept, int line); // 0x80019254

extern long CAMERA_ACForcedMovement(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x8001941C

extern void CAMERA_update_dist_debounced(struct Camera *camera, short dist); // 0x800194EC

extern short CAMERA_dampgetline(short angle); // 0x80019520

extern long CAMERA_ACNoForcedMovement(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x800195D8

extern long CAMERA_AbsoluteCollision(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x80019AE4

extern short CAMERA_update_z_damped(struct Camera *camera, short current, short target); // 0x80019C0C

extern void CAMERA_CombatCamDist(struct Camera *camera); // 0x80019E84

extern void CAMERA_GenericCameraProcess(struct Camera *camera); // 0x8001A148

extern void CAMERA_CinematicProcess(struct Camera *camera); // 0x8001A5A8

extern int CAMERA_GetDistSq(struct _SVector *point1, struct _SVector *point2); // 0x8001AAC4

extern void CAMERA_NearestPointOnLineVec(struct _SVector *linePoint, struct _SVector *start, struct _SVector *line, struct _Position *point); // 0x8001AB40

extern int CAMERA_CheckPoint(int linePoint, int linept1, int linept2); // 0x8001AC6C

extern int CAMERA_CheckIfPointOnLine(struct _SVector *linePoint, struct _SVector *linept1, struct _SVector *linept2); // 0x8001ACB0

extern int CAMERA_FindLinePoint(struct _Position *point, struct _SVector *linept1, struct _SVector *linept2, int target_dist_sq, struct _SVector *results); // 0x8001AD40

extern void CAMERA_SplineGetNearestPoint2(struct Camera *camera, struct Spline *spline, struct _SVector *point, int *currkey, struct _SVector *ret_dpoint); // 0x8001AF04

extern void CAMERA_SplineGetNearestPoint(struct Spline *spline, struct _SVector *point, int *currkey, struct _SVector *ret_dpoint); // 0x8001B0EC

extern void CAMERA_SplineHelpMove(struct Camera *camera); // 0x8001B484

extern void CAMERA_SplineProcess(struct Camera *camera); // 0x8001B5F8

extern void CAMERA_ShakeCamera(struct Camera *camera); // 0x8001B94C

extern void CAMERA_Process(struct Camera *camera); // 0x8001BA38

extern void CAMERA_CenterCamera(struct Camera *camera); // 0x8001BC84

extern void CAMERA_SetLookRot(struct Camera *camera, int x_rotation, int z_rotation); // 0x8001BD6C

extern void CAMERA_StartLookaroundMode(struct Camera *camera); // 0x8001BD78

extern void CAMERA_StartSwimThrowMode(struct Camera *camera); // 0x8001BE08

extern void CAMERA_EndSwimThrowMode(struct Camera *camera); // 0x8001BE48

extern void CAMERA_ForceEndLookaroundMode(struct Camera *camera); // 0x8001BE6C

extern void CAMERA_Control(struct Camera *camera, struct _Instance *playerInstance); // 0x8001BEA8

extern void CAMERA_EndLook(struct Camera *camera); // 0x8001C3B8

extern void CAMERA_ChangeToUnderWater(struct Camera *camera, struct _Instance *instance); // 0x8001C478

extern void CAMERA_ChangeToOutOfWater(struct Camera *camera, struct _Instance *instance); // 0x8001C524

extern void CAMERA_DebugMoveToNewFocusInstance(); // 0x8001C598

extern void CAMERA_UpdateFocusDistance(struct Camera *camera); // 0x8001C5A0

extern void CAMERA_UpdateFocusTilt(struct Camera *camera); // 0x8001C670

extern void CAMERA_UpdateFocusRoll(struct Camera *camera); // 0x8001C73C

extern void CAMERA_UpdateFocusRotate(struct Camera *camera); // 0x8001C858

extern void CAMERA_UpdateFocusRotationX(struct Camera *camera, struct _Instance *focusInstance); // 0x8001C944

extern void CAMERA_FollowPlayerTilt(struct Camera *camera, struct _Instance *focusInstance); // 0x8001CBB4

extern void CAMERA_FollowGoBehindPlayerWithTimer(struct Camera *camera); // 0x8001CDA4

extern void CAMERA_FollowGoBehindPlayer(struct Camera *camera); // 0x8001CE8C

extern void CAMERA_CalculateLead(struct Camera *camera); // 0x8001CEC8

extern void CAMERA_CalcFollowPosition(struct Camera *camera, struct _Rotation *rotation); // 0x8001D060

extern void CAMERA_SetupColInfo(struct Camera *camera, struct CameraCollisionInfo *colInfo, struct _Position *targetCamPos); // 0x8001D354

extern void CAMERA_DoPanicCheck(struct Camera *camera, struct CameraCollisionInfo *tmpcolInfo, struct _Rotation *rotation, short *best_z, short *max_dist); // 0x8001D414

extern void CAMERA_Panic(struct Camera *camera, short min_dist); // 0x8001D4E4

extern long CAMERA_DoCameraCollision2(struct Camera *camera, struct _Position *targetCamPos, int simpleflag); // 0x8001D694

extern int CAMERA_FocusInstanceMoved(struct Camera *camera); // 0x8001DBF8


#endif
