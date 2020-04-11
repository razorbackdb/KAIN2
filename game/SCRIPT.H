#ifndef SCRIPT_H
#define SCRIPT_H


extern void SCRIPT_CombineEulerAngles(struct _Rotation *combinedRotation, struct _Rotation *inputRotation1, struct _Rotation *inputRotation2); // 0x8003D214

extern void SCRIPT_InstanceSplineInit(struct _Instance *instance); // 0x8003D294

extern short SCRIPTCountFramesInSpline(struct _Instance *instance); // 0x8003D4E4

extern struct Spline * ScriptGetPosSpline(struct _Instance *instance); // 0x8003D634

extern struct RSpline * ScriptGetRotSpline(struct _Instance *instance); // 0x8003D66C

extern int SCRIPT_GetSplineFrameNumber(struct _Instance *instance, struct SplineDef *splineDef); // 0x8003D6A4

extern struct MultiSpline * SCRIPT_GetMultiSpline(struct _Instance *instance, unsigned long *isParent, unsigned long *isClass); // 0x8003D704

extern struct SplineDef * SCRIPT_GetPosSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003D7B0

extern struct SplineDef * SCRIPT_GetRotSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003D7DC

extern struct SplineDef * SCRIPT_GetScaleSplineDef(struct _Instance *instance, struct MultiSpline *multi, unsigned long isParent, unsigned long isClass); // 0x8003D808

extern void SCRIPT_RelativisticSpline(struct _Instance *instance, struct _SVector *point); // 0x8003D834

extern void SCRIPT_InstanceSplineSet(struct _Instance *instance, short frameNum, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef); // 0x8003DA24

extern long SCRIPT_SplineProcess(struct _Instance *instance, struct MultiSpline *multi, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef, int direction, int isClass); // 0x8003DCFC

extern long SCRIPT_InstanceSplineProcess(struct _Instance *instance, struct SplineDef *splineDef, struct SplineDef *rsplineDef, struct SplineDef *ssplineDef, int direction); // 0x8003DFE4

extern void SCRIPT_FadeOutProcess(struct _Instance *instance); // 0x8003E0EC

extern void ScriptKillInstance(struct _Instance *instance, int effect); // 0x8003E134


#endif
