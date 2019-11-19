#ifndef MONAPI_H
#define MONAPI_H


extern void MonsterProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007CFEC

extern void MonsterInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007D13C

extern void SendHitObject(struct _Instance *instance, struct _Instance *hit, int type); // 0x8007D318

extern void MonsterCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007D3EC

extern void MonsterAdditionalCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007D8C0

extern unsigned long MonsterQuery(struct _Instance *instance, unsigned long query); // 0x8007D8F0

extern void MonsterMessage(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8007DB1C

extern void AnimDistanceAndVel(struct Object *object, struct _MonsterAnim *mAnim); // 0x8007DD64

extern void TranslateAnimList(struct Object *object, struct _MonsterAnim *animList, int numAnims); // 0x8007DECC

extern void MonsterTranslateAnim(struct Object *object); // 0x8007DFC8

extern void MonsterRelocateTune(struct Object *object, long offset); // 0x8007E1D0

extern void MonsterRelocateInstanceObject(struct _Instance *instance, long offset); // 0x8007E3D8

extern void MONAPI_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x8007E4D8

extern void MONAPI_SetLookAround(struct _Instance *instance); // 0x8007E554

extern void MONAPI_ResetLookAround(struct _Instance *instance); // 0x8007E584

extern long MONAPI_OkToLookAround(struct _Instance *instance); // 0x8007E5B4

extern void MONAPI_DeleteRegen(struct _MONAPI_Regenerator *regen); // 0x8007E5C8

extern void MONAPI_ProcessGenerator(); // 0x8007E614

extern void MONAPI_AddToGenerator(struct _Instance *instance); // 0x8007E73C

extern void MONAPI_CheckGenerator(struct _Instance *instance); // 0x8007E7DC


#endif
