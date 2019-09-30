#ifndef CAMERA_H
#define CAMERA_H


extern void CAMERA_CalculateViewVolumeNormals(struct Camera *camera); // 0x80014720

extern void CAMERA_CalcVVClipInfo(struct Camera *camera); // 0x80014A5C

extern void CAMERA_SetViewVolume(struct Camera *camera); // 0x80014B7C

extern void CAMERA_SetProjDistance(struct Camera *camera, long distance); // 0x80014BA8

extern void CAMERA_CreateNewFocuspoint(struct Camera *camera); // 0x80014C50

extern void CAMERA_SaveMode(struct Camera *camera, long mode); // 0x80014CF4

extern void CAMERA_RestoreMode(struct Camera *camera); // 0x8001502C

extern void CAMERA_Save(struct Camera *camera, long save); // 0x800154D8

extern void CAMERA_Restore(struct Camera *camera, long restore); // 0x800155A8

extern struct _SVector * SplineGetNextPointDC(struct Spline *spline, struct SplineDef *def); // 0x80015664

extern void CAMERA_SetMode(struct Camera *camera, long mode); // 0x800156C8

extern void CAMERA_Initialize(struct Camera *camera); // 0x80015B48

extern void CAMERA_SetInstanceFocus(struct Camera *camera, struct _Instance *instance); // 0x80015E50

extern void CAMERA_SetZRotation(struct Camera *camera, short zrot); // 0x80015EB0

extern long CAMERA_LengthSVector(struct _SVector *sv); // 0x80015ED4

extern void CAMERA_SetValue(struct Camera *camera, long index, long value); // 0x80015F28

extern short CAMERA_AngleDifference(short angle0, short angle1); // 0x80016354

extern short CAMERA_SignedAngleDifference(short angle0, short angle1); // 0x800163CC

extern unsigned long CAMERA_QueryMode(struct Camera *camera); // 0x800163FC

extern void CAMERA_SetMaxVel(struct Camera *camera); // 0x80016498

extern void CAMERA_SetTarget(struct Camera *camera, struct _Position *pos); // 0x800165A4

extern void CAMERA_CalcPosition(struct _Position *position, struct _Position *base, struct _Rotation *rotation, short distance); // 0x80016620

extern void CAMERA_SetFocus(struct Camera *camera, struct _Position *targetfocusPoint); // 0x80016748

extern void CAMERA_Lock(struct Camera *camera, long lock); // 0x800169C4

extern void CAMERA_Unlock(struct Camera *camera, long unlock); // 0x800169D8

extern void CAMERA_SetSmoothValue(struct Camera *camera, long smooth); // 0x800169EC

extern void CAMERA_SetTimer(struct Camera *camera, long time); // 0x80016A3C

extern void CAMERA_Adjust_tilt(struct Camera *camera, long tilt); // 0x80016A5C

extern void CAMERA_Adjust_distance(struct Camera *camera, long dist); // 0x80016A98

extern void CAMERA_Adjust_rotation(struct Camera *camera, long rotation); // 0x80016B14

extern void CAMERA_Adjust_roll(long roll_degrees, int frames); // 0x80016B98

extern void CAMERA_Adjust(struct Camera *camera, long adjust); // 0x80016C1C

extern void CAMERA_ChangeTo(struct Camera *camera, struct _CameraKey *cameraKey); // 0x80016CDC

extern void CAMERA_SetShake(struct Camera *camera, long shake, long scale); // 0x80016CE4

extern void Decouple_AngleMoveToward(short *current_ptr, short destination, short step); // 0x80016D94

extern void CriticalDampValue(long dampMode, short *sourceVal, short targetVal, short *vel, short *accl, int smooth); // 0x80016DE4

extern void CriticalDampPosition(long dampMode, struct _Position *position, struct _Position *targetPos, struct _SVector *vel, struct _SVector *accl, int smooth); // 0x80016F98

extern void CriticalDampAngle(long dampMode, short *currentVal, short target, short *vel, short *accl, int smooth); // 0x8001765C

extern short CAMERA_CalcZRotation(struct _Position *target, struct _Position *position); // 0x800176FC

extern void CAMERA_CalcRotation(struct _Rotation *rotation, struct _Position *target, struct _Position *position); // 0x80017774

extern void CAMERA_CalcFSRotation(struct Camera *camera, struct _Rotation *rotation, struct _Position *target, struct _Position *position); // 0x80017810

extern void CAMERA_Relocate(struct Camera *camera, struct _SVector *offset, int streamSignalFlag); // 0x800178BC

extern struct _TFace * CAMERA_SphereToSphereWithLines(struct Camera *camera, struct CameraCollisionInfo *colInfo, int secondcheck_flag); // 0x80017A08

extern long CAMERA_CalcTilt(struct _Normal *normal, short zRot); // 0x80018550

extern void CAMERA_SetLookFocusAndBase(struct _Instance *focusInstance, struct _Position *focusPoint); // 0x800185C4

extern void CAMERA_SetLookFocusAndDistance(struct Camera *camera, struct VECTOR *focuspoint, int distance); // 0x8001860C

extern void CAMERA_LookProcess(struct Camera *camera); // 0x80018634

extern void CAMERA_Normalize(struct _SVector *svector); // 0x80018888

extern void CAMERA_HandleTransitions(struct Camera *camera); // 0x80018900

extern void CAMERA_CalcFocusOffset(struct _SVector *offset, struct Camera *camera); // 0x80018AB4

