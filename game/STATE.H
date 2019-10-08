#ifndef STATE_H
#define STATE_H

extern void InitMessageQueue(struct __MessageQueue *In);

extern struct __Event *DeMessageQueue(struct __MessageQueue *In);

extern void PurgeMessageQueue(struct __MessageQueue *In);

extern struct __Event *PeekMessageQueue(struct __MessageQueue *In);

extern void EnMessageQueue(struct __MessageQueue *In, struct __Event *Element);

extern void EnMessageQueueData(struct __MessageQueue *In, int ID, int Data);

extern void *CIRC_Alloc(int size);

extern int SetCollideInfoData(struct _CollideInfo *srcCI);

extern int SetMonsterHitData(struct _Instance *Sender, struct _Instance *lastHit, int Power, int knockBackDistance, int knockBackFrames);

extern int SetMonsterThrownData(struct _Instance *Sender, struct _Rotation *Direction, int Power);

extern int SetMonsterAlarmData(struct _Instance *sender, struct _Position *position, int type);

extern int SetMonsterSoulSuckData(struct _Instance *Sender, int x, int y, int z);

extern int SetMonsterImpaleData(struct _Instance *weapon, struct _Rotation *direction, struct _Position *position, int distance);

extern int SetObjectData(int x, int y, int PathNumber, struct _Instance *Force, int node);

extern int SetPositionData(int x, int y, int z);

extern int SetPhysicsGravityData(int UpperOffset, int LowerOffset, int x, int y, int z, int slope);

extern int SetPhysicsEdgeData(int UpperOffset, int ForwardOffset, int AboveOffset, int x, int y, int z, struct _SVector *Normal1, struct _SVector *Normal2, struct _SVector *Delta);

extern int SetPhysicsSwimData(int CheckDepth, struct _SVector *iVelocity, int SwimDepth, int WadeDepth, int TreadDepth);

extern int SetPhysicsDropOffData(int xOffset, int yOffset, int DropOffset, int slipSlope, int UpperOffset);

extern int SetPhysicsSlideData(int Segment, int ForwardVectorX, int ForwardVectorY, int ForwardVectorZ, int DropOffset, int UpperOffset, int Height);

extern int SetPhysicsWallCrawlData(int Segment, int Length, int ForwardOffset, int NormalDistance);

extern int SetPhysicsLinkedMoveData(struct _Instance *instance, int segment, struct _SVector *posDelta, struct _SVector *rotDelta);

extern int SetPhysicsDropHeightData(struct _Position *offset, int dropOffset, int mode);

extern int SetAnimationControllerDoneData(struct _Instance *instance, long segment, long type, int data);

extern int SetAnimationInstanceSwitchData(struct _Instance *instance, int anim, int frame, int frames, int mode);

extern int SetFXHitData(struct _Instance *hitter, int segment, int amount, int type);

extern int SetObjectThrowData(void *target, struct _SVector *angularVel, unsigned short type, unsigned short spinType, int speed, int gravity, int zVel, int initialXRot);

extern int SetObjectBreakOffData(struct _Instance *force, short node, short distance, short animation, int frame, int type, int action);

extern int SetControlInitHangData(struct _Instance *instance, long frame, long frames);

extern int SetControlInitIdleData(int mode, long frame, long frames);

extern int SetObjectDraftData(short force, unsigned short radius, unsigned short radiusCoef, unsigned short height, int maxVelocity);

extern int SetObjectAbsorbData(struct _Instance *force, unsigned short node, unsigned short steps);

extern int SetControlSaveDataData(long length, void *data);

extern int SetObjectIdleData(long mode, struct _Instance *instance);

extern int SetActionPlayHostAnimationData(struct _Instance *instance, struct _Instance *host, int newAnim, int newFrame, int frames, int mode);

extern int SetObjectBirthProjectileData(struct _Instance *instance, int joint, int type);

extern int SetShadowSegmentData(unsigned long total);

