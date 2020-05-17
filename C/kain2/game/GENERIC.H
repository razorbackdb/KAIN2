#ifndef GENERIC_H
#define GENERIC_H


extern void GenericInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8003E7A0

extern void GenericCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8003E8DC

extern void GenericProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8003E8E4

extern unsigned long GenericQuery(struct _Instance *instance, unsigned long query); // 0x8003E938

extern void GenericMessage(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8003EAB0

extern void GenericRelocateTune(struct Object *object, long offset); // 0x8003EC2C


#endif
