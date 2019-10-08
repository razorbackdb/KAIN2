#ifndef MONAPI_H
#define MONAPI_H

extern void MonsterProcess(struct _Instance *instance, struct GameTracker *gameTracker);

extern void MonsterInit(struct _Instance *instance, struct GameTracker *gameTracker);

extern void SendHitObject(struct _Instance *instance, struct _Instance *hit, int type);

extern void MonsterCollide(struct _Instance *instance, struct GameTracker *gameTracker);

extern void MonsterAdditionalCollide(struct _Instance *instance, struct GameTracker *gameTracker);

extern unsigned long MonsterQuery(struct _Instance *instance, unsigned long query);

extern void MonsterMessage(struct _Instance *instance, unsigned long message, unsigned long data);

extern void AnimDistanceAndVel(struct Object *object, struct _MonsterAnim *mAnim);

extern void TranslateAnimList(struct Object *object, struct _MonsterAnim *animList, int numAnims);

extern void MonsterTranslateAnim(struct Object *object);

extern void MonsterRelocateTune(struct Object *object, long offset);

extern void MonsterRelocateInstanceObject(struct _Instance *instance, long offset);

extern void MONAPI_TurnHead(struct _Instance *instance, short *rotx, short *rotz, struct GameTracker *gameTracker);

extern void MONAPI_SetLookAround(struct _Instance *instance);

extern void MONAPI_ResetLookAround(struct _Instance *instance);

extern long MONAPI_OkToLookAround(struct _Instance *instance);

extern void MONAPI_DeleteRegen(struct _MONAPI_Regenerator *regen);

extern void MONAPI_ProcessGenerator();

extern void MONAPI_AddToGenerator(struct _Instance *instance);

extern void MONAPI_CheckGenerator(struct _Instance *instance);

#endif
