#ifndef MONTABLE_H
#define MONTABLE_H

extern void MONTABLE_SetupTablePointer(struct Object *object);

extern struct _MonsterState *MONTABLE_GetStateFuncs(struct _Instance *instance, int state);

extern TDRFuncPtr_MONTABLE_GetDamageEffectFunc MONTABLE_GetDamageEffectFunc(struct _Instance *instance);

extern TDRFuncPtr_MONTABLE_GetInitFunc MONTABLE_GetInitFunc(struct _Instance *instance);

extern TDRFuncPtr_MONTABLE_GetCleanUpFunc MONTABLE_GetCleanUpFunc(struct _Instance *instance);

extern void MONTABLE_SetQueryFunc(struct _Instance *instance);

extern void MONTABLE_SetMessageFunc(struct _Instance *instance);

typedef void (*TDRFuncPtr_MONTABLE_GetCleanUpFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetDamageEffectFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetInitFunc)();

#endif
