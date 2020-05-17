#ifndef VRAM_H
#define VRAM_H


extern void VRAM_PrintVramBlock(struct _BlockVramEntry *vblock); // 0x80072E44

extern void VRAM_PrintInfo(); // 0x80072E4C

extern void VRAM_InitVramBlockCache(); // 0x80072E94

extern void VRAM_EnableTerrainArea(); // 0x80072EF4

extern void VRAM_DisableTerrainArea(); // 0x80072F24

extern int VRAM_ConcatanateMemory(struct _BlockVramEntry *curBlock); // 0x80072F50

extern void VRAM_GarbageCollect(); // 0x80073138

extern int VRAM_InsertFreeBlock(struct _BlockVramEntry *block); // 0x8007316C

extern void VRAM_DeleteFreeBlock(struct _BlockVramEntry *block); // 0x800731FC

extern void VRAM_InsertUsedBlock(struct _BlockVramEntry *block); // 0x80073264

extern void VRAM_DeleteUsedBlock(struct _BlockVramEntry *block); // 0x80073298

extern struct _BlockVramEntry * VRAM_GetOpenBlock(); // 0x800732FC

extern int VRAM_DeleteFreeVram(short x, short y, short w, short h); // 0x80073330

extern int VRAM_InsertFreeVram(short x, short y, short w, short h, int flags); // 0x80073460

extern struct _BlockVramEntry * VRAM_CheckVramSlot(short *x, short *y, short w, short h, int type, int startY); // 0x80073600

extern void VRAM_ClearVramBlock(struct _BlockVramEntry *block); // 0x80073A3C

extern void AdjustVramCoordsObject(int oldx, int oldy, int newx, int newy, struct Object *object); // 0x80073A70

extern struct _BlockVramEntry * VRAM_InsertionSort(struct _BlockVramEntry *rootNode, struct _BlockVramEntry *newBlock); // 0x80073C5C

extern void VRAM_RearrangeVramsLayer(long whichLayer); // 0x80073CB8

extern void VRAM_TransferBufferToVram(void *dataPtr, long dataSize, short status, void *data1, void *data2); // 0x80074070

extern void VRAM_LoadReturn(void *dataPtr, void *data1, void *data2); // 0x800742E8

extern long VRAM_GetObjectVramSpace(struct VramSize *vramSize, struct _ObjectTracker *objectTracker); // 0x80074308

extern void VRAM_InitMorphPalettes(); // 0x80074400

extern void VRAM_UpdateMorphPalettes(); // 0x80074408

extern void MORPH_ChangeAreaPalettes(long time); // 0x80074410


#endif
