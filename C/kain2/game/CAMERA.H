#ifndef CAMERA_H
#define CAMERA_H


extern void CAMERA_CalculateViewVolumeNormals(struct Camera *camera); // 0x80014AA4

extern void CAMERA_CalcVVClipInfo(struct Camera *camera); // 0x80014DE0

extern void CAMERA_SetViewVolume(struct Camera *camera); // 0x80014F00

extern void CAMERA_SetProjDistance(struct Camera *camera, long distance); // 0x80014F2C

extern void CAMERA_CreateNewFocuspoint(struct Camera *camera); // 0x80014FD0

extern void CAMERA_SaveMode(struct Camera *camera, long mode); // 0x80015074

extern void CAMERA_RestoreMode(struct Camera *camera); // 0x800153AC

extern void CAMERA_Save(struct Camera *camera, long save); // 0x80015854

extern void CAMERA_Restore(struct Camera *camera, long restore); // 0x80015924

extern struct _SVector * SplineGetNextPointDC(struct Spline *spline, struct SplineDef *def); // 0x800159E0

extern void CAMERA_SetMode(struct Camera *camera, long mode); // 0x80015A3C

extern void CAMERA_Initialize(struct Camera *camera); // 0x80015EEC

extern void CAMERA_SetInstanceFocus(struct Camera *camera, struct _Instance *instance); // 0x800161EC

extern void CAMERA_SetZRotation(struct Camera *camera, short zrot); // 0x8001624C

extern long CAMERA_LengthSVector(struct _SVector *sv); // 0x80016270

extern void CAMERA_SetValue(struct Camera *camera, long index, long value); // 0x800162C4

extern short CAMERA_AngleDifference(short angle0, short angle1); // 0x800166F0

extern short CAMERA_SignedAngleDifference(short angle0, short angle1); // 0x80016768

extern unsigned long CAMERA_QueryMode(struct Camera *camera); // 0x80016798

extern void CAMERA_SetMaxVel(struct Camera *camera); // 0x80016834

extern void CAMERA_SetTarget(struct Camera *camera, struct _Position *pos); // 0x80016940

extern void CAMERA_CalcPosition(struct _Position *position, struct _Position *base, struct _Rotation *rotation, short distance); // 0x800169BC

extern void CAMERA_SetFocus(struct Camera *camera, struct _Position *targetfocusPoint); // 0x80016AE4

extern void CAMERA_Lock(struct Camera *camera, long lock); // 0x80016D60

extern void CAMERA_Unlock(struct Camera *camera, long unlock); // 0x80016D74

extern void CAMERA_SetSmoothValue(struct Camera *camera, long smooth); // 0x80016D88

extern void CAMERA_SetTimer(struct Camera *camera, long time); // 0x80016DD8

extern void CAMERA_Adjust_tilt(struct Camera *camera, long tilt); // 0x80016DF8

extern void CAMERA_Adjust_distance(struct Camera *camera, long dist); // 0x80016E34

extern void CAMERA_Adjust_rotation(struct Camera *camera, long rotation); // 0x80016EB0

extern void CAMERA_Adjust_roll(long roll_degrees, int frames); // 0x80016F34

extern void CAMERA_Adjust(struct Camera *camera, long adjust); // 0x80016FB8

extern void CAMERA_ChangeTo(struct Camera *camera, struct _CameraKey *cameraKey); // 0x80017078

extern void CAMERA_SetShake(struct Camera *camera, long shake, long scale); // 0x80017080

extern void Decouple_AngleMoveToward(short *current_ptr, short destination, short step); // 0x80017130

extern void CriticalDampValue(long dampMode, short *sourceVal, short targetVal, short *vel, short *accl, int smooth); // 0x80017180

extern void CriticalDampPosition(long dampMode, struct _Position *position, struct _Position *targetPos, struct _SVector *vel, struct _SVector *accl, int smooth); // 0x80017334

extern void CriticalDampAngle(long dampMode, short *currentVal, short target, short *vel, short *accl, int smooth); // 0x800179F8

extern short CAMERA_CalcZRotation(struct _Position *target, struct _Position *position); // 0x80017A98

extern void CAMERA_CalcRotation(struct _Rotation *rotation, struct _Position *target, struct _Position *position); // 0x80017B10

extern void CAMERA_CalcFSRotation(struct Camera *camera, struct _Rotation *rotation, struct _Position *target, struct _Position *position); // 0x80017BAC

extern void CAMERA_Relocate(struct Camera *camera, struct _SVector *offset, int streamSignalFlag); // 0x80017C58

extern struct _TFace * CAMERA_SphereToSphereWithLines(struct Camera *camera, struct CameraCollisionInfo *colInfo, int secondcheck_flag); // 0x80017DA4

extern long CAMERA_CalcTilt(struct _Normal *normal, short zRot); // 0x800188E0

extern void CAMERA_SetLookFocusAndBase(struct _Instance *focusInstance, struct _Position *focusPoint); // 0x80018954

extern void CAMERA_SetLookFocusAndDistance(struct Camera *camera, struct VECTOR *focuspoint, int distance); // 0x8001899C

extern void CAMERA_LookProcess(struct Camera *camera); // 0x800189C4

extern void CAMERA_Normalize(struct _SVector *svector); // 0x80018C18

extern void CAMERA_HandleTransitions(struct Camera *camera); // 0x80018C90

extern void CAMERA_CalcFocusOffset(struct _SVector *offset, struct Camera *camera); // 0x80018E44

extern void CAMERA_CalcFocusOffsetForSwim(struct _SVector *offset, struct Camera *camera); // 0x80018EF8

