#ifndef STATE_H
#define STATE_H


extern void InitMessageQueue(struct __MessageQueue *In); // 0x80070024

extern struct __Event * DeMessageQueue(struct __MessageQueue *In); // 0x80070030

extern void PurgeMessageQueue(struct __MessageQueue *In); // 0x8007006C

extern struct __Event * PeekMessageQueue(struct __MessageQueue *In); // 0x80070078

extern void EnMessageQueue(struct __MessageQueue *In, struct __Event *Element); // 0x800700A0

extern void EnMessageQueueData(struct __MessageQueue *In, int ID, int Data); // 0x800700CC

extern void * CIRC_Alloc(int size); // 0x80070148

extern int SetCollideInfoData(struct _CollideInfo *srcCI); // 0x80070190

extern int SetMonsterHitData(struct _Instance *Sender, struct _Instance *lastHit, int Power, int knockBackDistance, int knockBackFrames); // 0x800701EC

extern int SetMonsterThrownData(struct _Instance *Sender, struct _Rotation *Direction, int Power); // 0x80070258

extern int SetMonsterAlarmData(struct _Instance *sender, struct _Position *position, int type); // 0x800702C0

extern int SetMonsterSoulSuckData(struct _Instance *Sender, int x, int y, int z); // 0x80070328

extern int SetMonsterImpaleData(struct _Instance *weapon, struct _Rotation *direction, struct _Position *position, int distance); // 0x80070384

extern int SetObjectData(int x, int y, int PathNumber, struct _Instance *Force, int node); // 0x8007041C

extern int SetPositionData(int x, int y, int z); // 0x80070488

extern int SetPhysicsGravityData(int UpperOffset, int LowerOffset, int x, int y, int z, int slope); // 0x800704D4

extern int SetPhysicsEdgeData(int UpperOffset, int ForwardOffset, int AboveOffset, int x, int y, int z, struct _SVector *Normal1, struct _SVector *Normal2, struct _SVector *Delta); // 0x80070550

extern int SetPhysicsSwimData(int CheckDepth, struct _SVector *iVelocity, int SwimDepth, int WadeDepth, int TreadDepth); // 0x800705FC

extern int SetPhysicsDropOffData(int xOffset, int yOffset, int DropOffset, int slipSlope); // 0x80070668

extern int SetPhysicsSlideData(int Segment, int ForwardVectorX, int ForwardVectorY, int ForwardVectorZ, int DropOffset, int UpperOffset, int Height); // 0x800706C4

extern int SetPhysicsWallCrawlData(int Segment, int Length, int ForwardOffset, int NormalDistance); // 0x80070750

extern int SetPhysicsLinkedMoveData(struct _Instance *instance, int segment, struct _SVector *posDelta, struct _SVector *rotDelta); // 0x800707AC

extern int SetPhysicsDropHeightData(struct _Position *offset, int dropOffset, int mode); // 0x8007084C

extern int SetAnimationControllerDoneData(struct _Instance *instance, long segment, long type, int data); // 0x800708BC

extern int SetAnimationInstanceSwitchData(struct _Instance *instance, int anim, int frame, int frames, int mode); // 0x80070918

extern int SetFXHitData(struct _Instance *hitter, int segment, int amount, int type); // 0x80070984

extern int SetObjectThrowData(void *target, struct _SVector *angularVel, unsigned short type, unsigned short spinType, int speed, int gravity, int zVel, int initialXRot); // 0x80070A80

extern int SetObjectBreakOffData(struct _Instance *force, short node, short distance, short animation, int frame, int type, int action); // 0x80070BEC

extern int SetControlInitHangData(struct _Instance *instance, long frame, long frames); // 0x80070C78

extern int SetControlInitIdleData(int mode, long frame, long frames); // 0x80070CC4

extern int SetObjectDraftData(short force, unsigned short radius, unsigned short radiusCoef, unsigned short height, int maxVelocity); // 0x80070D10

extern int SetObjectAbsorbData(struct _Instance *force, unsigned short node, unsigned short steps); // 0x80070D7C

extern int SetControlSaveDataData(long length, void *data); // 0x80070DC8

extern int SetObjectIdleData(long mode, struct _Instance *instance); // 0x80070E04

extern int SetActionPlayHostAnimationData(struct _Instance *instance, struct _Instance *host, int newAnim, int newFrame, int frames, int mode); // 0x80070E40

