#ifndef RAZLIB_H
#define RAZLIB_H


extern void razAlignYMoveRot(struct _Instance *dest, short distance, struct _Position *position, struct _Rotation *rotation, int extraZ); // 0x800A505C

extern void razAlignYRotMove(struct _Instance *dest, short distance, struct _Position *position, struct _Rotation *rotation, int extraZ); // 0x800A5120

extern void razAlignYRotMoveInterp(struct _Instance *source, struct _Instance *dest, short distance, unsigned char segNumber, int Frames, int extraZ); // 0x800A51F8

extern void razAlignYRotInterp(struct _Instance *source, struct _Position *dest, unsigned char segNumber, int Frames); // 0x800A52EC

extern int razConstrictAngle(struct _Instance *instance); // 0x800A5318

extern void razRotateUpperBody(struct _Instance *instance, struct evActionLookAroundData *data); // 0x800A542C

extern void razSetFadeEffect(short source, short dest, int steps); // 0x800A55FC

extern int razPlaneShift(struct _Instance *instance); // 0x800A5620

extern void razSpectralShift(); // 0x800A567C

extern void razMaterialShift(); // 0x800A578C

extern int RAZIEL_OkToShift(); // 0x800A5854

extern int razPickupAndGrab(struct __CharacterState *In, int CurrentSection); // 0x800A58E8

extern int razZeroAxis(long *x, long *y, int radius); // 0x800A5AF8

extern int razAdjustSpeed(struct _Instance *instance, int minSpeed); // 0x800A5B58

extern void razLaunchForce(struct _Instance *instance); // 0x800A5BF4

extern struct _Instance * razGetHeldItem(); // 0x800A5C84

extern struct _Instance * razGetHeldWeapon(); // 0x800A5CBC

extern void razReaverBladeOff(); // 0x800A5D1C

extern void razReaverBladeOn(); // 0x800A5D4C

extern int razReaverOff(); // 0x800A5D8C

extern int razReaverOn(); // 0x800A5E14

extern void razReaverPickup(struct _Instance *instance, struct _Instance *soulReaver); // 0x800A5EF8

extern void razReaverImbue(int reaverType); // 0x800A5FB4

extern int razGetReaverFromMask(int reaverMask); // 0x800A5FF4

extern void razReaverScale(int scale); // 0x800A6018

extern void razGetForwardNormal(struct _Instance *inst, struct _Instance *target); // 0x800A6080

extern void razGetRotFromNormal(struct _SVector *normal, struct _Rotation *rot); // 0x800A6164

extern void razCenterWithBlock(struct _Instance *inst, struct _Instance *target, int dist); // 0x800A61B0

extern void razSetPauseTranslation(struct _Instance *instance); // 0x800A6380

extern void razResetPauseTranslation(struct _Instance *instance); // 0x800A63F4

extern void razSelectMotionAnim(struct __CharacterState *In, int CurrentSection, int Frames, int *Anim); // 0x800A644C

extern int razApplyMotion(struct __CharacterState *In, int CurrentSection); // 0x800A6ABC

extern void razResetMotion(struct _Instance *instance); // 0x800A6C4C

extern void razSetDampingPhysics(struct _Instance *instance); // 0x800A6CA0

extern void razEnterWater(struct __CharacterState *In, int CurrentSection, struct evPhysicsSwimData *SwimData); // 0x800A6CD8

extern void razSetSwimVelocity(struct _Instance *instance, int vel, int accl); // 0x800A6F7C

extern void razSetWallCrawlNodes(struct _Instance *instance, struct evPhysicsWallCrawlData *data); // 0x800A6FD0

extern int razSwitchVAnimCharacterGroup(struct _Instance *instance, int animGroup, int *frame, int *frames); // 0x800A70BC

extern int razSwitchVAnimGroup(struct _Instance *instance, int section, int animGroup, int frame, int frames); // 0x800A7178

extern void razSwitchVAnimCharacterSingle(struct _Instance *instance, int anim, int *frame, int *frames); // 0x800A71D4

extern void razSwitchVAnimSingle(struct _Instance *instance, int section, int anim, int frame, int frames); // 0x800A728C

extern void razSwitchVAnim(struct _Instance *instance, int section, struct __VAnim *vAnim, int frame, int frames); // 0x800A72C0

extern int razProcessSAnim(struct _Instance *instance, int mode); // 0x800A738C

extern void razSwitchStringAnimation(struct _Instance *instance, int anim); // 0x800A7504

extern int CheckStringAnimation(struct _Instance *instance, int mode); // 0x800A75CC

extern void razLaunchBubbles(int segments, int count, int type); // 0x800A762C

extern void razSetCowlNoDraw(int mode); // 0x800A76C4

extern void razAttachControllers(); // 0x800A7774

extern void razSetPlayerEvent(); // 0x800A77DC

extern void razClearPlayerEvent(); // 0x800A7AE8

extern void razSetPlayerEventHistory(unsigned long event); // 0x800A7B20

extern int razSideMoveSpiderCheck(struct _Instance *instance, int x); // 0x800A7B38

extern struct _Instance * RAZIEL_QueryEngagedInstance(int index); // 0x800A7C04

extern int razUpdateSoundRamp(struct _Instance *instance, struct _SoundRamp *sound); // 0x800A7C3C

extern void razSetupSoundRamp(struct _Instance *instance, struct _SoundRamp *sound, int sfx, int startPitch, int endPitch, int startVolume, int endVolume, int timer, int distance); // 0x800A7D40

extern void RAZIEL_SetInteractiveMusic(int modifier, int action); // 0x800A7DE4

extern void RAZIEL_DebugHurtRaziel(); // 0x800A7E60

extern void RAZIEL_StartNewGame(); // 0x800A7E80

extern int razInBaseArea(char *name, int length); // 0x800A7EA8

extern void razPrepGlyph(); // 0x800A7F04


#endif
