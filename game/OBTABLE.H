#ifndef OBTABLE_H
#define OBTABLE_H

extern void OBTABLE_InstanceInit(struct _Instance *instance);

extern void OBTABLE_GetInstanceCollideFunc(struct _Instance *instance);

extern void OBTABLE_GetInstanceAdditionalCollideFunc(struct _Instance *instance);

extern void OBTABLE_GetInstanceProcessFunc(struct _Instance *instance);

extern void OBTABLE_GetInstanceQueryFunc(struct _Instance *instance);

extern void OBTABLE_GetInstanceMessageFunc(struct _Instance *instance);

extern void OBTABLE_InitObjectWithID(struct Object *object);

extern void OBTABLE_ClearObjectReferences();

extern void OBTABLE_RemoveObjectEntry(struct Object *object);

extern struct Object *OBTABLE_FindObject(char *objectName);

extern void OBTABLE_ChangeObjectAccessPointers(struct Object *oldObject, struct Object *newObject);

extern void OBTABLE_RelocateObjectTune(struct Object *object, long offset);

extern void OBTABLE_RelocateInstanceObject(struct _Instance *instance, long offset);

extern void OBTABLE_InitAnimPointers(struct _ObjectTracker *objectTracker);

#endif