extern void CAMERA_CalcFocusOffsetForSwim(struct _SVector *offset, struct Camera *camera); // 0x80018B68

extern short CAMERA_CalcIntersectAngle(struct _SVector *linept, struct _SVector *vertex0, struct _SVector *vertex1, short *high, short *low); // 0x80018BD4

extern short CAMERA_GetLineAngle(struct Camera *camera, struct CameraCollisionInfo *colInfo, struct _SVector *linept, int line); // 0x80018CC8

extern long CAMERA_ACForcedMovement(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x80018E90

extern void CAMERA_update_dist_debounced(struct Camera *camera, short dist); // 0x80018F60

extern short CAMERA_dampgetline(short angle); // 0x80018FD0

extern long CAMERA_ACNoForcedMovement(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x80019088

extern long CAMERA_AbsoluteCollision(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x80019594

extern short CAMERA_update_z_damped(struct Camera *camera, short current, short target); // 0x800196BC

extern void CAMERA_CombatCamDist(struct Camera *camera); // 0x80019934

extern void CAMERA_GenericCameraProcess(struct Camera *camera); // 0x80019BF8

extern void CAMERA_CinematicProcess(struct Camera *camera); // 0x8001A074

extern int CAMERA_GetDistSq(struct _SVector *point1, struct _SVector *point2); // 0x8001A590

extern void CAMERA_NearestPointOnLineVec(struct _SVector *linePoint, struct _SVector *start, struct _SVector *line, struct _Position *point); // 0x8001A60C

extern int CAMERA_CheckPoint(int linePoint, int linept1, int linept2); // 0x8001A738

extern int CAMERA_CheckIfPointOnLine(struct _SVector *linePoint, struct _SVector *linept1, struct _SVector *linept2); // 0x8001A77C

extern int CAMERA_FindLinePoint(struct _Position *point, struct _SVector *linept1, struct _SVector *linept2, int target_dist_sq, struct _SVector *results); // 0x8001A80C

extern void CAMERA_SplineGetNearestPoint2(struct Camera *camera, struct Spline *spline, struct _SVector *point, int *currkey, struct _SVector *ret_dpoint); // 0x8001A9D0

extern void CAMERA_SplineGetNearestPoint(struct Spline *spline, struct _SVector *point, int *currkey, struct _SVector *ret_dpoint); // 0x8001ABB8

extern void CAMERA_SplineHelpMove(struct Camera *camera); // 0x8001AF50

extern void CAMERA_SplineProcess(struct Camera *camera); // 0x8001B0C4

extern void CAMERA_ShakeCamera(struct Camera *camera); // 0x8001B418

extern void CAMERA_Process(struct Camera *camera); // 0x8001B504

extern void CAMERA_CenterCamera(struct Camera *camera); // 0x8001B750

extern void CAMERA_SetLookRot(struct Camera *camera, int x_rotation, int z_rotation); // 0x8001B838

extern void CAMERA_StartLookaroundMode(struct Camera *camera); // 0x8001B844

extern void CAMERA_StartSwimThrowMode(struct Camera *camera); // 0x8001B8D4

extern void CAMERA_EndSwimThrowMode(struct Camera *camera); // 0x8001B914

extern void CAMERA_ForceEndLookaroundMode(struct Camera *camera); // 0x8001B938

extern void CAMERA_Control(struct Camera *camera, struct _Instance *playerInstance); // 0x8001B974

extern void CAMERA_EndLook(struct Camera *camera); // 0x8001BEC4

extern void CAMERA_ChangeToUnderWater(struct Camera *camera, struct _Instance *instance); // 0x8001BF84

extern void CAMERA_ChangeToOutOfWater(struct Camera *camera, struct _Instance *instance); // 0x8001C030

extern void CAMERA_UpdateFocusDistance(struct Camera *camera); // 0x8001C0A4

extern void CAMERA_UpdateFocusTilt(struct Camera *camera); // 0x8001C174

extern void CAMERA_UpdateFocusRoll(struct Camera *camera); // 0x8001C240

extern void CAMERA_UpdateFocusRotate(struct Camera *camera); // 0x8001C35C

extern void CAMERA_UpdateFocusRotationX(struct Camera *camera, struct _Instance *focusInstance); // 0x8001C448

extern void CAMERA_FollowPlayerTilt(struct Camera *camera, struct _Instance *focusInstance); // 0x8001C6C0

extern void CAMERA_FollowGoBehindPlayerWithTimer(struct Camera *camera); // 0x8001C8B0

extern void CAMERA_FollowGoBehindPlayer(struct Camera *camera); // 0x8001C9AC

extern void CAMERA_CalculateLead(struct Camera *camera); // 0x8001C9E8

extern void CAMERA_CalcFollowPosition(struct Camera *camera, struct _Rotation *rotation); // 0x8001CB90

extern void CAMERA_SetupColInfo(struct Camera *camera, struct CameraCollisionInfo *colInfo, struct _Position *targetCamPos); // 0x8001CE84

extern void CAMERA_DoPanicCheck(struct Camera *camera, struct CameraCollisionInfo *tmpcolInfo, struct _Rotation *rotation, short *best_z, short *max_dist); // 0x8001CF44

extern void CAMERA_Panic(struct Camera *camera, short min_dist); // 0x8001D014

extern long CAMERA_DoCameraCollision2(struct Camera *camera, struct _Position *targetCamPos, int simpleflag); // 0x8001D1C4

extern int CAMERA_FocusInstanceMoved(struct Camera *camera); // 0x8001D7B4


#endif
