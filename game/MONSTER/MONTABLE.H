#ifndef MONTABLE_H
#define MONTABLE_H


extern void MONTABLE_SetupTablePointer(struct Object *object); // 0x8008C530

extern struct _MonsterState * MONTABLE_GetStateFuncs(struct _Instance *instance, int state); // 0x8008C580

extern TDRFuncPtr_MONTABLE_GetDamageEffectFunc MONTABLE_GetDamageEffectFunc(struct _Instance *instance); // 0x8008C5F0

extern TDRFuncPtr_MONTABLE_GetInitFunc MONTABLE_GetInitFunc(struct _Instance *instance); // 0x8008C624

extern TDRFuncPtr_MONTABLE_GetCleanUpFunc MONTABLE_GetCleanUpFunc(struct _Instance *instance); // 0x8008C658

extern void MONTABLE_SetQueryFunc(struct _Instance *instance); // 0x8008C68C

extern void MONTABLE_SetMessageFunc(struct _Instance *instance); // 0x8008C6C0


typedef void (*TDRFuncPtr_MONTABLE_GetCleanUpFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetDamageEffectFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetInitFunc)();




#endif
