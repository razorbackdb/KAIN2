#ifndef MONTABLE_H
#define MONTABLE_H


extern void MONTABLE_SetupTablePointer(struct Object *object); // 0x8008D044

extern struct _MonsterState * MONTABLE_GetStateFuncs(struct _Instance *instance, int state); // 0x8008D094

extern TDRFuncPtr_MONTABLE_GetDamageEffectFunc MONTABLE_GetDamageEffectFunc(struct _Instance *instance); // 0x8008D104

extern TDRFuncPtr_MONTABLE_GetInitFunc MONTABLE_GetInitFunc(struct _Instance *instance); // 0x8008D138

extern TDRFuncPtr_MONTABLE_GetCleanUpFunc MONTABLE_GetCleanUpFunc(struct _Instance *instance); // 0x8008D16C

extern void MONTABLE_SetQueryFunc(struct _Instance *instance); // 0x8008D1A0

extern void MONTABLE_SetMessageFunc(struct _Instance *instance); // 0x8008D1D4


typedef void (*TDRFuncPtr_MONTABLE_GetCleanUpFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetDamageEffectFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetInitFunc)();




#endif
