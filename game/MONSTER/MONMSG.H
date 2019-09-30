#ifndef MONMSG_H
#define MONMSG_H


extern void MON_SetGlyphHitData(struct _Instance *instance, struct evFXHitData *data, int type, int amount); // 0x80084384

extern int MON_GroundMoveQueueHandler(struct _Instance *instance); // 0x800843C0

extern void MON_PupateMessageHandler(struct _Instance *instance, struct __Event *message); // 0x80084448

extern void MON_IdleMessageHandler(struct _Instance *instance, struct __Event *message); // 0x8008474C

extern void MON_DefaultMessageHandler(struct _Instance *instance, struct __Event *message); // 0x80084890

extern void MON_PupateQueueHandler(struct _Instance *instance); // 0x800855E8

extern void MON_IdleQueueHandler(struct _Instance *instance); // 0x80085634

extern void MON_DefaultQueueHandler(struct _Instance *instance); // 0x80085680


#endif
