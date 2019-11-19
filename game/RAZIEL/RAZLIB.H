#ifndef RAZLIB_H
#define RAZLIB_H


extern void razAlignYMoveRot(struct _Instance *dest, short distance, struct _Position *position, struct _Rotation *rotation, int extraZ); // 0x800A1774

extern void razAlignYRotMove(struct _Instance *dest, short distance, struct _Position *position, struct _Rotation *rotation, int extraZ); // 0x800A184C

extern void razAlignYRotMoveInterp(struct _Instance *source, struct _Instance *dest, short distance, unsigned char segNumber, int Frames, int extraZ); // 0x800A1938

extern void razAlignYRotInterp(struct _Instance *source, struct _Position *dest, unsigned char segNumber, int Frames); // 0x800A1A2C

extern int razConstrictAngle(struct _Instance *instance); // 0x800A1A58

extern void razRotateUpperBody(struct _Instance *instance, struct evActionLookAroundData *data); // 0x800A1B70

extern void razSetFadeEffect(short source, short dest, int steps); // 0x800A1D40

extern int razPlaneShift(struct _Instance *instance); // 0x800A1D64

extern void razSpectralShift(); // 0x800A1DC0

extern void razMaterialShift(); // 0x800A1EB4

extern int RAZIEL_OkToShift(); // 0x800A1F58

extern int razPickupAndGrab(struct __CharacterState *In, int CurrentSection); // 0x800A1FEC

extern int razZeroAxis(long *x, long *y, int radius); // 0x800A21A8

extern int razAdjustSpeed(struct _Instance *instance, int minSpeed); // 0x800A2208

extern void razLaunchForce(struct _Instance *instance); // 0x800A22A4

extern struct _Instance * razGetHeldItem(); // 0x800A22FC

extern struct _Instance * razGetHeldWeapon(); // 0x800A2334

extern int razReaverOff(); // 0x800A2370

extern int razReaverOn(); // 0x800A23E4

extern void razReaverPickup(struct _Instance *instance, struct _Instance *soulReaver); // 0x800A248C

extern void razReaverImbue(int reaverType); // 0x800A2548

extern int razGetReaverFromMask(int reaverMask); // 0x800A2588

extern void razReaverScale(int scale); // 0x800A25AC

extern void razGetForwardNormal(struct _Instance *inst, struct _Instance *target); // 0x800A25F8

extern void razGetRotFromNormal(struct _SVector *normal, struct _Rotation *rot); // 0x800A26DC

extern void razSetPauseTranslation(struct _Instance *instance); // 0x800A2728

extern void razResetPauseTranslation(struct _Instance *instance); // 0x800A278C

extern void razSelectMotionAnim(struct __CharacterState *In, int CurrentSection, int Frames, int *Anim); // 0x800A27D0

extern int razApplyMotion(struct __CharacterState *In, int CurrentSection); // 0x800A2DE8

extern void razResetMotion(struct _Instance *instance); // 0x800A2F78

extern void razSetDampingPhysics(struct _Instance *instance); // 0x800A2FCC

extern void razEnterWater(struct __CharacterState *In, int CurrentSection, struct evPhysicsSwimData *SwimData); // 0x800A3004

extern void razSetSwimVelocity(struct _Instance *instance, int vel, int accl); // 0x800A32BC

extern void razSetWallCrawlNodes(struct _Instance *instance, struct evPhysicsWallCrawlData *data); // 0x800A3310

extern int razSwitchVAnimCharacterGroup(struct _Instance *instance, int animGroup, int *frame, int *frames); // 0x800A3414

extern int razSwitchVAnimGroup(struct _Instance *instance, int section, int animGroup, int frame, int frames); // 0x800A34D0

extern void razSwitchVAnimCharacterSingle(struct _Instance *instance, int anim, int *frame, int *frames); // 0x800A352C

extern void razSwitchVAnimSingle(struct _Instance *instance, int section, int anim, int frame, int frames); // 0x800A35E4

extern void razSwitchVAnim(struct _Instance *instance, int section, struct __VAnim *vAnim, int frame, int frames); // 0x800A3618

extern int razProcessSAnim(struct _Instance *instance, int mode); // 0x800A36E4

extern void razSwitchStringAnimation(struct _Instance *instance, int anim); // 0x800A385C

extern int CheckStringAnimation(struct _Instance *instance, int mode); // 0x800A3924

extern void razInitCollision(struct _Instance *instance); // 0x800A3984

extern void razLaunchBubbles(int segments, int count, int type); // 0x800A39DC

extern void razSetCowlNoDraw(int mode); // 0x800A3A74

extern void razAttachControllers(); // 0x800A3B2C

extern void razSetPlayerEvent(); // 0x800A3B98

extern void razSetPlayerEventHistory(unsigned long event); // 0x800A3E3C

extern int razSideMoveSpiderCheck(struct _Instance *instance, int x); // 0x800A3E54


#endif