extern short CAMERA_CalcIntersectAngle(struct _SVector *linept, struct _SVector *vertex0, struct _SVector *vertex1, short *high, short *low); // 0x80018F64

extern short CAMERA_GetLineAngle(struct Camera *camera, struct CameraCollisionInfo *colInfo, struct _SVector *linept, int line); // 0x80019054

extern long CAMERA_ACForcedMovement(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x8001921C

extern void CAMERA_update_dist_debounced(struct Camera *camera, short dist); // 0x800192EC

extern short CAMERA_dampgetline(short angle); // 0x8001935C

extern long CAMERA_ACNoForcedMovement(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x80019408

extern long CAMERA_AbsoluteCollision(struct Camera *camera, struct CameraCollisionInfo *colInfo); // 0x8001990C

extern short CAMERA_update_z_damped(struct Camera *camera, short current, short target); // 0x80019A34

extern void CAMERA_CombatCamDist(struct Camera *camera); // 0x80019CA4

extern void CAMERA_GenericCameraProcess(struct Camera *camera); // 0x80019F68

extern void CAMERA_CinematicProcess(struct Camera *camera); // 0x8001A3E4

extern int CAMERA_GetDistSq(struct _SVector *point1, struct _SVector *point2); // 0x8001A900

extern void CAMERA_NearestPointOnLineVec(struct _SVector *linePoint, struct _SVector *start, struct _SVector *line, struct _Position *point); // 0x8001A97C

extern int CAMERA_CheckPoint(int linePoint, int linept1, int linept2); // 0x8001AAA8

extern int CAMERA_CheckIfPointOnLine(struct _SVector *linePoint, struct _SVector *linept1, struct _SVector *linept2); // 0x8001AAEC

extern int CAMERA_FindLinePoint(struct _Position *point, struct _SVector *linept1, struct _SVector *linept2, int target_dist_sq, struct _SVector *results); // 0x8001AB7C

extern void CAMERA_SplineGetNearestPoint2(struct Camera *camera, struct Spline *spline, struct _SVector *point, int *currkey, struct _SVector *ret_dpoint); // 0x8001AD40

extern void CAMERA_SplineGetNearestPoint(struct Spline *spline, struct _SVector *point, int *currkey, struct _SVector *ret_dpoint); // 0x8001AF28

extern void CAMERA_SplineHelpMove(struct Camera *camera); // 0x8001B2C0

extern void CAMERA_SplineProcess(struct Camera *camera); // 0x8001B430

extern void CAMERA_ShakeCamera(struct Camera *camera); // 0x8001B784

extern void CAMERA_Process(struct Camera *camera); // 0x8001B86C

extern void CAMERA_CenterCamera(struct Camera *camera); // 0x8001BAB8

extern void CAMERA_SetLookRot(struct Camera *camera, int x_rotation, int z_rotation); // 0x8001BBA0

extern void CAMERA_StartLookaroundMode(struct Camera *camera); // 0x8001BBAC

extern void CAMERA_StartSwimThrowMode(struct Camera *camera); // 0x8001BC3C

extern void CAMERA_EndSwimThrowMode(struct Camera *camera); // 0x8001BC7C

extern void CAMERA_ForceEndLookaroundMode(struct Camera *camera); // 0x8001BCA0

extern void CAMERA_Control(struct Camera *camera, struct _Instance *playerInstance); // 0x8001BCDC

extern void CAMERA_EndLook(struct Camera *camera); // 0x8001C224

extern void CAMERA_ChangeToUnderWater(struct Camera *camera, struct _Instance *instance); // 0x8001C318

extern void CAMERA_ChangeToOutOfWater(struct Camera *camera, struct _Instance *instance); // 0x8001C3C4

extern void CAMERA_UpdateFocusDistance(struct Camera *camera); // 0x8001C438

extern void CAMERA_UpdateFocusTilt(struct Camera *camera); // 0x8001C508

extern void CAMERA_UpdateFocusRoll(struct Camera *camera); // 0x8001C5D4

extern void CAMERA_UpdateFocusRotate(struct Camera *camera); // 0x8001C6F0

extern void CAMERA_UpdateFocusRotationX(struct Camera *camera, struct _Instance *focusInstance); // 0x8001C7DC

extern void CAMERA_FollowPlayerTilt(struct Camera *camera, struct _Instance *focusInstance); // 0x8001CA58

extern void CAMERA_FollowGoBehindPlayerWithTimer(struct Camera *camera); // 0x8001CC68

extern void CAMERA_FollowGoBehindPlayer(struct Camera *camera); // 0x8001CD64

extern void CAMERA_CalculateLead(struct Camera *camera); // 0x8001CDA0

extern void CAMERA_CalcFollowPosition(struct Camera *camera, struct _Rotation *rotation); // 0x8001CF48

extern void CAMERA_SetupColInfo(struct Camera *camera, struct CameraCollisionInfo *colInfo, struct _Position *targetCamPos); // 0x8001D244

extern void CAMERA_DoPanicCheck(struct Camera *camera, struct CameraCollisionInfo *tmpcolInfo, struct _Rotation *rotation, short *best_z, short *max_dist); // 0x8001D304

extern void CAMERA_Panic(struct Camera *camera, short min_dist); // 0x8001D3D4

extern long CAMERA_DoCameraCollision2(struct Camera *camera, struct _Position *targetCamPos, int simpleflag); // 0x8001D584

extern int CAMERA_FocusInstanceMoved(struct Camera *camera); // 0x8001DB88


#endif
