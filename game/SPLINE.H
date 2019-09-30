#ifndef SPLINE_H
#define SPLINE_H


extern void _SplineS2Pos(struct vecS *p, long s, struct SplineKey *key, struct SplineKey *key2); // 0x800415E8

extern void SplineSetDefDenom(struct Spline *spline, struct SplineDef *def, int denomFlag); // 0x80041758

extern unsigned short SplineGetFrameNumber(struct Spline *spline, struct SplineDef *def); // 0x8004181C

extern short SplineSetDef2FrameNumber(struct Spline *spline, struct SplineDef *def, unsigned short frame_number); // 0x800418B0

extern short SplineIsWhere(struct Spline *spline, struct SplineDef *def); // 0x800419E0

extern short SplineMultiIsWhere(struct MultiSpline *multi); // 0x80041A48

extern struct _G2Quat_Type * SplineGetFirstRot(struct RSpline *rspline, struct SplineDef *def); // 0x80041AD4

extern struct _SVector * SplineGetFirstPoint(struct Spline *spline, struct SplineDef *def); // 0x80041AFC

extern struct _SVector * SplineGetNextPoint(struct Spline *spline, struct SplineDef *def); // 0x80041B24

extern struct _SVector * SplineGetPreviousPoint(struct Spline *spline, struct SplineDef *def); // 0x80041B84

extern struct _SVector * SplineGetNearestPoint(struct Spline *spline, struct _SVector *point, struct SplineDef *def); // 0x80041BE4

extern unsigned long SplineGetData(struct Spline *spline, struct SplineDef *def, void *p); // 0x80041FAC

extern unsigned long SplineGetQuatData(struct Spline *spline, struct SplineDef *def, void *p); // 0x800421BC

extern unsigned long SplineGetNext(struct Spline *spline, struct SplineDef *def); // 0x800422F0

extern unsigned long SplineGetPrev(struct Spline *spline, struct SplineDef *def); // 0x8004240C

extern unsigned long SplineGetOffsetNext(struct Spline *spline, struct SplineDef *def, long fracOffset); // 0x80042538

extern unsigned long SplineGetOffsetPrev(struct Spline *spline, struct SplineDef *def, long fracOffset); // 0x8004271C

extern struct _SVector * SplineGetOffsetNextPoint(struct Spline *spline, struct SplineDef *def, long offset); // 0x80042890

extern struct _SVector * SplineGetOffsetPreviousPoint(struct Spline *spline, struct SplineDef *def, long offset); // 0x800428F0


#endif
