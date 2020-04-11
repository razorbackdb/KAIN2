#ifndef RAZIEL_H
#define RAZIEL_H


extern void InitStates(struct _Instance *PlayerInstance); // 0x800A7090

extern void StateInitIdle(struct __CharacterState *In, int CurrentSection, int Ptr); // 0x800A73B0

extern void StateHandlerIdle(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A7654

extern void StateHandlerLookAround(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A7EEC

extern void StateHandlerCrouch(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A8210

extern void StateHandlerDropAction(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A8944

extern void StateHandlerSoulSuck(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A8BD4

extern void StateHandlerStartTurn(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A910C

extern void StateInitStartMove(struct __CharacterState *In, int CurrentSection, int Frame); // 0x800A930C

extern void StateHandlerStartMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A93B8

extern void StateInitMove(struct __CharacterState *In, int CurrentSection, int Frames); // 0x800A9A1C

extern void StateHandlerMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A9C58

extern void StateHandlerStopMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AA29C

extern void StateHandlerCompression(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AA5C0

extern void StateHandlerJump(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AA988

extern void StateHandlerFall(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AADC4

extern void StateHandlerSlide(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AB1F4

extern void StateHandlerBlock(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AB3D4

extern void StateHandlerDeCompression(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AB7EC

extern void StateHandlerGlide(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ABB50

extern void StateHandlerHang(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AC2B0

extern void StateHandlerPushObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AC7E4

extern void StateHandlerBreakOff(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ACB14

extern void StateHandlerPullSwitch(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ACEB4

extern void StateHandlerDragObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AD4C4

extern void StateHandlerPickupObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ADBEC

extern void StateHandlerAutoFace(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ADDD0

extern void StateHandlerGlyphs(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AE4E8

extern void DefaultStateHandler(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AED74

extern long RazielAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x800AF684

extern unsigned long RazielQuery(struct _Instance *instance, unsigned long Query); // 0x800AFC94

extern void RazielPost(struct _Instance *instance, unsigned long Message, unsigned long Data); // 0x800AFFF0

extern int SetStates(struct _Instance *instance, struct GameTracker *GT, long *controlCommand, int AnalogLength); // 0x800B08B4

extern void ProcessConstrict(); // 0x800B0EE0

extern void RelocateConstrict(struct _SVector *offset); // 0x800B11A4

extern void ProcessEffects(struct _Instance *instance); // 0x800B1304

extern void ProcessHints(); // 0x800B1528

extern void ProcessInteractiveMusic(struct _Instance *instance); // 0x800B164C

extern void ProcessTimers(struct _Instance *instance); // 0x800B17FC

extern void SetTimer(int ticks); // 0x800B1D1C

extern void ProcessSpecialAbilities(struct _Instance *instance); // 0x800B1D2C

extern int GetControllerMessages(long *controlCommand); // 0x800B1EE4

extern void RazielAdditionalCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800B2110

extern int GetEngageEvent(struct _Instance *instance); // 0x800B25E4

extern int SetupReaction(struct _Instance *player, struct _Instance *instance); // 0x800B263C

extern int CheckHolding(struct _Instance *instance); // 0x800B2738

extern void DisableWristCollision(struct _Instance *instance, int Side); // 0x800B2744

extern void EnableWristCollision(struct _Instance *instance, int Side); // 0x800B2794

extern int GetCollisionType(struct _Instance *instance); // 0x800B27E4

extern void InitGlyphSystem(struct _Instance *instance); // 0x800B2944

extern void mdRazielProcess(struct _Instance *playerInstance, struct GameTracker *gameTracker, long *controlCommand); // 0x800B297C

extern void RazielProcess(struct _Instance *playerInstance, struct GameTracker *gameTracker); // 0x800B2A38

extern void RazielInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800B2A80

extern void RazielCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800B2B50

extern void RAZIEL_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x800B2DB8

extern void RAZIEL_SetLookAround(struct _Instance *instance); // 0x800B2FE0

extern void RAZIEL_ResetLookAround(struct _Instance *instance); // 0x800B3058

extern long RAZIEL_OkToLookAround(struct _Instance *playerInstance); // 0x800B30D4

extern void TrailWaterFX(struct _Instance *instance, int Segment, int Bubbles, int Type); // 0x800B315C


#endif
