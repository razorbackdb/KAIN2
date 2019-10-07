#ifndef DRAW_H
#define DRAW_H


extern void fDRAW_SPLIT_INTPL_XYZ(struct _SVector *newVertex, struct _SVector *pvb, struct _SVector *pvc); // 0x8002A478

extern void DRAW_InitShadow(); // 0x8002A4F4

extern unsigned long * DRAW_DrawShadow(struct _PrimPool *primPool, struct _Model *model, unsigned long **ot, long fadeValue); // 0x8002A5C0

extern void DRAW_FlatQuad(struct CVECTOR *color, short x0, short y0, short x1, int y1, int x2, int y2, int x3, int y3, struct _PrimPool *primPool, unsigned long **ot); // 0x8002A788

extern void DRAW_TranslucentQuad(short x0, short y0, short x1, short y1, int x2, int y2, int x3, int y3, int r, int g, int b, int abr, struct _PrimPool *primPool, unsigned long **ot); // 0x8002A830

extern void DRAW_DrawButton(struct _ButtonTexture *button, short x, short y, unsigned long **ot); // 0x8002A914

extern void DRAW_LoadButton(long *addr, struct _ButtonTexture *button); // 0x8002AA74

extern void DRAW_LoadButtonByName(char *name, struct _ButtonTexture *button); // 0x8002AC14

extern void DRAW_FreeButton(struct _ButtonTexture *button); // 0x8002AC64

extern void DRAW_RingLine(struct _PrimPool *primPool, unsigned long **ot, long color); // 0x8002AC88

extern void DRAW_RingPoint(struct _PrimPool *primPool, unsigned long **ot, long color, struct _SVector *vel, struct _SVector *acc); // 0x8002ADB8

extern unsigned long * DRAW_DrawRingPoints(struct _Model *model, struct _VertexPool *vertexPool, struct MATRIX *pcTransform, struct _PrimPool *primPool, unsigned long **ot, long color, int ring_type); // 0x8002AEC8

extern void DRAW_GlowQuad(struct _PrimPool *primPool, unsigned long **ot, long otz, long color, struct _Vector *v0, struct _Vector *v1, struct _Vector *v2, struct _Vector *v3); // 0x8002B1E4

extern void DRAW_CreateAGlowingCircle(struct _Vector *f1, long z, struct _PrimPool *primPool, unsigned long **ot, long otz, long color, long w, long h, long angle); // 0x8002B448

extern unsigned long * DRAW_DrawGlowPoints2(struct _Instance *instance, long seg1, long seg2, struct _PrimPool *primPool, unsigned long **ot, long color, long height); // 0x8002B9F4

extern unsigned long * DRAW_DrawGlowPoint(struct _Instance *instance, long seg1, struct _PrimPool *primPool, unsigned long **ot, long color, int width, int height); // 0x8002BB60

extern int DRAW_DisplayTFace_zclipped_C(struct SVECTOR *vertex0, struct SVECTOR *vertex1, struct SVECTOR *vertex2, struct UVTYPE *uv0, struct UVTYPE *uv1, struct UVTYPE *uv2, long color0, long color1, long color2, struct _PrimPool *primPool, unsigned long **ot, int ndiv); // 0x8002BC30

extern long * DRAW_Zclip_subdiv(struct POLY_GT3 *texture, unsigned long **ot, int ndiv); // 0x8002C470

extern void DRAW_LoadingMessage(); // 0x8002C974


#endif
