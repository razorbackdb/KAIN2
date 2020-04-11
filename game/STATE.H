#ifndef STATE_H
#define STATE_H


extern void InitMessageQueue(struct __MessageQueue *In); // 0x80070538

extern struct __Event * DeMessageQueue(struct __MessageQueue *In); // 0x80070544

extern void PurgeMessageQueue(struct __MessageQueue *In); // 0x80070580

extern struct __Event * PeekMessageQueue(struct __MessageQueue *In); // 0x8007058C

extern void EnMessageQueue(struct __MessageQueue *In, struct __Event *Element); // 0x800705B4

extern void EnMessageQueueData(struct __MessageQueue *In, int ID, int Data); // 0x800705E0

extern void * CIRC_Alloc(int size); // 0x8007065C

extern int SetCollideInfoData(struct _CollideInfo *srcCI); // 0x800706A4

extern int SetMonsterHitData(struct _Instance *Sender, struct _Instance *lastHit, int Power, int knockBackDistance, int knockBackFrames); // 0x80070700

extern int SetMonsterThrownData(struct _Instance *Sender, struct _Rotation *Direction, int Power); // 0x8007076C

extern int SetMonsterAlarmData(struct _Instance *sender, struct _Position *position, int type); // 0x800707D4

extern int SetMonsterSoulSuckData(struct _Instance *Sender, int x, int y, int z); // 0x8007083C

extern int SetMonsterImpaleData(struct _Instance *weapon, struct _Rotation *direction, struct _Position *position, int distance); // 0x80070898

extern int SetObjectData(int x, int y, int PathNumber, struct _Instance *Force, int node); // 0x80070930

extern int SetPositionData(int x, int y, int z); // 0x8007099C

extern int SetPhysicsGravityData(int UpperOffset, int LowerOffset, int x, int y, int z, int slope); // 0x800709E8

extern int SetPhysicsEdgeData(int UpperOffset, int ForwardOffset, int AboveOffset, int x, int y, int z, struct _SVector *Normal1, struct _SVector *Normal2, struct _SVector *Delta); // 0x80070A64

extern int SetPhysicsSwimData(int CheckDepth, struct _SVector *iVelocity, int SwimDepth, int WadeDepth, int TreadDepth); // 0x80070B10

extern int SetPhysicsDropOffData(int xOffset, int yOffset, int DropOffset, int slipSlope, int UpperOffset); // 0x80070B7C

extern int SetPhysicsSlideData(int Segment, int ForwardVectorX, int ForwardVectorY, int ForwardVectorZ, int DropOffset, int UpperOffset, int Height); // 0x80070BE8

extern int SetPhysicsWallCrawlData(int Segment, int Length, int ForwardOffset, int NormalDistance); // 0x80070C74

extern int SetPhysicsLinkedMoveData(struct _Instance *instance, int segment, struct _SVector *posDelta, struct _SVector *rotDelta); // 0x80070CD0

extern int SetPhysicsDropHeightData(struct _Position *offset, int dropOffset, int mode); // 0x80070D70

extern int SetAnimationControllerDoneData(struct _Instance *instance, long segment, long type, int data); // 0x80070DE0

extern int SetAnimationInstanceSwitchData(struct _Instance *instance, int anim, int frame, int frames, int mode); // 0x80070E3C

extern int SetFXHitData(struct _Instance *hitter, int segment, int amount, int type); // 0x80070EA8

extern int SetObjectThrowData(void *target, struct _SVector *angularVel, unsigned short type, unsigned short spinType, int speed, int gravity, int zVel, int initialXRot); // 0x80070FA4

extern int SetObjectBreakOffData(struct _Instance *force, short node, short distance, short animation, int frame, int type, int action); // 0x80071110

extern int SetControlInitHangData(struct _Instance *instance, long frame, long frames); // 0x8007119C

extern int SetControlInitIdleData(int mode, long frame, long frames); // 0x800711E8

extern int SetObjectDraftData(short force, unsigned short radius, unsigned short radiusCoef, unsigned short height, int maxVelocity); // 0x80071234

extern int SetObjectAbsorbData(struct _Instance *force, unsigned short node, unsigned short steps); // 0x800712A0

extern int SetControlSaveDataData(long length, void *data); // 0x800712EC

extern int SetObjectIdleData(long mode, struct _Instance *instance); // 0x80071328

extern int SetActionPlayHostAnimationData(struct _Instance *instance, struct _Instance *host, int newAnim, int newFrame, int frames, int mode); // 0x80071364

extern int SetObjectBirthProjectileData(struct _Instance *instance, int joint, int type); // 0x800713E0

