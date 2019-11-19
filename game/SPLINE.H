#ifndef SPLINE_H
#define SPLINE_H


extern void _SplineS2Pos(struct vecS *p, long s, struct SplineKey *key, struct SplineKey *key2); // 0x80042178

extern void SplineSetDefDenom(struct Spline *spline, struct SplineDef *def, int denomFlag); // 0x800422E8

extern unsigned short SplineGetFrameNumber(struct Spline *spline, struct SplineDef *def); // 0x800423AC

extern short SplineSetDef2FrameNumber(struct Spline *spline, struct SplineDef *def, unsigned short frame_number); // 0x80042440

extern short SplineIsWhere(struct Spline *spline, struct SplineDef *def); // 0x80042570

extern short SplineMultiIsWhere(struct MultiSpline *multi); // 0x800425D8

extern struct _G2Quat_Type * SplineGetFirstRot(struct RSpline *rspline, struct SplineDef *def); // 0x80042664

extern struct _SVector * SplineGetFirstPoint(struct Spline *spline, struct SplineDef *def); // 0x8004268C

extern struct _SVector * SplineGetNextPoint(struct Spline *spline, struct SplineDef *def); // 0x800426B4

extern struct _SVector * SplineGetPreviousPoint(struct Spline *spline, struct SplineDef *def); // 0x80042714

extern struct _SVector * SplineGetNearestPoint(struct Spline *spline, struct _SVector *point, struct SplineDef *def); // 0x80042774

extern unsigned long SplineGetData(struct Spline *spline, struct SplineDef *def, void *p); // 0x80042B3C

extern unsigned long SplineGetQuatData(struct Spline *spline, struct SplineDef *def, void *p); // 0x80042D4C

extern unsigned long SplineGetNext(struct Spline *spline, struct SplineDef *def); // 0x80042E80

extern unsigned long SplineGetPrev(struct Spline *spline, struct SplineDef *def); // 0x80042F9C

extern unsigned long SplineGetOffsetNext(struct Spline *spline, struct SplineDef *def, long fracOffset); // 0x800430C8

extern unsigned long SplineGetOffsetPrev(struct Spline *spline, struct SplineDef *def, long fracOffset); // 0x800432AC

extern struct _SVector * SplineGetOffsetNextPoint(struct Spline *spline, struct SplineDef *def, long offset); // 0x80043420

extern struct _SVector * SplineGetOffsetPreviousPoint(struct Spline *spline, struct SplineDef *def, long offset); // 0x80043480


#endif
