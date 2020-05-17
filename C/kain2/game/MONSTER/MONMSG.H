#ifndef MONMSG_H
#define MONMSG_H


extern int MON_GroundMoveQueueHandler(struct _Instance *instance); // 0x80084984

extern void MON_PupateMessageHandler(struct _Instance *instance, struct __Event *message); // 0x80084A0C

extern void MON_IdleMessageHandler(struct _Instance *instance, struct __Event *message); // 0x80084C50

extern void MON_DefaultMessageHandler(struct _Instance *instance, struct __Event *message); // 0x80084D94

extern void MON_PupateQueueHandler(struct _Instance *instance); // 0x80085B8C

extern void MON_IdleQueueHandler(struct _Instance *instance); // 0x80085BD8

extern void MON_DefaultQueueHandler(struct _Instance *instance); // 0x80085C24


#endif
