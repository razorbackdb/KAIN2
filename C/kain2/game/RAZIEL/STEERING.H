#ifndef STEERING_H
#define STEERING_H


extern int UpdateZoneDelta(int rc, int LastRC); // 0x800A206C

extern int GetControllerInput(int *ZDirection, long *controlCommand); // 0x800A20A8

extern int DecodeDirection(int Source, int Destination, short *Difference, short *Zone); // 0x800A2288

extern int ProcessMovement(struct _Instance *instance, long *controlCommand, struct GameTracker *GT); // 0x800A2378

extern void SteerTurn(struct _Instance *instance, int rc); // 0x800A28BC

extern void SteerMove(struct _Instance *instance, int rc); // 0x800A2950

extern int SteerAutoFace(struct _Instance *instance, long *controlCommand); // 0x800A2A00

extern void SteerSwim(struct _Instance *instance); // 0x800A2C94

extern void SteerWallcrawling(struct _Instance *instance); // 0x800A2D84

extern void SteerDisableAutoFace(struct _Instance *instance); // 0x800A2DB8

extern void SteerSwitchMode(struct _Instance *instance, int mode); // 0x800A2E4C

extern void razInitWallCrawlSteering(struct _Instance *instance); // 0x800A30A8

extern void razDeinitWallCrawlSteering(struct _Instance *instance); // 0x800A31E4


#endif
