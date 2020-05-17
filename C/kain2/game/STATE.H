#ifndef STATE_H
#define STATE_H


extern void InitMessageQueue(struct __MessageQueue *In); // 0x80070C90

extern struct __Event * DeMessageQueue(struct __MessageQueue *In); // 0x80070C9C

extern void PurgeMessageQueue(struct __MessageQueue *In); // 0x80070CD8

extern struct __Event * PeekMessageQueue(struct __MessageQueue *In); // 0x80070CE4

extern void EnMessageQueue(struct __MessageQueue *In, struct __Event *Element); // 0x80070D0C

extern void EnMessageQueueData(struct __MessageQueue *In, int ID, int Data); // 0x80070D38

extern void * CIRC_Alloc(int size); // 0x80070DB4

extern int SetCollideInfoData(struct _CollideInfo *srcCI); // 0x80070DF8

extern int SetMonsterHitData(struct _Instance *Sender, struct _Instance *lastHit, int Power, int knockBackDistance, int knockBackFrames); // 0x80070E54

extern int SetMonsterThrownData(struct _Instance *Sender, struct _Rotation *Direction, int Power); // 0x80070EC0

extern int SetMonsterAlarmData(struct _Instance *sender, struct _Position *position, int type); // 0x80070F28

extern int SetMonsterSoulSuckData(struct _Instance *Sender, int x, int y, int z); // 0x80070F90

extern int SetMonsterImpaleData(struct _Instance *weapon, struct _Rotation *direction, struct _Position *position, int distance); // 0x80070FEC

extern int SetObjectData(int x, int y, int PathNumber, struct _Instance *Force, int node); // 0x80071084

extern int SetPositionData(int x, int y, int z); // 0x800710F0

extern int SetPhysicsGravityData(int UpperOffset, int LowerOffset, int x, int y, int z, int slope); // 0x8007113C

extern int SetPhysicsEdgeData(int UpperOffset, int ForwardOffset, int AboveOffset, int x, int y, int z, struct _SVector *Normal1, struct _SVector *Normal2, struct _SVector *Delta); // 0x800711B8

extern int SetPhysicsSwimData(int CheckDepth, struct _SVector *iVelocity, int SwimDepth, int WadeDepth, int TreadDepth); // 0x80071264

extern int SetPhysicsDropOffData(int xOffset, int yOffset, int DropOffset, int slipSlope, int UpperOffset); // 0x800712D0

extern int SetPhysicsSlideData(int Segment, int ForwardVectorX, int ForwardVectorY, int ForwardVectorZ, int DropOffset, int UpperOffset, int Height); // 0x8007133C

extern int SetPhysicsWallCrawlData(int Segment, int Length, int ForwardOffset, int NormalDistance); // 0x800713C8

extern int SetPhysicsLinkedMoveData(struct _Instance *instance, int segment, struct _SVector *posDelta, struct _SVector *rotDelta); // 0x80071424

extern int SetPhysicsDropHeightData(struct _Position *offset, int dropOffset, int mode); // 0x800714C4

extern int SetAnimationControllerDoneData(struct _Instance *instance, long segment, long type, int data); // 0x80071534

extern int SetAnimationInstanceSwitchData(struct _Instance *instance, int anim, int frame, int frames, int mode); // 0x80071590

extern int SetFXHitData(struct _Instance *hitter, int segment, int amount, int type); // 0x800715FC

extern int SetObjectThrowData(void *target, struct _SVector *angularVel, unsigned short type, unsigned short spinType, int speed, int gravity, int zVel, int initialXRot); // 0x800716F8

extern int SetObjectBreakOffData(struct _Instance *force, short node, short distance, short animation, int frame, int type, int action); // 0x80071864

extern int SetControlInitHangData(struct _Instance *instance, long frame, long frames); // 0x800718F0

extern int SetControlInitIdleData(int mode, long frame, long frames); // 0x8007193C

extern int SetObjectDraftData(short force, unsigned short radius, unsigned short radiusCoef, unsigned short height, int maxVelocity); // 0x80071988

extern int SetObjectAbsorbData(struct _Instance *force, unsigned short node, unsigned short steps); // 0x800719F4

extern int SetControlSaveDataData(long length, void *data); // 0x80071A40

extern int SetObjectIdleData(long mode, struct _Instance *instance); // 0x80071A7C

extern int SetActionPlayHostAnimationData(struct _Instance *instance, struct _Instance *host, int newAnim, int newFrame, int frames, int mode); // 0x80071AB8

