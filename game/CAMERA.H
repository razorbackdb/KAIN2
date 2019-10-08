#ifndef CAMERA_H
#define CAMERA_H

extern void CAMERA_CalculateViewVolumeNormals(struct Camera *camera);

extern void CAMERA_CalcVVClipInfo(struct Camera *camera);

extern void CAMERA_SetViewVolume(struct Camera *camera);

extern void CAMERA_SetProjDistance(struct Camera *camera, long distance);

extern void CAMERA_CreateNewFocuspoint(struct Camera *camera);

extern void CAMERA_SaveMode(struct Camera *camera, long mode);

extern void CAMERA_RestoreMode(struct Camera *camera);

extern void CAMERA_Save(struct Camera *camera, long save);

extern void CAMERA_Restore(struct Camera *camera, long restore);

extern struct _SVector *SplineGetNextPointDC(struct Spline *spline, struct SplineDef *def);

extern void CAMERA_SetMode(struct Camera *camera, long mode);

extern void CAMERA_Initialize(struct Camera *camera);

extern void CAMERA_SetInstanceFocus(struct Camera *camera, struct _Instance *instance);

extern void CAMERA_SetZRotation(struct Camera *camera, short zrot);

extern long CAMERA_LengthSVector(struct _SVector *sv);

extern void CAMERA_SetValue(struct Camera *camera, long index, long value);

extern short CAMERA_AngleDifference(short angle0, short angle1);

extern short CAMERA_SignedAngleDifference(short angle0, short angle1);

extern unsigned long CAMERA_QueryMode(struct Camera *camera);

extern void CAMERA_SetMaxVel(struct Camera *camera);

extern void CAMERA_SetTarget(struct Camera *camera, struct _Position *pos);

extern void CAMERA_CalcPosition(struct _Position *position, struct _Position *base, struct _Rotation *rotation, short distance);

extern void CAMERA_SetFocus(struct Camera *camera, struct _Position *targetfocusPoint);

extern void CAMERA_Lock(struct Camera *camera, long lock);

extern void CAMERA_Unlock(struct Camera *camera, long unlock);

extern void CAMERA_SetSmoothValue(struct Camera *camera, long smooth);

extern void CAMERA_SetTimer(struct Camera *camera, long time);

extern void CAMERA_Adjust_tilt(struct Camera *camera, long tilt);

extern void CAMERA_Adjust_distance(struct Camera *camera, long dist);

extern void CAMERA_Adjust_rotation(struct Camera *camera, long rotation);

extern void CAMERA_Adjust_roll(long roll_degrees, int frames);

extern void CAMERA_Adjust(struct Camera *camera, long adjust);

extern void CAMERA_ChangeTo(struct Camera *camera, struct _CameraKey *cameraKey);

extern void CAMERA_SetShake(struct Camera *camera, long shake, long scale);

extern void Decouple_AngleMoveToward(short *current_ptr, short destination, short step);

extern void CriticalDampValue(long dampMode, short *sourceVal, short targetVal, short *vel, short *accl, int smooth);

extern void CriticalDampPosition(long dampMode, struct _Position *position, struct _Position *targetPos, struct _SVector *vel, struct _SVector *accl, int smooth);

extern void CriticalDampAngle(long dampMode, short *currentVal, short target, short *vel, short *accl, int smooth);

extern short CAMERA_CalcZRotation(struct _Position *target, struct _Position *position);

extern void CAMERA_CalcRotation(struct _Rotation *rotation, struct _Position *target, struct _Position *position);

extern void CAMERA_CalcFSRotation(struct Camera *camera, struct _Rotation *rotation, struct _Position *target, struct _Position *position);

extern void CAMERA_Relocate(struct Camera *camera, struct _SVector *offset, int streamSignalFlag);

extern struct _TFace *CAMERA_SphereToSphereWithLines(struct Camera *camera, struct CameraCollisionInfo *colInfo, int secondcheck_flag);

extern long CAMERA_CalcTilt(struct _Normal *normal, short zRot);

extern void CAMERA_SetLookFocusAndBase(struct _Instance *focusInstance, struct _Position *focusPoint);

extern void CAMERA_SetLookFocusAndDistance(struct Camera *camera, struct VECTOR *focuspoint, int distance);

extern void CAMERA_LookProcess(struct Camera *camera);

extern void CAMERA_Normalize(struct _SVector *svector);

extern void CAMERA_HandleTransitions(struct Camera *camera);

extern void CAMERA_CalcFocusOffset(struct _SVector *offset, struct Camera *camera);

extern void CAMERA_CalcFocusOffsetForSwim(struct _SVector *offset, struct Camera *camera);

