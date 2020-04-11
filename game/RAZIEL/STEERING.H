#ifndef STEERING_H
#define STEERING_H


extern int UpdateZoneDelta(int rc, int LastRC); // 0x800A141C

extern int GetControllerInput(int *ZDirection, long *controlCommand); // 0x800A1458

extern int DecodeDirection(int Source, int Destination, short *Difference, short *Zone); // 0x800A1638

extern int ProcessMovement(struct _Instance *instance, long *controlCommand, struct GameTracker *GT); // 0x800A1728

extern void SteerTurn(struct _Instance *instance, int rc); // 0x800A1C54

extern void SteerMove(struct _Instance *instance, int rc); // 0x800A1CE8

extern int SteerAutoFace(struct _Instance *instance, long *controlCommand); // 0x800A1D98

extern void SteerSwim(struct _Instance *instance); // 0x800A202C

extern void SteerWallcrawling(struct _Instance *instance); // 0x800A211C

extern void SteerDisableAutoFace(struct _Instance *instance); // 0x800A2150

extern void SteerSwitchMode(struct _Instance *instance, int mode); // 0x800A21E4

extern void razInitWallCrawlSteering(struct _Instance *instance); // 0x800A2418

extern void razDeinitWallCrawlSteering(struct _Instance *instance); // 0x800A2558


#endif
