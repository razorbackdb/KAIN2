#ifndef SPLINE_H
#define SPLINE_H


extern void _SplineS2Pos(struct vecS *p, long s, struct SplineKey *key, struct SplineKey *key2); // 0x80041224

extern void SplineSetDefDenom(struct Spline *spline, struct SplineDef *def, int denomFlag); // 0x80041394

extern unsigned short SplineGetFrameNumber(struct Spline *spline, struct SplineDef *def); // 0x80041458

extern short SplineSetDef2FrameNumber(struct Spline *spline, struct SplineDef *def, unsigned short frame_number); // 0x800414EC

extern short SplineIsWhere(struct Spline *spline, struct SplineDef *def); // 0x8004161C

extern short SplineMultiIsWhere(struct MultiSpline *multi); // 0x80041684

extern struct _G2Quat_Type * SplineGetFirstRot(struct RSpline *rspline, struct SplineDef *def); // 0x80041710

extern struct _SVector * SplineGetFirstPoint(struct Spline *spline, struct SplineDef *def); // 0x80041738

extern struct _SVector * SplineGetNextPoint(struct Spline *spline, struct SplineDef *def); // 0x80041760

extern struct _SVector * SplineGetPreviousPoint(struct Spline *spline, struct SplineDef *def); // 0x800417B8

extern struct _SVector * SplineGetNearestPoint(struct Spline *spline, struct _SVector *point, struct SplineDef *def); // 0x80041810

extern unsigned long SplineGetData(struct Spline *spline, struct SplineDef *def, void *p); // 0x80041BCC

extern unsigned long SplineGetQuatData(struct Spline *spline, struct SplineDef *def, void *p); // 0x80041DDC

extern unsigned long SplineGetNext(struct Spline *spline, struct SplineDef *def); // 0x80041F10

extern unsigned long SplineGetPrev(struct Spline *spline, struct SplineDef *def); // 0x8004202C

extern unsigned long SplineGetOffsetNext(struct Spline *spline, struct SplineDef *def, long fracOffset); // 0x80042158

extern unsigned long SplineGetOffsetPrev(struct Spline *spline, struct SplineDef *def, long fracOffset); // 0x8004233C

extern struct _SVector * SplineGetOffsetNextPoint(struct Spline *spline, struct SplineDef *def, long offset); // 0x800424B0

extern struct _SVector * SplineGetOffsetPreviousPoint(struct Spline *spline, struct SplineDef *def, long offset); // 0x80042508


#endif
