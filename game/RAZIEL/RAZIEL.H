#ifndef RAZIEL_H
#define RAZIEL_H


extern void InitStates(struct _Instance *PlayerInstance); // 0x800A3F20

extern void StateInitIdle(struct __CharacterState *In, int CurrentSection, int Ptr); // 0x800A4284

extern void StateHandlerIdle(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A4528

extern void StateHandlerLookAround(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A4CA0

extern void StateHandlerCrouch(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A4F54

extern void StateHandlerDropAction(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A5698

extern void StateHandlerSoulSuck(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A599C

extern void StateHandlerStartTurn(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A5EC4

extern void StateInitStartMove(struct __CharacterState *In, int CurrentSection, int Frame); // 0x800A60C4

extern void StateHandlerStartMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A618C

extern void StateInitMove(struct __CharacterState *In, int CurrentSection, int Frames); // 0x800A67C0

extern void StateHandlerMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A6A14

extern void StateHandlerStopMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A6EF4

extern void StateHandlerCompression(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A7218

extern void StateHandlerJump(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A75E0

extern void StateHandlerFall(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A7A04

extern void StateHandlerSlide(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A7E10

extern void StateHandlerBlock(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A7FC4

extern void StateHandlerDeCompression(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A8328

extern void StateHandlerGlide(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A8688

extern void StateHandlerHang(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A8DD4

extern void StateHandlerPushObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A9308

extern void StateHandlerBreakOff(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A9630

extern void StateHandlerPullSwitch(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A99D0

extern void StateHandlerDragObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A9F40

extern void StateHandlerPickupObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AA64C

extern void StateHandlerAutoFace(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AA828

extern void StateHandlerGlyphs(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AAF24

extern void DefaultStateHandler(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AB594

extern long RazielAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x800ABE24

extern unsigned long RazielQuery(struct _Instance *instance, unsigned long Query); // 0x800AC1D4

extern void RazielPost(struct _Instance *instance, unsigned long Message, unsigned long Data); // 0x800AC518

extern int SetStates(struct _Instance *instance, struct GameTracker *GT, long *controlCommand, int AnalogLength); // 0x800ACD60

extern void ProcessConstrict(); // 0x800AD36C

extern void RelocateConstrict(struct _SVector *offset); // 0x800AD630

extern void ProcessEffects(struct _Instance *instance); // 0x800AD790

extern void ProcessInteractiveMusic(struct _Instance *instance); // 0x800AD8E0

extern void ProcessTimers(struct _Instance *instance); // 0x800ADA80

extern void SetTimer(int ticks); // 0x800ADAC8

extern void SetInteractiveMusic(int modifier, int action); // 0x800ADAD8

extern void ProcessSpecialAbilities(struct _Instance *instance); // 0x800ADB54

extern int GetControllerMessages(long *controlCommand); // 0x800ADD34

extern void RazielAdditionalCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800ADE8C

extern int GetEngageEvent(struct _Instance *instance); // 0x800AE374

extern int SetupReaction(struct _Instance *player, struct _Instance *instance); // 0x800AE3CC

extern int CheckHolding(struct _Instance *instance); // 0x800AE4C8

extern void DisableWristCollision(struct _Instance *instance, int Side); // 0x800AE4D4

extern void EnableWristCollision(struct _Instance *instance, int Side); // 0x800AE524

extern int GetCollisionType(struct _Instance *instance); // 0x800AE574

extern void InitGlyphSystem(struct _Instance *instance); // 0x800AE6D4

extern void mdRazielProcess(struct _Instance *playerInstance, struct GameTracker *gameTracker, long *controlCommand); // 0x800AE72C

extern void RazielProcess(struct _Instance *playerInstance, struct GameTracker *gameTracker); // 0x800AE7DC

extern void RazielInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800AE824

extern void RazielCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800AE8F4

extern void RAZIEL_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x800AEB08

extern void RAZIEL_SetLookAround(struct _Instance *instance); // 0x800AED30

extern void RAZIEL_ResetLookAround(struct _Instance *instance); // 0x800AEDA8

extern long RAZIEL_OkToLookAround(struct _Instance *playerInstance); // 0x800AEE24

extern void TrailWaterFX(struct _Instance *instance, int Segment, int Bubbles, int Type); // 0x800AEE78


#endif
