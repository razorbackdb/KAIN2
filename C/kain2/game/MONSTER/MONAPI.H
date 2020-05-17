#ifndef MONAPI_H
#define MONAPI_H


extern void MonsterProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007DCB0

extern void MonsterInit(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007DDE8

extern void SendHitObject(struct _Instance *instance, struct _Instance *hit, int type); // 0x8007DFF0

extern void MonsterCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007E0C4

extern void MonsterAdditionalCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8007E5C8

extern unsigned long MonsterQuery(struct _Instance *instance, unsigned long query); // 0x8007E5F8

extern void MonsterMessage(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8007E858

extern void AnimDistanceAndVel(struct Object *object, struct _MonsterAnim *mAnim); // 0x8007EAF4

extern void TranslateAnimList(struct Object *object, struct _MonsterAnim *animList, int numAnims); // 0x8007EC5C

extern void MonsterTranslateAnim(struct Object *object); // 0x8007ED58

extern void MonsterRelocateTune(struct Object *object, long offset); // 0x8007EF10

extern void MonsterRelocateInstanceObject(struct _Instance *instance, long offset); // 0x8007F12C

extern void MONAPI_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker); // 0x8007F250

extern void MONAPI_SetLookAround(struct _Instance *instance); // 0x8007F2CC

extern void MONAPI_ResetLookAround(struct _Instance *instance); // 0x8007F2FC

extern long MONAPI_OkToLookAround(struct _Instance *instance); // 0x8007F32C

extern void MONAPI_DeleteRegen(struct _MONAPI_Regenerator *regen); // 0x8007F340

extern void MONAPI_ProcessGenerator(); // 0x8007F38C

extern void MONAPI_AddToGenerator(struct _Instance *instance); // 0x8007F4CC

extern void MONAPI_CheckGenerator(struct _Instance *instance); // 0x8007F56C


#endif
