#ifndef STEERING_H
#define STEERING_H

extern int UpdateZoneDelta(int rc, int LastRC);

extern int GetControllerInput(int *ZDirection, long *controlCommand);

extern int DecodeDirection(int Source, int Destination, short *Difference, short *Zone);

extern int ProcessMovement(struct _Instance *instance, long *controlCommand, struct GameTracker *GT);

extern void SteerTurn(struct _Instance *instance, int rc);

extern void SteerMove(struct _Instance *instance, int rc);

extern int SteerAutoFace(struct _Instance *instance, long *controlCommand);

extern void SteerSwim(struct _Instance *instance);

extern void SteerWallcrawling(struct _Instance *instance);

extern void SteerDisableAutoFace(struct _Instance *instance);

extern void SteerSwitchMode(struct _Instance *instance, int mode);

extern void razInitWallCrawlSteering(struct _Instance *instance);

extern void razDeinitWallCrawlSteering(struct _Instance *instance);

#endif
