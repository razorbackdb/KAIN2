#ifndef SLUAGH_H
#define SLUAGH_H


extern unsigned long SLUAGH_Query(struct _Instance *instance, unsigned long query); // 0x8008CEE0

extern void SLUAGH_DamageEffect(struct _Instance *instance, struct evFXHitData *data); // 0x8008CF74

extern void SLUAGH_Init(struct _Instance *instance); // 0x8008D158

extern void SLUAGH_DeathEntry(struct _Instance *instance); // 0x8008D214

extern void SLUAGH_Death(struct _Instance *instance); // 0x8008D2D8

extern void SLUAGH_AttackEntry(struct _Instance *instance); // 0x8008D360

extern void SLUAGH_Attack(struct _Instance *instance); // 0x8008D3C4


#endif
