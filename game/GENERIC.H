#ifndef GENERIC_H
#define GENERIC_H

extern void GenericInit(struct _Instance *instance, struct GameTracker *gameTracker);

extern void GenericCollide(struct _Instance *instance, struct GameTracker *gameTracker);

extern void GenericProcess(struct _Instance *instance, struct GameTracker *gameTracker);

extern unsigned long GenericQuery(struct _Instance *instance, unsigned long query);

extern void GenericMessage(struct _Instance *instance, unsigned long message, unsigned long data);

extern void GenericRelocateTune(struct Object *object, long offset);

#endif
