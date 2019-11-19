#ifndef OBTABLE_H
#define OBTABLE_H


extern void OBTABLE_InstanceInit(struct _Instance *instance); // 0x8003EF8C

extern void OBTABLE_GetInstanceCollideFunc(struct _Instance *instance); // 0x8003F03C

extern void OBTABLE_GetInstanceAdditionalCollideFunc(struct _Instance *instance); // 0x8003F084

extern void OBTABLE_GetInstanceProcessFunc(struct _Instance *instance); // 0x8003F0C4

extern void OBTABLE_GetInstanceQueryFunc(struct _Instance *instance); // 0x8003F10C

extern void OBTABLE_GetInstanceMessageFunc(struct _Instance *instance); // 0x8003F154

extern void OBTABLE_InitObjectWithID(struct Object *object); // 0x8003F19C

extern void OBTABLE_ClearObjectReferences(); // 0x8003F374

extern void OBTABLE_RemoveObjectEntry(struct Object *object); // 0x8003F3A8

extern struct Object * OBTABLE_FindObject(char *objectName); // 0x8003F3F0

extern void OBTABLE_ChangeObjectAccessPointers(struct Object *oldObject, struct Object *newObject); // 0x8003F49C

extern void OBTABLE_RelocateObjectTune(struct Object *object, long offset); // 0x8003F4E4

extern void OBTABLE_RelocateInstanceObject(struct _Instance *instance, long offset); // 0x8003F538

extern void OBTABLE_InitAnimPointers(struct _ObjectTracker *objectTracker); // 0x8003F594


#endif
