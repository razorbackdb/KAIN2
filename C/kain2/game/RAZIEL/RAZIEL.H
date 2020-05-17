#ifndef RAZIEL_H
#define RAZIEL_H


extern void InitStates(struct _Instance *PlayerInstance); // 0x800A7F54

extern void StateInitIdle(struct __CharacterState *In, int CurrentSection, int Ptr); // 0x800A823C

extern void StateHandlerIdle(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A84E0

extern void StateHandlerLookAround(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A8DA0

extern void StateHandlerCrouch(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A90E8

extern void StateHandlerDropAction(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A9860

extern void StateHandlerSoulSuck(struct __CharacterState *In, int CurrentSection, int Data); // 0x800A9AE0

extern void StateHandlerStartTurn(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AA018

extern void StateInitStartMove(struct __CharacterState *In, int CurrentSection, int Frame); // 0x800AA218

extern void StateHandlerStartMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AA2C4

extern void StateInitMove(struct __CharacterState *In, int CurrentSection, int Frames); // 0x800AA964

extern void StateHandlerMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AABA8

extern void StateHandlerStopMove(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AB27C

extern void StateHandlerCompression(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AB5AC

extern void StateHandlerJump(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AB970

extern void StateHandlerFall(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ABDA8

extern void StateHandlerSlide(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AC21C

extern void StateHandlerBlock(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AC3FC

extern void StateHandlerDeCompression(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AC818

extern void StateHandlerGlide(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ACB88

extern void StateHandlerHang(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AD2F4

extern void StateHandlerPushObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AD898

extern void StateHandlerBreakOff(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ADBC4

extern void StateHandlerPullSwitch(struct __CharacterState *In, int CurrentSection, int Data); // 0x800ADFBC

extern void StateHandlerDragObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AE5CC

extern void StateHandlerPickupObject(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AECF4

extern void StateHandlerAutoFace(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AEF10

extern void StateHandlerGlyphs(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AF650

extern void DefaultStateHandler(struct __CharacterState *In, int CurrentSection, int Data); // 0x800AFEE4

extern long RazielAnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x800B087C

extern long RazielAnimCallbackDuringPause(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x800B0E80

extern unsigned long RazielQuery(struct _Instance *instance, unsigned long Query); // 0x800B0F34

extern void RazielPost(struct _Instance *instance, unsigned long Message, unsigned long Data); // 0x800B1290

extern int SetStates(struct _Instance *instance, struct GameTracker *GT, long *controlCommand, int AnalogLength); // 0x800B1C10

extern void ProcessConstrict(); // 0x800B22A0

extern void RelocateConstrict(struct _SVector *offset); // 0x800B2574

extern void ProcessEffects(struct _Instance *instance); // 0x800B26D4

extern void ProcessHints(); // 0x800B28E8

extern void ProcessInteractiveMusic(struct _Instance *instance); // 0x800B2A20

extern void ProcessTimers(struct _Instance *instance); // 0x800B2BD0

extern void SetTimer(int ticks); // 0x800B30C4

extern void ProcessSpecialAbilities(struct _Instance *instance); // 0x800B30D4

extern int GetControllerMessages(long *controlCommand); // 0x800B328C

extern void RazielAdditionalCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800B3484

extern int GetEngageEvent(struct _Instance *instance); // 0x800B3944

extern int SetupReaction(struct _Instance *player, struct _Instance *instance); // 0x800B399C

extern int CheckHolding(struct _Instance *instance); // 0x800B3A8C

extern void DisableWristCollision(struct _Instance *instance, int Side); // 0x800B3A98

extern void EnableWristCollision(struct _Instance *instance, int Side); // 0x800B3AE8

extern int GetCollisionType(struct _Instance *instance); // 0x800B3B38

extern void InitGlyphSystem(struct _Instance *instance); // 0x800B3CE0

extern void mdRazielProcess(struct _Instance *playerInstance, struct GameTracker *gameTracker, long *controlCommand); // 0x800B3D18

extern void RazielProcess(struct _Instance *playerInstance, struct GameTracker *gameTracker); // 0x800B3DD0

extern void RazielInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800B3E14

extern void RazielCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x800B3EDC

extern void RAZIEL_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x800B4140

extern void RAZIEL_SetLookAround(struct _Instance *instance); // 0x800B4364

extern void RAZIEL_ResetLookAround(struct _Instance *instance); // 0x800B43DC

extern long RAZIEL_OkToLookAround(struct _Instance *playerInstance); // 0x800B4458

extern void TrailWaterFX(struct _Instance *instance, int Segment, int Bubbles, int Type); // 0x800B44B8


#endif
