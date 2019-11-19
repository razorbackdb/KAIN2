#ifndef SIGNAL_H
#define SIGNAL_H


extern long SIGNAL_HandleLightGroup(struct _Instance *instance, struct Signal *signal); // 0x8001DC68

extern long SIGNAL_HandleCameraAdjust(struct _Instance *instance, struct Signal *signal); // 0x8001DC84

extern long SIGNAL_HandleCamera(struct _Instance *instance, struct Signal *signal); // 0x8001DCB0

extern void SIGNAL_RelocateCamera(struct Signal *signal, long offset); // 0x8001DCDC

extern long SIGNAL_HandleCameraMode(struct _Instance *instance, struct Signal *signal); // 0x8001DCF8

extern long SIGNAL_HandleCameraLock(struct _Instance *instance, struct Signal *signal); // 0x8001DD24

extern long SIGNAL_HandleCameraUnlock(struct _Instance *instance, struct Signal *signal); // 0x8001DD50

extern long SIGNAL_HandleCameraSmooth(struct _Instance *instance, struct Signal *signal); // 0x8001DD7C

extern long SIGNAL_HandleCameraTimer(struct _Instance *instance, struct Signal *signal); // 0x8001DDA8

extern long SIGNAL_HandleCameraSave(struct _Instance *instance, struct Signal *signal); // 0x8001DDD4

extern long SIGNAL_HandleCameraRestore(struct _Instance *instance, struct Signal *signal); // 0x8001DE00

extern long SIGNAL_HandleCameraValue(struct _Instance *instance, struct Signal *signal); // 0x8001DE2C

extern long SIGNAL_HandleStreamLevel(struct _Instance *instance, struct Signal *signal); // 0x8001DE60

extern long SIGNAL_HandleFogNear(struct _Instance *instance, struct Signal *signal); // 0x8001E0A8

extern long SIGNAL_HandleFogFar(struct _Instance *instance, struct Signal *signal); // 0x8001E0FC

extern long SIGNAL_HandleCameraShake(struct _Instance *instance, struct Signal *signal); // 0x8001E158

extern long SIGNAL_HandleCallSignal(struct _Instance *instance, struct Signal *signal); // 0x8001E18C

extern long SIGNAL_HandleStopPlayerControl(struct _Instance *instance, struct Signal *signal); // 0x8001E1B4

extern long SIGNAL_HandleStartPlayerControl(struct _Instance *instance, struct Signal *signal); // 0x8001E1CC

extern void SIGNAL_RelocateCameraSpline(struct Signal *signal, long offset); // 0x8001E1EC

extern long SIGNAL_HandleCameraSpline(struct _Instance *instance, struct Signal *signal); // 0x8001E208

extern long SIGNAL_HandleScreenWipe(struct _Instance *instance, struct Signal *signal); // 0x8001E288

extern long SIGNAL_HandleBlendStart(struct _Instance *instance, struct Signal *signal); // 0x8001E2C0

extern long SIGNAL_HandleScreenWipeColor(struct _Instance *instance, struct Signal *signal); // 0x8001E2C8

extern long SIGNAL_HandleSetSlideAngle(struct _Instance *instance, struct Signal *signal); // 0x8001E2F4

extern long SIGNAL_HandleResetSlideAngle(struct _Instance *instance, struct Signal *signal); // 0x8001E324

extern long SIGNAL_HandleSetCameraTilt(struct _Instance *instance, struct Signal *signal); // 0x8001E350

extern long SIGNAL_HandleSetCameraDistance(struct _Instance *instance, struct Signal *signal); // 0x8001E3E0

extern long SIGNAL_ErrorNoFunction(struct _Instance *instance, struct Signal *signal); // 0x8001E414

extern long SIGNAL_HandleEnd(struct _Instance *instance, struct Signal *signal); // 0x8001E448

extern void COLLIDE_HandleSignal(struct _Instance *instance, struct Signal *signal, long numSignals, int dontForceDoSignal); // 0x8001E450

extern long SIGNAL_IsThisStreamAWarpGate(struct Signal *signal); // 0x8001E544

extern long SIGNAL_IsStreamSignal(struct Signal *signal, long *isWarpGate); // 0x8001E5A4

extern void SIGNAL_HandleSignal(struct _Instance *instance, struct Signal *signal, int dontForceDoSignal); // 0x8001E684

extern struct _MultiSignal * SIGNAL_RelocateSignal(struct _MultiSignal *multiSignal, long offset); // 0x8001E6A8

extern struct _MultiSignal * SIGNAL_FindSignal(struct Level *level, long id); // 0x8001E788

extern void SIGNAL_OutOfWater(struct _Instance *instance); // 0x8001E83C

extern void SIGNAL_InWater(struct _Instance *instance); // 0x8001E88C


#endif
