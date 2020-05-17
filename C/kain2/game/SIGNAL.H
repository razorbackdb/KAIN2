#ifndef SIGNAL_H
#define SIGNAL_H


extern long SIGNAL_HandleLightGroup(struct _Instance *instance, struct Signal *signal); // 0x8001DBF8

extern long SIGNAL_HandleCameraAdjust(struct _Instance *instance, struct Signal *signal); // 0x8001DC14

extern long SIGNAL_HandleCamera(struct _Instance *instance, struct Signal *signal); // 0x8001DC3C

extern void SIGNAL_RelocateCamera(struct Signal *signal, long offset); // 0x8001DC64

extern long SIGNAL_HandleCameraMode(struct _Instance *instance, struct Signal *signal); // 0x8001DC80

extern long SIGNAL_HandleCameraLock(struct _Instance *instance, struct Signal *signal); // 0x8001DCA8

extern long SIGNAL_HandleCameraUnlock(struct _Instance *instance, struct Signal *signal); // 0x8001DCD0

extern long SIGNAL_HandleCameraSmooth(struct _Instance *instance, struct Signal *signal); // 0x8001DCF8

extern long SIGNAL_HandleCameraTimer(struct _Instance *instance, struct Signal *signal); // 0x8001DD20

extern long SIGNAL_HandleCameraSave(struct _Instance *instance, struct Signal *signal); // 0x8001DD48

extern long SIGNAL_HandleCameraRestore(struct _Instance *instance, struct Signal *signal); // 0x8001DD70

extern long SIGNAL_HandleCameraValue(struct _Instance *instance, struct Signal *signal); // 0x8001DD98

extern long SIGNAL_HandleStreamLevel(struct _Instance *instance, struct Signal *signal); // 0x8001DDC8

extern long SIGNAL_HandleFogNear(struct _Instance *instance, struct Signal *signal); // 0x8001E024

extern long SIGNAL_HandleFogFar(struct _Instance *instance, struct Signal *signal); // 0x8001E078

extern long SIGNAL_HandleCameraShake(struct _Instance *instance, struct Signal *signal); // 0x8001E0D4

extern long SIGNAL_HandleCallSignal(struct _Instance *instance, struct Signal *signal); // 0x8001E104

extern long SIGNAL_HandleStopPlayerControl(struct _Instance *instance, struct Signal *signal); // 0x8001E12C

extern long SIGNAL_HandleStartPlayerControl(struct _Instance *instance, struct Signal *signal); // 0x8001E144

extern void SIGNAL_RelocateCameraSpline(struct Signal *signal, long offset); // 0x8001E164

extern long SIGNAL_HandleCameraSpline(struct _Instance *instance, struct Signal *signal); // 0x8001E180

extern long SIGNAL_HandleScreenWipe(struct _Instance *instance, struct Signal *signal); // 0x8001E200

extern long SIGNAL_HandleBlendStart(struct _Instance *instance, struct Signal *signal); // 0x8001E238

extern long SIGNAL_HandleScreenWipeColor(struct _Instance *instance, struct Signal *signal); // 0x8001E240

extern long SIGNAL_HandleSetSlideAngle(struct _Instance *instance, struct Signal *signal); // 0x8001E26C

extern long SIGNAL_HandleResetSlideAngle(struct _Instance *instance, struct Signal *signal); // 0x8001E29C

extern long SIGNAL_HandleSetCameraTilt(struct _Instance *instance, struct Signal *signal); // 0x8001E2C8

extern long SIGNAL_HandleSetCameraDistance(struct _Instance *instance, struct Signal *signal); // 0x8001E354

extern long SIGNAL_HandleEnd(struct _Instance *instance, struct Signal *signal); // 0x8001E384

extern void COLLIDE_HandleSignal(struct _Instance *instance, struct Signal *signal, long numSignals, int dontForceDoSignal); // 0x8001E38C

extern long SIGNAL_IsThisStreamAWarpGate(struct Signal *signal); // 0x8001E490

extern long SIGNAL_IsStreamSignal(struct Signal *signal, long *isWarpGate); // 0x8001E4F0

extern void SIGNAL_HandleSignal(struct _Instance *instance, struct Signal *signal, int dontForceDoSignal); // 0x8001E5C8

extern struct _MultiSignal * SIGNAL_RelocateSignal(struct _MultiSignal *multiSignal, long offset); // 0x8001E5EC

extern struct _MultiSignal * SIGNAL_FindSignal(struct Level *level, long id); // 0x8001E6C8

extern void SIGNAL_OutOfWater(struct _Instance *instance); // 0x8001E778

extern void SIGNAL_InWater(struct _Instance *instance); // 0x8001E7C8


#endif
