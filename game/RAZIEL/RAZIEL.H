#ifndef RAZIEL_H
#define RAZIEL_H

extern void InitStates(struct _Instance *PlayerInstance);

extern void StateInitIdle(struct __CharacterState *In, int CurrentSection, int Ptr);

extern void StateHandlerIdle(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerLookAround(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerCrouch(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerDropAction(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerSoulSuck(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerStartTurn(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateInitStartMove(struct __CharacterState *In, int CurrentSection, int Frame);

extern void StateHandlerStartMove(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateInitMove(struct __CharacterState *In, int CurrentSection, int Frames);

extern void StateHandlerMove(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerStopMove(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerCompression(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerJump(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerFall(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerSlide(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerBlock(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerDeCompression(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerGlide(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerHang(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerPushObject(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerBreakOff(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerPullSwitch(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerDragObject(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerPickupObject(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerAutoFace(struct __CharacterState *In, int CurrentSection, int Data);

extern void StateHandlerGlyphs(struct __CharacterState *In, int CurrentSection, int Data);

extern void DefaultStateHandler(struct __CharacterState *In, int CurrentSection, int Data);

extern long RazielAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data);

extern unsigned long RazielQuery(struct _Instance *instance, unsigned long Query);

extern void RazielPost(struct _Instance *instance, unsigned long Message, unsigned long Data);

extern int SetStates(struct _Instance *instance, struct GameTracker *GT, long *controlCommand, int AnalogLength);

extern void ProcessConstrict();

extern void RelocateConstrict(struct _SVector *offset);

extern void ProcessEffects(struct _Instance *instance);

extern void ProcessHints();

extern void ProcessInteractiveMusic(struct _Instance *instance);

extern void ProcessTimers(struct _Instance *instance);

extern void SetTimer(int ticks);

extern void ProcessSpecialAbilities(struct _Instance *instance);

extern int GetControllerMessages(long *controlCommand);

extern void RazielAdditionalCollide(struct _Instance *instance, struct GameTracker *gameTracker);

extern int GetEngageEvent(struct _Instance *instance);

extern int SetupReaction(struct _Instance *player, struct _Instance *instance);

extern int CheckHolding(struct _Instance *instance);

extern void DisableWristCollision(struct _Instance *instance, int Side);

extern void EnableWristCollision(struct _Instance *instance, int Side);

extern int GetCollisionType(struct _Instance *instance);

extern void InitGlyphSystem(struct _Instance *instance);

extern void mdRazielProcess(struct _Instance *playerInstance, struct GameTracker *gameTracker, long *controlCommand);

extern void RazielProcess(struct _Instance *playerInstance, struct GameTracker *gameTracker);

extern void RazielInit(struct _Instance *instance, struct GameTracker *gameTracker);

extern void RazielCollide(struct _Instance *instance, struct GameTracker *gameTracker);

extern void RAZIEL_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker);

extern void RAZIEL_SetLookAround(struct _Instance *instance);

extern void RAZIEL_ResetLookAround(struct _Instance *instance);

extern long RAZIEL_OkToLookAround(struct _Instance *playerInstance);

extern void TrailWaterFX(struct _Instance *instance, int Segment, int Bubbles, int Type);

#endif
