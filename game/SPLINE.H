#ifndef SPLINE_H
#define SPLINE_H

extern void _SplineS2Pos(struct vecS *p, long s, struct SplineKey *key, struct SplineKey *key2);

extern void SplineSetDefDenom(struct Spline *spline, struct SplineDef *def, int denomFlag);

extern unsigned short SplineGetFrameNumber(struct Spline *spline, struct SplineDef *def);

extern short SplineSetDef2FrameNumber(struct Spline *spline, struct SplineDef *def, unsigned short frame_number);

extern short SplineIsWhere(struct Spline *spline, struct SplineDef *def);

extern short SplineMultiIsWhere(struct MultiSpline *multi);

extern struct _G2Quat_Type *SplineGetFirstRot(struct RSpline *rspline, struct SplineDef *def);

extern struct _SVector *SplineGetFirstPoint(struct Spline *spline, struct SplineDef *def);

extern struct _SVector *SplineGetNextPoint(struct Spline *spline, struct SplineDef *def);

extern struct _SVector *SplineGetPreviousPoint(struct Spline *spline, struct SplineDef *def);

extern struct _SVector *SplineGetNearestPoint(struct Spline *spline, struct _SVector *point, struct SplineDef *def);

extern unsigned long SplineGetData(struct Spline *spline, struct SplineDef *def, void *p);

extern unsigned long SplineGetQuatData(struct Spline *spline, struct SplineDef *def, void *p);

extern unsigned long SplineGetNext(struct Spline *spline, struct SplineDef *def);

extern unsigned long SplineGetPrev(struct Spline *spline, struct SplineDef *def);

extern unsigned long SplineGetOffsetNext(struct Spline *spline, struct SplineDef *def, long fracOffset);

extern unsigned long SplineGetOffsetPrev(struct Spline *spline, struct SplineDef *def, long fracOffset);

extern struct _SVector *SplineGetOffsetNextPoint(struct Spline *spline, struct SplineDef *def, long offset);

extern struct _SVector *SplineGetOffsetPreviousPoint(struct Spline *spline, struct SplineDef *def, long offset);

#endif
