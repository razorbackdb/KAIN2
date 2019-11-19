#ifndef VRAM_H
#define VRAM_H


extern void VRAM_PrintVramBlock(struct _BlockVramEntry *vblock); // 0x800720D0

extern void VRAM_PrintInfo(); // 0x80072174

extern void VRAM_InitVramBlockCache(); // 0x800722BC

extern int VRAM_ConcatanateMemory(struct _BlockVramEntry *curBlock); // 0x80072320

extern void VRAM_GarbageCollect(); // 0x80072508

extern int VRAM_InsertFreeBlock(struct _BlockVramEntry *block); // 0x8007253C

extern void VRAM_DeleteFreeBlock(struct _BlockVramEntry *block); // 0x800725CC

extern void VRAM_InsertUsedBlock(struct _BlockVramEntry *block); // 0x80072634

extern void VRAM_DeleteUsedBlock(struct _BlockVramEntry *block); // 0x80072668

extern struct _BlockVramEntry * VRAM_GetOpenBlock(); // 0x800726CC

extern int VRAM_InsertFreeVram(short x, short y, short w, short h, int flags); // 0x80072728

extern struct _BlockVramEntry * VRAM_CheckVramSlot(short *x, short *y, short w, short h, int type, int startY); // 0x800728C8

extern void VRAM_ClearVramBlock(struct _BlockVramEntry *block); // 0x80072EC8

extern void AdjustVramCoordsObject(int oldx, int oldy, int newx, int newy, struct Object *object); // 0x80072F54

extern struct _BlockVramEntry * VRAM_InsertionSort(struct _BlockVramEntry *rootNode, struct _BlockVramEntry *newBlock); // 0x80073140

extern void VRAM_RearrangeVramsLayer(long whichLayer); // 0x8007319C

extern void VRAM_TransferBufferToVram(void *dataPtr, long dataSize, short status, void *data1, void *data2); // 0x800735BC

extern void VRAM_AbortLoad(void *dataPtr, void *data1, void *data2); // 0x80073814

extern long VRAM_GetObjectVramSpace(struct VramSize *vramSize, struct _ObjectTracker *objectTracker); // 0x80073834

extern void VRAM_InitMorphPalettes(); // 0x80073944

extern void VRAM_UpdateMorphPalettes(); // 0x8007394C

extern void MORPH_ChangeAreaPalettes(long time); // 0x80073954


#endif
