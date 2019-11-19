#ifndef MONMSG_H
#define MONMSG_H


extern void MON_SetGlyphHitData(struct _Instance *instance, struct evFXHitData *data, int type, int amount); // 0x800836F8

extern int MON_GroundMoveQueueHandler(struct _Instance *instance); // 0x80083734

extern void MON_PupateMessageHandler(struct _Instance *instance, struct __Event *message); // 0x800837BC

extern void MON_IdleMessageHandler(struct _Instance *instance, struct __Event *message); // 0x80083AC0

extern void MON_DefaultMessageHandler(struct _Instance *instance, struct __Event *message); // 0x80083C18

extern void MON_PupateQueueHandler(struct _Instance *instance); // 0x800848B0

extern void MON_IdleQueueHandler(struct _Instance *instance); // 0x800848FC

extern void MON_DefaultQueueHandler(struct _Instance *instance); // 0x80084948


#endif
