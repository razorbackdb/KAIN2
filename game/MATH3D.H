#ifndef MATH3D_H
#define MATH3D_H


extern void MATH3D_Sort3VectorCoords(long *a, long *b, long *c); // 0x8003A26C

extern long MATH3D_LengthXYZ(long x, long y, long z); // 0x8003A2F0

extern long MATH3D_LengthXY(long x, long y); // 0x8003A3C0

extern void MATH3D_Normalize(struct _Normal *normal); // 0x8003A420

extern short MATH3D_FastAtan2(long y, long x); // 0x8003A4B0

extern long MATH3D_FastSqrt(long square); // 0x8003A5CC

extern long MATH3D_FastSqrt0(long square); // 0x8003A6AC

extern long MATH3D_DistanceBetweenPositions(struct _Position *pos1, struct _Position *pos2); // 0x8003A73C

extern short MATH3D_AngleBetweenVectors(struct _SVector *vector1, struct _SVector *vector2); // 0x8003A788

extern void MATH3D_RotMatAboutVec(struct _SVector *vec, struct MATRIX *mat, short angle); // 0x8003A874

extern void MATH3D_SetUnityMatrix(struct MATRIX *mat); // 0x8003A944

extern void AngleMoveToward(short *current_ptr, short destination, short step); // 0x8003A960

extern short AngleDiff(short current, short destination); // 0x8003AA0C

extern short MATH3D_AngleFromPosToPos(struct _Position *from, struct _Position *to); // 0x8003AA30

extern void MATH3D_ZYXtoXYZ(struct _Rotation *rot); // 0x8003AA68

extern short MATH3D_ElevationFromPosToPos(struct _Position *from, struct _Position *to); // 0x8003AAC4

extern void MATH3D_RotationFromPosToPos(struct _Position *from, struct _Position *to, struct _Rotation *rot); // 0x8003AB48

extern int MATH3D_veclen2(int ix, int iy); // 0x8003AB9C

extern void MATH3D_RotateAxisToVector(struct MATRIX *dest, struct MATRIX *src, struct _SVector *vec, enum MATH3D_AXIS axis); // 0x8003ABFC

extern int MATH3D_ConeDetect(struct _SVector *pos, int arc, int elevation); // 0x8003AE54

extern unsigned long MATH3D_SquareLength(long x, long y, long z); // 0x8003AF0C


#endif
