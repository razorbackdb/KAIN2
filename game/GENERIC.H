#ifndef GENERIC_H
#define GENERIC_H


extern void GenericInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8003ED00

extern void GenericCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8003EE40

extern void GenericProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8003EE48

extern unsigned long GenericQuery(struct _Instance *instance, unsigned long query); // 0x8003EE9C

extern void GenericMessage(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8003F018

extern void GenericRelocateTune(struct Object *object, long offset); // 0x8003F19C


#endif