extern void G2EmulationInit();

extern void G2EmulationInstancePlayAnimation(struct _Instance *instance);

extern void G2EmulatePlayAnimation(struct __CharacterState *In);

extern void G2EmulationInstanceToInstanceSwitchAnimation(struct _Instance *instance, struct _Instance *host, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode);

extern void G2EmulationInstanceSwitchAnimation(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode);

extern void G2EmulationInstanceSwitchAnimationAlpha(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable);

extern void G2EmulationSwitchAnimation(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode);

extern void G2EmulationSwitchAnimationAlpha(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable);

extern void G2EmulationSwitchAnimationSync(struct __CharacterState *In, int SlaveSectionID, int MasterSectionID, int Frames);

extern void G2EmulationInstanceToInstanceSwitchAnimationCharacter(struct _Instance *instance, struct _Instance *host, int NewAnim, int NewFrame, int Frames, int Mode);

extern void G2EmulationSwitchAnimationCharacter(struct __CharacterState *In, int NewAnim, int NewFrame, int Frames, int Mode);

extern void G2EmulationSwitchAnimationCharacterAlpha(struct __CharacterState *In, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable);

extern void G2EmulationInstanceSetAnimation(struct _Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames);

extern void G2EmulationSetAnimation(struct __CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames);

extern void G2EmulationInstanceSetMode(struct _Instance *instance, int CurrentSection, int Mode);

extern void G2EmulationSetMode(struct __CharacterState *In, int CurrentSection, int Mode);

extern void G2EmulationInstanceSetAnimSpeed(struct _Instance *instance, int CurrentSection, int speed);

extern int G2EmulationInstanceQueryAnimation(struct _Instance *instance, int CurrentSection);

extern int G2EmulationQueryAnimation(struct __CharacterState *In, int CurrentSection);

extern int G2EmulationInstanceQueryFrame(struct _Instance *instance, int CurrentSection);

extern int G2EmulationInstanceQueryLastFrame(struct _Instance *instance, int CurrentSection);

extern int G2EmulationInstanceQueryPassedFrame(struct _Instance *instance, int CurrentSection, int frame);

extern int G2EmulationQueryFrame(struct __CharacterState *In, int CurrentSection);

extern int G2EmulationInstanceQueryMode(struct _Instance *instance, int CurrentSection);

extern int G2EmulationQueryMode(struct __CharacterState *In, int CurrentSection);

extern void G2EmulationInstanceSetStartAndEndSegment(struct _Instance *instance, int CurrentSection, short Start, short End);

extern void G2EmulationSetStartAndEndSegment(struct __CharacterState *In, int CurrentSection, short Start, short End);

extern void G2EmulationInstanceSetTotalSections(struct _Instance *instance, short Total);

extern void G2EmulationSetTotalSections(struct __CharacterState *In, short Total);

extern void G2EmulationInstanceInitSection(struct _Instance *instance, int CurrentSection, void *callback, void *data);

extern void G2EmulationSetInterpController_Vector(struct _Instance *instance, long segment, long type, struct _G2SVector3_Type *vec, int Frames, int Data);

extern void StateSwitchStateDataDefault(struct __CharacterState *In, int CurrentSection, TDRFuncPtr_StateSwitchStateDataDefault2NewProcess NewProcess, int Data);

extern void StateSwitchStateCharacterDataDefault(struct __CharacterState *In, TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess NewProcess, int Data);

extern void StateSwitchStateData(struct __CharacterState *In, int CurrentSection, TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess, int Data);

extern void StateSwitchStateCharacterData(struct __CharacterState *In, TDRFuncPtr_StateSwitchStateCharacterData1NewProcess NewProcess, int Data);

extern void StateGovernState(struct __CharacterState *In, int Frames);

typedef void (*TDRFuncPtr_StateSwitchStateCharacterData1NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateData2NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)();

#endif
