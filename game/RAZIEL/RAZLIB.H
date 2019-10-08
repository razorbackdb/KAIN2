#ifndef RAZLIB_H
#define RAZLIB_H

extern void razAlignYMoveRot(struct _Instance *dest, short distance, struct _Position *position, struct _Rotation *rotation, int extraZ);

extern void razAlignYRotMove(struct _Instance *dest, short distance, struct _Position *position, struct _Rotation *rotation, int extraZ);

extern void razAlignYRotMoveInterp(struct _Instance *source, struct _Instance *dest, short distance, unsigned char segNumber, int Frames, int extraZ);

extern void razAlignYRotInterp(struct _Instance *source, struct _Position *dest, unsigned char segNumber, int Frames);

extern int razConstrictAngle(struct _Instance *instance);

extern void razRotateUpperBody(struct _Instance *instance, struct evActionLookAroundData *data);

extern void razSetFadeEffect(short source, short dest, int steps);

extern int razPlaneShift(struct _Instance *instance);

extern void razSpectralShift();

extern void razMaterialShift();

extern int RAZIEL_OkToShift();

extern int razPickupAndGrab(struct __CharacterState *In, int CurrentSection);

extern int razZeroAxis(long *x, long *y, int radius);

extern int razAdjustSpeed(struct _Instance *instance, int minSpeed);

extern void razLaunchForce(struct _Instance *instance);

extern struct _Instance *razGetHeldItem();

extern struct _Instance *razGetHeldWeapon();

extern void razReaverBladeOff();

extern void razReaverBladeOn();

extern int razReaverOff();

extern int razReaverOn();

extern void razReaverPickup(struct _Instance *instance, struct _Instance *soulReaver);

extern void razReaverImbue(int reaverType);

extern int razGetReaverFromMask(int reaverMask);

extern void razReaverScale(int scale);

extern void razGetForwardNormal(struct _Instance *inst, struct _Instance *target);

extern void razGetRotFromNormal(struct _SVector *normal, struct _Rotation *rot);

extern void razCenterWithBlock(struct _Instance *inst, struct _Instance *target, int dist);

extern void razSetPauseTranslation(struct _Instance *instance);

extern void razResetPauseTranslation(struct _Instance *instance);

extern void razSelectMotionAnim(struct __CharacterState *In, int CurrentSection, int Frames, int *Anim);

extern int razApplyMotion(struct __CharacterState *In, int CurrentSection);

extern void razResetMotion(struct _Instance *instance);

extern void razSetDampingPhysics(struct _Instance *instance);

extern void razEnterWater(struct __CharacterState *In, int CurrentSection, struct evPhysicsSwimData *SwimData);

extern void razSetSwimVelocity(struct _Instance *instance, int vel, int accl);

extern void razSetWallCrawlNodes(struct _Instance *instance, struct evPhysicsWallCrawlData *data);

extern int razSwitchVAnimCharacterGroup(struct _Instance *instance, int animGroup, int *frame, int *frames);

extern int razSwitchVAnimGroup(struct _Instance *instance, int section, int animGroup, int frame, int frames);

extern void razSwitchVAnimCharacterSingle(struct _Instance *instance, int anim, int *frame, int *frames);

extern void razSwitchVAnimSingle(struct _Instance *instance, int section, int anim, int frame, int frames);

extern void razSwitchVAnim(struct _Instance *instance, int section, struct __VAnim *vAnim, int frame, int frames);

extern int razProcessSAnim(struct _Instance *instance, int mode);

extern void razSwitchStringAnimation(struct _Instance *instance, int anim);

extern int CheckStringAnimation(struct _Instance *instance, int mode);

extern void razInitCollision(struct _Instance *instance);

extern void razLaunchBubbles(int segments, int count, int type);

extern void razSetCowlNoDraw(int mode);

extern void razAttachControllers();

extern void razSetPlayerEvent();

extern void razClearPlayerEvent();

extern void razSetPlayerEventHistory(unsigned long event);

extern int razSideMoveSpiderCheck(struct _Instance *instance, int x);

extern struct _Instance *RAZIEL_QueryEngagedInstance(int index);

extern int razUpdateSoundRamp(struct _Instance *instance, struct _SoundRamp *sound);

extern void razSetupSoundRamp(struct _Instance *instance, struct _SoundRamp *sound, int sfx, int startPitch, int endPitch, int startVolume, int endVolume, int timer, int distance);

extern void RAZIEL_SetInteractiveMusic(int modifier, int action);

extern void RAZIEL_StartNewGame();

extern int razInBaseArea(char *name, int length);

#endif
