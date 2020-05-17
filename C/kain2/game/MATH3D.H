#ifndef MATH3D_H
#define MATH3D_H


extern void MATH3D_Sort3VectorCoords(long *a, long *b, long *c); // 0x80039A58

extern long MATH3D_LengthXYZ(long x, long y, long z); // 0x80039ADC

extern long MATH3D_LengthXY(long x, long y); // 0x80039BAC

extern void MATH3D_Normalize(struct _Normal *normal); // 0x80039C0C

extern short MATH3D_FastAtan2(long y, long x); // 0x80039C9C

extern long MATH3D_FastSqrt(long square); // 0x80039DB8

extern long MATH3D_FastSqrt0(long square); // 0x80039E98

extern long MATH3D_DistanceBetweenPositions(struct _Position *pos1, struct _Position *pos2); // 0x80039F28

extern short MATH3D_AngleBetweenVectors(struct _SVector *vector1, struct _SVector *vector2); // 0x80039F74

extern void MATH3D_RotMatAboutVec(struct _SVector *vec, struct MATRIX *mat, short angle); // 0x8003A060

extern void MATH3D_SetUnityMatrix(struct MATRIX *mat); // 0x8003A130

extern void AngleMoveToward(short *current_ptr, short destination, short step); // 0x8003A14C

extern short AngleDiff(short current, short destination); // 0x8003A1F8

extern short MATH3D_AngleFromPosToPos(struct _Position *from, struct _Position *to); // 0x8003A21C

extern void MATH3D_ZYXtoXYZ(struct _Rotation *rot); // 0x8003A254

extern short MATH3D_ElevationFromPosToPos(struct _Position *from, struct _Position *to); // 0x8003A2B0

extern void MATH3D_RotationFromPosToPos(struct _Position *from, struct _Position *to, struct _Rotation *rot); // 0x8003A334

extern int MATH3D_veclen2(int ix, int iy); // 0x8003A388

extern void MATH3D_RotateAxisToVector(struct MATRIX *dest, struct MATRIX *src, struct _SVector *vec, enum MATH3D_AXIS axis); // 0x8003A3E8

extern int MATH3D_ConeDetect(struct _SVector *pos, int arc, int elevation); // 0x8003A640

extern void MATH3D_CrossProduct(struct _SVector *t, struct _SVector *r, struct _SVector *s); // 0x8003A6F8

extern unsigned long MATH3D_SquareLength(long x, long y, long z); // 0x8003A79C


#endif
