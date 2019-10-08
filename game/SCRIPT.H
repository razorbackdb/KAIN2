#ifndef SCRIPT_H
#define SCRIPT_H

extern void SCRIPT_CombineEulerAngles(struct _Rotation *combinedRotation, struct _Rotation *inputRotation1, struct _Rotation *inputRotation2);

extern void SCRIPT_InstanceSplineInit(struct _Instance *instance);

extern short SCRIPTCountFramesInSpline(struct _Instance *instance);

extern struct Spline *ScriptGetPosSpline(struct _Instance *instance);

extern struct RSpline *ScriptGetRotSpline(struct _Instance *instance);

extern int SCRIPT_GetSplineFrameNumber(struct _Instance *instance, struct SplineDef *splineDef);

extern struct MultiSpline *SCRIPT_GetMultiSpline(struct _Instance *instance, unsigned long *isParent, unsigned long *isClass);

extern struct SplineDef *SCRIPT_GetPosSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass);

extern struct SplineDef *SCRIPT_GetRotSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass);

extern struct SplineDef *SCRIPT_GetScaleSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass);

extern void SCRIPT_RelativisticSpline(struct _Instance *instance, struct _SVector *point);

extern void SCRIPT_InstanceSplineSet(struct _Instance *instance, short frameNum, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef);

extern long SCRIPT_SplineProcess(struct _Instance *instance, struct MultiSpline *multi, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef, int direction, int isClass);

extern long SCRIPT_InstanceSplineProcess(struct _Instance *instance, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef, int direction);

extern void SCRIPT_FadeOutProcess(struct _Instance *instance);

extern void ScriptKillInstance(struct _Instance *instance, int effect);

#endif