extern int SetObjectBirthProjectileData(struct _Instance *instance, int joint, int type); // 0x80070EBC

extern int SetShadowSegmentData(unsigned long total); // 0x80070F0C

extern void G2EmulationInit(); // 0x80070F38

extern void G2EmulationInstancePlayAnimation(struct _Instance *instance); // 0x80071124

extern void G2EmulatePlayAnimation(struct __CharacterState *In); // 0x8007118C

extern void G2EmulationInstanceToInstanceSwitchAnimation(struct _Instance *instance, struct _Instance *host, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x800711B0

extern void G2EmulationInstanceSwitchAnimation(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x800712A8

extern void G2EmulationInstanceSwitchAnimationAlpha(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable); // 0x8007139C

extern void G2EmulationSwitchAnimation(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x8007140C

extern void G2EmulationSwitchAnimationAlpha(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable); // 0x80071450

extern void G2EmulationSwitchAnimationSync(struct __CharacterState *In, int SlaveSectionID, int MasterSectionID, int Frames); // 0x800714C8

extern void G2EmulationInstanceToInstanceSwitchAnimationCharacter(struct _Instance *instance, struct _Instance *host, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80071694

extern void G2EmulationSwitchAnimationCharacter(struct __CharacterState *In, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80071780

extern void G2EmulationSwitchAnimationCharacterAlpha(struct __CharacterState *In, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable); // 0x80071874

extern void G2EmulationInstanceSetAnimation(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames); // 0x800718CC

extern void G2EmulationSetAnimation(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames); // 0x80071974

extern void G2EmulationInstanceSetMode(struct _Instance *instance, int CurrentSection, int Mode); // 0x800719AC

extern void G2EmulationSetMode(struct __CharacterState *In, int CurrentSection, int Mode); // 0x80071A2C

extern void G2EmulationInstanceSetAnimSpeed(struct _Instance *instance, int CurrentSection, int speed); // 0x80071A50

extern int G2EmulationInstanceQueryAnimation(struct _Instance *instance, int CurrentSection); // 0x80071A6C

extern int G2EmulationQueryAnimation(struct __CharacterState *In, int CurrentSection); // 0x80071A8C

extern int G2EmulationInstanceQueryFrame(struct _Instance *instance, int CurrentSection); // 0x80071AB0

extern int G2EmulationInstanceQueryLastFrame(struct _Instance *instance, int CurrentSection); // 0x80071AE4

extern int G2EmulationInstanceQueryPassedFrame(struct _Instance *instance, int CurrentSection, int frame); // 0x80071B18

extern int G2EmulationQueryFrame(struct __CharacterState *In, int CurrentSection); // 0x80071BC0

extern int G2EmulationInstanceQueryMode(struct _Instance *instance, int CurrentSection); // 0x80071BE4

extern int G2EmulationQueryMode(struct __CharacterState *In, int CurrentSection); // 0x80071C2C

extern void G2EmulationInstanceSetStartAndEndSegment(struct _Instance *instance, int CurrentSection, short Start, short End); // 0x80071C50

extern void G2EmulationSetStartAndEndSegment(struct __CharacterState *In, int CurrentSection, short Start, short End); // 0x80071C7C

extern void G2EmulationInstanceSetTotalSections(struct _Instance *instance, short Total); // 0x80071CAC

extern void G2EmulationSetTotalSections(struct __CharacterState *In, short Total); // 0x80071D30

extern void G2EmulationInstanceInitSection(struct _Instance *instance, int CurrentSection, void *callback, void *data); // 0x80071D60

extern void G2EmulationSetInterpController_Vector(struct _Instance *instance, long segment, long type, struct _G2SVector3_Type *vec, int Frames, int Data); // 0x80071D84

extern void StateSwitchStateData(struct __CharacterState *In, int CurrentSection, TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess, int Data); // 0x80071E0C

extern void StateSwitchStateCharacterData(struct __CharacterState *In, TDRFuncPtr_StateSwitchStateCharacterData1NewProcess NewProcess, int Data); // 0x80071ED8

extern void StateGovernState(struct __CharacterState *In, int Frames); // 0x80071F50


typedef void (*TDRFuncPtr_StateSwitchStateCharacterData1NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateData2NewProcess)();




#endif
