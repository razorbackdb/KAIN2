#ifndef OBTABLE_H
#define OBTABLE_H


extern void OBTABLE_InstanceInit(struct _Instance *instance); // 0x8003DFB8

extern void OBTABLE_GetInstanceCollideFunc(struct _Instance *instance); // 0x8003E09C

extern void OBTABLE_GetInstanceAdditionalCollideFunc(struct _Instance *instance); // 0x8003E0E4

extern void OBTABLE_GetInstanceProcessFunc(struct _Instance *instance); // 0x8003E124

extern void OBTABLE_GetInstanceQueryFunc(struct _Instance *instance); // 0x8003E16C

extern void OBTABLE_GetInstanceMessageFunc(struct _Instance *instance); // 0x8003E1B4

extern void OBTABLE_InitObjectWithID(struct Object *object); // 0x8003E1FC

extern void OBTABLE_ClearObjectReferences(); // 0x8003E3D4

extern void OBTABLE_RemoveObjectEntry(struct Object *object); // 0x8003E408

extern struct Object * OBTABLE_FindObject(char *objectName); // 0x8003E450

extern void OBTABLE_ChangeObjectAccessPointers(struct Object *oldObject, struct Object *newObject); // 0x8003E4FC

extern void OBTABLE_RelocateObjectTune(struct Object *object, long offset); // 0x8003E544

extern void OBTABLE_RelocateInstanceObject(struct _Instance *instance, long offset); // 0x8003E5A8

extern void OBTABLE_InitAnimPointers(struct _ObjectTracker *objectTracker); // 0x8003E604


#endif