extern int SetShadowSegmentData(unsigned long total); // 0x80071430

extern void G2EmulationInit(); // 0x8007145C

extern void G2EmulationInstancePlayAnimation(struct _Instance *instance); // 0x80071648

extern void G2EmulatePlayAnimation(struct __CharacterState *In); // 0x800716B0

extern void G2EmulationInstanceToInstanceSwitchAnimation(struct _Instance *instance, struct _Instance *host, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x800716D4

extern void G2EmulationInstanceSwitchAnimation(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x800717CC

extern void G2EmulationInstanceSwitchAnimationAlpha(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable); // 0x800718C0

extern void G2EmulationSwitchAnimation(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80071930

extern void G2EmulationSwitchAnimationAlpha(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable); // 0x80071974

extern void G2EmulationSwitchAnimationSync(struct __CharacterState *In, int SlaveSectionID, int MasterSectionID, int Frames); // 0x800719EC

extern void G2EmulationInstanceToInstanceSwitchAnimationCharacter(struct _Instance *instance, struct _Instance *host, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80071BB8

extern void G2EmulationSwitchAnimationCharacter(struct __CharacterState *In, int NewAnim, int NewFrame, int Frames, int Mode); // 0x80071CA4

extern void G2EmulationSwitchAnimationCharacterAlpha(struct __CharacterState *In, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable); // 0x80071D98

extern void G2EmulationInstanceSetAnimation(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames); // 0x80071DF0

extern void G2EmulationSetAnimation(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames); // 0x80071E98

extern void G2EmulationInstanceSetMode(struct _Instance *instance, int CurrentSection, int Mode); // 0x80071ED0

extern void G2EmulationSetMode(struct __CharacterState *In, int CurrentSection, int Mode); // 0x80071F50

extern void G2EmulationInstanceSetAnimSpeed(struct _Instance *instance, int CurrentSection, int speed); // 0x80071F74

extern int G2EmulationInstanceQueryAnimation(struct _Instance *instance, int CurrentSection); // 0x80071F90

extern int G2EmulationQueryAnimation(struct __CharacterState *In, int CurrentSection); // 0x80071FB0

extern int G2EmulationInstanceQueryFrame(struct _Instance *instance, int CurrentSection); // 0x80071FD4

extern int G2EmulationInstanceQueryLastFrame(struct _Instance *instance, int CurrentSection); // 0x80072008

extern int G2EmulationInstanceQueryPassedFrame(struct _Instance *instance, int CurrentSection, int frame); // 0x8007203C

extern int G2EmulationQueryFrame(struct __CharacterState *In, int CurrentSection); // 0x800720E4

extern int G2EmulationInstanceQueryMode(struct _Instance *instance, int CurrentSection); // 0x80072108

extern int G2EmulationQueryMode(struct __CharacterState *In, int CurrentSection); // 0x80072150

extern void G2EmulationInstanceSetStartAndEndSegment(struct _Instance *instance, int CurrentSection, short Start, short End); // 0x80072174

extern void G2EmulationSetStartAndEndSegment(struct __CharacterState *In, int CurrentSection, short Start, short End); // 0x800721A0

extern void G2EmulationInstanceSetTotalSections(struct _Instance *instance, short Total); // 0x800721D0

extern void G2EmulationSetTotalSections(struct __CharacterState *In, short Total); // 0x80072254

extern void G2EmulationInstanceInitSection(struct _Instance *instance, int CurrentSection, void *callback, void *data); // 0x80072284

extern void G2EmulationSetInterpController_Vector(struct _Instance *instance, long segment, long type, struct _G2SVector3_Type *vec, int Frames, int Data); // 0x800722A8

extern void StateSwitchStateDataDefault(struct __CharacterState *In, int CurrentSection, TDRFuncPtr_StateSwitchStateDataDefault2NewProcess NewProcess, int Data); // 0x80072330

extern void StateSwitchStateCharacterDataDefault(struct __CharacterState *In, TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess NewProcess, int Data); // 0x80072398

extern void StateSwitchStateData(struct __CharacterState *In, int CurrentSection, TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess, int Data); // 0x80072410

extern void StateSwitchStateCharacterData(struct __CharacterState *In, TDRFuncPtr_StateSwitchStateCharacterData1NewProcess NewProcess, int Data); // 0x800724DC

extern void StateGovernState(struct __CharacterState *In, int Frames); // 0x80072554


typedef void (*TDRFuncPtr_StateSwitchStateCharacterData1NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateData2NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)();




#endif
