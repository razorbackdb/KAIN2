#ifndef SIGNAL_H
#define SIGNAL_H


extern long SIGNAL_HandleLightGroup(struct _Instance *instance, struct Signal *signal); // 0x8001D824

extern long SIGNAL_HandleCameraAdjust(struct _Instance *instance, struct Signal *signal); // 0x8001D840

extern long SIGNAL_HandleCamera(struct _Instance *instance, struct Signal *signal); // 0x8001D86C

extern void SIGNAL_RelocateCamera(struct Signal *signal, long offset); // 0x8001D898

extern long SIGNAL_HandleCameraMode(struct _Instance *instance, struct Signal *signal); // 0x8001D8B4

extern long SIGNAL_HandleCameraLock(struct _Instance *instance, struct Signal *signal); // 0x8001D8E0

extern long SIGNAL_HandleCameraUnlock(struct _Instance *instance, struct Signal *signal); // 0x8001D90C

extern long SIGNAL_HandleCameraSmooth(struct _Instance *instance, struct Signal *signal); // 0x8001D938

extern long SIGNAL_HandleCameraTimer(struct _Instance *instance, struct Signal *signal); // 0x8001D964

extern long SIGNAL_HandleCameraSave(struct _Instance *instance, struct Signal *signal); // 0x8001D990

extern long SIGNAL_HandleCameraRestore(struct _Instance *instance, struct Signal *signal); // 0x8001D9BC

extern long SIGNAL_HandleCameraValue(struct _Instance *instance, struct Signal *signal); // 0x8001D9E8

extern long SIGNAL_HandleStreamLevel(struct _Instance *instance, struct Signal *signal); // 0x8001DA1C

extern long SIGNAL_HandleFogNear(struct _Instance *instance, struct Signal *signal); // 0x8001DC7C

extern long SIGNAL_HandleFogFar(struct _Instance *instance, struct Signal *signal); // 0x8001DCD0

extern long SIGNAL_HandleCameraShake(struct _Instance *instance, struct Signal *signal); // 0x8001DD2C

extern long SIGNAL_HandleCallSignal(struct _Instance *instance, struct Signal *signal); // 0x8001DD60

extern long SIGNAL_HandleStopPlayerControl(struct _Instance *instance, struct Signal *signal); // 0x8001DD88

extern long SIGNAL_HandleStartPlayerControl(struct _Instance *instance, struct Signal *signal); // 0x8001DDA0

extern void SIGNAL_RelocateCameraSpline(struct Signal *signal, long offset); // 0x8001DDC0

extern long SIGNAL_HandleCameraSpline(struct _Instance *instance, struct Signal *signal); // 0x8001DDDC

extern long SIGNAL_HandleScreenWipe(struct _Instance *instance, struct Signal *signal); // 0x8001DE5C

extern long SIGNAL_HandleBlendStart(struct _Instance *instance, struct Signal *signal); // 0x8001DE94

extern long SIGNAL_HandleScreenWipeColor(struct _Instance *instance, struct Signal *signal); // 0x8001DE9C

extern long SIGNAL_HandleSetSlideAngle(struct _Instance *instance, struct Signal *signal); // 0x8001DEC8

extern long SIGNAL_HandleResetSlideAngle(struct _Instance *instance, struct Signal *signal); // 0x8001DEF8

extern long SIGNAL_HandleSetCameraTilt(struct _Instance *instance, struct Signal *signal); // 0x8001DF24

extern long SIGNAL_HandleSetCameraDistance(struct _Instance *instance, struct Signal *signal); // 0x8001DFB4

extern long SIGNAL_HandleEnd(struct _Instance *instance, struct Signal *signal); // 0x8001DFE8

extern void COLLIDE_HandleSignal(struct _Instance *instance, struct Signal *signal, long numSignals, int dontForceDoSignal); // 0x8001DFF0

extern long SIGNAL_IsThisStreamAWarpGate(struct Signal *signal); // 0x8001E0F8

extern long SIGNAL_IsStreamSignal(struct Signal *signal, long *isWarpGate); // 0x8001E158

extern void SIGNAL_HandleSignal(struct _Instance *instance, struct Signal *signal, int dontForceDoSignal); // 0x8001E234

extern struct _MultiSignal * SIGNAL_RelocateSignal(struct _MultiSignal *multiSignal, long offset); // 0x8001E258

extern struct _MultiSignal * SIGNAL_FindSignal(struct Level *level, long id); // 0x8001E338

extern void SIGNAL_OutOfWater(struct _Instance *instance); // 0x8001E3EC

extern void SIGNAL_InWater(struct _Instance *instance); // 0x8001E43C


#endif