extern short CAMERA_CalcIntersectAngle(struct _SVector *linept, struct _SVector *vertex0, struct _SVector *vertex1, short *high, short *low);

extern short CAMERA_GetLineAngle(struct Camera *camera, struct CameraCollisionInfo *colInfo, struct _SVector *linept, int line);

extern long CAMERA_ACForcedMovement(struct Camera *camera, struct CameraCollisionInfo *colInfo);

extern void CAMERA_update_dist_debounced(struct Camera *camera, short dist);

extern short CAMERA_dampgetline(short angle);

extern long CAMERA_ACNoForcedMovement(struct Camera *camera, struct CameraCollisionInfo *colInfo);

extern long CAMERA_AbsoluteCollision(struct Camera *camera, struct CameraCollisionInfo *colInfo);

extern short CAMERA_update_z_damped(struct Camera *camera, short current, short target);

extern void CAMERA_CombatCamDist(struct Camera *camera);

extern void CAMERA_GenericCameraProcess(struct Camera *camera);

extern void CAMERA_CinematicProcess(struct Camera *camera);

extern int CAMERA_GetDistSq(struct _SVector *point1, struct _SVector *point2);

extern void CAMERA_NearestPointOnLineVec(struct _SVector *linePoint, struct _SVector *start, struct _SVector *line, struct _Position *point);

extern int CAMERA_CheckPoint(int linePoint, int linept1, int linept2);

extern int CAMERA_CheckIfPointOnLine(struct _SVector *linePoint, struct _SVector *linept1, struct _SVector *linept2);

extern int CAMERA_FindLinePoint(struct _Position *point, struct _SVector *linept1, struct _SVector *linept2, int target_dist_sq, struct _SVector *results);

extern void CAMERA_SplineGetNearestPoint2(struct Camera *camera, struct Spline *spline, struct _SVector *point, int *currkey, struct _SVector *ret_dpoint);

extern void CAMERA_SplineGetNearestPoint(struct Spline *spline, struct _SVector *point, int *currkey, struct _SVector *ret_dpoint);

extern void CAMERA_SplineHelpMove(struct Camera *camera);

extern void CAMERA_SplineProcess(struct Camera *camera);

extern void CAMERA_ShakeCamera(struct Camera *camera);

extern void CAMERA_Process(struct Camera *camera);

extern void CAMERA_CenterCamera(struct Camera *camera);

extern void CAMERA_SetLookRot(struct Camera *camera, int x_rotation, int z_rotation);

extern void CAMERA_StartLookaroundMode(struct Camera *camera);

extern void CAMERA_StartSwimThrowMode(struct Camera *camera);

extern void CAMERA_EndSwimThrowMode(struct Camera *camera);

extern void CAMERA_ForceEndLookaroundMode(struct Camera *camera);

extern void CAMERA_Control(struct Camera *camera, struct _Instance *playerInstance);

extern void CAMERA_EndLook(struct Camera *camera);

extern void CAMERA_ChangeToUnderWater(struct Camera *camera, struct _Instance *instance);

extern void CAMERA_ChangeToOutOfWater(struct Camera *camera, struct _Instance *instance);

extern void CAMERA_UpdateFocusDistance(struct Camera *camera);

extern void CAMERA_UpdateFocusTilt(struct Camera *camera);

extern void CAMERA_UpdateFocusRoll(struct Camera *camera);

extern void CAMERA_UpdateFocusRotate(struct Camera *camera);

extern void CAMERA_UpdateFocusRotationX(struct Camera *camera, struct _Instance *focusInstance);

extern void CAMERA_FollowPlayerTilt(struct Camera *camera, struct _Instance *focusInstance);

extern void CAMERA_FollowGoBehindPlayerWithTimer(struct Camera *camera);

extern void CAMERA_FollowGoBehindPlayer(struct Camera *camera);

extern void CAMERA_CalculateLead(struct Camera *camera);

extern void CAMERA_CalcFollowPosition(struct Camera *camera, struct _Rotation *rotation);

extern void CAMERA_SetupColInfo(struct Camera *camera, struct CameraCollisionInfo *colInfo, struct _Position *targetCamPos);

extern void CAMERA_DoPanicCheck(struct Camera *camera, struct CameraCollisionInfo *tmpcolInfo, struct _Rotation *rotation, short *best_z, short *max_dist);

extern void CAMERA_Panic(struct Camera *camera, short min_dist);

extern long CAMERA_DoCameraCollision2(struct Camera *camera, struct _Position *targetCamPos, int simpleflag);

extern int CAMERA_FocusInstanceMoved(struct Camera *camera);

#endif
