#ifndef VRAM_H
#define VRAM_H


extern void VRAM_PrintVramBlock(struct _BlockVramEntry *vblock); // 0x800726D4

extern void VRAM_PrintInfo(); // 0x800726DC

extern void VRAM_InitVramBlockCache(); // 0x80072724

extern void VRAM_EnableTerrainArea(); // 0x80072788

extern void VRAM_DisableTerrainArea(); // 0x800727B8

extern int VRAM_ConcatanateMemory(struct _BlockVramEntry *curBlock); // 0x800727E4

extern void VRAM_GarbageCollect(); // 0x800729CC

extern int VRAM_InsertFreeBlock(struct _BlockVramEntry *block); // 0x80072A00

extern void VRAM_DeleteFreeBlock(struct _BlockVramEntry *block); // 0x80072A90

extern void VRAM_InsertUsedBlock(struct _BlockVramEntry *block); // 0x80072AF8

extern void VRAM_DeleteUsedBlock(struct _BlockVramEntry *block); // 0x80072B2C

extern struct _BlockVramEntry * VRAM_GetOpenBlock(); // 0x80072B90

extern int VRAM_DeleteFreeVram(short x, short y, short w, short h); // 0x80072BC8

extern int VRAM_InsertFreeVram(short x, short y, short w, short h, int flags); // 0x80072CF8

extern struct _BlockVramEntry * VRAM_CheckVramSlot(short *x, short *y, short w, short h, int type, int startY); // 0x80072E98

extern void VRAM_ClearVramBlock(struct _BlockVramEntry *block); // 0x800732D4

extern void AdjustVramCoordsObject(int oldx, int oldy, int newx, int newy, struct Object *object); // 0x80073308

extern struct _BlockVramEntry * VRAM_InsertionSort(struct _BlockVramEntry *rootNode, struct _BlockVramEntry *newBlock); // 0x800734F4

extern void VRAM_RearrangeVramsLayer(long whichLayer); // 0x80073550

extern void VRAM_TransferBufferToVram(void *dataPtr, long dataSize, short status, void *data1, void *data2); // 0x800738E8

extern void VRAM_LoadReturn(void *dataPtr, void *data1, void *data2); // 0x80073B18

extern long VRAM_GetObjectVramSpace(struct VramSize *vramSize, struct _ObjectTracker *objectTracker); // 0x80073B38

extern void VRAM_InitMorphPalettes(); // 0x80073C30

extern void VRAM_UpdateMorphPalettes(); // 0x80073C38

extern void MORPH_ChangeAreaPalettes(long time); // 0x80073C40


#endif
