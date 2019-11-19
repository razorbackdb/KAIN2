#ifndef MONTABLE_H
#define MONTABLE_H


extern void MONTABLE_SetupTablePointer(struct Object *object); // 0x8008AE7C

extern struct _MonsterState * MONTABLE_GetStateFuncs(struct _Instance *instance, int state); // 0x8008AECC

extern TDRFuncPtr_MONTABLE_GetDamageEffectFunc MONTABLE_GetDamageEffectFunc(struct _Instance *instance); // 0x8008AF3C

extern TDRFuncPtr_MONTABLE_GetInitFunc MONTABLE_GetInitFunc(struct _Instance *instance); // 0x8008AF70

extern TDRFuncPtr_MONTABLE_GetCleanUpFunc MONTABLE_GetCleanUpFunc(struct _Instance *instance); // 0x8008AFA4

extern void MONTABLE_SetQueryFunc(struct _Instance *instance); // 0x8008AFD8

extern void MONTABLE_SetMessageFunc(struct _Instance *instance); // 0x8008B00C


typedef void (*TDRFuncPtr_MONTABLE_GetCleanUpFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetDamageEffectFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetInitFunc)();




#endif
