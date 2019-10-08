#ifndef SIGNAL_H
#define SIGNAL_H

extern long SIGNAL_HandleLightGroup(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleCameraAdjust(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleCamera(struct _Instance *instance, struct Signal *signal);

extern void SIGNAL_RelocateCamera(struct Signal *signal, long offset);

extern long SIGNAL_HandleCameraMode(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleCameraLock(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleCameraUnlock(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleCameraSmooth(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleCameraTimer(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleCameraSave(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleCameraRestore(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleCameraValue(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleStreamLevel(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleFogNear(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleFogFar(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleCameraShake(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleCallSignal(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleStopPlayerControl(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleStartPlayerControl(struct _Instance *instance, struct Signal *signal);

extern void SIGNAL_RelocateCameraSpline(struct Signal *signal, long offset);

extern long SIGNAL_HandleCameraSpline(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleScreenWipe(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleBlendStart(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleScreenWipeColor(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleSetSlideAngle(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleResetSlideAngle(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleSetCameraTilt(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleSetCameraDistance(struct _Instance *instance, struct Signal *signal);

extern long SIGNAL_HandleEnd(struct _Instance *instance, struct Signal *signal);

extern void COLLIDE_HandleSignal(struct _Instance *instance, struct Signal *signal, long numSignals, int dontForceDoSignal);

extern long SIGNAL_IsThisStreamAWarpGate(struct Signal *signal);

extern long SIGNAL_IsStreamSignal(struct Signal *signal, long *isWarpGate);

extern void SIGNAL_HandleSignal(struct _Instance *instance, struct Signal *signal, int dontForceDoSignal);

extern struct _MultiSignal *SIGNAL_RelocateSignal(struct _MultiSignal *multiSignal, long offset);

extern struct _MultiSignal *SIGNAL_FindSignal(struct Level *level, long id);

extern void SIGNAL_OutOfWater(struct _Instance *instance);

extern void SIGNAL_InWater(struct _Instance *instance);

#endif
