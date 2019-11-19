#ifndef STEERING_H
#define STEERING_H


extern int UpdateZoneDelta(int rc, int LastRC); // 0x8009ECE8

extern int GetControllerInput(int *ZDirection, long *controlCommand); // 0x8009ED24

extern int DecodeDirection(int Source, int Destination, short *Difference, short *Zone); // 0x8009EF04

extern int ProcessMovement(struct _Instance *instance, long *controlCommand, struct GameTracker *GT); // 0x8009EFF4

extern void SteerTurn(struct _Instance *instance, int rc); // 0x8009F518

extern void SteerMove(struct _Instance *instance, int rc); // 0x8009F5AC

extern int SteerAutoFace(struct _Instance *instance, long *controlCommand); // 0x8009F65C

extern void SteerSwim(struct _Instance *instance); // 0x8009F8F0

extern void SteerWallcrawling(struct _Instance *instance); // 0x8009F9E0

extern void SteerDisableAutoFace(struct _Instance *instance); // 0x8009FA14

extern void SteerSwitchMode(struct _Instance *instance, int mode); // 0x8009FAA8

extern void razInitWallCrawlSteering(struct _Instance *instance); // 0x8009FCC0

extern void razDeinitWallCrawlSteering(struct _Instance *instance); // 0x8009FE00


#endif
