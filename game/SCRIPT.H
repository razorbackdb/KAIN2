#ifndef SCRIPT_H
#define SCRIPT_H


extern void SCRIPT_CombineEulerAngles(struct _Rotation *combinedRotation, struct _Rotation *inputRotation1, struct _Rotation *inputRotation2); // 0x8003D93C

extern void SCRIPT_InstanceSplineInit(struct _Instance *instance); // 0x8003D9BC

extern short SCRIPTCountFramesInSpline(struct _Instance *instance); // 0x8003DC0C

extern struct Spline * ScriptGetPosSpline(struct _Instance *instance); // 0x8003DD5C

extern struct RSpline * ScriptGetRotSpline(struct _Instance *instance); // 0x8003DD94

extern int SCRIPT_GetSplineFrameNumber(struct _Instance *instance, struct SplineDef *splineDef); // 0x8003DDCC

extern struct MultiSpline * SCRIPT_GetMultiSpline(struct _Instance *instance, unsigned long *isParent, unsigned long *isClass); // 0x8003DE2C

extern struct SplineDef * SCRIPT_GetPosSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003DED8

extern struct SplineDef * SCRIPT_GetRotSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003DF04

extern struct SplineDef * SCRIPT_GetScaleSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003DF30

extern void SCRIPT_RelativisticSpline(struct _Instance *instance, struct _SVector *point); // 0x8003DF5C

extern void SCRIPT_InstanceSplineSet(struct _Instance *instance, short frameNum, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef); // 0x8003E14C

extern long SCRIPT_SplineProcess(struct _Instance *instance, struct MultiSpline *multi, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef, int direction, int isClass); // 0x8003E424

extern long SCRIPT_InstanceSplineProcess(struct _Instance *instance, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef, int direction); // 0x8003E70C

extern void SCRIPT_FadeOutProcess(struct _Instance *instance); // 0x8003E814

extern void ScriptKillInstance(struct _Instance *instance, int effect); // 0x8003E85C


#endif
