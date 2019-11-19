#ifndef GENERIC_H
#define GENERIC_H


extern void GenericInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8003F730

extern void GenericCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8003F870

extern void GenericProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8003F878

extern unsigned long GenericQuery(struct _Instance *instance, unsigned long query); // 0x8003F8CC

extern void GenericMessage(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8003FA48


#endif
