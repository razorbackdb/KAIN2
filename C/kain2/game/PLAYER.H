#ifndef PLAYER_H
#define PLAYER_H


extern void PLAYER_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x80012D54

extern long PLAYER_OkToLookAround(struct _Instance *instance); // 0x80012DD4

extern void PLAYER_SetLookAround(struct _Instance *instance); // 0x80012E20

extern void PLAYER_ReSetLookAround(struct _Instance *instance); // 0x80012E6C


#endif
