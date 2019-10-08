#ifndef MONMSG_H
#define MONMSG_H

extern void MON_SetGlyphHitData(struct _Instance *instance, struct evFXHitData *data, int type, int amount);

extern int MON_GroundMoveQueueHandler(struct _Instance *instance);

extern void MON_PupateMessageHandler(struct _Instance *instance, struct __Event *message);

extern void MON_IdleMessageHandler(struct _Instance *instance, struct __Event *message);

extern void MON_DefaultMessageHandler(struct _Instance *instance, struct __Event *message);

extern void MON_PupateQueueHandler(struct _Instance *instance);

extern void MON_IdleQueueHandler(struct _Instance *instance);

extern void MON_DefaultQueueHandler(struct _Instance *instance);

#endif
