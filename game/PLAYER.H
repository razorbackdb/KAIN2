#ifndef PLAYER_H
#define PLAYER_H


extern void PLAYER_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x80012C2C

extern long PLAYER_OkToLookAround(struct _Instance *instance); // 0x80012CAC

extern void PLAYER_SetLookAround(struct _Instance *instance); // 0x80012CF8

extern void PLAYER_ReSetLookAround(struct _Instance *instance); // 0x80012D44


#endif
