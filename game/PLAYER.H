#ifndef PLAYER_H
#define PLAYER_H


extern void PLAYER_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x80012AC8

extern long PLAYER_OkToLookAround(struct _Instance *instance); // 0x80012B48

extern void PLAYER_SetLookAround(struct _Instance *instance); // 0x80012B94

extern void PLAYER_ReSetLookAround(struct _Instance *instance); // 0x80012BE0


#endif
