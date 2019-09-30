#ifndef MONAPI_H
#define MONAPI_H


extern void MonsterProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007DA70

extern void MonsterInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007DBA4

extern void SendHitObject(struct _Instance *instance, struct _Instance *hit, int type); // 0x8007DDAC

extern void MonsterCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007DE80

extern void MonsterAdditionalCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007E388

extern unsigned long MonsterQuery(struct _Instance *instance, unsigned long query); // 0x8007E3B8

extern void MonsterMessage(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8007E5EC

extern void AnimDistanceAndVel(struct Object *object, struct _MonsterAnim *mAnim); // 0x8007E834

extern void TranslateAnimList(struct Object *object, struct _MonsterAnim *animList, int numAnims); // 0x8007E99C

extern void MonsterTranslateAnim(struct Object *object); // 0x8007EA98

extern void MonsterRelocateTune(struct Object *object, long offset); // 0x8007EC50

extern void MonsterRelocateInstanceObject(struct _Instance *instance, long offset); // 0x8007EE6C

extern void MONAPI_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x8007EF6C

extern void MONAPI_SetLookAround(struct _Instance *instance); // 0x8007EFE8

extern void MONAPI_ResetLookAround(struct _Instance *instance); // 0x8007F018

extern long MONAPI_OkToLookAround(struct _Instance *instance); // 0x8007F048

extern void MONAPI_DeleteRegen(struct _MONAPI_Regenerator *regen); // 0x8007F05C

extern void MONAPI_ProcessGenerator(); // 0x8007F0A8

extern void MONAPI_AddToGenerator(struct _Instance *instance); // 0x8007F1D0

extern void MONAPI_CheckGenerator(struct _Instance *instance); // 0x8007F270


#endif
