#ifndef MATH3D_H
#define MATH3D_H

extern void MATH3D_Sort3VectorCoords(long *a, long *b, long *c);

extern long MATH3D_LengthXYZ(long x, long y, long z);

extern long MATH3D_LengthXY(long x, long y);

extern void MATH3D_Normalize(struct _Normal *normal);

extern short MATH3D_FastAtan2(long y, long x);

extern long MATH3D_FastSqrt(long square);

extern long MATH3D_FastSqrt0(long square);

extern long MATH3D_DistanceBetweenPositions(struct _Position *pos1, struct _Position *pos2);

extern short MATH3D_AngleBetweenVectors(struct _SVector *vector1, struct _SVector *vector2);

extern void MATH3D_RotMatAboutVec(struct _SVector *vec, struct MATRIX *mat, short angle);

extern void MATH3D_SetUnityMatrix(struct MATRIX *mat);

extern void AngleMoveToward(short *current_ptr, short destination, short step);

extern short AngleDiff(short current, short destination);

extern short MATH3D_AngleFromPosToPos(struct _Position *from, struct _Position *to);

extern void MATH3D_ZYXtoXYZ(struct _Rotation *rot);

extern short MATH3D_ElevationFromPosToPos(struct _Position *from, struct _Position *to);

extern void MATH3D_RotationFromPosToPos(struct _Position *from, struct _Position *to, struct _Rotation *rot);

extern int MATH3D_veclen2(int ix, int iy);

extern void MATH3D_RotateAxisToVector(struct MATRIX *dest, struct MATRIX *src, struct _SVector *vec, enum MATH3D_AXIS axis);

extern int MATH3D_ConeDetect(struct _SVector *pos, int arc, int elevation);

extern void MATH3D_CrossProduct(struct _SVector *t, struct _SVector *r, struct _SVector *s);

extern unsigned long MATH3D_SquareLength(long x, long y, long z);

#endif
