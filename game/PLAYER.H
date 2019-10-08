#ifndef PLAYER_H
#define PLAYER_H

extern void PLAYER_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker);

extern long PLAYER_OkToLookAround(struct _Instance *instance);

extern void PLAYER_SetLookAround(struct _Instance *instance);

extern void PLAYER_ReSetLookAround(struct _Instance *instance);

#endif
