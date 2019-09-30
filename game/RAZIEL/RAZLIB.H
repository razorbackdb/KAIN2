#ifndef RAZLIB_H
#define RAZLIB_H


extern void razAlignYMoveRot(struct _Instance *dest, short distance, struct _Position *position, struct _Rotation *rotation, int extraZ); // 0x800A4274

extern void razAlignYRotMove(struct _Instance *dest, short distance, struct _Position *position, struct _Rotation *rotation, int extraZ); // 0x800A4338

extern void razAlignYRotMoveInterp(struct _Instance *source, struct _Instance *dest, short distance, unsigned char segNumber, int Frames, int extraZ); // 0x800A4410

extern void razAlignYRotInterp(struct _Instance *source, struct _Position *dest, unsigned char segNumber, int Frames); // 0x800A4504

extern int razConstrictAngle(struct _Instance *instance); // 0x800A4530

extern void razRotateUpperBody(struct _Instance *instance, struct evActionLookAroundData *data); // 0x800A4648

extern void razSetFadeEffect(short source, short dest, int steps); // 0x800A4818

extern int razPlaneShift(struct _Instance *instance); // 0x800A483C

extern void razSpectralShift(); // 0x800A4898

extern void razMaterialShift(); // 0x800A499C

extern int RAZIEL_OkToShift(); // 0x800A4A40

extern int razPickupAndGrab(struct __CharacterState *In, int CurrentSection); // 0x800A4AD4

extern int razZeroAxis(long *x, long *y, int radius); // 0x800A4CA4

extern int razAdjustSpeed(struct _Instance *instance, int minSpeed); // 0x800A4D04

extern void razLaunchForce(struct _Instance *instance); // 0x800A4DA0

extern struct _Instance * razGetHeldItem(); // 0x800A4E34

extern struct _Instance * razGetHeldWeapon(); // 0x800A4E6C

extern void razReaverBladeOff(); // 0x800A4ECC

extern void razReaverBladeOn(); // 0x800A4EFC

extern int razReaverOff(); // 0x800A4F2C

extern int razReaverOn(); // 0x800A4FA0

extern void razReaverPickup(struct _Instance *instance, struct _Instance *soulReaver); // 0x800A5070

extern void razReaverImbue(int reaverType); // 0x800A512C

extern int razGetReaverFromMask(int reaverMask); // 0x800A516C

extern void razReaverScale(int scale); // 0x800A5190

extern void razGetForwardNormal(struct _Instance *inst, struct _Instance *target); // 0x800A51DC

extern void razGetRotFromNormal(struct _SVector *normal, struct _Rotation *rot); // 0x800A52C0

extern void razCenterWithBlock(struct _Instance *inst, struct _Instance *target, int dist); // 0x800A530C

extern void razSetPauseTranslation(struct _Instance *instance); // 0x800A54E0

extern void razResetPauseTranslation(struct _Instance *instance); // 0x800A5554

extern void razSelectMotionAnim(struct __CharacterState *In, int CurrentSection, int Frames, int *Anim); // 0x800A55AC

extern int razApplyMotion(struct __CharacterState *In, int CurrentSection); // 0x800A5C1C

extern void razResetMotion(struct _Instance *instance); // 0x800A5DAC

extern void razSetDampingPhysics(struct _Instance *instance); // 0x800A5E00

extern void razEnterWater(struct __CharacterState *In, int CurrentSection, struct evPhysicsSwimData *SwimData); // 0x800A5E38

extern void razSetSwimVelocity(struct _Instance *instance, int vel, int accl); // 0x800A60DC

extern void razSetWallCrawlNodes(struct _Instance *instance, struct evPhysicsWallCrawlData *data); // 0x800A6130

extern int razSwitchVAnimCharacterGroup(struct _Instance *instance, int animGroup, int *frame, int *frames); // 0x800A621C

extern int razSwitchVAnimGroup(struct _Instance *instance, int section, int animGroup, int frame, int frames); // 0x800A62D8

extern void razSwitchVAnimCharacterSingle(struct _Instance *instance, int anim, int *frame, int *frames); // 0x800A6334

extern void razSwitchVAnimSingle(struct _Instance *instance, int section, int anim, int frame, int frames); // 0x800A63EC

extern void razSwitchVAnim(struct _Instance *instance, int section, struct __VAnim *vAnim, int frame, int frames); // 0x800A6420

extern int razProcessSAnim(struct _Instance *instance, int mode); // 0x800A64EC

extern void razSwitchStringAnimation(struct _Instance *instance, int anim); // 0x800A6664

extern int CheckStringAnimation(struct _Instance *instance, int mode); // 0x800A672C

extern void razInitCollision(struct _Instance *instance); // 0x800A678C

extern void razLaunchBubbles(int segments, int count, int type); // 0x800A67E4

extern void razSetCowlNoDraw(int mode); // 0x800A687C

extern void razAttachControllers(); // 0x800A6934

extern void razSetPlayerEvent(); // 0x800A69A0

extern void razClearPlayerEvent(); // 0x800A6C8C

extern void razSetPlayerEventHistory(unsigned long event); // 0x800A6CC4

extern int razSideMoveSpiderCheck(struct _Instance *instance, int x); // 0x800A6CDC

extern struct _Instance * RAZIEL_QueryEngagedInstance(int index); // 0x800A6DA8

extern int razUpdateSoundRamp(struct _Instance *instance, struct _SoundRamp *sound); // 0x800A6DE0

extern void razSetupSoundRamp(struct _Instance *instance, struct _SoundRamp *sound, int sfx, int startPitch, int endPitch, int startVolume, int endVolume, int timer, int distance); // 0x800A6EE4

extern void RAZIEL_SetInteractiveMusic(int modifier, int action); // 0x800A6F88

extern void RAZIEL_StartNewGame(); // 0x800A7004

extern int razInBaseArea(char *name, int length); // 0x800A7030


#endif