extern int SetObjectBirthProjectileData(struct _Instance *instance, int joint, int type); // 0x80071B34

extern int SetShadowSegmentData(unsigned long total); // 0x80071B84

extern void G2EmulationInit(); // 0x80071BB0

extern void G2EmulationInstancePlayAnimation(struct _Instance *instance); // 0x80071D9C

extern void G2EmulatePlayAnimation(struct __CharacterState *In); // 0x80071E04

extern void G2EmulationInstanceToInstanceSwitchAnimation(struct _Instance *instance, struct _Instance *host, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80071E28

extern void G2EmulationInstanceSwitchAnimation(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80071F20

extern void G2EmulationInstanceSwitchAnimationAlpha(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable); // 0x80072014

extern void G2EmulationSwitchAnimation(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80072080

extern void G2EmulationSwitchAnimationAlpha(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable); // 0x800720C4

extern void G2EmulationSwitchAnimationSync(struct __CharacterState *In, int SlaveSectionID, int MasterSectionID, int Frames); // 0x80072138

extern void G2EmulationInstanceToInstanceSwitchAnimationCharacter(struct _Instance *instance, struct _Instance *host, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80072304

extern void G2EmulationSwitchAnimationCharacter(struct __CharacterState *In, int NewAnim, int NewFrame, int Frames, int Mode); // 0x800723F0

extern void G2EmulationInstanceSetAnimation(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames); // 0x800724E4

extern void G2EmulationSetAnimation(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames); // 0x8007258C

extern void G2EmulationInstanceSetMode(struct _Instance *instance, int CurrentSection, int Mode); // 0x800725C4

extern void G2EmulationSetMode(struct __CharacterState *In, int CurrentSection, int Mode); // 0x80072644

extern void G2EmulationInstanceSetAnimSpeed(struct _Instance *instance, int CurrentSection, int speed); // 0x80072668

extern int G2EmulationInstanceQueryAnimation(struct _Instance *instance, int CurrentSection); // 0x80072684

extern int G2EmulationQueryAnimation(struct __CharacterState *In, int CurrentSection); // 0x800726A4

extern int G2EmulationInstanceQueryFrame(struct _Instance *instance, int CurrentSection); // 0x800726C8

extern int G2EmulationInstanceQueryLastFrame(struct _Instance *instance, int CurrentSection); // 0x800726FC

extern int G2EmulationInstanceQueryPassedFrame(struct _Instance *instance, int CurrentSection, int frame); // 0x80072730

extern int G2EmulationQueryFrame(struct __CharacterState *In, int CurrentSection); // 0x800727D8

extern int G2EmulationInstanceQueryMode(struct _Instance *instance, int CurrentSection); // 0x800727FC

extern int G2EmulationQueryMode(struct __CharacterState *In, int CurrentSection); // 0x80072844

extern void G2EmulationInstanceSetStartAndEndSegment(struct _Instance *instance, int CurrentSection, short Start, short End); // 0x80072868

extern void G2EmulationSetStartAndEndSegment(struct __CharacterState *In, int CurrentSection, short Start, short End); // 0x80072894

extern void G2EmulationInstanceSetTotalSections(struct _Instance *instance, short Total); // 0x800728C4

extern void G2EmulationSetTotalSections(struct __CharacterState *In, short Total); // 0x80072948

extern void G2EmulationInstanceInitSection(struct _Instance *instance, int CurrentSection, void *callback, void *data); // 0x80072978

extern void G2EmulationSetInterpController_Vector(struct _Instance *instance, long segment, long type, struct _G2SVector3_Type *vec, int Frames, int Data); // 0x8007299C

extern void StateSwitchStateDataDefault(struct __CharacterState *In, int CurrentSection, TDRFuncPtr_StateSwitchStateDataDefault2NewProcess NewProcess, int Data); // 0x80072A24

extern void StateSwitchStateCharacterDataDefault(struct __CharacterState *In, TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess NewProcess, int Data); // 0x80072A8C

extern void StateSwitchStateData(struct __CharacterState *In, int CurrentSection, TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess, int Data); // 0x80072B04

extern void StateSwitchStateCharacterData(struct __CharacterState *In, TDRFuncPtr_StateSwitchStateCharacterData1NewProcess NewProcess, int Data); // 0x80072BD0

extern void StateGovernState(struct __CharacterState *In, int Frames); // 0x80072CC4


typedef void (*TDRFuncPtr_StateSwitchStateCharacterData1NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateData2NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)();




#endif
