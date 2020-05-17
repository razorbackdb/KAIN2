#ifndef SCRIPT_H
#define SCRIPT_H


extern void SCRIPT_CombineEulerAngles(struct _Rotation *combinedRotation, struct _Rotation *inputRotation1, struct _Rotation *inputRotation2); // 0x8003CCBC

extern void SCRIPT_InstanceSplineInit(struct _Instance *instance); // 0x8003CD3C

extern short SCRIPTCountFramesInSpline(struct _Instance *instance); // 0x8003CF8C

extern struct Spline * ScriptGetPosSpline(struct _Instance *instance); // 0x8003D0DC

extern struct RSpline * ScriptGetRotSpline(struct _Instance *instance); // 0x8003D114

extern int SCRIPT_GetSplineFrameNumber(struct _Instance *instance, struct SplineDef *splineDef); // 0x8003D14C

extern struct MultiSpline * SCRIPT_GetMultiSpline(struct _Instance *instance, unsigned long *isParent, unsigned long *isClass); // 0x8003D1AC

extern struct SplineDef * SCRIPT_GetPosSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003D258

extern struct SplineDef * SCRIPT_GetRotSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003D284

extern struct SplineDef * SCRIPT_GetScaleSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003D2B0

extern void SCRIPT_RelativisticSpline(struct _Instance *instance, struct _SVector *point); // 0x8003D2DC

extern void SCRIPT_InstanceSplineSet(struct _Instance *instance, short frameNum, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef); // 0x8003D4CC

extern long SCRIPT_SplineProcess(struct _Instance *instance, struct MultiSpline *multi, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef, int direction, int isClass); // 0x8003D7A4

extern long SCRIPT_InstanceSplineProcess(struct _Instance *instance, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef, int direction); // 0x8003DA8C

extern void SCRIPT_FadeOutProcess(struct _Instance *instance); // 0x8003DB94

extern void ScriptKillInstance(struct _Instance *instance, int effect); // 0x8003DBDC


#endif
